/*
Compiling environment: VS2015
Date:2019-4-1
User:HanSir
*/
/*
题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数
class CMyString
{
public:
		CMyString(char *pData = nullptr);
		CMyString(const CMyString &str);
		~CMyString(void);
private:
		char *m_pData;
};
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class CMyString
{
public:
	CMyString(char *pData = nullptr);
	CMyString(const CMyString &str);
	~CMyString(void);
	//myCode
	CMyString &operator=(const CMyString &str);
	void dispData(void);
private:
	char *m_pData;
};

CMyString::CMyString(char *pData)
{
	m_pData = new char[strlen(pData) + 1];
	strcpy(m_pData, pData);
}

CMyString::CMyString(const CMyString &str)
{
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
	delete[] m_pData;
	m_pData = nullptr;
}

void CMyString::dispData()
{
	cout << m_pData <<endl;
}
//myCode
CMyString &CMyString::operator=(const CMyString &str)
{
	if (this != &str)
	{
		CMyString strTemp(str);
		char *pTemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}
	return *this;
}

int main()
{
	char *pStr = "sdu";
	CMyString str(pStr);
	CMyString str2(str);

	cout << "before '=' operation" << endl;
	str.dispData();
	str2.dispData();
	char *pStr3 = "sduwh";
	CMyString str4(pStr3);
	str = str2 = str4;
	cout << "after '=' operation" << endl;
	str.dispData();
	str2.dispData();
	return 0;
}