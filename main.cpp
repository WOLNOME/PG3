#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
bool thread1_done = false, thread2_done = false;

void threadOne() {
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "thread1\n";

    // thread2 を動かす
    unique_lock<mutex> lock(mtx);
    thread1_done = true;
    cv.notify_all();
}

void threadTwo() {
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [] { return thread1_done; });
    cout << "thread2\n";

    // thread3 を動かす
    thread2_done = true;
    cv.notify_all();
}

void threadThree() {
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [] { return thread2_done; });
    cout << "thread3\n";
}

int main() {
    thread th1(threadOne);
    thread th2(threadTwo);
    thread th3(threadThree);

    th1.join();
    th2.join();
    th3.join();

    return 0;
}
