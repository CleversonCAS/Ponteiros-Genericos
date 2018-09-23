#ifndef FUN_H
#define FUN_H
typedef unsigned char byte;
using compare = bool (*Compare)(const void *a, const void *b);
using Predicate = bool (*predic)(const void *a);
using Equal = bool (*Equal)(const void *a, const void *b);
//Q1
void min(void *first, void *last, size_t size, Compare cmp);

//Q2
void reverse(void *first,void *last,size_t size);

//Q3
void *copy(const void *firstA, const void *lastA , const void *firstB , size_t size);

//Q4

//Q5
find_if(const void *first,const void *last,size_t size,Predicate p );

//Q6
const void *find(const void *first , const void *last , size_t size , const void *value , Equal eq);

//Q7
bool all_of(const void *first , const void *last , size_t size,Predicate p);
bool any_of(const void *first , const void *last , size_t size , Predicate p);
bool none_of(const void *first , const void *last , size_t size ,  Predicate p );

//Q8
bool equal(const void *first , const void *last ,void *first 2, size_t size , Equal eq);
bool equal(const void *first , const void *last ,void *first2, void *last2, size_t size , Equal eq);

//Q9
void *unique(const void *first , const void *last , size_t size , Equal eq);

#endif 