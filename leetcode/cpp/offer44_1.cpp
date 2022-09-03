class Solution {
public:
    int findNthDigit(int n) {

        if(n < 10)
            return n;

        long long base = 9;
        long long index = 1;
        long long bits = 1;


        while(n >= base * bits)
        {
            n = n - base * bits;
            ++bits;
            base = base * 10;
        }

        int kth = (n - 1) / bits;
        int kkth = (n - 1) % bits;
        cout<<kth<<" "<<kkth<<endl;

        return getting(base / 9 + kth, bits - kkth - 1);

    }

    int getting(int num, int kth)
    {
        cout<<num<<" "<<kth<<endl;
        if(kth == 0)
            return num % 10;
        else
            return num / (int)(pow(10, kth)) % 10;
    }
};