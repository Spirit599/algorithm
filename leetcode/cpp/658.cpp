class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {


        auto cmp = [&](int a, int b){
            int aa = abs(x - a);
            int bb = abs(x - b);
            if(aa != bb)
                return aa > bb;
            else
                return a > b;
        };

        priority_queue<int, vector<int>, decltype(cmp)> pq(arr.begin(), arr.end(), cmp);

        vector<int> ans;
        while(k--)
        {
            ans.push_back(pq.top());
            pq.pop();
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};