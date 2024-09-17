#include "StringHelper.h"

#include <sstream>
#include <iomanip>

char buffer[BUFFER_SIZE];

std::vector<std::string> split(const std::string& str, char delimiter)
{
	std::vector<std::string> tokens;
	std::stringstream ss(str);  // Create string stream from the string
	std::string token;

	// Use std::getline to split the string using the delimiter
	while (std::getline(ss, token, delimiter))
		tokens.push_back(token);  // Add each token to the vector

	return tokens;
}

std::string format(std::string string, float number)
{
	sprintf_s(buffer, string.c_str(), number);

	return buffer;
}
std::string format(std::string string, int number)
{
	sprintf_s(buffer, string.c_str(), number);

	return buffer;
}
std::string getStringTime(int time)
{
	int h, min, s;

	// starting with 5500s
	// 5400s -> 91min + 40s -> 1h + 31min + 40s

	s = time % 60;

	// total minutes in the provided time
	min = time / 60;
	// find remainder of mins after removing hours
	min = min % 60;

	h = time / 60 / 60;

	std::stringstream ss;
	if (h > 0)
		ss << h << "h";

	ss << std::setw(2) << std::setfill('0') << min << "min";
	ss << std::setw(2) << std::setfill('0') << s << "s";
	return ss.str();
}