// VC_CPP_thread.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <iostream>
#include <thread>
#include <queue>
using namespace std;

queue<int> q1;
queue<int>::size_type q1_size;

void first_thread_job(int x)
{
	// 將元素放入 queue
	q1.push(x);
	cout << "This is the first thread " << x << endl;
}
void Pause()
{
	printf("Press Enter key to continue…");
	fgetc(stdin);
}

int main()
{
	thread first_thread(first_thread_job, 2);
	first_thread.join();
	// 傳回隊列的第一個元素，並沒有將此元素剔除隊列
	int a = q1.front();
	cout << "The first element is " << a << endl;
	q1_size = q1.size();
	cout << "The queue1 length is " << q1_size << endl;
	// 彈出對列的第一個元素
	q1.pop();
	q1_size = q1.size();
	cout << "The queue2 length is " << q1_size << endl;
	Pause();
	return 0;

}
