#include "RPN.hpp"

int	isNum(const char *s, int check)
{
	int	i = 0;
	for (; s[i] && s[i] != ' '; i++)
	{
		if (((s[i] == '+' || s[i] == '-') && !isnumber(s[i + 1])) || !isnumber(s[i]))
			return (0);
	}
	if (check && s[i] == ' ')
		return (0);
	return (1);
}

// int	operator_count(std::string &s)
// {
// 	int count = 0;
// 	for (int i = 0; i < s.size(); i++)
// 		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
// 			count++;
// 	return (count);
// }

// int	numbers_count(std::string &s)
// {
// 	int count = 0;
// 	for (int i = 0; i < s.size(); i++)
// 	{
// 		if ((s[i] == '+' || s[i] == '-') && isdigit(s[i]))
// 			for (; s[i] != ' ' && ; i++);
// 			count++;
// 	}
// 	return (count);
// }

// void	parseArray(std::string &s)
// {
// 	char	*s = strtok(const_cast<char *>(s.c_str()), " ");
// 	int		operatorCount = 0;
// 	int		numbersCount = 0;
// 	while  (s)
// 	{
// 		if ()
// 	}
// }

char	getNextOperator(const char *s)
{
	int i = 0;
	for (; s[i]; i++)
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
			return (s[i]);
	return (-1);
}

void	rpn(std::string &s)
{
	int				n1;
	int				n2;
	// int				tmp;
	std::stack<int> stack;
	char			operat;
	for (int i = 0; i < (int)s.size(); i++)
	{
		std::cout << s.c_str() + i << " ===> rest of string\n";
		for (; i < (int)s.size() && s[i] == ' '; i++);
		if (isNum(s.c_str() + i, 0))
		{
			std::cout << atoi(s.c_str() + i) << " pushed to stack\n";
			stack.push(atoi(s.c_str() + i));
		}
		for (; i < (int)s.size(); i++)
			if (((s[i] == '+' || s[i] == '-') && !isdigit(s[i + 1])) || !isnumber(s[i]))
				break;
		if (stack.size() >= 2)
		{
			operat = getNextOperator(s.c_str() + i);
			if (operat == -1)
				break; ;
			switch (operat)
			{
				case '+':
					n1 = stack.top();
					stack.pop();
					n2 = stack.top();
					stack.pop();
					stack.push(n2 + n1);
					break;
				case '-':
					n1 = stack.top();
					stack.pop();
					n2 = stack.top();
					stack.pop();
					stack.push(n2 - n1);
					break;
				case '/':
					n1 = stack.top();
					stack.pop();
					n2 = stack.top();
					stack.pop();
					stack.push(n2 / n1);
					break;
				case '*':
					n1 = stack.top();
					stack.pop();
					n2 = stack.top();
					stack.pop();
					stack.push(n2 * n1);
					break;
				default:
					break;
			}
		}
	}
	std::cout << stack.top() << "\n";
}


//* "8 9 * 9 - 9 - 9 - 4 - 1 +"