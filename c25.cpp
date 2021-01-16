#include<QMainWindow>
#include<QApplication>
#include<QTableWidget>
#include<QWidget>
#include<QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>

class table : public QTableWidget
{
    

public:
    table(int,int, QWidget  *parent = 0);

private:
    int x,y;
   
};

table::table(int width,int height, QWidget *parent) : QTableWidget(parent),x(width),y(height)
{
    
    setRowCount(x);
    setColumnCount(y);
    
    
    horizontalHeader()->setDefaultSectionSize(160);
    verticalHeader()->setDefaultSectionSize(16);
}

class prozor:public QMainWindow {
    
  public:
    prozor(QWidget  *parent = 0);
    
   
  
    
    
};


prozor::prozor(QWidget  *parent)
    : QMainWindow (parent) {
    
 
   
    table *form_widget=new table(10,5,0);
     
    this->setCentralWidget(form_widget);
    
    this->setWindowTitle("Text edit");
    this->show();
    } 


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    prozor w;
   

    return a.exec();
}
