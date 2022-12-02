class Solution {
public:
    unordered_map<int, int> memo;
    int minDays(int n) {

        // printf("%d\n", n);

        if(n <= 1)
            return n;

        auto it = memo.find(n);
        if(it != memo.end())
            return it->second;

        return memo[n] = min(n % 2 + 1 + minDays(n / 2), n % 3 + 1 + minDays(n / 3));
    }
};