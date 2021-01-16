#include<QMainWindow>
#include<QApplication>
#include<QTableWidget>
#include<QWidget>
#include<QPushButton>

class bouton_chiffre : public QPushButton
{
    

public:
    bouton_chiffre(int, QWidget*);

private:
    int valeur_du_bouton;
    QPushButton *le_bouton;
};

bouton_chiffre::bouton_chiffre(int valeur_init, QWidget *parent) : QPushButton(parent)
{
    valeur_du_bouton = valeur_init;
    setText(QString::number(valeur_init));
    this->show();
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bouton_chiffre w(42, 0);
   

    return a.exec();
}
