#include "newSequence.h"

Sequence::Sequence(int s): m_size(0), m_cap(s)
{
	m_data = new ItemType[s];
}

Sequence::Sequence(const Sequence &s)
{
	this->m_data = new ItemType[s.m_size];
	this->m_size = s.m_size;
	this->m_cap = s.m_cap;
	for (int i = 0; i < this->m_size; i++)
		this->m_data[i] = s.m_data[i];
}

Sequence &Sequence::operator=(const Sequence &s)
{
	if (this == &s)
		return (*this);
	delete []this->m_data;
	this->m_data = new ItemType[s.m_cap];
	this->m_cap = s.m_cap;
	this->m_size = s.m_size;
	for (int i = 0; i < s.m_size; i++)
		this->m_data[i] = s.m_data[i];
	return (*this);
}

Sequence::~Sequence()
{
	delete []m_data;
}

bool Sequence::empty()const
{
	if (m_size == 0)
		return true;
	else
		return false;
}

int Sequence::size()const
{
	return m_size;
}

bool Sequence::insert(int pos, const ItemType &value)
{
	if (pos < 0 || pos > m_size || m_size >= m_cap)
		return false;
	for (int i = m_size - 1; i >= pos; i--)
		m_data[i + 1] = m_data[i];
	m_data[pos] = value;
	m_size++;
	return true;
}

int Sequence::insert(const ItemType &value)
{
	int pos = 0;
	bool temp = false;
	for (int i = 0; i < m_size; i++)
	{
		if (value <= m_data[i])
		{
			pos = i;
			temp = true;
			break;
		}
	}
	if (!temp)
		pos = m_size;
	if (!insert(pos, value))
		return -1;
	return pos;
}

bool Sequence::erase(int pos)
{
	if (pos < 0 || pos >= m_size)
		return false;
	for (int i = pos; i < m_size - 1; i++)
		m_data[i] = m_data[i + 1];
	m_size--;
	return true;
}

int Sequence::remove(const ItemType & value)
{
	int count = 0;
	for (int i = 0; i < m_size; i++)
	{
		if (m_data[i] == value) {
			erase(i);
			i--;
			count++;
		}
	}
	return count;
}

bool Sequence::get(int pos, ItemType & value)const
{
	if (pos < 0 || pos >= m_size)
		return false;
	value = m_data[pos];
	return true;
}

bool Sequence::set(int pos, const ItemType & value)
{
	if (pos < 0 || pos >= m_size)
		return false;
	m_data[pos] = value;
	return true;
}

int Sequence::find(const ItemType & value)const
{
	for (int i = 0; i < m_size; i++)
	{
		if (m_data[i] == value)
			return i;
	}
	return -1;
}

void Sequence::swap(Sequence & other)
{
	Sequence temp = *this;
	*this = other;
	other = temp;
}