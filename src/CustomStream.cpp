

// Own
#include <CustomStream.hpp>
#include <StreamListenerInterface.hpp>


CustomStream::CustomStream(std::ostream& stream, StreamListenerInterface * pListener):
    std::basic_streambuf<char>(), m_stream(stream), _pListener(pListener)
{
    m_old_buf = stream.rdbuf();
    stream.rdbuf(this);
}

CustomStream::~CustomStream()
{
    m_stream.rdbuf(m_old_buf);
}

CustomStream::int_type CustomStream::overflow(CustomStream::int_type v)
{
    if (v == '\n' && _pListener)
        _pListener->endLine();

    return v;
}

std::streamsize CustomStream::xsputn(const char *cStr, std::streamsize n)
{
    if (_pListener)
    {
        _pListener->print(std::string(cStr));
        return n;
    }
    else
        return 0;
}
