#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
using namespace std;
void PrimaryIndex::writeIndexFile(string indexType, string nameIndex, unsigned long position)
{
    indexType=this->fileName+indexType;
    ofstream myfile;
    myfile.open(indexType,ios::app);
    myfile << nameIndex <<"," << position << "\n";
    myfile.close();
}

void indexFile(string fileName)
{
    string line,cur,prev,indexType;
    indexType="wordsIndex";
    vector<string> readLine;
    ifstream myfile(this->fileName);//open file to indexing
    unsigned long setPosition=0;
    if (myfile.is_open()) {
        getline(myfile,line);
        boost::split(readLine,line,boost::is_any_of(","));
        prev=readLine[1];
        setPosition=setPosition+line.length();
        myfile.seekg(setPosition+1);
        this->writeIndexFile(indexType,prev,setPosition);
        while (getline(myfile,line)) {
            setPosition=setPosition+line.length();
            boost::split(readLine,line,boost::is_any_of(","));
            cur=readLine[1];
            if(cur!=prev)
            {
                prev=cur;
                writeIndexFile(indexType,prev,setPosition);
            }
        }
        myfile.close();
    }
}
int main()
{

}