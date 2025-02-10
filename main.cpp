#include <stdio.h>
#include <functional>
#include <thread>

using namespace std;

int main() {
	function<void()> threadOne = [=]() {
		printf("thread1\n");
		};
	function<void()> threadTwo = [=]() {
		printf("thread2\n");
		};
	function<void()> threadThree = [=]() {
		printf("thread3\n");
		};

	thread th1(threadOne);
	thread th2(threadTwo);
	thread th3(threadThree);

	th1.join();
	th2.join();
	th3.join();

	return 0;
}