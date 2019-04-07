/*
Compiling environment: VS2015
Date:2019-4-6
User:HanSir
*/
/*
��Ŀ:�ҳ��������ظ������֣�����ı�ֱ�Ӹı�ԭ���飩
	��һ������Ϊ n ����������������ֶ��� 0 - n~1 �ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ������
�ظ��˼��Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7������{2�� 3�� 1�� 0�� 2�� 5�� 3}�� ��ô��Ӧ��������ظ�������
2����3��
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
		cout << "���� "<< c.first << " ���� " << c.second << " ��" << endl;
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
			cout << "Error�������д�, ����ϸ�Ķ���Ŀ!" << endl;
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