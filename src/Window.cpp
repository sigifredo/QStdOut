

// Own
#include <Window.hpp>
#include <CustomStream.hpp>
#include <QStreamListener.hpp>

// Qt
#include <QBoxLayout>
#include <QTextEdit>

Window::Window(QWidget * pParent):
    QWidget(pParent)
{
    QBoxLayout * pLayout = new QBoxLayout(QBoxLayout::LeftToRight, this);
    QTextEdit * pTextEdit = new QTextEdit(this);
    QStreamListener * pStreamListener = new QStreamListener(this);
    _pCustomStream = new CustomStream(std::cout, pStreamListener);

    connect(pStreamListener, SIGNAL(textCatched(const QString&)), pTextEdit, SLOT(append(const QString&)));

    pLayout->addWidget(pTextEdit);
}

Window::~Window()
{
    delete _pCustomStream;
}
