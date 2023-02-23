class Solution {
public:
    vector<int> circularPermutation(int n, int start) {

        vector<int> ans;

        ans.push_back(0);
        for(int i = 0; i < n; ++i)
        {
            int m = ans.size();
            for(int j = m - 1; j >= 0; --j)
            {
                ans.push_back(ans[j] | (1 << i));
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {

        vector<int> ans;

        int len = (1 << n);
        for(int i = 0; i < len; ++i)
        {
            ans.push_back(i ^ (i >> 1) ^ start);
        }

        return ans;
    }
};