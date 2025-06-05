#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN& src){(void) src;}

RPN& RPN::operator=(const RPN& src){(void) src; return(*this);}

bool isoperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int aoperatorb(int a, int b, char op)
{
	if (op == '+')
		return( a + b);
	else if (op == '-')
		return (a - b);
	else if (op == '*')
		return (a * b);
	else
		return (a / b);
}

void RPN::calculate(char* argv)
{
	int i = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
		{
			i++;
			continue;
		}
		if (std::isdigit(argv[i]))
		{
			if (argv[i + 1] == ' ' || argv[i + 1] == '\0')
				this->resultat.push(argv[i] - 48);
			else
				throw InputInvalid();
		}
		else if (isoperator(argv[i]))
		{
			if (this->resultat.empty())
				throw BadOperator();
			int a = this->resultat.top();
			this->resultat.pop();
			if (this->resultat.empty())
				throw BadOperator();
			int b = this->resultat.top();	
			this->resultat.pop();
			this->resultat.push(aoperatorb(b,a,argv[i]));
		}
		else
			throw InputInvalid();
		i++;
	}
	if (this->resultat.size() > 1)
		throw TooManyDigits();
	std::cout << this->resultat.top();
}

