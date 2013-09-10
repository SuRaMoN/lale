#ifndef LALE_CORE_ENTITYNOTFOUNDEXCEPTION_H
#define LALE_CORE_ENTITYNOTFOUNDEXCEPTION_H

#include "app/lale.h"

namespace lale { namespace core {

class EntityNotFoundException : public std::exception
{
protected:
    std::string message;

public:
    EntityNotFoundException(std::string message) throw();
    virtual ~EntityNotFoundException() throw();
    virtual const char* what() const throw();
};

}}

#endif // LALE_CORE_ENTITYNOTFOUNDEXCEPTION_H
