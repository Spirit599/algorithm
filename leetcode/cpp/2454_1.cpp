// 有序列表
// nlogn 试k大小而定
typedef pair<int, int> pii;

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n, -1);
        set<int> st;


        vector<pii> arr;
        for(int i = 0; i < n; ++i)
            arr.push_back(make_pair(-nums[i], i));
        sort(arr.begin(), arr.end());

        for(int i = 0; i < n; ++i)
        {
            int index = arr[i].second;
            auto it = st.upper_bound(index);
            if(it == st.end() || ++it == st.end())
                ans[index] = -1;
            else
                ans[index] = nums[*it];

            st.insert(index);
        }

        return ans;
    }
};