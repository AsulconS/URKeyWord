#include "mainwindow.h"
#include <QApplication>
#include "hashtable.h"
#include "hashtable.cpp"
#include "node.h"
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
    HashTable<string,Record> h = HashTable<string,Record>(600);
    unsigned long start=0,end=0;
    if(file.is_open())
    {
        unsigned long sum=0;
        Record *r;
        while (getline(file,line)) {
            boost::split(readLine,line,boost::is_any_of("("));
            start=sum+readLine[0].length()+5;
            end=sum+line.length()+1;
            if(line.length()>2){
                r=new Record(start,end);
                h.insert(readLine[0],*r);
                writeIndexFile(readLine[0],start,end);
            }
            sum=sum+line.length()+1;
        }
    }
    //h.print();
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
void proofHash()
{
    Record *r=new Record(2,3);
    HashTable<string,Record> h = HashTable<string,Record>(600);
    string txt="helll";
    h.insert(txt,*r);
    Node<string,Record> *ptr=h.find(txt);
    cout << ptr->getData();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
