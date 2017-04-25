#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <string>
using namespace std;

const int DEFAULT_MAX_ITEMS = 200;
typedef unsigned long ItemType;

class Sequence
{
public:
	Sequence();
	bool empty()const;
	int size()const;
	bool insert(int, const ItemType&);
	int insert(const ItemType&);
	bool erase(int);
	int remove(const ItemType &);
	bool get(int, ItemType &)const;
	bool set(int, const ItemType &);
	int find(const ItemType &)const;
	void swap(Sequence &);
private:
	ItemType m_data[DEFAULT_MAX_ITEMS];
	int m_size;
};

#endif