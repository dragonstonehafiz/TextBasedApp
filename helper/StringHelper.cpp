#include "StringHelper.h"

#include <sstream>

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