class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int n = plantTime.size();
        pair<int, int> arr[n];
        for(int i = 0; i < n; ++i)
            arr[i] = make_pair(growTime[i], plantTime[i]);

        sort(arr, arr + n, greater<pair<int, int>>());

        int ans = 0;
        int pre = 0;
        for(int i = 0; i < n; ++i)
        {
            pre += arr[i].second;
            ans = max(ans, pre + arr[i].first);
        }

        return ans;

    }
};