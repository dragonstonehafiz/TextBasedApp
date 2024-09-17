#ifndef QUESTION_MANAGER_H_
#define QUESTION_MANAGER_H_

#include <string>
#include <vector>

#include "../base/SingletonTemplate.h"

struct Question
{
	std::string qns;
	std::string ans;
	std::vector<std::string> options;
	std::vector<std::string> tags;
};

class QuestionManager
	: public Singleton<QuestionManager>
{
	friend Singleton<QuestionManager>;
public:
	bool loadQuestions(std::string path);
private:
	QuestionManager();
	~QuestionManager();

	std::vector<Question> questions;
	std::vector<std::string> tags;
};

#endif // !QUESTION_MANAGER_H_