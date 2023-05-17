#include <atomic>

class spinMutex
{
private:
    std::atomic<bool> flag;
public:
    spinMutex()
        :
        flag(false)
    {}

    void lock()
    {
        for(;;)
        {
            if(!flag.exchange(true, std::memory_order_acquire))
                break;
            while(flag.load(std::memory_order_relaxed))
            {
                ;
            }
        }
    }

    void unlock()
    {
        flag.store(false, std::memory_order_release);
    }

};

class spinLock
{
public:
	spinLock(spinMutex& mtx) : mutex_(mtx) { mutex_.lock(); }
	spinLock(const spinLock&) = delete;
	spinLock& operator=(const spinLock&) = delete;
	~spinLock() { mutex_.unlock(); }

private:
	spinMutex& mutex_;
};

void func(int& num)
{
    for(int i = 0; i < 100000000; ++i)
    {
        ++num;
    }
}

spinMutex spinmutex;
void funcWithSpinLock(int& num)
{
    for(int i = 0; i < 100000000; ++i)
    {
        spinLock spinLock(spinmutex);
        ++num;
    }
}

#include <mutex>
std::mutex mutex_;
void funcWithMutex(int& num)
{
    for(int i = 0; i < 100000000; ++i)
    {
        std::lock_guard<std::mutex> lockGuard(mutex_);
        ++num;
    }
}

#include <thread>
#include <iostream>
#include <chrono>
using namespace std;

int main(int argc, char const *argv[])
{
    
    int a = 0;
    std::thread thr1(func, std::ref(a));
    std::thread thr2(func, std::ref(a));
    thr1.join();
    thr2.join();
    cout << a << endl;

    auto start1 = std::chrono::high_resolution_clock::now();

    a = 0;
    std::thread thr3(funcWithSpinLock, std::ref(a));
    std::thread thr4(funcWithSpinLock, std::ref(a));
    thr3.join();
    thr4.join();
    cout << a << endl;

    std::cout<<std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start1).count() << std::endl;
    start1 = std::chrono::high_resolution_clock::now();

    a = 0;
    std::thread thr5(funcWithMutex, std::ref(a));
    std::thread thr6(funcWithMutex, std::ref(a));
    thr5.join();
    thr6.join();
    cout << a << endl;

    std::cout<<std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start1).count() << std::endl;

    return 0;
}
