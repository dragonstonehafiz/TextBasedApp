#include "ObjectMenu_LevelSelect.h"

#include "../helper/ConfigFile.h"

#include <filesystem>
namespace fs = std::filesystem;

ObjectMenu_LevelSelect::ObjectMenu_LevelSelect()
{

}
ObjectMenu_LevelSelect::~ObjectMenu_LevelSelect()
{

}

/// <summary>
/// Check the provided path for valid data
/// </summary>
bool ObjectMenu_LevelSelect::loadDirectories(std::string dataFolderPath)
{
	directories.clear();
	// We check if the provided path actually leads to a folder
	int pathIndex = 0;
	if (fs::exists(dataFolderPath) && fs::is_directory(dataFolderPath))
	{
		// Iterate through all items in the folder
		for (const auto& entry : fs::directory_iterator(dataFolderPath))
		{
			// If this path is not a directory, skip.
			if (!fs::is_directory(entry.status()))
				continue;

			std::string path = dataFolderPath + '/' + entry.path().filename().string();
			std::string configFilePath = path + "/config.cfg";
			std::string csvFilePath = path + "/data.csv";
			// If this directory does not have a config or csv file, skip
			if (!fs::exists(configFilePath) || !fs::exists(csvFilePath))
				continue;

			ConfigFile config(configFilePath);
			if (!config.success)
				continue;

			// Get the path to the current folder
			std::string name = config.data["name"];
			DataDirectory pathNamePair = { name, path, csvFilePath, configFilePath, pathIndex };
			directories.push_back(pathNamePair);
			++pathIndex;
		}
	}

	createOptions();

	// Returns falls if not directories were found
	return directories.size() > 0;
}

bool ObjectMenu_LevelSelect::isCurr_Back() const
{
	// Back is the final option
	return (currOption == options.size() - 1);
}
std::string ObjectMenu_LevelSelect::getCurrCSVPath() const
{
	if (!isCurr_Back())
		return directories.at(currOption).csvPath;
}
std::string ObjectMenu_LevelSelect::getCurrConfigPath() const
{
	if (isCurr_Back())
		return directories.at(currOption).configPath;
}

void ObjectMenu_LevelSelect::createOptions()
{
	std::string output = "";
	for (auto path : directories)
		output = output + path.name + ',';
	//output[output.length() - 1] = '\0';
	output += "Back";
	
	setOptions(output);
}