class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        
        int n = flowers.size();
        vector<int> bloom(n);
        vector<int> fallen(n);
        for(int i = 0; i < n; ++i)
        {
            bloom[i] = flowers[i][0];
            fallen[i] = flowers[i][1] + 1;
        }
        sort(bloom.begin(), bloom.end());
        sort(fallen.begin(), fallen.end());

        int m = persons.size();
        vector<int> ans(m);
        for(int i = 0; i < m; ++i)
        {
            auto it1 = upper_bound(bloom.begin(), bloom.end(), persons[i]);
            auto it2 = upper_bound(fallen.begin(), fallen.end(), persons[i]);
            int n1 = (it1 - bloom.begin());
            int n2 = (it2 - fallen.begin());
            ans[i] = n1 - n2;
        }
        return ans;
    }
};