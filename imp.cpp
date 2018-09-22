#include <iostream>
#include <algorithm>
#include <iterator>
#include "fun.h"
using std::cout;
using std::endl;
using std::vector;
	typedef bool (*MinCompare)( const void *a, const void *b );//pra q isso msm?
	void printV(void *first, void *last, size_t size)
	{														//Imprime o vetor
		const byte *it = static_cast<byte>(first);
		it+=size;
		for(it=first ; it!=last ; it+size)
		{
			cout<<*it<<' ';
		}
		cout<<endl;
	}
	void criaV(void *first, int tam)
	{														//Cria o Vetor int
		srand(time(NULL));
		vector<int> v;
		vector<int>::const_interator it;
		
		for(it = v.begin() ; it! = tam ; it++)
		{
			v.pushback(rand() % 50) ;
		}
	}
	void *min(void *first, void *last, size_t size , compare cmp)
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

	