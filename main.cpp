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

	return *static_cast<const int *>(a) % 2 == 1 ;//achar o primeiro impar
}
bool eq(void *a , void *b)
{
	return static_cast<int *>(a)   ==   static_cast<int *>(b);
}

int main()
{	
	int A[]={0,-15,12,25,10};
	int B[]={72,51,23 ,15,94};
	int C[]={-11,2,10,15,12,9};

	printEspaco(1);
	//Questão 1
	//criarVetorAleatorio( begin(A) , sizeof(int) ,10);
	std::cout << "Vetor: ";
	printVetor(begin(A) , end(A));
	auto result_min = (const int*) min(begin(A) , end(A) , sizeof(int) , menor);
	std::cout << "Menor elemento do vetor é: " << *result_min << std::endl;

	printEspaco( 2);

	//Questão 2
	std::cout << "Vetor: ";
	printVetor(begin(A) , end(A));
	reverse(begin(A) , end(A) , sizeof(int));
	std::cout<<"Vetor revertido: \n";
	printVetor(begin(A) , end(A));

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
	printVetor(begin(C) , end(C));
	auto result_par = (const int*)find_if(begin(C) , end(C) , sizeof(int) , par);
	std::cout << "Primeiro par do vetor: "<<*result_par<<'\n';
	auto result_impar = (const int*)find_if(begin(C) , end(C) , sizeof(int) , impar);
	std::cout << "Primeiro impar do vetor: "<<*result_impar<<'\n';

/*
	//Questão 6
	criarVetorAleatorio( begin(A) , sizeof(int) ,10);;
	std::cout << "Vetor: ";
	printVetor(begin(A) , end(A));
	auto find = find(begin(A) , end(A) , sizeof(int) , 15 , eq);
	std::cout << "Valor retornado(Se não encontrado, retornará o ultimo elemento): "<<find<<'\n';


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