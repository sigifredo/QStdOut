

#ifndef WINDOW_HPP
#define WINDOW_HPP

// Own
#include <QWidget>

class CustomStream;

class Window: public QWidget
{
    Q_OBJECT
public:
    Window(QWidget * pParent = nullptr);
    ~Window();

private:
    CustomStream * _pCustomStream;
};

#endif
