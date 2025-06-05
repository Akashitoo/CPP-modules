#include "PmergeMe.hpp"

//PmergeMe::PmergeMe(){}
//PmergeMe::PmergeMe(const PmergeMe& src){(void)src;}
//PmergeMe& PmergeMe::operator=(const PmergeMe& src){(void)src;return(*this);}
//PmergeMe::~PmergeMe(){}

int jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n-1) + 2 * jacobsthal(n-2));
}

std::vector<int> jacobsthal_order(size_t size)
{
	std::vector<int> order;
	for (size_t i = 0; i < size; i++)
	{
		size_t idx = jacobsthal(i);
		if (idx > size)
			break;
		if (std::find(order.begin(), order.end(), idx) == order.end())
			order.push_back(idx);
	}
	size_t i = 0;
	int idx = 0;
	size_t limit = size - order.size();
	while (i < limit)
	{
		if (std::find(order.begin(), order.end(), idx) == order.end())
		{
			order.push_back(idx);
			i++;	
		}
		idx++;
	}
	return (order);
}

//void FJMI(std::vector<int>::iterator first, std::vector<int>::iterator last)
//{
//	size_t size = std::distance(first, last);
//	if (size < 2)
//		return;
//	std::vector<int> larger;
//	std::vector<std::pair<int, std::vector<int>::iterator> > smaller;
//	std::vector<int>::iterator it;
//	int odd;
//	for (it = first; it != last; it++)
//	{
//		std::vector<int>::iterator next = it;
//		++next;
//		if (next != last)
//		{
//			if (*it < *next)
//			{
//				larger.push_back(*next);
//				smaller.push_back(std::make_pair(*it, larger.end()-1));
//			}
//			else
//			{
//				larger.push_back(*it);
//				smaller.push_back(std::make_pair(*next, larger.end()-1));
//			}
//			it = ++next;
//		}
//		else
//		{
//			//smaller.push_back(*it, NULL);
//			odd = *it;
//			++it;
//		}
//	}
//	FJMI(larger.begin(), larger.end());
//	std::vector<std::pair<int, std::vector<int>::iterator> >::iterator insert;
//	for (insert = smaller.begin(); insert != smaller.end(); insert++)
//	{
//		std::vector<int>::iterator pos = std::lower_bound(larger.begin(), insert->second, insert->first);
//		larger.insert(pos, insert->first);
//	}
//	std::vector<int>::iterator pos = std::lower_bound(larger.begin(),larger.end(), odd);
//	larger.insert(pos, odd);
//	std::copy(larger.begin(), larger.end(), first);
//}