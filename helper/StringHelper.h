#ifndef STRING_HELPER_H_
#define STRING_HELPER_H_

#include <vector>
#include <string>

#define BUFFER_SIZE 256

std::vector<std::string> split(const std::string& str, char delimiter);

/// <summary>
/// Warning: max buffer size is only 256
/// </summary>
/// <param name="string">string with c formating</param>
/// <param name="number"></param>
/// <returns></returns>
std::string format(std::string string, float number);
/// <summary>
/// Warning: max buffer size is only 256
/// </summary>
/// <param name="string">string with c formating</param>
/// <param name="number">integer you want to format</param>
/// <returns></returns>
std::string format(std::string string, int number);

#endif // !STRING_HELPER_H_

