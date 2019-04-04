#ifndef __SINGLENTON_H
#define __SINGLENTON_H

//����ģʽ
#include <iostream>
class Singleton 
{
private:	
	Singleton() { std::cout << "�������ұ�������" << std::endl; }
	static Singleton *instance;
public:
	static Singleton *getInstance();
};

Singleton *Singleton::instance = nullptr;
Singleton *Singleton::getInstance()
{
	if (instance == nullptr)
		instance = new Singleton();
	return instance;
}
#endif // !__SINGLENTON

