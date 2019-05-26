#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QQmlContext>
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
    return this->elnombre;
}
