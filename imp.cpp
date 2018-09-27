#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstdio>
#include <string.h>
#include "fun.h"
#include <vector>
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
const void  *min(const void *first, const void *last, size_t size , Compare cmp)
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




void reverse(void *first,void *last,size_t size)///////////Tá errado(?)//AS VEZES DÁ CERTO (com vetor C dá errado)
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
		it++;								//Se colocar it+=size dá falha de segmentação 
		it2--;
		//std::cout << 
	}
}


//Questão 3
void *copy(const  void *first,const   void *last ,  void *d_first, size_t size)
	{
	 	void *firsta = const_cast < void*> (first);
	 	void *lasta = const_cast <  void*> (last);
	 	void *firstb = const_cast <  void*> (d_first);
		byte *i = static_cast < byte*> (firsta);
		byte *j = static_cast < byte*> (firstb);
		byte *p = static_cast < byte*> (lasta);
		byte k= std::distance(i,p)/size;

		while(i != lasta)
		{
			memcpy(j, i, size);
			i+=size; 
			j+=size;

		}

		return firstb+static_cast < byte>(k);
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
	return it-size;//////////////////////////////////////Retorna lixo(?)
}


//Questão 6
void *find(void *first , void *last , size_t size , void *value , Equal eq)
{
	byte *it = static_cast<byte*>(first);
	//byte valor = static_cast<byte>(value);
	while(it != last)
	{
	
		if(eq(it,value))
		{
			return it;
		}
		it+=size;
	}
	return it-size;
}


//Questão 7
bool all_of(const void *first , const void *last , size_t size,Predicate p)
{
	const byte *it = static_cast <const byte*>(first);
	while(it != last)
	{
		if(  !(p(it))  )
		{
			return false;
		}
		it+=size;
	}
	return true;
}
bool any_of(const void *first , const void *last , size_t size , Predicate p)
{
	const byte *it = static_cast <const byte*>(first);
	while(it != last)
	{
		if(  p(it)  )
		{
			return true;
		}
		it+=size;
	}
	return false;
}

bool none_of(const void *first , const void *last , size_t size ,  Predicate p )
{
	const byte *it = static_cast <const byte*>(first);
	while(it != last)
	{
		if(  p(it)  )
		{
			return false;
		}
		it+=size;
	}
	return true;
}


//Questão 8
bool equal(const void *first , const void *last ,void *first2, size_t size , Equal eq)
{
	const byte *it = static_cast<const byte*>(first);
	const byte *it2 = static_cast<const byte*>(first2);
	while(it != last)
	{
		if(!(eq(it,it2)))
		{
			return false;
		}
		it+=size;
		it2+=size;
	}
	return true;
}

bool equal(const void *first , const void *last ,void *first2, void *last2, size_t size , Equal eq)
{
	const byte *it = static_cast<const byte*>(first);
	const byte *it2 = static_cast<const byte*>(first2);
	while(it != last or it2!=last2)
	{
		if(!(eq(it,it2)))
		{
			return false;
		}
		it+=size;
		it2+=size;
	}
	return true;
}


//Questão 9 //?
void *unique(void *first ,void *last , size_t size , Equal eq)
{
	byte *i= static_cast<byte*>(first);
	byte *j= static_cast<byte*>(last);
	byte *a= static_cast<byte*>(last);

	for(/**/; i<=a ; i+=size )
	{
		for(j=static_cast<byte*>(first) ; j<=i ; j+=size)
		{
			if (eq(i,j))
			{
				memmove( i , i+size , std::distance(i,static_cast<byte*>(last)));
				a-=size;
			}
		}
	}
	return a;

}	
void sort( void* first , void *last , size_t size, Compare cmp)
{
	byte *i = static_cast< byte *>(first);
	byte *j = static_cast< byte *>(first);
	byte *p = static_cast< byte *>(last);

	int aux;

	for(; i < last-size; i+=size)
	{
		for(j = i+size; j < last; j+=size)
		{
			if(cmp(j,i))
			{
				aux = *j;
				*j = *i;
				*i = aux;
			}
		}
	}
}