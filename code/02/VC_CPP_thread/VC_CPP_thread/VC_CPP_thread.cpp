// VC_CPP_thread.cpp : �w�q�D���x���ε{�����i�J�I�C
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
	// �N������J queue
	q1.push(x);
	cout << "This is the first thread " << x << endl;
}
void Pause()
{
	printf("Press Enter key to continue�K");
	fgetc(stdin);
}

int main()
{
	thread first_thread(first_thread_job, 2);
	first_thread.join();
	// �Ǧ^���C���Ĥ@�Ӥ����A�èS���N�������簣���C
	int a = q1.front();
	cout << "The first element is " << a << endl;
	q1_size = q1.size();
	cout << "The queue1 length is " << q1_size << endl;
	// �u�X��C���Ĥ@�Ӥ���
	q1.pop();
	q1_size = q1.size();
	cout << "The queue2 length is " << q1_size << endl;
	Pause();
	return 0;

}
