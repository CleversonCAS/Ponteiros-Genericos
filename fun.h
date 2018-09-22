#ifndef FUN_H
#define FUN_H

typedef bool (*Compare)( const void *a, const void *b);//devo definir isso aqui tmb?
void *min(int *first , int *last , size_t size , compare cmp );
	



#endif