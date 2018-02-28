//
//  money.cpp
//  
//
//  Created by Shamit Bhatia on 1/31/17.
//
//

#include "money.h"

Money::Money()
{
	dollars = 0;
	cents = 0;
}

Money::Money(long long inDollars, short inCents)
{
	// handle lots of cents here...
	dollars = inDollars + inCents / 100;
	
}
