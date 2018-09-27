#include <iostream>
#include <iterator>
#include <string>
#include <ctime> //rand
#include <vector>
#include "fun.h"
#include <fstream>

using std::begin;
using std::end;
//namespace graal;
//namespace graal;
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
	int A[]={0,-15,12,12,-15,25,10};
	int B[]={72,51,23 ,15,94};
	int C[]={-11,-2,10,15,12,9};
	int D[]={2,2,2,4,6,8,12,5,5,5,5,5,5,5,5,10,5,12,14,8,10,16,16};
	int E[]={5,7,1,9,10,2,8,3,4,6};
	printEspaco(1);
	//Questão 1 OK
	//criarVetorAleatorio( begin(A) , sizeof(int) ,10);
	std::cout << "Vetor: ";
	printVetor(begin(A) , end(A));
	auto result_min = (const int*) min(begin(A) , end(A) , sizeof(int) , menor);
	std::cout << "Menor elemento do vetor é: " << *result_min << std::endl;

	printEspaco( 2);

	//Questão 2		OK(???)//testar com outros vetores															//Está imprimindo números "aleatórios" em alguns caso
	std::cout << "Vetor: ";
	printVetor(begin(B) , end(B));
	reverse(begin(B) , end(B) , sizeof(int));
	std::cout<<"Vetor revertido: \n";
	printVetor(begin(B) , end(B));

	printEspaco(3); 

	//Questão OK
	std::cout << "Vetor que será copiado: ";
	printVetor(begin(A) , end(A));
	std::cout<<"Vetor aleatório: ";
	printVetor(begin(B) , end(B));
	auto result_copy = (const int*)copy(begin(A) , end(A), begin(B), sizeof(int));
	std::cout<<"Novo Vetor copiado\n";
	std::cout<<*result_copy<<'\n';
	printVetor(begin(B) , end(B));

	
	//Questão 4     //?Num sei fazer nao

	printEspaco(5);
	//Questão 5 OK
	std::ofstream outFile;
	outFile.open("teste.txt");
	outFile<<"AAAAAAAAAA"<<std::endl;
	std::cout << "Vetor: ";
	printVetor(begin(D) , end(D));
	auto result_par = (const int*)find_if(begin(D) , end(D) , sizeof(int) , par);
	std::cout << "Primeiro par do vetor: "<<*result_par<<'\n';
	auto result_impar = (const int*)find_if(begin(D) , end(D) , sizeof(int) , impar);
	std::cout << "Primeiro impar do vetor: "<<*result_impar<<'\n';
	std::cout << "PS: Se não encontrado retorna o ultimo elemento\n";


	printEspaco(6);
	//Questão 6 OK
	std::cout << "Vetor: ";
	printVetor(begin(A) , end(A));
	int *p,a=12;//Necessário, pois a função tem como parametro um ponteiro
	p=&a;
	std::cout << *p<<'\n';	
	auto result_find = (int*)find(begin(A) , end(A) , sizeof(int) , p , eq);//Acontece falha de segmentação (?)
	std::cout << "Valor retornado(Se não encontrado, retornará o ultimo elemento): "<<*result_find<<'\n';


	printEspaco(7);
	//Questão 7 OK
	std::cout << "Vetor: ";
	printVetor(begin(D) , end(D));
	auto  result_all_of= all_of(begin(D) , end(D) , sizeof(int) , par);////////////////
	std::cout<<"Todos são pares?  "<<result_all_of<<std::endl;
	std::cout << "Vetor: ";
	printVetor(begin(D) , end(D));
	auto result_any_of = any_of(begin(D) , end(D) , sizeof(int) , par);////////////////
	std::cout<<"Algum é par?  "<<result_any_of<<std::endl;
	std::cout << "Vetor: ";
	printVetor(begin(D) , end(D));
	auto result_none_of = none_of(begin(D) , end(D), sizeof(int) , par);////////////////
	std::cout<<"Nenhum é par?  "<<result_none_of<<std::endl;


	printEspaco(8);	
	//Questão 8 OK
	std::cout << "Vetor A: ";
	printVetor(begin(A) , end(A));
	std::cout << "Vetor B: ";
	printVetor(begin(B) , end(B));
	auto result_equal_1 = equal(begin(A) , end(A), begin(B), sizeof(int), eq );
	std::cout<<"A == B? "<<result_equal_1<<std::endl;


	std::cout << "Vetor A: "; 
	printVetor(begin(A) , end(A));
	std::cout << "Vetor B: ";
	printVetor(begin(C) , end(C));
	auto result_equal_2 = equal(begin(A) , end(A), begin(C), end(C) , sizeof(int) , eq);
	std::cout<<"A == B? "<<result_equal_2<<std::endl; 


	
	//Questão 9 
	printEspaco(9);
	std::cout << "Vetor: ";
	printVetor(begin(D) , end(D));
	int * fin = (int*)unique(begin(D) , end(D), sizeof(int),eq);
	std::cout<<"Vetor arrumado: ";
	printVetor(begin(D) , fin);


	//Questão 10

	
	printEspaco(11);
	//Questão 11
	std::cout << "Vetor: ";
	printVetor(begin(E) , end(E));
	sort(begin(E) , end(E), sizeof(int),menor);
	std::cout<<"Vetor ordenado: ";
	printVetor(begin(E) , end(E));




		
	return 0;
}