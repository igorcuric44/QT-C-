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
#include<QAction>
#include <QMenu>
#include <QMenuBar>

class table : public QTableWidget
{
    

public:
    table(int,int, QWidget  *parent = 0);
	void open_sheet();
	void save_sheet();
	void quit();

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

void table::save_sheet()
{
QString str=QFileDialog::getSaveFileName(this,"Save file",QDir::currentPath());
    QFile file(str);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
QTextStream out(stdout);
    out<<str<<endl;
QTextStream data( &file );
    QStringList strList;
    out<<this->rowCount()<<endl;
    out<<this->columnCount()<<endl;
    
    for( int r = 0; r < this->rowCount(); ++r )
    {
        strList.clear();
        for( int c = 0; c < this->columnCount(); ++c )
        {   
        QTableWidgetItem* item = this->item(r,c);        //Load items
            if (!item || item->text().isEmpty())                        //Test if there is something at item(r,c)
            {
                this->setItem(r,c,new QTableWidgetItem("0"));//IF there is nothing write 0
            }
            strList << "\" "+this->item( r, c )->text()+"\" ";

        }
        data << strList.join( ";" )+"\n";
    }
  file.close();  
}

void table::quit()
{

QCoreApplication::quit();
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
    void onClick(QAction *p);
    table *form_widget=new table(5,2,0);
    
   private:
   QMenu *file;
    QAction *open_action,*save_action,*quit_action;
  
    
    
};


prozor::prozor(QWidget  *parent)
    : QMainWindow (parent) {
    
 open_action=new QAction("&Open",this);
    open_action->setShortcut(tr("Ctrl+O"));
    
    save_action=new QAction("&Save",this);
    save_action->setShortcut(tr("Ctrl+S"));
    
    quit_action=new QAction("&Quit",this);
    
    
    
    
    
    file = new QMenu("File");
    
    
    menuBar()->addMenu(file);
   
    
    file->addAction(open_action);
    file->addAction(save_action);
    file->addAction(quit_action);
   
   connect(file,&QMenu::triggered,this,
                &prozor::onClick);
   
    
     
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


void prozor::onClick(QAction *p)
{
QString q=p->text();
    QTextStream out(stdout);
    out<<"igor"<<endl;
    out<<q+" selected"<<endl;
    if(q=="&Open"){
    form_widget->open_sheet();
    out<<q+" +selected"<<endl;
    }else if(q=="&Save"){
    form_widget->save_sheet();
    out<<q+" +selected"<<endl;
    }else if(q=="&Quit"){
    form_widget->quit();
    out<<q+" +selected"<<endl;
    }
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    prozor w;
   

    return a.exec();
}
