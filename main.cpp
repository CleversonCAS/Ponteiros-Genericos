#include <iostream>
#include <iterator>
#include <string>
#include <ctime> //rand
#include <vector>
#include "fun.h"

using std::begin;
using std::end;
//#include "imp.cpp"
//Os ponteiro para função, aonde devo colocar?(No momento estão no .h)
//E as função bool?(tão na main)
//Em quais funções devo usar memcpy?

bool menor(void *a , void *b)
{
	return static_cast<int *>(a)   <   static_cast<int *>(b);//Pq tenho que comparar como sendo int?
}

bool par(void *a)
{
	return (static_cast<int *>(a) % 2 == 0 );//achar o primeiro par
}
bool impar(void *a)
{
	return (static_cast<int *>(a) % 2 == 1 );//achar o primeiro impar
}
bool eq(void *a , void *b)
{
	return static_cast<int *>(a)   ==   static_cast<int *>(b);
}

int main()
{	
	int A[10],B[10];
	//Questão 1
	criarVetorAleatorio( begin(A) , sizeof(int) ,10);
	std::cout << "Vetor: ";
	printVetor(begin(A) , end(A) , sizeof(int));
	auto menor = min(begin(A) , end(A) , sizeof(int) , menor);
	std::cout << "Menor elemento do vetor é: " << *menor << std::endl;


	//Questão 2
	criarVetorAleatorio( begin(A) , sizeof(int) ,10);
	std::cout << "Vetor: ";
	printVetor(begin(A) , end(A) , sizeof(int));
	reverse(begin(A) , end(A) , sizeof(int));
	std::cout<<"Vetor revertido: \n";
	printVetor(begin(A) , end(A) , sizeof(int));


	//Questão 3
	criarVetorAleatorio( begin(A) , sizeof(int) ,10);
	criarVetorAleatorio(begin(B) , sizeof(int) ,10)
	std::cout << "Vetor que será copiado: ";
	printVetor(begin(A) , end(A) , sizeof(int));
	std::cout<<"Vetor aleatório: ";
	printVetor(begin(B) , end(B) , sizeof(int));
	auto copy = copy(begin(A) , end(A), begin(B), sizeof(int))
	std::cout<<"Novo Vetor copiado\n";
	printVetor(begin(B) , end(B) , sizeof(int));


	//Questão 4     //?Num sei fazer nao


	//Questão 5
	criarVetorAleatorio( begin(A) , sizeof(int) ,10);
	std::cout << "Vetor: ";
	printVetor(begin(A) , end(A) , sizeof(int));
	auto par = find_if(begin(A) , end(A) , sizeof(int) , par);
	std::cout << "Primeiro par do vetor: "<<par<<'\n';
	auto par = find_if(begin(A) , end(A) , sizeof(int) , impar);
	std::cout << "Primeiro impar do vetor: "<<impar<<'\n';


	//Questão 6
	criarVetorAleatorio( begin(A) , sizeof(int) ,10);;
	std::cout << "Vetor: ";
	printVetor(begin(A) , end(A) , sizeof(int));
	auto find = find(begin(A) , end(A) , sizeof(int) , 15 , eq);
	std::cout << "Valor retornado(Se não encontrado, retornará o ultimo elemento): "<<find<<'\n';


	//Questão 7
	criarVetorAleatorio( begin(A) , sizeof(int) ,10);;
	std::cout << "Vetor: ";
	printVetor(begin(A) , end(A) , sizeof(int));
	auto  all_of= all_of(begin(A) , end(A) , sizeof(int) , par);////////////////
	std::cout<<"Todos são pares?  "<<all_of<<std::endl;
	criarVetorAleatorio( begin(A) , sizeof(int) ,10);;
	std::cout << "Vetor: ";
	printVetor(begin(A) , end(A) , sizeof(int));
	auto any_of = any_of(begin(A) , end(A) , sizeof(int) , par);////////////////
	std::cout<<"Algum é par?  "<<any_of<<std::endl;
	criarVetorAleatorio( begin(A) , sizeof(int) ,10);;
	std::cout << "Vetor: ";
	printVetor(begin(A) , end(A) , sizeof(int));
	auto none_of = none_of(begin(A) , end(A) , sizeof(int) , par);////////////////
	std::cout<<"Nenhum é par?  "<<none_of<<std::endl;


	//Questão 8
	criarVetorAleatorio( begin(A) , sizeof(int) ,10);;
	std::cout << "Vetor A: ";
	printVetor(begin(A) , end(A) , sizeof(int));
	criarVetorAleatorio( begin(B) , sizeof(int) ,10);;
	std::cout << "Vetor B: ";
	printVetor(begin(B) , end(B) , sizeof(int));
	auto equal1 = equal(begin(A) , end(A), begin(B), sizeof(int), eq );
	std::cout<<"A == B? "<<equal1<<std::endl;

	criarVetorAleatorio( begin(A) , sizeof(int) ,10);;
	std::cout << "Vetor A: ";
	printVetor(begin(A) , end(A) , sizeof(int));
	criarVetorAleatorio( begin(B) , sizeof(int) ,10);;
	std::cout << "Vetor B: ";
	printVetor(begin(B) , end(B) , sizeof(int));
	auto equal2 = equal(begin(A) , end(A), begin(B), end(B) , sizeof(int) , eq);
	std::cout<<"A == B? "<<equal1<<std::endl; 


	//Questão 9


	//Questão 10


	//Questão 11





		
	return 0;
}