

#ifndef QSTREAMLISTENER_HPP
#define QSTREAMLISTENER_HPP

// Qt
#include <QObject>

// Own
#include <StreamListenerInterface.hpp>

class QStreamListener: public QObject, public StreamListenerInterface
{
    Q_OBJECT
public:
    QStreamListener(QObject * pParent = nullptr);

    virtual void endLine();
    virtual void print(const std::string& str);

signals:
    void textCatched(const QString& str);
};

#endif
