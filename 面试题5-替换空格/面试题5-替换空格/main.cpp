/*
Compiling environment: VS2015
Date:2019-4-6
Author:HanSir
*/
/*
题目:替换空格
	请实现一个函数，把字符串中的每个空格替换成“%20”。例如：当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/
#include <iostream>
#include <string>
using namespace std;
void replaceSpace(char *&str, int length);

#define MAX_INPUT 256
int main()
{
	char *s = new char[MAX_INPUT + 1];
	cin.getline(s, MAX_INPUT);
	replaceSpace(s, strlen(s));
	cout << s << endl;
}

void replaceSpace(char *&str, int length)
{
	int count = 0;
	int j = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ' ')
			count++;
	}
	char *s = new char[length + 2 * count + 1];
	for (int i = 0; i < length; i++)
	{
		if (str[i] != ' ')
		{
			s[j] = str[i];
			j++;
		}
		else
		{
			s[j] = '%';
			s[j + 1] = '2';
			s[j + 2] = '0';
			j += 3;
		}
	}
	s[j] = '\0';
	str = s;
}
