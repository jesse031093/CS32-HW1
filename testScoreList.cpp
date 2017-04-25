#include "ScoreList.h"
#include <iostream>
#include <cassert>

int main()
{
	ScoreList a;
	a.add(59);	//59
	a.add(73);	//59 73
	a.add(53);	//53 59 73
	a.add(43);	//43 53 59 73
	a.add(100);	//43 53 59 73 100
	a.add(1);	//1 43 53 59 73 100
	a.add(98);	//1 43 53 59 73 98 100
	assert(!a.add(101));
	assert(!a.remove(10));
	a.add(59);	//1 43 53 59 59 73 98 100
	assert(a.remove(59));	//1 43 53 59 73 98 100
	assert(a.size() == 7);
	assert(a.minimum() == 1 && a.maximum() == 100);
}