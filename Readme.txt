C++ 11 thread[WINDOWS/LINUX]

資料來源: https://medium.com/@chingi071/%E5%A4%9A%E5%9F%B7%E8%A1%8C%E7%B7%92-c-thread-9f6e37c7cf32

C++ 11之後有了std::thread函式庫，需要引入的標頭檔: <thread>

VC++(2015) / CB20.03 支援

gcc g++ 支援c++11編譯的標準和區別
	g++ -g -Wall -std=c++11 main.cpp
	gcc -g -Wall -std=c11 main.cpp	

範例01
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
	
範例02
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

範例03[C++ thread lock 共用變數]
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
		std::this_thread::sleep_for(std::chrono::seconds(intData-1));
		cout << "thread  " << intData <<" finish..."<< endl;
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
