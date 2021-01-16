#include<QApplication>
#include<QAction>
#include<QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include<QWidget>
#include <QTextStream>

class MenuDemo:public QMainWindow {
    
  public:
    MenuDemo(QWidget  *parent = 0);
    
    private slots:
   void onClick1();
   void onClick2(QAction *p);
   
   private:
    QMenu *file,*edit,*find_menu;
    QAction *new_action,*open_action,*save_action,
    *quit_action;
    QAction *find_action,*replace_action;
    
};

MenuDemo::MenuDemo(QWidget  *parent)
    : QMainWindow (parent) {
    
    
    new_action=new QAction("&New",this);
    new_action->setShortcut(tr("Ctrl+N"));
    
    open_action=new QAction("&Open",this);
    open_action->setShortcut(tr("Ctrl+O"));
    
    save_action=new QAction("&Save",this);
    save_action->setShortcut(tr("Ctrl+S"));
    
    quit_action=new QAction("&Quit",this);
    
    find_action=new QAction("Find...",this);
		
    replace_action=new QAction("Replace...",this);
    
    
    
    file = new QMenu("File");
    edit= new QMenu("Edit");
    find_menu= new QMenu("Find");
    
    menuBar()->addMenu(file);
    menuBar()->addMenu(edit);
    file->addAction(new_action);
    file->addAction(open_action);
    file->addAction(save_action);
    file->addAction(quit_action);
    
    
    find_menu->addAction(find_action);
    find_menu->addAction(replace_action);
    edit->addMenu(find_menu);
    
    connect(quit_action,&QAction::triggered,this,
               &MenuDemo::onClick1);
    
    connect(file,&QMenu::triggered,this,
                &MenuDemo::onClick2);
   
    
    QWidget *centralwidget = new QWidget(this);
    this->setCentralWidget(centralwidget);
    
    this->setWindowTitle("Text edit");
    this->show();
    } 
    
    
    void MenuDemo::onClick1()
    {
    QCoreApplication::quit();
    } 
    
   
   void MenuDemo::onClick2(QAction *p)
    {
    
    QTextStream out(stdout);
    out<<"igor"<<endl;
    out<<p->text()+" selected"<<endl;
    } 
   
    

int main(int argc, char *argv[]) {
    
  QApplication app(argc, argv);  
    
  MenuDemo window;
  

  
  return app.exec();
}   
