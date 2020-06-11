#include <iostream>
#include <boost/thread.hpp>
#include <thread>
#include <stdio.h>

void foo() {
    printf("Hello from foo \n");
}

int main() {
    boost::thread thread1(foo);
    thread1.join();
    printf("Hello from main \n");
    return 0;
}