#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QQmlContext>
#include "fstream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->quickWidget->rootContext()->setContextProperty("s",this);
    qmlRegisterType<MainWindow>("com.qt.name",1,0,"MainWindow");
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/gui.qml")));
    indexFile();
}
MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::leerNombre()
{
    return this->contenido;
}

string MainWindow::getVal()
{
    /*
    int lstart=37951,lend=38020;
    file.seekg(start);
    string s;
    s.resize(end-start);
    file.read(&s[0],end-start);
    return s;*/
}

void MainWindow::indexFile()
{
    string line="";
    std::ifstream file("Z.csv");
    vector<string> readLine;
    unsigned long start=0,end=0;
    if(file.is_open())
    {
        unsigned long sum=0;
        Record *r;
        int i=0;
        while (getline(file,line)) {
            boost::split(readLine,line,boost::is_any_of("("));
            start=sum+readLine[0].length()+5;
            end=sum+line.length()+1;
            if(readLine[0].length()>2){
                r=new Record(start,end);
                h.insert(readLine[0],*r);
                cout << readLine[0] <<endl;
            }
            i++;
            sum=sum+line.length()+1;
        }
    }
    /*
    cout << "index" << endl;
    string ss="Zythum ";
    Node<string,Record> *ptr=h.find(ss);
    cout << ptr->getData();*/
}

void MainWindow::on_pushButton_clicked()
{
    QString sss=ui->lineEdit->text();
    string ss="Zythum ";
    Node<string,Record> *ptr=h.find(ss);
    std::ifstream file("Z.csv");
    int start=ptr->getData().getStart(),end=ptr->getData().getEnd();
    file.seekg(start);
    string s;
    s.resize(end-start);
    file.read(&s[0],end-start);
    this->contenido=QString::fromStdString(s);
}
