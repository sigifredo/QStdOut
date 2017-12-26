

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
        _pListener->textCatched(std::string(cStr));
        return n;
    }
    else
        return 0;
    /*
    QString str(p);

    if (str.contains("\n"))
    {
        QStringList strSplitted = str.split("\n");

        log_window->moveCursor (QTextCursor::End);
        log_window->insertPlainText (strSplitted.at(0)); //Index 0 is still on the same old line

        for (int i = 1; i < strSplitted.size(); i++)
        {
            log_window->append(strSplitted.at(i));
        }
    }
    else
    {
        log_window->moveCursor (QTextCursor::End);
        log_window->insertPlainText (str);
    }
    return n;
    */
}
