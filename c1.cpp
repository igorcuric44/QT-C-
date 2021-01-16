#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTextStream>

int main(int argc, char *argv[]) {
    
    QApplication app(argc, argv);

    QWidget *window=new QWidget;
window->setWindowTitle("example title");
    window->resize(350, 250);
   
   QHBoxLayout *layout=new QHBoxLayout;
    
    QPushButton *button1=new QPushButton;
     QPushButton *button2=new QPushButton;
    button1->setText("stisni");
    button2->setText("pritisni");
    

    layout->addWidget(button1);
    layout->addWidget(button2);
    window->setLayout(layout);
    window->show();

    return app.exec();
}
