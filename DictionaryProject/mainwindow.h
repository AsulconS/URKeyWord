#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QQuickView>
#include "iostream"
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
private:
    Ui::MainWindow *ui;
    QString elnombre="gerson se la come entera";
};

#endif // MAINWINDOW_H
