#include "RPN.hpp"

int main(int argc, char **argv)
{	
	try
	{
		RPN rpn;
		if (argc != 2)
			throw BadArguments();
		rpn.calculate(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}