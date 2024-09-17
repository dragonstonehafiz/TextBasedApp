#ifndef OBJECT_MENU_H_
#define OBJECT_MENU_H_

#include "ObjectBase.h"
#include <vector>
#include <string>

class ObjectMenu :
	public ObjectBase
{
public:
	ObjectMenu();
	~ObjectMenu();

	/// <summary>
	/// Sets the current option to whatever index is given. Wraps is value is too high or too low.
	/// </summary>
	/// <param name="_currOption"></param>
	void setCurrOption(int _currOption);
	/// <summary>
	/// The current option that the user is on.
	/// </summary>
	/// <returns>The index of the current option</returns>
	int getCurrOption() const;
	/// <summary>
	/// Go to the option above. Wraps to bottom if goes under min.
	/// </summary>
	void goUp();
	/// <summary>
	/// Go to the option below. Wraps to top if goes over max.
	/// </summary>
	void goDown();
	/// <summary>
	/// Options are added by providing a comma seperated string
	/// </summary>
	/// <param name="options">A string where each option is seperated by a string</param>
	void setOptions(std::string _options);

	void setSpaceBetweenOptions(int _spaceBetweenOptions);
	void setCentered(bool _centered);

	virtual void update(double dt);
	virtual void render();
protected:
	int currOption;
	std::vector<std::string> options;
	int spaceBetweenOptions;
	bool centered;

	void wrap();
};

#endif // !OBJECT_MENU_H_
