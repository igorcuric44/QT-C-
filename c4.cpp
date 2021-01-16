#include <QApplication>
#include <QWidget>
#include <QTextEdit>
#include <QtGui>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextStream>
#include <QLabel>
#include<iostream>



class Click : public QWidget {
    
  public:
    Click(QWidget *parent = 0);
    
    private slots:
    void onClick();
};




Click::Click(QWidget *parent)
    : QWidget(parent) {
       
  QHBoxLayout *hbox = new QHBoxLayout(this);
  hbox->setSpacing(5);
        
  QPushButton *quitBtn = new QPushButton("Quit", this);
  hbox->addWidget(quitBtn, 0, Qt::AlignLeft | Qt::AlignTop);

  connect(quitBtn, &QPushButton::clicked, this, &Click::onClick);
}


void Click::onClick() {
    
  QTextStream out(stdout);
  out << "Button clicked" << endl;
}
int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
    
  Click window;
  
  window.resize(250, 150);
  window.setWindowTitle("Click");
  window.show();

  return app.exec();
}


