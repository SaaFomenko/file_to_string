#include <fstream>
#include "file_to_string.h"
#include "lib/app_exception/app_exception.h"


static const std::string err_file_msg = "Не удалось прочитать файл, проерьте его наличие и праава доступа: ";

std::string file_to_string(const std::string& path_str)
{
	std::string str = "";

	std::ifstream fin(path_str);

	if(!fin.is_open())
	{
		throw AppException(err_file_msg + path_str);
	}

	int i = 0;

	while (!fin.eof())
	{
		std::string word = "";
		fin >> word;

		if (i != 0 && !fin.eof())
		{
			word = " " + word;
		}

		str += word;
		++i;
	}

	return str;
}
