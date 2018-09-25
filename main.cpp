#include <iostream>
#include <iterator>
#include <string>
#include <ctime> //rand
#include <vector>
#include "fun.h"
#include <fstream>

using std::begin;
using std::end;
//#include "imp.cpp"
//Os ponteiro para função, aonde devo colocar?(No momento estão no .h)
//E as função bool?(tão na main)
//Em quais funções devo usar memcpy?

bool menor(const void *a ,const void *b)
{
	return *static_cast<const int *>(a)   <   *static_cast<const int *>(b);//Pq tenho que comparar como sendo int?
}

bool par( const void *a)
{
	return *static_cast<const int *>(a) % 2 == 0 ;//achar o primeiro par
}
bool impar(const void *a)
{

	return *static_cast<const int *>(a) % 2 == 1 ;//achar o primeiro impar//Se for negativo, retorna o próximo positivo(?)
}
bool eq(const void *a ,const void *b)
{
	return *static_cast<const int *>(a)   ==   *static_cast<const int *>(b);
}

int main()
{	
	int A[]={0,-15,12,25,10};
	int B[]={72,51,23 ,15,94};
	int C[]={-11,-2,10,15,12,9};
	int D[]={2,4,6,8,10,12,14,16};

	printEspaco(1);
	//Questão 1
	//criarVetorAleatorio( begin(A) , sizeof(int) ,10);
	std::cout << "Vetor: ";
	printVetor(begin(A) , end(A));
	auto result_min = (const int*) min(begin(A) , end(A) , sizeof(int) , menor);
	std::cout << "Menor elemento do vetor é: " << *result_min << std::endl;

	printEspaco( 2);

	//Questão 2																	//Está imprimindo números "aleatórios" em alguns caso
	std::cout << "Vetor: ";
	printVetor(begin(B) , end(B));
	reverse(begin(B) , end(B) , sizeof(int));
	std::cout<<"Vetor revertido: \n";
	printVetor(begin(B) , end(B));

	printEspaco(3); 

	//Questão 3
	std::cout << "Vetor que será copiado: ";
	printVetor(begin(A) , end(A));
	std::cout<<"Vetor aleatório: ";
	printVetor(begin(B) , end(B));
	auto result_copy = (const int*)copy(begin(A) , end(A), begin(B), sizeof(int));
	std::cout<<"Novo Vetor copiado\n";
	printVetor(begin(B) , end(B));

	
	//Questão 4     //?Num sei fazer nao

	printEspaco(5);
	//Questão 5
	std::ofstream outFile;
	outFile.open("teste.txt");
	outFile<<"AAAAAAAAAA"<<std::endl;
	std::cout << "Vetor: ";
	printVetor(begin(D) , end(D));
	auto result_par = (const int*)find_if(begin(D) , end(D) , sizeof(int) , par);
	std::cout << "Primeiro par do vetor: "<<*result_par<<'\n';
	auto result_impar = (const int*)find_if(begin(D) , end(D) , sizeof(int) , impar);
	std::cout << "Primeiro impar do vetor: "<<*result_impar<<'\n';

	printEspaco(6);
	//Questão 6
	std::cout << "Vetor: ";
	printVetor(begin(A) , end(A));
	int *p;
	*p=12;
	auto result_find = (int*)find(begin(A) , end(A) , sizeof(int) , p , eq);
	std::cout << "Valor retornado(Se não encontrado, retornará o ultimo elemento): "<<*result_find<<'\n';
std::cout << "Valor retornado(Se não encontrado, retornará o ultimo elemento): ";
/*
	//Questão 7
	criarVetorAleatorio( begin(A) , sizeof(int) ,10);;
	std::cout << "Vetor: ";
	printVetor(begin(A) , end(A));
	auto  all_of= all_of(begin(A) , end(A) , sizeof(int) , par);////////////////
	std::cout<<"Todos são pares?  "<<all_of<<std::endl;
	criarVetorAleatorio( begin(A) , sizeof(int) ,10);;
	std::cout << "Vetor: ";
	printVetor(begin(A) , end(A));
	auto any_of = any_of(begin(A) , end(A) , sizeof(int) , par);////////////////
	std::cout<<"Algum é par?  "<<any_of<<std::endl;
	criarVetorAleatorio( begin(A) , sizeof(int) ,10);;
	std::cout << "Vetor: ";
	printVetor(begin(A) , end(A));
	auto none_of = none_of(begin(A) , end(A) , sizeof(int) , par);////////////////
	std::cout<<"Nenhum é par?  "<<none_of<<std::endl;


	//Questão 8
	criarVetorAleatorio( begin(A) , sizeof(int) ,10);;
	std::cout << "Vetor A: ";
	printVetor(begin(A) , end(A));
	criarVetorAleatorio( begin(B) , sizeof(int) ,10);;
	std::cout << "Vetor B: ";
	printVetor(begin(B) , end(B));
	auto equal1 = equal(begin(A) , end(A), begin(B), sizeof(int), eq );
	std::cout<<"A == B? "<<equal1<<std::endl;

	criarVetorAleatorio( begin(A) , sizeof(int) ,10);;
	std::cout << "Vetor A: ";
	printVetor(begin(A) , end(A));
	criarVetorAleatorio( begin(B) , sizeof(int) ,10);;
	std::cout << "Vetor B: ";
	printVetor(begin(B) , end(B));
	auto equal2 = equal(begin(A) , end(A), begin(B), end(B) , sizeof(int) , eq);
	std::cout<<"A == B? "<<equal1<<std::endl; 


	//Questão 9


	//Questão 10


	//Questão 11*/





		
	return 0;
}