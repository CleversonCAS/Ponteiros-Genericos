#include <iostream>
#include <iterator>
#include <string>
#include <ctime> //rand
#include <vector>
#include "fun.h"
//#include "imp.cpp"

bool menor(ponteiroGenerico a , ponteiroGenerico b)
{
	return static_cast<int *>(a) < static_cast<int *>(b);
}

int main()
{	
	std::vector<int> vetor;
	//Criando vetor aleatório
	criarVetorAleatorio(vetor.begin() , 10)

	std::cout << "Vetor: ";
	printVetor(begin(v) , end(v) , sizeof(int));
	auto menor = min(vetor.begin() , vetor.end() , sizeof(int) , menor);
	std::cout << "Menor elemento do vetor é: " << *menor << std::endl;

	return 0;
}