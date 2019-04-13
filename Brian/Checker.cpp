// PROGRAMA VALIDADOR DE FORMATO

#include <fstream>
#include <iostream>
using namespace std;

void readingData();
bool checkData( string );

int main() {

    readingData();
    return 0;
}

void readingData() {

    ifstream archive;
    ofstream errors;
    string name, text;

    cout << "INGRESE EL NOMBRE DEL ARCHIVO A LEER: " << endl;
    cin >> name;

    archive.open( name, ios::in );
    errors.open( "Errors.txt", ios::out );

    if( archive.fail()) {
        cout << "Incapaz de abrir el archivo..." << endl;
        exit( 1 );
    }

    while( !archive.eof()) {
        getline( archive, text );
        if( !checkData( text ))
            errors << text << endl;
    }
    
    archive.close();
    errors.close();
}

bool checkData( string text ) {

    int lim = text.size();

    if( text[ lim - 2 ] == '\\' && text[ lim - 1 ] == '\\' ) {
        int acc = 0;
        for( int i = 0; i < lim - 2; ++i ) {
            if( text[ i ] == '$') 
            ++acc;
        }

        if( acc == 4 ) return true;
        else return false;
    }
}
