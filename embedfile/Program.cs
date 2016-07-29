using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.IO;

namespace embedfile
{
	class Program
	{
		static string HelpText = @"Usage:
	embedfile.exe <input file> [options]

embedfile embeds the text of the file as a C string
in a C source file.

Options:
    -o         Indicates an output file for the output to be recorded in.
    -?/-h      Prints out this help dialog.
    -n --name  Provides an alternate name for the variable that the string is recorded to.";

		static string output = null;
		static string input = null;
		static string name = null;
		static string CurrentFile = null;

		static IEnumerable<string> ProcessLines(IEnumerable<string> lines)
		{
			List<string> outlines = new List<string>();

			foreach (string ln in lines)
			{
				if (ln.StartsWith("#include"))
				{
					string oldfile = CurrentFile;
					string file = ln.Split(' ', '\t')[1];
					CurrentFile = Path.GetDirectoryName(CurrentFile) + "\\" + file.Trim('"');
					outlines.AddRange(ProcessLines(File.ReadLines(CurrentFile)));
					CurrentFile = oldfile;
				}
				else
				{
					// Escape quotes in file
					string nln = Regex.Replace(ln, "\"", @"\""");
					outlines.Add("\"" + nln + "\\n\"");
				}
			}

			return outlines;
		}

		static void Main(string[] args)
		{

			if (args.Length < 1)
			{
				Console.Error.WriteLine(HelpText);
				return;
			}

			for (int i = 0; i < args.Length; ++i)
			{
				if (args[i] == "-o")
				{
					output = args[i + 1];
					++i;
				}
				else if (args[i] == "-?" || args[i] == "-h")
				{
					Console.Error.WriteLine(HelpText);
					return;
				}
				else if (args[i] == "-n" || args[i] == "--name")
				{
					name = args[i + 1];
					++i;
				}
				else
				{
					if (input == null)
						input = args[i];
					else
					{
						Console.Error.WriteLine("Warning: Unknown argument '" + args[i] + "'. Argument will be ignored.");
					}
				}
			}

			if (input == null)
			{
				Console.Error.WriteLine("Error: No input file provided. Exiting.");
				return;
			}

			var lines = File.ReadLines(input);

			List<string> outlines = new List<string>();

			if (name == null)
			{
				name = input.Split('.').First();
			}

			outlines.Add("const char* " + name + " = ");


			CurrentFile = Path.GetFullPath(input);

			outlines.AddRange(ProcessLines(lines));

			outlines.Add(";");
			outlines.Add("");

			if (output == null)
			{
				foreach (string ln in outlines)
				{
					Console.WriteLine(ln);
				}
			}
			else
			{
				File.WriteAllLines(output, outlines);
			}
		}
	}
}
