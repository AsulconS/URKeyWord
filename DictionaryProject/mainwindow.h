#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QQuickView>
#include "hashtable.h"
#include "hashtable.cpp"
#include "node.h"
#include "fstream"
#include "iostream"
#include <vector>
#include "string"
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(QString elnombre READ leerNombre);
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Q_INVOKABLE QString leerNombre();
    string getVal();
    void indexFile();
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    HashTable<string,Record> h = HashTable<string,Record>(600);
    QString contenido="hello";
};

#endif // MAINWINDOW_H
