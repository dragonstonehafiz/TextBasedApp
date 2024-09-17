#include "QuestionManager.h"

#include "../helper/CSV_Reader.h"
#include "../helper/StringHelper.h"

QuestionManager::QuestionManager()
{

}
QuestionManager::~QuestionManager()
{

}


bool QuestionManager::loadQuestions(std::string path)
{
	questions.clear();

	CSV_Reader reader = CSV_Reader::readfile(path);

	for (int i = 0; i < reader.size(); ++i)
	{
		std::string qns = reader.get(i, "qns");
		std::string ans = reader.get(i, "ans");
		std::string options_raw = reader.get(i, "options");
		std::vector<std::string> options = split(options_raw, '|');
		std::string tags_raw = reader.get(i, "tags");
		std::vector<std::string> tags = split(tags_raw, '|');

		Question qn = { qns, ans, options, tags };
		questions.push_back(qn);
	}

	return true;
}