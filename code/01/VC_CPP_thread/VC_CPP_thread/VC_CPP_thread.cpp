// VC_CPP_thread.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <iostream>
#include <thread>
using namespace std;

void first_thread_job()
{
	cout << "This is the first thread " << endl;
}
// 傳入string x
void second_thread_job(int x)
{
	cout << "This is the second thread ";
	cout << x;
	cout << endl;
}
void Pause()
{
	printf("Press Enter key to continue…");
	fgetc(stdin);
}
int main()
{
	// 建立執行緒
	thread first_thread(first_thread_job);
	thread second_thread(second_thread_job, 10);
	// 將主執行緒暫停，等待指定的執行緒結束
	first_thread.join();
	second_thread.join();
	Pause();
	return 0;
}
