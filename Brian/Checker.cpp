// PROGRAMA VALIDADOR DE FORMATO

#include <fstream>
#include <iostream>
#include "Matrix.h"
using namespace std;

void readingData();
bool checkData( string );
void dataProccessor();

int main() {

    readingData();
    Matrix M( 1, 1 );
    M.fillMatrixArch( "Hola.txt");
    M.printMatrix();
    return 0;
}

void readingData() {

    ifstream archive;
    ofstream errors;
    string name, text;
    bool control = true;

    cout << "INGRESE EL NOMBRE DEL ARCHIVO A LEER: " << endl;
    cin >> name;

    archive.open( name, ios::in );
    errors.open( "Errors.txt", ios::out );

    if( archive.fail()) {
        cout << "Incapaz de abrir el archivo..." << endl;
        exit( EXIT_FAILURE );
    }

    while( !archive.eof()) {
        getline( archive, text );
        if( !checkData( text )) {
            control = false;
            errors << text << endl;
        }
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

        if( acc == 5 ) return true;
        else return false;
    }
}
