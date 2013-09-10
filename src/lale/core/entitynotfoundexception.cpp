#include "entitynotfoundexception.h"

using namespace lale::core;

EntityNotFoundException::EntityNotFoundException(std::string message) throw()
{
    this->message = message;
}


EntityNotFoundException::~EntityNotFoundException() throw()
{
}

const char *EntityNotFoundException::what() const throw()
{
    return message.c_str();
}
