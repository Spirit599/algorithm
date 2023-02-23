class Solution {
public:
    vector<int> constructArray(int n, int k) {

        int a = 1;
        int b = k + 1;
        vector<int> ans;

        while(ans.size() < k + 1)
        {
            ans.emplace_back(a++);
            if(ans.size() < k + 1)
                ans.emplace_back(b--);
        }
        k += 2;
        while(ans.size() < n)
            ans.emplace_back(k++);
        return ans;
    }
};