#include <iostream>
#include <iterator>
#include <sctring>
#include <ctime>//rand
#include "fun.h"
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;
	bool menor(void *a , void *b)
	{
		return static_cast<int *>(a) < static_cast<int *>(b);
	}
int main()
{	
	vector<int> v;
	criaV(begin(v) , 10)//Criando vetor aleatório
	cout<<"Vetor: "
	printV(begin(v) , end(v) , sizeof(int);)
	auto menor = min(begin(v) , end(v) , sizeof(int) , menor);
	cout<<"Menor elemento do vetor é: "<< *menor <<endl;


	return 0;
}