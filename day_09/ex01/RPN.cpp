#include "RPN.hpp"

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
			throw (std::logic_error("Invalid syntax: " + s.substr(i)));
		if ((isdigit(s[i]) || isOperator(s[i])) && s[i + 1] && std::string(" 	").find_first_of(s[i + 1]) > 2)
			throw (std::logic_error("Invalid syntax: " + s.substr(i)));
	}
	if (operatorCount != numbersCount - 1)
		throw (std::logic_error("the operators not equal to (numbers - 1)"));
}

void	rpn(std::string &s)
{
	int				n1;
	int				n2;
	std::stack<int> stack;

	s.erase(0, s.find_first_not_of(" 	") > s.length() ? 0 : s.find_first_not_of(" 	"));
	s.erase(s.find_last_not_of(" 	")> s.length() ? s.length() : s.find_last_not_of(" 	") + 1);
	parseArray(s);
	for (int i = 0; i < (int)s.size(); i++)
	{
		for (; i < (int)s.size() && s[i] == ' '; i++);
		if (isdigit(s[i]) || (s[i] == '-' && isdigit(s[i + 1])))
		{
			if (s[i] == '-')
				stack.push(atoi(s.substr(i, 2).c_str()));
			else
				stack.push(atoi(s.substr(i, 1).c_str()));
			if (s[i] == '-')
				i++;
		}
		else if (isOperator(s[i]))
		{
			if (stack.size() < 2)
				throw (std::logic_error("Syntax error detected\n"));
			n2 = stack.top();
			stack.pop();
			n1 = stack.top();
			stack.pop();
			switch (s[i])
			{
				case '+':
					stack.push(n1 + n2);
					break;
				case '-':
					stack.push(n1 - n2);
					break;
				case '*':
					stack.push(n1 * n2);
					break;
				case '/':
					stack.push(n1 / n2);
					break;
				default:
					break;
			}
		}
	}
	std::cout << stack.top() << "\n";
}
