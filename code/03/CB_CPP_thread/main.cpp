#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

/*
std::this_thread::sleep_for(std::chrono::seconds(5)); // sleep 5 ¬í(seconds)
std::this_thread::sleep_for(std::chrono::milliseconds(5)); // sleep 5 ²@¬í(milliseconds)
std::this_thread::sleep_for(std::chrono::microseconds(5)); // sleep 5 ·L¬í(microseconds)
std::this_thread::sleep_for(std::chrono::nanoseconds(5)); // sleep 5 ¯Ç¬í(nanoseconds)

*/
mutex mu;
int gintCount = 0;
void thread_job(int intData)
{
	mu.lock();
	gintCount += intData;
	std::this_thread::sleep_for(std::chrono::seconds(intData-1));
	cout << "thread  " << intData <<" finish..."<< endl;
	mu.unlock();
}
void Pause()
{
	printf("Press Enter key to continue¡K");
	fgetc(stdin);
}

int main()
{
	thread cthread[10];

	cout << "gintCount is " << gintCount << endl;
	for (int i = 0; i < 10; i++)
	{
		cthread[i] = thread(thread_job, i+1);
	}
	for (int i = 0; i < 10; i++)
	{
		cthread[i].join();
	}
	cout << "gintCount is " << gintCount << endl;
	Pause();
	return 0;

}
