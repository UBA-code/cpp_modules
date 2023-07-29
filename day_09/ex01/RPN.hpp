#pragma once
#include "iostream"
#include "list"
#include "cstring"


#define isOperator(c) (c == '+' || c == '-' || c == '*' || c == '/')
void	parseArray(std::string &s);
int     rpn(std::string &s);

