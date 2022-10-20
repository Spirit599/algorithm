class Solution {
public:
    int uniquePaths(int m, int n) {

        --m;--n;
        long long ans = 1;
        int x = m + n;
        int y = min(m, n);
        int i = 1;
        int j = x - y + 1;
        while(i <= y) {
            ans *= j++;
            ans /= i++;
        }
        return ans;
    }
};