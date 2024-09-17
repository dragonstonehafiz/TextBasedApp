#ifndef OBJECT_MENU_LEVEL_SELECT_H_
#define OBJECT_MENU_LEVEL_SELECT_H_

#include "ObjectMenu.h"

/// <summary>
/// Contains data on each directory in the directory that should have all our data.
/// </summary>
struct DataDirectory
{
	/// <summary>
	/// This is the name that will appear in the options.
	/// </summary>
	std::string name;

	/// <summary>
	/// This is the relative path to the directory
	/// </summary>
	std::string path;
	std::string csvPath;
	std::string configPath;

	/// <summary>
	/// This is the index of the option in the menu
	/// </summary>
	int index;
};

class ObjectMenu_LevelSelect :
	public ObjectMenu
{
public:
	ObjectMenu_LevelSelect();
	~ObjectMenu_LevelSelect();

	/// <summary>
	/// Check the provided path for valid data
	/// </summary>
	bool loadDirectories(std::string dataFolderPath);

	/// <summary>
	/// If the current option is the option to go back to the prev directory.
	/// </summary>
	bool isCurr_Back() const;
	/// <summary>
	/// Gets the path to the current csv file.
	/// </summary>
	/// <returns></returns>
	std::string getCurrCSVPath() const;
	/// <summary>
	/// Gets the path to the current config file
	/// </summary>
	/// <returns></returns>
	std::string getCurrConfigPath() const;
private:
	std::vector<DataDirectory> directories;

	/// <summary>
	/// Called during loadDirectories().
	/// This function basically creates all the options that the user can choose from.
	/// </summary>
	void createOptions();
};


#endif // !OBJECT_MENU_LEVEL_SELECT_H_
