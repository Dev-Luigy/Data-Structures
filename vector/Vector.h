#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
    int* m_list {nullptr}; // ponteiro para a lista
    int  m_size {0};       // numero de elementos na lista
    int  m_capacity {0};   // capacidade total da lista

public:
    // Construtor default: aloca uma lista com 
    // capacidade inicial igual a 16 e size = 0
    Vector(); // O(1)
    
    // Construtor: aloca uma lista com 
    // capacidade inicial igual a n e size = 0
    Vector(int n); // O(1)
    
    // Copy constructor: cria uma nova lista com os
    // mesmos elementos da lista passada como argumento
    Vector(const Vector& vector); // O(n)
    
    // Destrutor: libera memoria alocada
    ~Vector(); // O(1)

    // Retorna a capacidade atual da lista
    int capacity() const; // O(1)

    // Retorna o numero de elementos na lista
    int size() const; // O(1)
    
    // Retorna true se e somente se a lista estiver vazia
    bool empty() const; // O(1)

    // Retorna o elemento na posicao k.
    // A funcao verifica se k esta dentro dos 
    // limites de elementos validos no vetor. Caso contrário, retorna -1.
    int at(int k) const; // O(1)

    //Redimensiona a capacidade para tamanho n. 
    // Se n for maior que a capacidade atual do vetor, a 
    // funcao faz com que a lista aumente sua capacidade 
    // realocando os elementos para o novo vetor. 
    // Se n for menor que a capacidade atual, 
    // o conteúdo é reduzido aos seus primeiros n elementos, 
    // removendo aqueles além.
    void resize(int n); // O(n)
    
    // Recebe um inteiro como argumento e o adiciona
    // logo apos o ultimo elemento da lista. 
    // Se por acaso a lista estiver cheia, chame a função
    // resize duplicando sua capacidade atual. 
    void push_back(int value); // tempo medio O(1)
    
    // Remove e retorna o ultimo elemento da lista se a lista nao
    // estiver vazia. Caso contrario, retorna -1 
    int pop_back(); // O(1)
    
    //########################################################
    
    
    // Substitui o elemento no índice k pelo elemento 
    // value (somente se 0 <= k <= m_size -1)
    void replaceAt(int value, int k);

    // Remove o elemento com índice k na lista. 
    // Deve-se ter 0 <= k <= m_size -1; 
    // caso contrário, a remoção não é realizada.
    // Será necessário fazer um deslocamento de uma posição 
    // para a esquerda dos elementos de k+1 até m_size-1
    void removeAt(int k);

    // Adiciona o elemento value no índice k 
    // (somente se 0 <= k <= m_size). 
    // Antes de fazer a inserção, todos os elementos do 
    // índice k em diante são deslocados uma posição para a direita.
    // Se não houve espaço, será necessário chamar a função resize duplicando a capacidade.
    void insert(int value, int k);
    
    // Remove todas as ocorrências do elemento value na lista.
    void removeAll(int value);
    
    //Semelhante a função push_back só que adiciona
    // o elemento na primeira posição
    void push_front(int value);  
    
    //Semelhante a função pop_back só que remove e retorna o primeiro elemento
    // se a lista nao estiver vazia. Caso contrario, retorna -1 
    int pop_front(); 

    void remove_duplicates();
};

#endif