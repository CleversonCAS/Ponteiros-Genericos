#include <iostream>
#include <sstream>
#include <random>
#include <algorithm>
#include <functional>
#include <limits>
#include "fun.h"

std::size_t compacta( int * V_, std::size_t count_ )
{
    auto iSlow(0ul);
    auto iFast(0ul);
    for( /* empty */ ; iFast < count_ ; ++iFast )
    {
        if( V_[ iFast ] > 0 )
            V_[ iSlow++ ] = V_[ iFast ];
    }

    return iSlow; // New vector size.
}

void randomFill( int *V_, std::size_t arrSz_,
                 const int lower_, const int upper_,
                 const unsigned int seed_ )
{
    //use the default random engine and an uniform distribution
    std::default_random_engine eng( seed_ );
    std::uniform_real_distribution<double> distr( lower_, upper_ );

    // Fill up vector
    for ( auto i(0) ; i < arrSz_ ; ++i )
        V_[ i ] = distr( eng );
}