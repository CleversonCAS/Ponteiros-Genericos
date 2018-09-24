#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstdio>
#include <string.h>
#include "fun.h"
/*
typedef bool(Compare*)(const void *a, const void *b);
typedef bool(Predicate*)(const void *a);
typedef bool(Equal*)(const void *a, const void *b);
*/
void printEspaco(int a)
{
	std::cout<<"\n\n_____________________________________________________________________\nQuestão: "<<a<<"\n\n";
}
void printVetor(int *first, int *last)
{	
	int *it = first;													//Imprime o vetor
	for(it=first ; it!=last ; it++)
	{
		std::cout<<*it<<' ';
	}
	std::cout<<std::endl;
}

/*void criarVetorAleatorio(void *first, size_t size , int tam)
{
	srand(time(NULL));												//Cria o Vetor int, Sabosta funciona?
	const byte *it = static_cast <byte*>(first);

	while(it != static_cast<byte*>(tam))
	{
		first[it] = srand() % 50; //pode isso?
		it+=size;
	}
}
*/


//Questão 1
const void  *min(void *first, void *last, size_t size , Compare cmp)
{
	//convertendo para poder usar aritimética de ponteiros
	const byte *it = static_cast <const byte*> (first);

	it+=size;
	const byte *menor = it;
	while(it != last)////////////////quero parar na metade como q faz(?)
	{
		if(cmp(it , menor))
		{
			menor = it;
		}
		it+=size;
	}
	return menor;
}


//Questão 2




void reverse(void *first,void *last,size_t size)///////////Tá errado(?)
{
	byte *it = static_cast < byte*> (first);
	//byte *i = static_cast < byte*> (first);
	byte *it2= static_cast < byte*> (last);
	it2-=size;
	byte tmp ;
	while(it != it2)
	{
		tmp = *it;
		*it = *it2;
		*it2 = tmp;
		//std::swap(it, it2);
		//memcpy(it, it2, size);
		it+=size;
		it2-=size;
		//std::cout << 
	}
}


//Questão 3
const void *copy(  void *firstA,   void *lastA ,  void *firstB , size_t size)
	{
	 	
		byte *i = static_cast < byte*> (firstA);
		byte *j = static_cast < byte*> (firstB);
		byte *p = static_cast < byte*> (lastA);
		byte k= std::distance(i,p)/size;

		while(i != lastA)
		{
			memcpy(j, i, size);
			i+=size; 
			j+=size;

		}

		return firstB+k;//?
	}


//Questão 4
//////////////////////////////////////////


//Questão 5
	
const void *find_if( const void *first, const void *last,size_t size,Predicate p )
{
	const byte *it = static_cast <const byte*>(first);
	while(it != last)
	{
		if(  p(it)  )
		{
			return it;
		}
		it+=size;
	}
	return it;
}

/*
//Questão 6
const void *find(const void *first , const void *last , size_t size , const void *value , Equal eq)
{
	byte *it = static_cast<byte*>(first);
	while(it != last)
	{
		if(eq(*it,*value))
		{
			return it;
		}
		it+=size;
	}
	return it;
}


//Questão 7
bool all_of(const void *first , const void *last , size_t size,Predicate p)
{
	byte *it = static_cast <byte*>(first);
	while(it != last)
	{
		if(  !(p(*it))  )
		{
			return false
		}
		it+=size;
	}
	return true;
}
bool any_of(const void *first , const void *last , size_t size , Predicate p)
{
	byte *it = static_cast <byte*>(first);
	while(it != last)
	{
		if(  p(*it)  )
		{
			return true
		}
		it+=size;
	}
	return false;
}
}
bool none_of(const void *first , const void *last , size_t size ,  Predicate p )
{
	byte *it = static_cast <byte*>(first);
	while(it != last)
	{
		if(  p(*it)  )
		{
			return false
		}
		it+=size;
	}
	return true;
}


//Questão 8
bool equal(const void *first , const void *last ,void *first2, size_t size , Equal eq)
{
	byte *it = static_cast<byte*>(first);
	byte *it2 = static_cast<byte*>(first2);
	while(it != last)
	{
		if(!(eq(*it,*it2))
		{
			return false
		}
		it+=size;
		it2+=size;
	}
	return true;
}

bool equal(const void *first , const void *last ,void *first2, void *last2, size_t size , Equal eq)
{
	byte *it = static_cast<byte*>(first);
	byte *it2 = static_cast<byte*>(first2);
	while(it != last or it2!=last2)
	{
		if(!(eq(*it,*it2))
		{
			return false
		}
		it+=size;
		it2+=size;
	}
	return true;
}


//Questão 9 //?
void *unique(const void *first , const void *last , size_t size , Equal eq)
{
	
}*/

