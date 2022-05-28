class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();

        stack<int> st;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
        {
            while(!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                int cur = st.top();
                st.pop();
                ans[cur] = (i - cur);
            }
            st.push(i);
        }

        return ans;
    }
};