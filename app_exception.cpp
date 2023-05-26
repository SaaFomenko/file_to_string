#include "app_exception.h"


AppException::AppException(const std::string& msg) :
	_msg(msg)
{}

const char* AppException::what() const noexcept
{
	return _msg.c_str();
}

AppException::~AppException()
{}
