//多线程

class FizzBuzz {
private:
    int n;
    int i = 1;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(i <= n)
        {
            if(i % 3 == 0 && i % 5 != 0)
            {
                printFizz();
                ++i;
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(i <= n)
        {
            if(i % 5 == 0 && i % 3 != 0)
            {
                printBuzz();
                ++i;
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(i <= n)
        {
            if(i % 5 == 0 && i % 3 == 0)
            {
                printFizzBuzz();
                ++i;
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(i <= n)
        {
            cout<<i<<" "<<n<<endl;
            if(i % 5 != 0 && i % 3 != 0)
            {
                printNumber(i);
                ++i;
            }
        }
    }
};