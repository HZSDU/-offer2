/*
Compiling environment: VS2015
Date:2019-4-6
User:HanSir
*/
/*
��Ŀ:��ά�����еĲ���
��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
*/
#include <iostream>
#include <vector>
using namespace std;

bool Find(int target, vector<vector<int> > array);
int main()
{
	int target = 0; 
	//vector<vector<int> > array = { {1, 2, 8, 9},{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	//vector<vector<int> > array = { { 1 },{ 2 },{ 4 },{ 6} };
	vector<vector<int> > array = { { 1, 2, 8, 9 }};
	bool r = Find(target, array);
	if (r == true)
		cout << "I find the number " << target << "."<< endl;
	else
		cout << "Sorry, I cannot find it." << endl;
	return 0;
	
}

bool Find(int target, vector<vector<int> > array) {
	int lineNum = array.size();
	int columnNum = array[0].size();
	int i = lineNum - 1;
	int j = 0;
	while (i >= 0 && j <= columnNum - 1)
	{
		if (target == array[i][j])
			return true;
		if (target > array[i][j])
			j++;
		else
			i--;
	}
	return false;
}