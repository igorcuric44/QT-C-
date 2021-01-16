#include<QMainWindow>
#include<QApplication>
#include<QTableWidget>
#include<QWidget>
#include<QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QTextStream>
#include <QTableWidgetItem>
#include <QDebug>
#include <QFile>
#include <QStringList>
#include <QFileDialog>

class table : public QTableWidget
{
    

public:
    table(int,int, QWidget  *parent = 0);
	void open_sheet();

private:
    int x,y;
    bool check_change;

private slots:
    void c_current(int, int);

};

table::table(int width,int height, QWidget *parent) : QTableWidget(parent),x(width),y(height)
{
    check_change=true;
    setRowCount(x);
    setColumnCount(y);
    
    
    horizontalHeader()->setDefaultSectionSize(160);
    verticalHeader()->setDefaultSectionSize(16);
    
   connect(this,&QTableWidget::cellChanged, this,&table::c_current ); 
   
   open_sheet();
   
   
   
   
}

void table::open_sheet()
{
check_change=false;
QString filename =  QFileDialog::getOpenFileName(
          this,"Open Document",QDir::currentPath());

QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
       
    }
    this->setRowCount(0);
    this->setColumnCount(5);
   int j= 0;                     // file line counter
    QTextStream in(&file);
    QTextStream out(stdout);
    int row=0;
    while (!in.atEnd()) {                           
row=this->rowCount();
					this->insertRow(row);
        // read one line from textstream(separated by "\n") 
        QString fileLine = in.readLine();  
out<<fileLine<<endl;
    QStringList lineToken = fileLine.split(",", QString::SkipEmptyParts);  
      for (int i = 0; i < lineToken.size(); i++) {
            QString value = lineToken.at(i);
          out<<value<<endl; 
          QTableWidgetItem *number=new QTableWidgetItem(value);
    
    //form_widget->setItem(1,1,new QTableWidgetItem("5"));
    this->setItem(j,i,number);
        }
  

        j++;   
    }

    file.close();
    
check_change=true;
}


    
void table::c_current(int x,int y) {
  if(check_change){  
  QTextStream out(stdout);
  out << "Button clicked" << endl;
  qDebug("value changed row = %d, col = %d", x, y);
  }
  
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
    
    //QTableWidgetItem *number=new QTableWidgetItem("10");
    
    //form_widget->setItem(1,1,new QTableWidgetItem("5"));
    //form_widget->setItem(0,0,number);
    this->setWindowTitle("Table");
    
    
    
    this->show();
    } 


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    prozor w;
   

    return a.exec();
}
