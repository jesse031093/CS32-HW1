#include "Sequence.h"

Sequence::Sequence():m_size(0)
{

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
	if (pos < 0 || pos > m_size || m_size >= DEFAULT_MAX_ITEMS)
		return false;
	//move every element after pos-th element one space backward
	//starting from the last element
	for (int i = m_size - 1; i >= pos; i--)
		m_data[i + 1] = m_data[i];
	m_data[pos] = value;
	m_size++;
	return true;
}

int Sequence::insert(const ItemType &value)
{
	int pos = 0;
	bool temp = false;	//check if every element is all smaller that value
	//check at what position the element is bigger than value
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
	//insert the value at pos
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
	//in this case, we don't use assignment operator overloading
	if (this->m_size > other.m_size)
	{
		for (int i = 0; i < other.m_size; i++)
		{
			ItemType temp = other.m_data[i];
			other.m_data[i] = this->m_data[i];
			this->m_data[i] = temp;
		}
		for (int i = other.m_size; i < this->m_size; i++)
			other.m_data[i] = this->m_data[i];
	}
	else
	{
		for (int i = 0; i < this->m_size; i++)
		{
			ItemType temp = other.m_data[i];
			other.m_data[i] = this->m_data[i];
			this->m_data[i] = temp;
		}
		for (int i = this->m_size; i < other.m_size; i++)
			this->m_data[i] = other.m_data[i];
	}
	int temp = this->m_size;
	this->m_size = other.m_size;
	other.m_size = temp;
}