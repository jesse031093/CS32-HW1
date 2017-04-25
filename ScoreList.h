#ifndef SCORELIST_H
#define SCORELIST_H

#include "Sequence.h"
#include <limits>
using namespace std;
const unsigned long NO_SCORE = numeric_limits<unsigned long>::max();

typedef unsigned long ItemType;

class ScoreList
{
public:
	ScoreList();
	bool add(ItemType);
	bool remove(ItemType);
	int size()const;
	ItemType minimum()const;
	ItemType maximum()const;
private:
	Sequence m_s;
};

#endif