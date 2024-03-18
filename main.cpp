#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include "wheel.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Wheel *wheel = new Wheel;

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(wheel);

    QWidget window;
    window.setLayout(layout);
    window.resize(800, 600);

    window.show();

    return app.exec();
}
