#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>
# include <cstring>
# include <cstdlib>

class RPN
{
	public :

		RPN();
		RPN(const RPN& src);
		RPN& operator=(const RPN& src);
		~RPN();

		void calculate(char *argv);
	
	private :
		std::stack<int> calcul;
		std::stack<int> resultat;

		class InputInvalid: public std::exception
		{
			public :
				virtual const char*  what() const throw()
				{
					return ("Input invalid ! Only digits and operators are accepted");
				}
		};

		class BadOperator: public std::exception
		{
			public :
				virtual const char*  what() const throw()
				{
					return ("Too many operators or expression beginning with an operator !\n =>Make sure that for n digits there are n - 1 operators and expression beginning with a digits.");
				}
		};

		class TooManyDigits: public std::exception
		{
			public :
				virtual const char*  what() const throw()
				{
					return ("Too many digits !\n => Make sure that for n digits there are n - 1 operators and expression beginning with a digits.");
				}
		};
};

class BadArguments: public std::exception
{
	public :
		virtual const char*  what() const throw()
		{
			return ("Bad arguments !\n => ./RPN <expression> ");
		}
};

#endif