#include<QMainWindow>
#include<QApplication>
#include<QTableWidget>
#include<QWidget>
#include<QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QTextStream>
#include <QTableWidgetItem>

class table : public QTableWidget
{
    

public:
    table(int,int, QWidget  *parent = 0);

private:
    int x,y;

private slots:
    void c_current(int, int);

};

table::table(int width,int height, QWidget *parent) : QTableWidget(parent),x(width),y(height)
{
    
    setRowCount(x);
    setColumnCount(y);
    
    
    horizontalHeader()->setDefaultSectionSize(160);
    verticalHeader()->setDefaultSectionSize(16);
    
   connect(this,&QTableWidget::cellChanged, this,&table::c_current ); 
}
    
void table::c_current(int x,int y) {
    
  QTextStream out(stdout);
  out << "Button clicked" << endl;
  qDebug("value changed row = %d, col = %d", x, y);
}



class prozor:public QMainWindow {
    
  public:
    prozor(QWidget  *parent = 0);
    
   
  
    
    
};


prozor::prozor(QWidget  *parent)
    : QMainWindow (parent) {
    
 
   
    table *form_widget=new table(5,2,0);
     
    this->setCentralWidget(form_widget);
    QStringList list;
    
    list<< "test1" << "test2";
    
    form_widget->setHorizontalHeaderLabels(list);
    
    QTableWidgetItem *number=new QTableWidgetItem("10");
    
    //form_widget->setItem(1,1,new QTableWidgetItem("5"));
    form_widget->setItem(0,0,number);
    this->setWindowTitle("Table");
    
    
    
    this->show();
    } 


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    prozor w;
   

    return a.exec();
}
