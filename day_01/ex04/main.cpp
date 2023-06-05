#include "fstream"
#include "iostream"
#include "string"

std::string replace_line(std::string &line, std::string s1, std::string s2)
{
	std::string temp = "";
	std::string final = "";
	int			lastPos = 0;
	int			i = 0;

	while (1)
	{
		temp = line.substr(i, line.length());
		lastPos = temp.find(s1);
		if (lastPos != -1)
		{
			lastPos = i + lastPos;
			line.erase(lastPos, s1.length());
			line.insert(lastPos, s2);
			i = lastPos + s2.length();
		}
		else
			break;
	}
	return (line);
}

int main(int ac, char const *av[])
{
	if (ac != 4 || !strlen(av[2])){
		std::cerr << "\033[0;31mcheck args please\033[0;37m" << std::endl;
		return (1);
	}
	std::ifstream infile(av[1]);
	std::ofstream outfile((std::string)av[1] + ".replace");
	if (!infile || !outfile){
        if (!infile)
			perror(av[1]);
        else
			perror("output file");
        return (1);
    }
	std::string line;
	while (std::getline(infile, line))
	{	
		outfile << replace_line(line, (std::string)av[2], (std::string)av[3]);
		if (!infile.eof())
			outfile << "\n";
	}
	infile.close();
	outfile.close();
	return 0;
}
