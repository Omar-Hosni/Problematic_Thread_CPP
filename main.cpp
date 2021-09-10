#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void sleep_function(int &x) {
	while (true) {
			cout << x << endl;
			this_thread::sleep_for(chrono::milliseconds(1000));
	}

}


void detach_function() {
	int x = 5;
	thread T(sleep_function, ref(x));
	T.detach();
	this_thread::sleep_for(chrono::milliseconds(5000));
	cout << "Thread_1 finished execution \n";
}

int main() {
	
	//problematic logic
	//we are joining a thread that contains a detach thread
	//which will cause the detach wanting to continue executing
	//while the join thread has already stopped
	thread T(detach_function);
	T.join();

}
