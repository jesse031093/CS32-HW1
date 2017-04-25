#include "ScoreList.h"

ScoreList::ScoreList()
{
	
}

bool ScoreList::add(ItemType score)
{
	if (score < 0 || score > 100 || m_s.size() >= DEFAULT_MAX_ITEMS)
		return false;
	m_s.insert(score);
	return true;
}

bool ScoreList::remove(ItemType score)
{
	int p = m_s.find(score);
	if (p == -1)
		return false;
	m_s.erase(p);
	return true;
}

int ScoreList::size()const
{
	return m_s.size();
}

ItemType ScoreList::minimum()const
{
	if (!m_s.size())
		return NO_SCORE;
	ItemType m;
	m_s.get(0, m);
	return m;
}

ItemType ScoreList::maximum()const
{
	if (!m_s.size())
		return NO_SCORE;
	ItemType M;
	m_s.get(m_s.size() - 1, M);
	return M;
}