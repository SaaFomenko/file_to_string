#ifndef APP_EXCEPTION_H
#define APP_EXCEPTION_H

#include <string>


class AppException : public std::exception
{
	const std::string _msg;

	public:
	AppException(const std::string& msg);
	virtual ~AppException();

	const char* what() const noexcept override;
};

#endif
