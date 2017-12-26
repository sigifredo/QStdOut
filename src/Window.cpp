

// Own
#include <Window.hpp>

// Qt
#include <QBoxLayout>
#include <QTextEdit>

Window::Window(QWidget * pParent):
    QWidget(pParent)
{
    QBoxLayout * pLayout = new QBoxLayout(QBoxLayout::LeftToRight, this);
    QTextEdit * pTextEdit = new QTextEdit(this);

    pLayout->addWidget(pTextEdit);
}
