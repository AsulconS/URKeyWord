#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Matrix {
    
    public:
        Matrix();
        Matrix( const int, const int );
        ~Matrix();

        void printMatrix();
        void fillMatrixUser();
        void fillMatrixArch( string arch );
        string getData( const int pos_i, const int pos_j );
    
    private:
        int row, column;
        vector<vector<string>> m_matrix;        
};

Matrix::Matrix() {

    this -> row = 1;
    this -> column = 1;

    m_matrix.resize( row );
    for( int i = 0; i < row; ++i )
        m_matrix[ i ].resize( column );
}


Matrix::Matrix( const int row, const int column ) {

    this -> row = row;
    this -> column = column;

    m_matrix.resize( row );
    for( int i = 0; i < row; ++i )
        m_matrix[ i ].resize( column );
}

Matrix::~Matrix() {
}

void Matrix::printMatrix() {
    
    for( int i = 0; i < row; ++i ) {
        for( int j = 0; j < column; ++j )
            cout << m_matrix[ i ][ j ] << "\t";
        cout << endl;
    }
}

void Matrix::fillMatrixUser() {

    for( int i = 0; i < row; ++i ) {
        for( int j = 0; j < column; ++j )
            getline( cin, m_matrix[ i ][ j ]);
    }
}

void Matrix::fillMatrixArch( string arch ) {

    ifstream archive;
    string cont;
    archive.open( arch, ios::in );
    vector <string> temp;
    int rows = -1;

    if( archive.fail()) {
        cout << "Incapaz de abrir el archivo..." << endl;
        exit( EXIT_FAILURE );
    }

    while( !archive.eof()) {

        getline( archive, cont );
        int lim = cont.size();
        int ini = 0, fin = 0;
        string palabra;

        for( int i = 0; i < lim; ++i )
            if( cont[ i ] == '$' ) {
                fin = i - ini;
                palabra = cont.substr( ini, fin );
                ini = i + 1;
                temp.push_back( palabra );
            }
        rows++;
    }

    archive.close();

    this -> row = rows;
    this -> column = 5;

    this -> m_matrix.resize( row );
    for( int i = 0; i < row; ++i )
        m_matrix[ i ].resize( column );

    int k = 0;
    for( int i = 0; i < row; ++i )
        for( int j = 0; j < column; ++j ) {
            m_matrix[ i ][ j ] = temp[ k ];
            ++k;
        }
}

string Matrix::getData( const int pos_i, const int pos_j ) {
    return m_matrix[ pos_i ][ pos_j ];
}


#endif