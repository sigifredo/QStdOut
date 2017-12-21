

// Own
#include <CustomStream.hpp>

CustomStream::CustomStream(std::ostream& stream):
    std::basic_streambuf<char>(), m_stream(stream)
{
    m_old_buf = stream.rdbuf();
    stream.rdbuf(this);
}

CustomStream::~CustomStream()
{
    m_stream.rdbuf(m_old_buf);
}

virtual int_type CustomStream::overflow(int_type v)
{
    if (v == '\n')
    {
        log_window->append("");
    }
    return v;
}

virtual std::streamsize CustomStream::xsputn(const char *str, std::streamsize n)
{
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
}
