#ifndef CONFIG_FILE_H_
#define CONFIG_FILE_H_

#include <map>
#include <string>
#include <fstream>
#include "StringHelper.h"


struct ConfigFile
{
	ConfigFile(std::string path)
	{
		std::ifstream config_file(path);

		if (!config_file.is_open())
		{
			success = false;
			return;
		}

		std::string line;
		while (std::getline(config_file, line))
		{
			std::vector<std::string> splitString = split(line, '=');
			data[splitString.at(0)] = splitString.at(1);
		}

		success = true;
	}

	std::map<std::string, std::string> data;
	bool success;
};

#endif // !CONFIG_FILE_H_
