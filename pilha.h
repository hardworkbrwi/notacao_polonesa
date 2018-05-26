#ifndef PILHA_H
#define PILHA_H

#include <iostream>
//#include <memory>

/* Para permitir sobrecarregar o operador de insercao
   numa classe template como friend é preciso adicionar
   o trecho de codigo a seguir */
template <typename T> class Pilha; // Declaracao antecipada da classe
template <typename T> // Definicao antecipada do template para o operador de insercao
std::ostream& operator<<( std::ostream&, Pilha<T> const & );


/**
* @brief Implementacao da classe Pilha
* @detail Define um template de pilha
*/
template <typename T>
class Pilha{
    private:
        T* elementos; /**< Elementos da pilha */
        int tamanho; /**< Quantidade de elementos */
        int capacidade; /**< Quantidade máxima de elementos */

    public:
        Pilha( int capacidade = 50 );
        ~Pilha();
        bool vazia();
        bool cheia();
        T& topo();
        int empilhar( T novo );
        int desempilhar();
        int getTamanho();

        //friend std::ostream& operator<< <T>(std::ostream& o, Pilha<T> const &p);
};

template <typename T>
Pilha<T>::Pilha( int capacidade ): tamanho( 0 ), capacidade( capacidade ){
    elementos = new T[ capacidade ];
}

template <typename T>
Pilha<T>::~Pilha(){
    delete [] elementos;
}

template <typename T>
bool Pilha<T>::vazia(){
    return tamanho == 0;
}

template <typename T>
bool Pilha<T>::cheia(){
    return tamanho == capacidade;
}

template <typename T>
int Pilha<T>::empilhar( T novo ){
    if( cheia() )
        return 0;
    
    elementos[ tamanho++ ] = novo;
    return 1;
}

template <typename T>
int Pilha<T>::desempilhar(){
    if( vazia() )
        return 0;
    
    tamanho--;

    return 1;
}

template <typename T>
T& Pilha<T>::topo(){
    if( vazia() ){
        std::cerr << "Acesso inválido a elementos no topo da pilha." << std::endl << "O programa será encerrado!" << std::endl;
        exit(EXIT_FAILURE);
    }

    return elementos[ tamanho - 1 ];
}

template <typename T>
int Pilha<T>::getTamanho(){
    return tamanho;
}

#endif