#include <memory>
#include <mutex>

namespace DoubleCheck
{
    class Singleton
    {
    private:
        Singleton() {};
        static std::unique_ptr<Singleton> instance_;
        static std::mutex mutex_;
    public:
        static Singleton* getInstance();
    };

    Singleton* Singleton::getInstance()
    {
        if(instance_.get() == nullptr)
        {
            std::lock_guard<std::mutex> lockGuard(mutex_);
            if(instance_.get() == nullptr)
            {
                instance_.reset(new Singleton());
            }
        }
        return instance_.get();
    }

    std::unique_ptr<DoubleCheck::Singleton> DoubleCheck::Singleton::instance_;
    std::mutex DoubleCheck::Singleton::mutex_;
}

#include <atomic>
namespace AtomicFixReorder
{
    class Singleton
    {
    private:
        Singleton() {};
        static std::atomic<Singleton*> instance_;
        static std::mutex mutex_;

    public:
        static Singleton* getInstance();
    };

    Singleton* Singleton::getInstance()
    {
        Singleton* tmp = instance_.load(std::memory_order_acquire);
        if(tmp == nullptr)
        {
            std::lock_guard<std::mutex> lockGuard(mutex_);
            tmp = instance_.load(std::memory_order_relaxed);
            if(tmp == nullptr)
            {
                tmp = new Singleton();
                instance_.store(tmp, std::memory_order_release);
            }
        }
        return tmp;
    }

    std::atomic<Singleton*> AtomicFixReorder::Singleton::instance_;
    std::mutex AtomicFixReorder::Singleton::mutex_;
}


#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	DoubleCheck::Singleton* s1 = DoubleCheck::Singleton::getInstance();
	DoubleCheck::Singleton* s2 = DoubleCheck::Singleton::getInstance();
	if(s1 == s2)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

    AtomicFixReorder::Singleton* s3 = AtomicFixReorder::Singleton::getInstance();
    AtomicFixReorder::Singleton* s4 = AtomicFixReorder::Singleton::getInstance();
    if(s3 == s4)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	return 0;
}

