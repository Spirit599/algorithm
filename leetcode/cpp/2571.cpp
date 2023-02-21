class Solution {
public:
    int minOperations(int n) {
        
        int lb = n & -n;
        if(lb == n)
            return 1;
        return min(minOperations(n + lb), minOperations(n - lb)) + 1;
    }
};