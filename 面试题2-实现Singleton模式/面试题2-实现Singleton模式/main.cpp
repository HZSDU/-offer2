#if 0
//singleton�ࣺ���߳̿���
#include <iostream>
#include "singleton.h"
using namespace std;

//HANDLE hMutex = CreateMutex(nullptr, FALSE, "Demo");
int main()
{
	Singleton *s1 = Singleton::getInstance();
	cout << s1 << endl;
	Singleton *s2 = Singleton::getInstance();
	cout << s2 << endl;
	system("pause");
	return 0;
	
}
#endif

#if 0
//singleton�ࣺ���̲߳�����
#include <iostream>
#include "singleton.h"
#include <thread>
using namespace std;

void threadfun()
{
	Singleton *s = Singleton::getInstance();	
	cout << "���߳�:" << s << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
}

int main()
{
	thread th(threadfun);
	th.detach();
	Singleton *s1 = Singleton::getInstance();
	cout << "���߳�:" << s1 << endl;
	std::this_thread::sleep_for(std::chrono::seconds(5));
}
#endif

#if 1
//SingletonThread�ࣺ���߳̿���
#include <iostream>
#include "singletonthread.h"
#include <thread>
using namespace std;

void threadfun()
{
	SingletonThread  *s = SingletonThread::getinstance();
	cout << "���߳�:" << s << endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
}

int main()
{
	thread th(threadfun);
	th.detach();
	SingletonThread *s1 = SingletonThread::getinstance();
	cout << "���߳�:" << s1 << endl;
	std::this_thread::sleep_for(std::chrono::seconds(5));
}


#endif