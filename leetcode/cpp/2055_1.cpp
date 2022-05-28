//二分 还可前缀和

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        
        vector<int> arr;
        for(int i = 0; i < s.size(); ++i)
            if(s[i] == '|')
                arr.push_back(i);


        vector<int> ans;
        for(auto vec : queries)
        {
            int left = vec[0];
            int right = vec[1];
            auto start = lower_bound(arr.begin(), arr.end(), left);
            auto end = upper_bound(arr.begin(), arr.end(), right);

            if(start == arr.end() || end == arr.begin())
            {
                ans.push_back(0);
                continue;
            }

            --end;

            int anss = *end - *start - 1 - (end - start - 1);

            anss = max(anss, 0);
            ans.push_back(anss);

        }

        return ans;
    }
};