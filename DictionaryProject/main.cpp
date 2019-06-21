#include "mainwindow.h"
#include <QApplication>
#include "fstream"
#include "iostream"
#include <vector>
#include "string"
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
using namespace  std;
int main(int argc, char *argv[])
{
    //createHashForFile("Z.csv");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
