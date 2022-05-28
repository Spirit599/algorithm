//最小栈

class Solution {
public:
    /**
     * @param arr: the height of all buildings
     * @return: how many buildings can he see at the location of each building
     */
    vector<int> tallBuilding(vector<int> &arr) {
        // Write your code here.

        int n = arr.size();
        vector<int> ans(n, 1);

        stack<int> st;
        for(int i = 0; i < n; ++i)
        {
            ans[i] += st.size();

            while(!st.empty() && arr[i] >= st.top())
                st.pop();

            st.push(arr[i]);
        }

        st = stack<int>();
        for(int i = n - 1; i >= 0; --i)
        {
            ans[i] += st.size();

            while(!st.empty() && arr[i] >= st.top())
                st.pop();

            st.push(arr[i]);
        }

        return ans;
    }
};