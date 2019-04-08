/*
Compiling environment: VS2015
Date:2019-4-6
Author:HanSir
*/
/*
题目:找出数组中重复的数字（允许改变直接改变原数组）
	在一个长度为 n 的数组里的所有数字都在 0 - n~1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字
重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2， 3， 1， 0， 2， 5， 3}， 那么对应的输出的重复地数字
2或者3。
*/

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int>> FindRepetitiveNumber(vector<int>, int);

int main()
{
	int len;
	cin >> len;
	vector<int> test(len);
	for (int i = 0; i < len; i++)
		cin >> test[i];
	vector<pair<int, int>> result = FindRepetitiveNumber(test, len);
	for (auto c : result)
	{
		cout << "数字 "<< c.first << " 出现 " << c.second << " 次" << endl;
	}
	return 0;
}

vector<pair<int, int>> FindRepetitiveNumber(vector<int> inputArray, int length)
{
	vector<pair<int, int>> result;
	for (int i = 0; i < inputArray.size(); i++)
	{
		if (inputArray[i] < 0 || inputArray[i] > length - 1)
		{
			cout << "Error：输入有错, 请仔细阅读题目!" << endl;
			return result;
		}		
	}
	int repetitiveNum = 0;
	int repetitiveTimes = 1;
	bool flag = false;
	for (int i = 0; i < length; i++)
	{
		while (inputArray[i] != i)
		{
			int j = inputArray[i];
			if (inputArray[i] == inputArray[j])
			{
				for (int j = 0; j < result.size(); j++)
				{
					if (result[j].first == inputArray[i])
					{
						flag = true;
						result[j].second++;
						break;
					}
				}
				if (flag == true)
				{
					flag = false;
					break;
				}					
				repetitiveNum = inputArray[i];
				repetitiveTimes = 2;
				result.push_back(make_pair(repetitiveNum,repetitiveTimes));
				break;
			}
			else
			{
				int temp = inputArray[i];
				inputArray[i] = inputArray[j];
				inputArray[j] = temp;
			}
		}
	}
	return result;
}
