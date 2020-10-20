// VC_CPP_thread.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

/*
std::this_thread::sleep_for(std::chrono::seconds(5)); // sleep 5 秒(seconds)
std::this_thread::sleep_for(std::chrono::milliseconds(5)); // sleep 5 毫秒(milliseconds)
std::this_thread::sleep_for(std::chrono::microseconds(5)); // sleep 5 微秒(microseconds)
std::this_thread::sleep_for(std::chrono::nanoseconds(5)); // sleep 5 納秒(nanoseconds)

*/
mutex mu;
int gintCount = 0;
void thread_job(int intData)
{
	mu.lock();
	gintCount += intData;
	std::this_thread::sleep_for(std::chrono::seconds(intData - 1));
	cout << "thread  " << intData << " finish..." << endl;
	mu.unlock();
}
void Pause()
{
	printf("Press Enter key to continue…");
	fgetc(stdin);
}

int main()
{
	thread cthread[10];

	cout << "gintCount is " << gintCount << endl;
	for (int i = 0; i < 10; i++)
	{
		cthread[i] = thread(thread_job, i + 1);
	}
	for (int i = 0; i < 10; i++)
	{
		cthread[i].join();
	}
	cout << "gintCount is " << gintCount << endl;
	Pause();
	return 0;

}
