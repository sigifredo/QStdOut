

#ifndef STREAMLISTENERINTERFACE_HPP
#define STREAMLISTENERINTERFACE_HPP

#include <string>

class StreamListenerInterface
{
public:
    virtual void endLine() = 0;
    virtual void print(const std::string& str) = 0;
};

#endif
