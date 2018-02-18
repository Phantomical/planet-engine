#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <deque>

// Files that have already been included
std::vector<std::string> Included;
// Directories in which to search for include files
std::vector<std::string> IncludeDirs;
std::string File;

bool StartsWith(const std::string& str, const std::string& val)
{
	if (val.size() > str.size())
		return false;

	for (size_t i = 0; i < val.size(); ++i)
	{
		if (val[i] != str[i])
			return false;
	}

	return true;
}
std::string Strip(const std::string& str)
{
	size_t i = 0;
	for (; i < str.size() && iswspace(str[i]); ++i);

	std::string tmp = str.data() + i;

	if (!tmp.empty())
	{
		for (i = tmp.size() - 1; i != 0 && iswspace(tmp[i]); --i)
		{
			tmp[i] = '\0';
		}
	}

	return tmp.c_str();
}

void ParseFile(std::ifstream& file, std::deque<std::string>& lines)
{
	std::string line;
	long index = -1;

	while (std::getline(file, line))
	{
		++index;
		line = Strip(line);

		if (StartsWith(line, "#include"))
		{
			std::string filename = Strip(line.data() + 8);

			auto it = std::find(filename.begin() + 1, filename.end(), '"');
			if (it == filename.end())
			{
				std::cout << File << '(' << index << ')' << " Error: Incomplete include directive." << std::endl;
				continue;
			}
			size_t idx = it - filename.begin();

			filename[idx] = '\0';

			std::string fname = filename.c_str() + 1;

			std::ifstream newfile;
			bool opened = false;

			for (auto& path : IncludeDirs)
			{
				newfile = std::ifstream(path + fname.c_str());

				if (newfile.is_open())
				{
					opened = true;
					break;
				}
			}

			if (!opened)
			{
				std::cout << File << '(' << index << ") Error: Unable to open file '" << fname.c_str() << "'." << std::endl;
				continue;
			}

			std::string oldfile = File;
			File = filename;

			lines.push_back("#line 1");
			ParseFile(newfile, lines);
			std::stringstream ss;
			ss << "#line " << index + 2;
			lines.push_back(ss.str());

			File = oldfile;
		}
		else
		{
			lines.push_back(line);
		}
	}
}

int main(int argc, char** argv)
{
	bool val = false;
	std::string outfile;
	if (argc < 2)
	{
		std::cout <<
			"usage:\n glslpp <input-file> <output-file> [options]\n"
			"\n"
			"Options:\n"
			" -I<path>  Adds a directory to the include path."
			<< std::endl;
	}

	for (int i = 1; i < argc; ++i)
	{
		if (StartsWith(argv[i], "-I"))
		{
			IncludeDirs.push_back(argv[i] + 2 + std::string("\\"));
		}
		else
		{
			if (!val)
			{
				File = argv[i];
				val = true;
			}
			else
				outfile = argv[i];
		}
	}

	std::ifstream file(File.c_str());
	std::ofstream output(outfile);
	std::deque<std::string> lines;

	if (!file.is_open())
	{
		std::cout << "Error: Unable to open '" << File << "'." << std::endl;
		return 1;
	}
	if (!output.is_open())
	{
		std::cout << "Error: Unable to open '" << outfile << "'." << std::endl;
		return 1;
	}

	ParseFile(file, lines);

	for (auto& line : lines)
	{
		output << line << std::endl;
	}

	return 0;
}
