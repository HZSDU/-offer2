#ifndef __SINGLETONTHREAD_H
#define __SINGLETONTHREAD_H

#include <mutex>
#include <thread>
#include <iostream>
using namespace std;
mutex mu;//定义互斥量
class SingletonThread 
{
private:
	SingletonThread() { cout << "哈哈，我被创建了！" << endl; }
	static SingletonThread *instance;
public:
	static SingletonThread *getinstance();
};

SingletonThread *SingletonThread::instance = nullptr;
SingletonThread *SingletonThread::getinstance()
{
	if (instance == NULL)
	{
		mu.lock();
		if (instance == NULL)
			instance = new SingletonThread();
		mu.unlock();
	}
	return instance;
}
#endif // !__SINGLETONTHREAD_H

