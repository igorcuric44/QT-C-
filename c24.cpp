#include<QMainWindow>
#include<QApplication>
#include<QTableWidget>
#include<QWidget>
#include<QTableWidget>
#include <QVBoxLayout>

class table : public QTableWidget
{
    

public:
    table(int,int, QWidget*);

private:
    int x,y;
    QTableWidget *tabla;
};

table::table(int width,int height, QWidget *parent) : QTableWidget(parent),x(width),y(height)
{
    //valeur_du_bouton = valeur_init;
    //setText(QString::number(valeur_init));
    //this->tabla=new QTableWidget(x,y);
    
    //QVBoxLayout *layout=new QVBoxLayout();
    //layout->addWidget(this->tabla);
    //this->setLayout(layout);
    
    setRowCount(x);
    setColumnCount(y);
    
    this->show();
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    table w(10,5, 0);
   

    return a.exec();
}
