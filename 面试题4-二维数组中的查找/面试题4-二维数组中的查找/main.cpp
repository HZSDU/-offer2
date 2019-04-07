/*
Compiling environment: VS2015
Date:2019-4-6
User:HanSir
*/
/*
题目:二维数组中的查找
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
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