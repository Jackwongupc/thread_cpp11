#ifndef SWAP_THREAD_H__
#define SWAP_THREAD_H__

#include <iostream>
#include <thread>
#include <chrono>

void foo() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
 }

void bar() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
 }

class SwapThread {
 public:
  void run() {
    std::thread t1(&SwapThread::foo, this);
    std::thread t2(&SwapThread::bar, this);

    std::cout << "thread 1 id: " << t1.get_id() << std::endl;
    std::cout << "thread 2 id: " << t2.get_id() << std::endl;
 
    std::swap(t1, t2);
 
    std::cout << "after std::swap(t1, t2):" << std::endl;
    std::cout << "thread 1 id: " << t1.get_id() << std::endl;
    std::cout << "thread 2 id: " << t2.get_id() << std::endl;
 
    t1.swap(t2);
 
    std::cout << "after t1.swap(t2):" << std::endl;
    std::cout << "thread 1 id: " << t1.get_id() << std::endl;
    std::cout << "thread 2 id: " << t2.get_id() << std::endl;
 
    t1.join();
    t2.join();    
  }

 public:
  void foo() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  void bar() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }


 };

#endif
