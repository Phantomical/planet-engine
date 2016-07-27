using System;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Xml;

namespace noisemaker
{
	class Program
	{
		class Params
		{
			public string ScalarType;
			public string VectorPrefix;

			public Params()
			{
				ScalarType = "float";
				VectorPrefix = "";
			}
		}

		class Function
		{
			public string Name;
			public Dictionary<string, string> Params = new Dictionary<string, string>();
		}

		static Dictionary<string, Function> Functions = new Dictionary<string, Function>();

		static int Main(string[] args)
		{
			if (args.Length < 1)
			{
				Console.WriteLine("usage: noisemaker <input file> [-o <output file>]");
				return 1;
			}

			string input_file = null, output_file = null;

			for (int i = 0; i < args.Length; ++i)
			{
				if (args[i] == "-o")
				{
					output_file = args[i + 1];
					++i;
				}
				else if (args[i].StartsWith("-"))
				{
					Console.WriteLine("Warning: Unknown switch '" + args[i] + "' switch will be ignored.");
				}
				else
				{
					if (input_file != null)
					{
						Console.WriteLine("Error: Unknown argument '" + args[i] + "'");
						return 1;
					}
					input_file = args[i];
				}
			}

			XmlDocument doc = new XmlDocument();
			doc.Load(input_file);

			Function last = null;

			foreach (XmlNode source in doc.SelectNodes("/noise/source"))
			{
				Function func = new Function();

				foreach (XmlNode node in source.ChildNodes)
				{
					func.Params.Add(node.Name, node.InnerText);
				}

				func.Name = source.Attributes["name"].Value;

				Functions.Add(func.Name, func);
				last = func;
			}

			Params noiseparams = new Params();

			foreach (XmlNode node in doc.LastChild.ChildNodes)
			{
				switch (node.Name)
				{
					case "scalartype":
						if (node.InnerText == "double")
						{
							noiseparams.ScalarType = "double";
							noiseparams.VectorPrefix = "d";
						}
						break;
					case "source":
						continue;
				}
			}

			List<string> lines = new List<string>();

			foreach (var func in Functions)
			{
				string functext;
				switch (func.Value.Params["type"])
				{
					case "constant":
						functext = Resources.Constant;
						break;
					case "simplex":
						functext = Resources.Simplex;
						break;
					case "voronoi_f1":
						functext = Resources.VoronoiF1;
						break;
					case "voronoi_f2":
						functext = Resources.VoronoiF2;
						break;
					case "voronoi":
						functext = Resources.Voronoi;
						break;
					case "fractal":
						functext = Resources.fBm;
						break;
					case "fbm":
						functext = Resources.fBm;
						break;
					default:
						Console.WriteLine("Error: Invalid function type '" + func.Value.Name + "'. Exiting now.");
						return 1;
				}

				functext = Regex.Replace(functext, "@name", func.Value.Name);
				functext = Regex.Replace(functext, "@scalar", noiseparams.ScalarType);
				functext = Regex.Replace(functext, "@vec(1|2|3|4)", noiseparams.VectorPrefix + "vec$1");

				foreach (var param in func.Value.Params)
				{
					if (param.Key == "type")
						continue;
					string text;
					double tmp;
					if (Double.TryParse(param.Value, out tmp))
						text = param.Value;
					else
						text = param.Value + "(v)";
					functext = Regex.Replace(functext, "@" + param.Key, text);
				}

				lines.Add(functext);
			}

			TextWriter file;
			if (output_file != null)
				file = new StreamWriter(new FileStream(output_file, FileMode.Create));
			else
				file = Console.Out;

			foreach (var line in lines)
			{
				file.WriteLine(line);
			}

			file.Close();

			return 0;
		}
	}
}
