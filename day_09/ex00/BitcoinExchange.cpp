#include "BitcoinExchange.hpp"

btc::btc(){};

btc::btc(const std::string db_file)
{
	this->parse_DB_File(db_file);
};

btc::btc(const btc &obj) { *this = obj; };

btc &btc::operator=(const btc &obj)
{
	if (&obj != this)
		_db = obj._db;
	return (*this);
}

btc::~btc() {}

void btc::parse_DB_File(const std::string db_file)
{
	std::ifstream db_stream(db_file.c_str());

	if (!db_stream)
		throw(std::runtime_error("Failed to open file !"));
	parseDB(db_stream);
}

void btc::parseDB(std::ifstream &db_stream)
{
	std::string tmp = "";
	std::pair<std::string, std::string> tmpPair;
	if (!getline(db_stream, tmp))
		throw(std::logic_error("Empty File !"));
	tmpPair = parseLine(tmp, ',');
	if (tmpPair.first != "date" || tmpPair.second != "exchange_rate")
		throw(std::logic_error(("Invalid Value: " + tmp).c_str()));
	while (getline(db_stream, tmp))
	{
		tmpPair = parseLine(tmp, ',');
		try
		{
			checkDate(tmpPair.first);
			if (tmpPair.second.find_first_not_of("0123456789.") < tmpPair.second.length()
				|| atoi(tmpPair.second.c_str()) < 0)
				throw (std::logic_error(""));
			for (size_t i = 0, x = 0; i < tmpPair.second.length(); i++)
				if (tmpPair.second[i] == '.' && ++x && x > 1)
					throw (std::logic_error(""));
			_db[tmpPair.first] = tmpPair.second;
		}
		catch (const std::exception &e)
		{
			_db[tmpPair.first] = "Invalid";
		}
	}

	// std::map<std::string, std::string>::iterator b = _db.begin();

	// for (; b != _db.end(); b++)
	// 	std::cout << (*b).first << " " << (*b).second << "\n";
}

void trimString(std::string &str, const std::string seperator)
{
	size_t pos = str.find_first_not_of(seperator);
	str.erase(0, pos > str.length() ? 0 : pos);
	pos = str.find_last_not_of(seperator);
	str.erase(pos > str.length() ? str.length() : pos + 1);
}
std::pair<std::string, std::string> btc::parseLine(const std::string line, char separator)
{
	std::string key = "", value = "";
	// ? parse key
	{
		size_t lastChar = line.find_first_of(separator);
		key = line.substr(0, lastChar > line.length() ? line.length() : lastChar);
		trimString(key, " 	");
	}
	// ? parse value
	{
		size_t firstChar = line.find_first_of(separator) + 1;
		value = line.substr(firstChar > line.length() ? 0 : firstChar);
		trimString(value, " 	");
	}

	return (std::pair<std::string, std::string>(key, value));
}


void btc::checkDate(const std::string originalStr)
{
	std::string str(originalStr);
	std::string date[4];
	for (size_t i = 0; i < 3; i++)
	{
		size_t pos = str.find_first_of("-") > str.length() ? str.length() : str.find_first_of("-");
		date[i] = str.substr(0, pos);
		str.erase(0, pos + 1 > str.length() ? str.length() : pos + 1);
	}
	if (date[0].length() != 4 || date[0].find_first_not_of("0123456789") < date[0].length())
		throw(std::logic_error(("bad input => " + originalStr).c_str()));
	if (date[1].length() != 2 || date[1].find_first_not_of("0123456789") < date[1].length())
		throw(std::logic_error(("bad input => " + originalStr).c_str()));
	if (date[2].length() != 2 || date[2].find_first_not_of("0123456789") < date[2].length())
		throw(std::logic_error(("bad input => " + originalStr).c_str()));
	if (!isValidDate(atoi(date[0].c_str()), atoi(date[1].c_str()), atoi(date[2].c_str())))
		throw(std::logic_error(("bad input => " + originalStr).c_str()));
}

void	btc::processInput(const std::string inFile)
{
	std::ifstream	inFileStream(inFile.c_str());
	std::string		tmp = "";
	std::pair<std::string, std::string> tmpPair = parseLine(tmp, '|');

	if (!inFileStream)
		throw (std::runtime_error(("Failed when try to open " + inFile + " file").c_str()));
	if (!getline(inFileStream, tmp))
		throw (std::logic_error("Empty file !"));
	{
		tmpPair = parseLine(tmp, '|');
		if (tmpPair.first != "date" || tmpPair.second != "value")
			throw(std::logic_error(("Invalid Value: " + tmp).c_str()));
	}
	while (std::getline(inFileStream, tmp))
	{
		try {
			tmpPair = parseLine(tmp, '|');
			checkDate(tmpPair.first);
			if (tmpPair.second.find_first_not_of("-0123456789.") < tmpPair.second.length())
				throw (std::logic_error(("bad input => " + tmpPair.second).c_str()));
			if (tmpPair.second.find_first_of("-") < tmpPair.second.length())
			{
				if (!isdigit(tmpPair.second[tmpPair.second.find_first_of("-") + 1]))
					throw (std::logic_error(("bad input => " + tmpPair.second).c_str()));
				if (tmpPair.second.find_first_of("-") > 0
					&& !isdigit(tmpPair.second[tmpPair.second.find_first_of("-") - 1]))
					throw (std::logic_error(("bad input => " + tmpPair.second).c_str()));
				for (size_t i = 0, x = 0; i < tmpPair.second.length(); i++)
					if (tmpPair.second[i] == '-' && ++x && x > 1)
						throw (std::logic_error(("bad input => " + tmpPair.second).c_str()));
			}
			if (atoll(tmpPair.second.c_str()) < 0)
				throw (std::logic_error("not a positive number."));
			if (atoll(tmpPair.second.c_str()) > 1000)
				throw (std::logic_error("too large a number."));
			std::map<std::string, std::string>::iterator itt = _db.lower_bound(tmpPair.first);
			if ((*itt).first != tmpPair.first && itt != _db.begin())
				--itt;
			std::cout << tmpPair.first << " => " << tmpPair.second << " => ";
			std::cout << atof(tmpPair.second.c_str()) * atof(_db[(*itt).first].c_str()) << "\n";
			// std::cout << (*itt).first << "\n";
		}
		catch (const std::exception &err)
		{
			std::cout << "Error: " << err.what() << "\n";
		}
	}
}


bool isValidDate(int year, int month, int day)
{
	int monthsDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year < 1 || month < 0 || month > 12 || day < 1 || day > 31)
		return (0);
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		monthsDays[month] += 1;
	return (day <= monthsDays[month]);
}
