#include "binarytree.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

Node<int>* nodeCreater(int valor){
    return new Node<int>(valor, nullptr, nullptr);
}

void bts_inserir_rec(Node<int>* root, std::string doenca, std::string aux){
    Node<int>* iterator = root;
    while(doenca.size()){

        // Aqui é para verificar se já existe aquela doença no nó
        std::istringstream doencasInString(iterator->getCode());
        std::string doencas;
        int nEncontrado = 0;
        while(getline(doencasInString, doencas, ',')){
            if (!(doencas == aux)) {
                nEncontrado = 1;
                break;
            }
        }

        //Abaixo ele pega cada numero e cria ou persegue o caminho da resposta do usuário.
        if (doenca[0] - '0' == 1){
            if (!iterator->getLeft()){
                iterator->setLeft(nodeCreater(doenca[0] - '0'));
                iterator->getLeft()->setCode(aux);
            } else {
                if (nEncontrado){
                    if (iterator->getCode().find(aux) == std::string::npos) {
                        iterator->setCode(iterator->getCode().insert(iterator->getCode().size(), "," + aux));
                    }
                } else {
                    iterator->setCode(aux);
                }
            }
            iterator = iterator->getLeft();
        }  
        else{
            if (!iterator->getRight()){
                iterator->setRight(nodeCreater(doenca[0] - '0'));
                iterator->getRight()->setCode(aux);
            } else {
                if (nEncontrado){
                    if (iterator->getCode().find(aux) == std::string::npos) {
                        iterator->setCode(iterator->getCode().insert(iterator->getCode().size(), "," + aux));
                    }
                } else {
                    iterator->setCode(aux);
                }
            }
            iterator = iterator->getRight();
        }
        //Diminuição da string tirando o numero que foi usado
        doenca = doenca.substr(1, doenca.size());
    }

	//Insere na folha.
    if (iterator->getCode().find(aux) == std::string::npos) {
        if (iterator->getCode().size())
            iterator->setCode(iterator->getCode() + "," + aux);
        else
            iterator->setCode(aux);
    }
}

void bts_inserir(BinaryTree<int>& bts, std::string doenca, std::string aux){
    if (!bts.getRoot()){
        bts.setRoot(nodeCreater(1));
    }
    aux = aux.substr(0, aux.size() - 1); //remover /n
    bts_inserir_rec(bts.getRoot(),doenca, aux);
}

void executar(BinaryTree<int>& Arvore, std::string* Sintomas, int& quantSintomas){
    Node<int>* iterator = Arvore.getRoot();
    for (int i = 0; i < quantSintomas; i++){
        int opc;
        std::cout << "Você sente: " << Sintomas[i] << std::endl;
        std::cin >> opc;
        //caso Sim ele vai pra direita, caso não pra esquerda.
        iterator = opc ? iterator->getLeft() : iterator->getRight();
        if(!iterator){
            std::cout << "Diagnóstico inexistente." << std::endl << std::endl;
            return;
        }
        //enquanto não tiver o diagnostico, mostre as possibilidades.
        system("clear");
        std::cout << "Possíveis doenças atuais: \n[" << iterator->getCode() << "]" << std::endl;
    }
    std::cout << iterator->getCode() << std::endl << std::endl;
}


int main () {
    BinaryTree<int> Arvore;
    std::ifstream leitor("SintomasMenor.txt");
    
    //Agora devo ler as primeiras
    int quantDoencas, quantSintomas = quantDoencas = 0;
    leitor >> quantDoencas;
    leitor >> quantSintomas;

    std::string Doencas[quantDoencas];
    std::string Sintomas[quantSintomas];

    std::string clearEmpty;
    getline(leitor, clearEmpty);//  Para ler o \n;

    //Insere o nome das doenças no vetor de Doenças.
    for (int i = 0; i < quantDoencas; i++)
        getline(leitor, Doencas[i], '\n');
        
    //insere o nome dos Sintomas no vetor de Sintomas.
    for (int i = 0; i < quantSintomas; i++)
        getline(leitor, Sintomas[i], '\n');


    //Leitura de arquivo e construção da arvore.
    while(!leitor.eof()){
        std::string stringParts {""};
        std::string line;
        //aqui eu pego cada linha do arquivo.
        while(getline(leitor, line)){
            std::string aux;
            for (int i = 0; i <= (int) line.size(); i++){
                if (i == 0){
                    //tratativa do id da Doença verificando se é entre 1 a 9 e logo após >= 10  
                    aux = line.substr(0, line.find('\t'));
                    if (stoi(aux) >= 10)
                        i++;
                    continue;
                }
                if (line[i] >= '0' && line[i] <= '9')
                    stringParts.push_back(line[i]);
            }

            //enviando para a criação do galho até a folha, lá será tratado se já existe percusso ou não;
            bts_inserir(Arvore, stringParts, Doencas[stoi(aux)-1]);
            stringParts.clear();
        }
    }
    leitor.close();

    //Execução do código após arvore construida;
    //Usar 1 como Sim e 0 como Não.
    while(1)
        executar(Arvore, Sintomas, quantSintomas);
}
