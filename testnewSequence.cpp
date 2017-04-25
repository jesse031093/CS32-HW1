#include "newSequence.h"
#include <iostream>
#include <cassert>

int main()
{
	Sequence a(7); 
	Sequence b(5); 
	Sequence c;
	
	a.insert(38);
	a.insert(59);
	a.insert(42);
	a.insert(26);
	a.insert(1);
	a.insert(73);
	a.insert(38);	//1 26 38 38 42 59 73

	b.insert(4);
	b.insert(88);
	b.insert(36);
	b.insert(45);
	b.insert(89);	//4 36 45 88 89

	assert(a.find(41) == -1);
	a = b;
	assert(a.find(4) == 0);
	c = a;
	assert(!c.empty());
}