#ifndef FUN_H
#define FUN_H

#include <cstdlib>
typedef char byte;
typedef bool(*Compare)(const void *, const void *);
typedef bool(*Predicate)(const void *);
typedef bool(*Equal)(const void *, const void *);


//void criarVetorAleatorio(void *first, size_t size , int tam);
void printEspaco(int a);

void printVetor(int *first, int *last);
//Q1
const void *min(void *first, void *last, size_t size, Compare cmp);

//Q2
void reverse(void *first,void *last,size_t size);

//Q3
const void *copy(  void *firstA,   void *lastA ,  void *firstB , size_t size);

//Q4
//Q5
const void *find_if(const void *first,const void *last,size_t size,Predicate p );
/*
//Q6
const void *find(const void *first , const void *last , size_t size , const void *value , Equal eq);

//Q7
bool all_of(const void *first , const void *last , size_t size,Predicate p);
bool any_of(const void *first , const void *last , size_t size , Predicate p);
bool none_of(const void *first , const void *last , size_t size ,  Predicate p );

//Q8
bool equal(const void *first , const void *last ,void *first2, size_t size , Equal eq);
bool equal(const void *first , const void *last ,void *first2, void *last2, size_t size , Equal eq);

//Q9
void *unique(const void *first , const void *last , size_t size , Equal eq);
*/
#endif 