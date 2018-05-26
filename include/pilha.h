/**
 * @file	pilha.h
 * @brief	Implementação da classe Pilha em C++
 * @author	Bruno César L. Silva
 * @author  Willian Talles
 * @since	19/05/2018
 * @date	26/05/2018
 */

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

        /**
        * @brief Método construtor parametrizado de Pilha
        * @param int - Recebe o valor da capacidade máxima do vetor.
        * Quando vazio, inicializa com 50 espaços
        */  
        Pilha( int capacidade = 50 );

        /**
        * @brief Método destrutor de Pilha
        */
        ~Pilha();

        /**
        * @brief Verifica se pilha está vazia
        * @return Retorna verdadeiro ou falso
        */
        bool vazia();

        /**
        * @brief Verifica se pilha está cheia
        * @return Retorna verdadeiro ou falso
        */
        bool cheia();

        /**
        * @brief Verifica o valor do topo a pilha
        * @return Retorna o valor do topo da pilha
        */
        T& topo();

        /**
        * @brief Empilha valores na pilha
        * @param T - Recebe um novo valor do tipo T para ser empilhado
        * @return Se houve sucesso no armazenamento do valor, retorna 1; se não, retorna 0
        */
        int empilhar( T novo );

        /**
        * @brief Desempilha os valores da pilha
        * @return Retorna 1 para sucesso ou 0 para falha
        */
        int desempilhar();

        /**
        * @brief Verifica a quantidade de dados da pilha
        * @return Retorna um inteiro relativo ao tamanho da pilha
        */
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