#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include "Node.cpp"

class ForwardList {
private:
    Node* m_head {nullptr}; // aponta para o inicio da lista se houver, caso contrário será null
    int m_size {0};   // numero de elementos na lista
    
public:
    // construtor: cria lista vazia
    ForwardList();

    // construtor de copia
    ForwardList(ForwardList& lst);
    
    // destrutor: libera memoria alocada
    ~ForwardList();

    // retorna o numero de elementos na lista
    int size() const;
    
    // Retorna true se e somente se a lista estiver vazia
    bool empty() const;

    // Remove todos os elementos da lista, ou seja, deixa a lista vazia
    void clear();

    // Retorna o elemento na posicao k.
    // A funcao verifica se k esta dentro dos 
    // limites de elementos validos da lista. Caso contrário, retorna -1.
    int at(int k) const;

    // Recebe um inteiro como argumento e o adiciona
    // logo apos o ultimo elemento da lista. 
    void push_back(int value); 
    
    // Remove e retorna o ultimo elemento da lista se a lista nao
    // estiver vazia. Caso contrario, retorna -1 
    int pop_back(); 
    
    // insere um elemento no indice especificado
    void insert(int value, int k);

    // remove o elemento no indice especificado
    void removeAt(int k);
    
    //Retorma o ponteiro para o nó de índice k
    Node* getNode(int k);
    
    // Substitui o elemento no índice k pelo elemento value (somente se 0 <= k <= m_size -1)
    // Apenas o valor, não precisa substitui o nó
    void replaceAt(int value, int k);
    
    // Remove todas as ocorrências do elemento value na lista. A ordem dos demais elementos da lista entre se devem se manter
    void removeAll(int value);
    
    //Semelhante a função push_back só que adiciona o elemento na primeira posição
    void push_front(int value);
    
    //Semelhante a função pop_back só que remove e retorna o primeiro elemento se a lista nao estiver vazia. Caso contrario, retorna -1
    int pop_front();    
    
    //Determina se a lista lst, passada por parâmetro, é igual a lista do objeto.
    //Duas listas são iguais se têm o mesmo tamanho e o valor do k-ésimo elemento da primeira lista é igual ao k-ésimo valor da segunda.
    bool equals(ForwardList& lst);
    
    //Concatena a lista do objeto com a lista lst, passada por parâmetro. A lista lst não é modificada nessa operação.
    //Os elementos de lst serão adicionados na ordem no final da lista do objeto da função.
    void concat(ForwardList& lst);    

    void remove_duplicates();
};

#endif
