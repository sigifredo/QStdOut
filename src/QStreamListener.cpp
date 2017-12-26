

// Own
#include <QStreamListener.hpp>


QStreamListener::QStreamListener(QObject * pParent):
    QObject(pParent)
{
}

void QStreamListener::endLine()
{
    emit textCatched("\n");
}

void QStreamListener::print(const std::string& str)
{
    emit textCatched(QString::fromStdString(str));
}
