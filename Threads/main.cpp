#include <iostream>
#include <thread>

//This function will be called from a thread

void call_from_thread() {
  std::cout << "Hello, World from Thread!" << std::endl;
}

int main() {
  //Launch a thread
  std::thread t1(call_from_thread);
    for(int i=0; i<10; i++)
        std::cout << "Hello, World!" << std::endl;
  //Join the thread with the main thread
  t1.join();
  return 0;
}
