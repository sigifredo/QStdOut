

#ifndef CUSTOMSTREAM_HPP
#define CUSTOMSTREAM_HPP

// std
#include <iostream>
#include <streambuf>

class StreamListenerInterface;

class CustomStream: public std::basic_streambuf<char>
{
public:
    CustomStream(std::ostream& stream, StreamListenerInterface * pListener = nullptr);
    ~CustomStream();

protected:
    virtual int_type overflow(int_type v);
    virtual std::streamsize xsputn(const char *cStr, std::streamsize n);

private:
    std::ostream& m_stream;
    std::streambuf* m_old_buf;
    StreamListenerInterface * _pListener;
};

#endif
