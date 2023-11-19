#pragma once
#include "iostream"
#include "fstream"
#include "map"
#include <utility>
#include <cstdlib>

class btc {
	private:
		std::map<std::string, std::string> _db;
		// std::map<std::string, std::string> _input;
		void	parseDB(std::ifstream& db_stream);
		void	parse_DB_File(const std::string db_file);
		void	checkDate(const std::string originalStr);
		std::pair<std::string, std::string> parseLine(const std::string line, char separator);
	public:
		btc();
		btc(const std::string db_file);
		btc(const btc& obj);
		btc& operator=(const btc& obj);
		~btc();
		void	processInput(const std::string inFile);
};

void trimString(std::string &str, const std::string seperator);
bool isValidDate(int year, int month, int day);
