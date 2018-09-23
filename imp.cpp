#include <iostream>
#include <algorithm>
#include <iterator>
#include "fun.h"

void printVetor(ponteiroGenericofirst, ponteiroGenericolast, size_t size)
{														//Imprime o vetor
	const byte *it = static_cast<byte>(first);
	it+=size;
	for(it=first ; it!=last ; it+size)
	{
		cout<<*it<<' ';
	}
	cout<<endl;
}

void criarVetorAleatorio(ponteiroGenerico first, int tam)
{
	//Cria o Vetor int
	srand(time(NULL));
	vector<int> v;
	vector<int>::const_interator it;
	
	for(it = v.begin() ; it! = tam ; it++)
	{
		v.pushback(rand() % 50) ;
	}
}

void min(ponteiroGenerico first, ponteiroGenerico last, size_t size , compare cmp)
{
	//convertendo para poder usar aritimética de ponteiros
	const byte *it = static_cast <byte*> (first);

	it+=size;//PQ NÃO APENAS it=size?
	const byte *menor = it;
	while(it != last)
	{
		if(cmp(it , menor))
		{
			menor = it;
		}
		it+=size;
	}
	return menor;
}
