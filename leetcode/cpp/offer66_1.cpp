class Solution {
public:
    vector<int> constructArr(vector<int>& a) {

        int n = a.size();

        vector<int> ans(n, 1);

        int pre = 1;
        for (int i = 1; i < n; ++i)
        {
            pre *= a[i - 1];
            ans[i] *= pre;
        }

        int suf = 1;
        for (int i = n - 2; i >= 0; --i)
        {
            suf *= a[i + 1];
            ans[i] *= suf;
        }

        return ans;
    }
};