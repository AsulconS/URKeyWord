#include "mainwindow.h"
#include <QApplication>
#include "hashtable.h"
#include "fstream"
#include "iostream"
#include <vector>
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
using namespace  std;
void createHashForFile(string fileName)
{
    string line="";
    std::ifstream file(fileName);
    vector<string> readLine;
    HashTable<int,string> h = HashTable<int,string>(600);
    if(file.is_open())
    {
        int k=0;
        unsigned int setPos=0;
        unsigned int sum=0;
        while (getline(file,line)) {
            boost::split(readLine,line,boost::is_any_of("("));
            setPos=sum+readLine[0].length()+4;
            if(line.length()>1)
                h.set(k,readLine[0],setPos);
            k++;
            sum=sum+line.length()+1;
        }
    }
    h.print();
}
int main(int argc, char const *argv[])
{
    //createHashForFile("Z.csv");
    std::ifstream file("Z.csv");
    int start=2000,end=3000;
    file.seekg(200);
    string s;
    s.resize(end-start);
    file.read(&s[0],end-start);
    cout << s << endl;
    /*unsigned int n=12;
    HashTable<int,string> h = HashTable<int,string>(10);
    h.set(3,"hola",n);
    h.set(4,"hasdf",n);
    h.set(9,"dsadsadasd",n);
    h.print();
    return 0;*/
/*QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return a.exec();*/

}