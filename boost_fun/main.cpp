/**
 * @file main.cpp
 * @author George Murray
 * @brief 
 * @version 0.1
 * @date 2019-06-19
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>

/**
 * @brief make the current thread sleep for specified amount of time
 * 
 * @param seconds number of seconds to make the current thread sleep for
 */
void wait(int seconds)
{
    boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
}

/**
 * @brief Creates 5 threads and waits one second
 * 
 */
void thread()
{
    for (int i = 0; i < 5; ++i)
    {
        wait(1);
        std::cout << i << '\n';
    }
}

int main(int argc, char const *argv[])
{
    boost::thread t{thread};
    t.join();
    return 0;
}
