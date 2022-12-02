class Solution {
public:
    string smallestGoodBase(string n) {

        long long num = stol(n);
        int maxm = log(num) / log(2);
        // printf("%d\n", maxm);
        for(int i = maxm; i > 1; --i)
        {
            int k = pow(num, 1.0 / i);
            long long sum = 1;
            long long cur = 1;
            for(int j = 0; j < i; ++j)
            {
                cur *= k;
                sum += cur;
            }

            // printf("%d %d %lld\n", i,k,sum);

            if(sum == num)
                return to_string(k);
        }

        return to_string(num - 1);

    }
};