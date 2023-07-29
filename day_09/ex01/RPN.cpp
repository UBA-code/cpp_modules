#include "RPN.hpp"

void	ft_error(const std::string s)
{
	std::cout << s;
	exit (EXIT_FAILURE);
}

void	parseArray(std::string &s)
{
	int		operatorCount = 0;
	int		numbersCount = 0;

	for (int i = 0; i < (int)s.size(); i++)
	{
		for (; i < (int)s.size() && s[i] == ' '; i++);
		if (isdigit(s[i]) || (s[i] == '-' && isdigit(s[i + 1])))
		{
			numbersCount++;
			if (s[i] == '-')
				i++;
		}
		else if (isOperator(s[i]) && (s[i + 1] == ' ' || !s[i + 1]))
			operatorCount++;
		else
			ft_error("Invalid syntax: " + s.substr(i) + "\n");
	}
	if (operatorCount != numbersCount - 1)
		ft_error("the operators not equal to (numbers - 1)\n");
}

int	rpn(std::string &s)
{
	int				n1;
	int				n2;
	std::list<int> stack;

	parseArray(s);
	for (int i = 0; i < (int)s.size(); i++)
	{
		for (; i < (int)s.size() && s[i] == ' '; i++);
		if (isdigit(s[i]) || (s[i] == '-' && isdigit(s[i + 1])))
		{
			if (s[i] == '-')
				stack.push_back(atoi(s.substr(i, 2).c_str()));
			else
				stack.push_back(atoi(s.substr(i, 1).c_str()));
			if (s[i] == '-')
				i++;
		}
		else if (isOperator(s[i]))
		{
			if (stack.size() < 2)
				ft_error("Syntax error detected\n");
			n2 = stack.back();
			stack.pop_back();
			n1 = stack.back();
			stack.pop_back();
			switch (s[i])
			{
				case '+':
					stack.push_back(n1 + n2);
					break;
				case '-':
					stack.push_back(n1 - n2);
					break;
				case '*':
					stack.push_back(n1 * n2);
					break;
				case '/':
					stack.push_back(n1 / n2);
					break;
				default:
					break;
			}
		}
	}
	std::cout << stack.back() << "\n";
	return (1);
}


//* "8 9 * 9 - 9 - 9 - 4 - 1 +"