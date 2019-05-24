#include "mainwindow.h"
#include <QApplication>
#include "hashtable.h"
#include "fstream"
#include "iostream"
#include <vector>
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
using namespace  std;
void writeIndexFile(const string &index,const unsigned long& start,const unsigned long &end )
{
    ofstream file("indexFile.txt",ios::app);
    file << index <<"," << start << "," << end << endl;
}
void createHashForFile(string fileName)
{
    string line="";
    std::ifstream file(fileName);
    vector<string> readLine;
    HashTable<int,string> h = HashTable<int,string>(600);
    unsigned long start=0,end=0;
    if(file.is_open())
    {
        int k=0;
        unsigned long sum=0;
        while (getline(file,line)) {
            boost::split(readLine,line,boost::is_any_of("("));
            start=sum+readLine[0].length()+5;
            end=sum+line.length()+1;
            if(line.length()>2){
                h.set(k,readLine[0],start,end);
                writeIndexFile(readLine[0],start,end);
            }
            k++;
            sum=sum+line.length()+1;
        }
    }
    h.print();
}
void proof()
{
    std::ifstream file("Z.csv");
    int start=27894,end=27952;
    file.seekg(start);
    string s;
    s.resize(end-start);
    file.read(&s[0],end-start);
    cout << s << endl;

}
int main(int argc, char const *argv[])
{
    //proof();
    createHashForFile("Z.csv");
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
