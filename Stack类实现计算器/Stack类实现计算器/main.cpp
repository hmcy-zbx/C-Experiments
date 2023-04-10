#include<iostream>
#include"stack.h"
using namespace std;

string GetSuffix(string s, stack s1);
int GetPri(char ch);
int GetResult(string str ,stack s);
int main() 
{
	while (true)
	{
		stack s1;//s1字符栈
		string OriEqu;//创建字符串存储原表达式
		cout << "请输入您想要计算的式子：（以“=”结尾）";
		cin >> OriEqu;
		string Equ = GetSuffix(OriEqu, s1);//获取后缀表达式
		stack s2;
		int result = GetResult(Equ, s2);//获取计算结果
		cout << "该式子结果为：" << result;
		cout << "请问是否还要继续:(Y/N)" << endl;
		char ch;
		cin >> ch;
		if (ch == 'N') 
		{
			return 0;
		}
	};
	return 0;
}

string GetSuffix(string OriEqu, stack s1)
{
	int i = 0;
	string str;//后缀表达式
	while (OriEqu.at(i) != '=')  //遍历全部字符,运算符压栈，数字进入字符串
	{
		char ch = OriEqu.at(i);
		if (isdigit(ch))//判断是不是数字
		{
			//进入字符串
			str += ch;
		}
		else //分各种情况入栈
		{
			if (ch == '(') //左括号直接入栈
			{
				s1.push(ch);
			}
			else if (ch == ')') //右括号需要找到左括号
			{
				while ( !s1.isempty() && s1.gettop() != '(' )
				{
					str += s1.pop();//没找到左括号之前的全部运算符出栈
				}
				if (s1.isempty())//检测之前是否存在左括号
				{
					cout << "括号不匹配！！！" << endl;
					return "";
				}
				s1.pop();//左括号出栈
			}
			else if (GetPri(ch) == 2)
			{
				//*/优先级高，可以直接入栈
				while (s1.isempty() != true && s1.gettop() != '(' && GetPri(ch) == GetPri(s1.gettop()))//不为空并且最顶端不是左括号
				{
					s1.pop();
				}
				s1.push(ch);//将当前运算符入栈
			}
			else if(GetPri(ch) ==1)
			{
				//+-优先级低，需要把等级高的都出栈自己才能入栈
				while (!s1.isempty() && s1.gettop() != '(' && GetPri(ch) <= GetPri(s1.gettop()))
				{
					str += s1.pop();
				}
				s1.push(ch);
			}
			else 
			{
				cout << "表达式包含非法字符！" << endl;
				return "";
			}
		}
		i++;
	}
	while (s1.isempty() != true)
	{	
		if (s1.gettop() == '(')
        {
            cout << "括号不匹配！" << endl;
            return "";
        }
		str += s1.pop();
	}
	s1.clearstack();
	return str;
}

int GetResult(string str,stack s1) 
{
	int len = str.size();
	int i = 1;
	//由于传递过来的是后缀表达式，第一个字符一定是数字,直接压栈
	int number = str.at(0) - '0';
	s1.push(number);
	while (i < len)
	{
		char ch = str.at(i);
		if (isdigit(ch)) // 判断是否为数字
		{
			int num = ch - '0';
			s1.push(num);
		}
		else if (ispunct(ch)) // 判断是否为运算符
		{
			int num2 = s1.pop();
			int num1 = s1.pop();
			switch (ch)
			{
			case '+':
				s1.push(num1 + num2);
				break;
			case '-':
				s1.push(num1 - num2);
				break;
			case '*':
				s1.push(num1 * num2);
				break;
			case '/':
				if (num2 == 0)
				{
					cout << "除0错误" << endl;
					return 0;
				}
				s1.push(num1 / num2);
				break;
			default:
				cout << "错误的操作" << endl;
				return 0;
			}
		}
		i++;
	}
	return s1.pop();
}

int GetPri(char ch) 
{
	int level = 0;//优先级
	switch (ch)
	{
	case '+':
	case '-':
		level = 1;
		break;
	case '*':
	case '/':
		level = 2;
		break;
	default:
		break;
	}
	return level;
}