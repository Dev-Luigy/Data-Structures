#include <stdio.h>
#include "Vector.h"

void print(const Vector& list) {
    if(!list.empty()){
        printf("%d\n", list.size());
    	for(int i = 0; i < list.size(); i++) printf("%d ", list.at(i));
    	printf("\n");        
    }else printf("Lista Vazia\n");
}
void remove(Vector& list) {
    if(!list.empty()){
    	while(!list.empty()){
    	    printf("%d ", list.pop_back());
    	    if(!list.empty()) printf("%d ", list.pop_front());
    	}
    	printf("\n"); 
    }
}
int main() {
    int n, k;
    scanf("%d", &n);
	//Testa o construtor default
	Vector listaPares, listaImpares;
	
	//Testa as funções push_back e resize
	for(int i = 0; i < n; ++i) {
	    scanf("%d", &k); 
	    if(k % 2 == 0) listaPares.push_back(k);
		else listaImpares.push_back(k);
	}
	printf("Testa o construtor default, funcoes push_back, resize quando aumenta e at\n");
	print(listaPares);
	print(listaImpares);
	
	printf("Testa a funcao resize quando diminui e pop_back\n");
	if(listaPares.size() > 10) listaPares.resize(listaPares.size() - 5);
	if(listaImpares.size() > 10){
	    printf("%d %d\n", listaImpares.pop_back(), listaImpares.pop_back());
	}
	print(listaPares);
	print(listaImpares);
	
	printf("Testa o construtor que faz copia\n");
	Vector listaSomentePar(listaPares), listaSomenteImpar(listaImpares);
	print(listaSomentePar);
	print(listaSomenteImpar);	
	
	printf("Testa a funcao replaceAt\n");
	if(listaSomentePar.size() > 10){
	    int value, index; 
	    scanf("%d %d", &value, &index);
	    listaSomentePar.replaceAt(value, index);
	}
	if(listaSomenteImpar.size() > 10){
	    int value, index; 
	    scanf("%d %d", &value, &index);
	    listaSomenteImpar.replaceAt(value, index);
	}	
	print(listaSomentePar);
	print(listaSomenteImpar);
	
	printf("Testa a funcao removeAt\n");
	if(listaSomentePar.size() > 10){
	    int index; 
	    scanf("%d", &index);
	    listaSomentePar.removeAt(index);
	}
	if(listaSomenteImpar.size() > 10){
	    int index; 
	    scanf("%d", &index);
	    listaSomenteImpar.removeAt(index);
	}	
	print(listaSomentePar);
	print(listaSomenteImpar);
	
	printf("Testa a funcao insert\n");
	if(listaSomentePar.size() > 10){
	    int value, index; 
	    scanf("%d %d", &value, &index);
	    listaSomentePar.insert(value, index + 1);
	}
	if(listaSomenteImpar.size() > 10){
	    int value, index; 
	    scanf("%d %d", &value, &index);
	    listaSomenteImpar.insert(value, index + 1);
	}	
	print(listaSomentePar);
	print(listaSomenteImpar);
	
	printf("Testa a funcao removeAll\n");
	if(listaSomentePar.size() > 10){
	    int value; 
	    scanf("%d", &value);
	    listaSomentePar.removeAll(value);
	}
	if(listaSomenteImpar.size() > 10){
	    int value; 
	    scanf("%d", &value);
	    listaSomenteImpar.removeAll(value);
	}	
	print(listaSomentePar);
	print(listaSomenteImpar);	
	
	printf("Testa a funcao push_front\n");
	if(listaSomentePar.size() >= 2){
	    int value; 
	    scanf("%d", &value);
	    listaSomentePar.push_front(value);
	    scanf("%d", &value);
	    listaSomentePar.push_front(value);	    
	}
	if(listaSomenteImpar.size() >= 2){
	    int value; 
	    scanf("%d", &value);
	    listaSomenteImpar.push_front(value);
	    scanf("%d", &value);
	    listaSomenteImpar.push_front(value);	    
	}	
	print(listaSomentePar);
	print(listaSomenteImpar);	
	
	printf("Testa a funcao pop_back e pop_front\n");
	remove(listaSomentePar);
	remove(listaSomenteImpar);
}