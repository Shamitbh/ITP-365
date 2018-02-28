// ITP 365 Spring 2017
// LP04 - Money
// Name: Shamit Bhatia
// Email: Shamitbh@usc.edu
// Platform: MAC
//
// money.cpp

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
	cents = inCents % 100;
}

std::ostream& operator<< (std::ostream& os, Money& m1)
{
	os << "$" << m1.dollars << "." << m1.cents;
	return os;
}

Money operator+ (const Money& m1, const Money& m2)
{
	return Money(m1.dollars+m2.dollars, m1.cents+m2.cents);
}

Money operator/ (const Money& m1, const double& toDivideBy)
{
	return Money(m1.dollars/toDivideBy, m1.cents/toDivideBy);
}
