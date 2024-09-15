#ifndef CSV_H_
#define CSV_H_

#include <string>
#include <vector>
#include <map>

std::vector<std::string> split(const std::string& str, char delimiter);

class CSV_Reader
{
public:
	~CSV_Reader();

	std::string getcolnames() const;
	std::string *get(int index, const std::string& col);
	std::map<std::string, std::string> *get(int index);
	bool isEmpty();

	static CSV_Reader readfile(const std::string& filepath);
private:
	CSV_Reader();

	std::vector<std::string> colnames;
	std::vector<std::map<std::string, std::string>> rows;
};

#endif // !CSV_H_
