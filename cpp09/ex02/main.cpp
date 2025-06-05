#include "PmergeMe.hpp"

void FJMI(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	size_t size = std::distance(first, last);
	if (size <= 1)
		return;
	std::vector<int> larger;
	larger.reserve(size/2 + 1);
	std::vector<int> smaller;
	std::vector<int>::iterator it = first;

	while(it != last)
	{
		std::vector<int>::iterator next = it;
		++next;
		if (next != last)
		{
			if (*it < *next)
			{
				larger.push_back(*next);
				smaller.push_back(*it);
			}
			else
			{
				larger.push_back(*it);
				smaller.push_back(*next);
			}
			it = ++next;
		}
		else
		{
			smaller.push_back(*it);
			++it;
		}
	}
	FJMI(larger.begin(), larger.end());
	std::vector<int> order = jacobsthal_order(smaller.size());
	std::vector<int>::iterator index;
	for (index = order.begin(); index != order.end(); index++)
	{
		std::vector<int>::iterator pos = std::lower_bound(larger.begin(), larger.end(),smaller[*index]);
		larger.insert(pos, smaller[*index]);
	}
	std::copy(larger.begin(), larger.end(), first);
}

int main()
{

	std::vector<int> lst;
	lst.push_back(5);
	lst.push_back(7);
	lst.push_back(9);
	lst.push_back(78);
	lst.push_back(45);
	lst.push_back(13);
	lst.push_back(17);

	std::cout << "Before : ";
	std::vector<int>::iterator it;
	for(it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';

	FJMI(lst.begin(), lst.end());

	std::cout << "After : ";
	for(it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << ' ';
}


//int main()
//{
//	std::vector<int> test = jacobsthal_order(10);

//	std::vector<int>::iterator it;
//	for (it = test.begin(); it != test.end(); it++)
//	{
//		std::cout << *it << " ";
//	}
//}