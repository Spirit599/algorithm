class Solution {
public:
    int minimumNumbers(int num, int k) {
        
        if(num == 0)
            return 0;

        for(int i = 1; i <= num; ++i)
        {
            int sum = i * k;
            if(sum % 10 == num % 10 && sum <= num)
                return i;
        }
        return -1;
    }
};