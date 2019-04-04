#ifndef __SINGLENTON_H
#define __SINGLENTON_H

//懒汉模式
#include <iostream>
class Singleton 
{
private:	
	Singleton() { std::cout << "哈哈，我被创建了" << std::endl; }
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

