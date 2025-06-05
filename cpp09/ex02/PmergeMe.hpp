#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>
# include "CustomIterator.hpp"

//class PmergeMe
//{
//	public :

//		PmergeMe();
//		PmergeMe(const PmergeMe& src);
//		PmergeMe& operator=(const PmergeMe& src);
//		~PmergeMe();
		
//	private :

//	std::vector<int>	vectint;
//	std::list<int>	listint;
//};

int jacobsthal(int n);

std::vector<int> jacobsthal_order(size_t size);

//template <typename Iterator>

//void FJMI(CustomIterator<Iterator> first, CustomIterator<Iterator> last, size_t size)
//{
//	if (size <= 1)
//		return;
//	typedef typename std::iterator_traits<CustomIterator>::value_type T;
//	std::vector< std::pair<T, T> > recursive;
//	Iterator it = first;
//	bool has_odd = false;
//	T odd;

//	while(it != last)
//	{
//		Iterator next = it;
//		next++;
//		if (next != last)
//		{
//			if (*it < *next)
//				recursive.push_back(std::make_pair(*it, *next));
//			else
//				recursive.push_back(std::make_pair(*next, *it));
//			it = ++next;
//		}
//		else
//		{
//			has_odd = true;
//			odd = *it;
//			++it;
//		}
//	}
//	FJMI(CustomIterator(recursive.begin()), CustomIterator(recursive.end()), recursive.size());
//	std::vector<T> main;
//	for (size_t i = 0; i < recursive.size(); i++)
//		main.push_back(recursive[i].second);
//	for (size_t i = 0; i < recursive.size(); i++)
//	{
//		Iterator pos = std::lower_bound(main.begin(), main.end(),recursive[i].first);
//		main.insert(pos, recursive[i].first);
//	}
//	if (has_odd)
//	{
//		Iterator pos = std::lower_bound(main.begin(), main.end(), odd);
//		main.insert(pos, odd);
//	}
//	std::copy(main.begin(), main.end(), first);
//}

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

#endif