#include <iostream>
#include <thread>
using namespace std;

void first_thread_job()
{
	cout << "This is the first thread " << endl;
}
// �ǤJstring x
void second_thread_job(string x)
{
	cout << "This is the second thread "<< x << endl;
}
void Pause()
{
	printf("Press Enter key to continue�K");
	fgetc(stdin);
}
int main()
{
	// �إ߰����
	thread first_thread(first_thread_job);
	thread second_thread(second_thread_job, "10");
	// �N�D������Ȱ��A���ݫ��w�����������
	first_thread.join();
	second_thread.join();
	Pause();
	return 0;
}
