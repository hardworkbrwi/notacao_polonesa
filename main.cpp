#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::atoi;

#include <algorithm>
using std::reverse;

#include <vector>
using std::vector;

#include "pilha.h"

int main(){
    string expressao;
    Pilha<char> pilha;
    vector<int> valores;
    int tamanhoTexto, contador = 0, aux1, aux2;

    cout << "Digite a expressao polonesa: ";
    getline( cin, expressao );

    tamanhoTexto = ( int ) expressao.size();

    reverse( expressao.begin(), expressao.end() );

    while( contador < tamanhoTexto ){
        pilha.empilhar( expressao[contador] );
        contador++;
    }

    contador = 0;
    while( contador < tamanhoTexto ){        
        switch( pilha.topo() ){
            case '+':
                aux1 = valores[0];
                aux2 = valores[1];
                valores.clear();
                valores.push_back( aux1 + aux2 );
                break;
            case '-':
                aux1 = valores[0];
                aux2 = valores[1];
                valores.clear();
                valores.push_back( aux1 - aux2 );
                break;
            case '*':
                aux1 = valores[0];
                aux2 = valores[1];
                valores.clear();
                valores.push_back( aux1 * aux2 );
                break;
            case '/':
                aux1 = valores[0];
                aux2 = valores[1];
                valores.clear();
                valores.push_back( aux1 / aux2 );
                break;
            case ' ':
                break;
            default:
                valores.push_back( atoi(  &pilha.topo() ) );
        }
        pilha.desempilhar();
        contador++;
    }

    cout << "Resultado: " << valores[0] << endl;
    
    return 0;
}
