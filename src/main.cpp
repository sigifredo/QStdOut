

// Qt
#include <QApplication>

// Own
#include <Window.hpp>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    Window window;
    window.show();

    return app.exec();
}
