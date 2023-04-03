#include "fstream"
#include "iostream"
#include "string"

std::string replace_line(std::string &line, std::string s1, std::string s2)
{
	std::string temp = "";
	std::string final = "";
	for (int i = 0; line[i]; i++)
	{
		temp = line.substr(i, s1.length());
		if (temp == s1)
		{
			final += s2;
			i += s1.length() -1;
		}
		else
			final += line[i];
	}
	return (final);
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
        if (!infile) perror(av[1]);
        else
			perror("output file");
        return (1);
    }
	std::string temp;
	while (std::getline(infile, temp))
	{
		outfile << replace_line(temp, (std::string)av[2], (std::string)av[3]) << std::endl;
	}
	infile.close();
	outfile.close();
	return 0;
}
