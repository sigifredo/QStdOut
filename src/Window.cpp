

// Own
#include <Window.hpp>
#include <CustomStream.hpp>
#include <QStreamListener.hpp>

// Qt
#include <QBoxLayout>
#include <QPlainTextEdit>

Window::Window(QWidget * pParent):
    QWidget(pParent)
{
    QBoxLayout * pLayout = new QBoxLayout(QBoxLayout::LeftToRight, this);
    QPlainTextEdit * pTextEdit = new QPlainTextEdit(this);
    QStreamListener * pStreamListener = new QStreamListener(this);
    _pCustomStream = new CustomStream(std::cout, pStreamListener);

    connect(pStreamListener, SIGNAL(textCatched(const QString&)), pTextEdit, SLOT(insertPlainText(const QString&)));

    pLayout->addWidget(pTextEdit);

    std::cout << "prueba2";
    std::cout << "prueba3" << std::endl;
    std::cout << std::endl;
    std::cout << "prueba4" << std::endl;
}

Window::~Window()
{
    delete _pCustomStream;
}
