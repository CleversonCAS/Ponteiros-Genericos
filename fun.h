#ifndef FUN_H
#define FUN_H

void randomFill( int *V_, std::size_t arrSz_,
	   	const int lower_, const int upper_,
		const unsigned int seed_ );

std::size_t compacta( int * V_, std::size_t count_ );
#endif  