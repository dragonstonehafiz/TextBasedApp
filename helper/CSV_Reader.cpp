#include "CSV_Reader.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include "StringHelper.h"

CSV_Reader::CSV_Reader()
{

}
CSV_Reader::~CSV_Reader()
{

}


std::string CSV_Reader::getcolnames() const
{
	std::string output;
	for (auto colname : colnames)
		output = output + "," + colname;
	return output;
}
std::string *CSV_Reader::get(int index, const std::string& col)
{
	// Check if the provided index is in the row vector
	if (index < 0 || index >= rows.size())
		return nullptr;

	// Checks if the provided key is in the map
	if (rows[index].count(col) == 0)
		return nullptr;
	
	return &rows[index][col];
}
std::map<std::string, std::string>* CSV_Reader::get(int index)
{
	// Check if the provided index is in the row vector
	if (index < 0 || index >= rows.size())
		return nullptr;

	return &rows[index];
}
bool CSV_Reader::isEmpty()
{
	return rows.size() == 0;
}

CSV_Reader CSV_Reader::readfile(const std::string& filepath)
{
	std::ifstream file(filepath);

	// return empty csv file if nothing was opening
	if (!file.is_open())
		return CSV_Reader();

	std::string line;
	// Get the columns first
	std::getline(file, line);
	// Check for BOM (0xEF, 0xBB, 0xBF) at the beginning of the file
	if (line.size() >= 3 &&
		static_cast<unsigned char>(line[0]) == 0xEF &&
		static_cast<unsigned char>(line[1]) == 0xBB &&
		static_cast<unsigned char>(line[2]) == 0xBF) {
		// Remove BOM by erasing the first 3 characters
		line.erase(0, 3);
	}
	std::vector<std::string> colnames = split(line, ',');
	
	// Add each row to the output vector
	std::vector<std::map<std::string, std::string>> rows;
	while (std::getline(file, line))
	{
		// Add a new row to the map
		std::map<std::string, std::string> row;
		// Add each column to the row map
		std::vector<std::string> values = split(line, ',');
		for (int i = 0; i < colnames.size(); ++i)
		{
			std::string col = colnames[i];
			try {
				row[col] = values.at(i);
			}
			catch (const std::out_of_range& e) {
				row[col] = "MISSING VALUE DURING READING";
			}
		}
		rows.push_back(row);
	}

	CSV_Reader csv;
	csv.colnames = colnames;
	csv.rows = rows;

	return csv;
}