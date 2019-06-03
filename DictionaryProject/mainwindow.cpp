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

}
MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::leerNombre()
{
    string s=getVal();
    QString nn=QString::fromStdString(s);
    return nn;
}

string MainWindow::getVal()
{
    std::ifstream file("Z.csv");
    int start=27894,end=27952;
    file.seekg(start);
    string s;
    s.resize(end-start);
    file.read(&s[0],end-start);
    return s;
}
