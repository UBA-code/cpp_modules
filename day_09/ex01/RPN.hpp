#pragma once
#include "iostream"
#include "stack"
#include "cstring"
#include "cstdlib"
#include <stdexcept>


#define isOperator(c) (c == '+' || c == '-' || c == '*' || c == '/')
void	parseArray(std::string &s);
void    rpn(std::string &s);

