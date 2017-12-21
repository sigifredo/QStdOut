

#ifndef WINDOW_HPP
#define WINDOW_HPP

// Own
#include <QWidget>

class Window: public QWidget
{
    Q_OBJECT
public:
    Window(QWidget * pParent = nullptr);
};

#endif
