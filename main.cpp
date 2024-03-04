#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include "wheel.h" // Предполагается, что Wheel наследуется от QWidget

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Wheel *wheel = new Wheel;
    QPushButton *button = new QPushButton("Rotate");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(wheel);
    layout->addWidget(button);

    QWidget window;
    window.setLayout(layout);
    window.resize(800, 600);

    QObject::connect(button, SLOT(click()), wheel, SLOT({
                         wheel->press = !(wheel->press);
                         wheel->rotate();
                     }));

    window.show();

    return app.exec();
}
