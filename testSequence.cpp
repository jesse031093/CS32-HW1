//TEST MODEL BY CHANG-YU (JESSE) CHIANG

#include "Sequence.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// To test a Sequence of unsigned long, leave the following #define line
// commented out; to test a Sequence of string, remove the "//".

//#define TEST_WITH_STRING
#ifdef TEST_WITH_STRING
const ItemType VAL[6] = { "hillary", "gary", "donald", "jill", "evan", "tim" };
#else // assume unsigned long
const ItemType VAL[6] = { 15, 7, 1, 56, 4, 77 };
#endif

void test()
{
	Sequence s;
	assert(s.empty());						//test empty
	assert(s.insert(VAL[0]) == 0);			//insert every element in VAL
	assert(s.insert(VAL[1]) == 0);
	assert(s.insert(VAL[2]) == 0);
	assert(s.insert(VAL[3]) == 3);
	assert(s.insert(VAL[4]) == 1);
	assert(s.insert(VAL[5]) == 5);			//the elements inside the array in s are in order
											//which is {VAL[2], VAL[4], VAL[1], VAL[0], VAL[3], VAL[5]}
	assert(!s.empty() && s.size() == 6);	//s is not empty and size is 6
	ItemType n = VAL[0];
	assert(!s.get(6, n) && n == VAL[0] && s.get(0, n) && n == VAL[2]
		&& s.get(1, n) && n == VAL[4] && s.get(2, n) && n == VAL[1]
		&& s.get(3, n) && n == VAL[0] && s.get(4, n) && n == VAL[3]
		&& s.get(5, n) && n == VAL[5]);		//check if the array in s is in correct order
	assert(!s.insert(7, VAL[0]) && s.insert(2, VAL[2]) && s.get(2, n)
		&& n == VAL[2] && s.size() == 7);	//test insert(int, const ItemType &)
											//now the array is {VAL[2], VAL[4], VAL[2], VAL[1], VAL[0], VAL[3], VAL[5]}
	assert(!s.erase(8) && s.erase(4) && s.size() == 6);	//test erase
														//{VAL[2], VAL[4], VAL[2], VAL[1], VAL[3], VAL[5]}
	assert(s.find(VAL[0]) == -1 && s.find(VAL[3]) == 4);//can't find VAL[0] because we just erased it
														//and instead, VAL[3] is in 4th position
	assert(s.remove(VAL[2]) == 2 && s.size() == 4);		//test remove
														//{VAL[4], VAL[1], VAL[3], VAL[5]}
	assert(!s.set(4, VAL[2]) && s.set(0, VAL[2]));		//test set
														//{VAL[2], VAL[1], VAL[3], VAL[5]}
	assert(s.get(0, n) && n == VAL[2] && s.get(1, n) && n == VAL[1]
		&& s.get(2, n) && n == VAL[3] && s.get(3, n) && n == VAL[5]);	//check array order
	Sequence t;
	for (int i = 0; i < 6; i++)
		t.insert(VAL[i]);
	//test swap
	t.swap(s);
	assert(t.size() == 4 && s.size() == 6);
	assert(s.get(0, n) && n == VAL[2] && s.get(1, n) && n == VAL[4] 
		&& s.get(2, n) && n == VAL[1] && s.get(3, n) && n == VAL[0]
		&& s.get(4, n) && n == VAL[3] && s.get(5, n) && n == VAL[5]);
	assert(t.get(0, n) && n == VAL[2] && t.get(1, n) && n == VAL[1]
		&& t.get(2, n) && n == VAL[3] && t.get(3, n) && n == VAL[5]);
	//test what happens when exceeding DEFAULT_MAX_ITEMS
	Sequence x;
	for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
		x.insert(VAL[2]);
	assert(x.insert(VAL[2]) == -1 && x.size() == DEFAULT_MAX_ITEMS);
}

int main()
{
	test();
	cout << "Passed all tests" << endl;
}