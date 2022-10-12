class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int ans = 0;
        int n = heights.size();
        stack<int> sta;
        int right[n];

        for(int i = 0; i < n; ++i)
        {
            while(!sta.empty() && heights[i] < heights[sta.top()])
            {
                right[sta.top()] = i - 1;
                sta.pop();
            }
            sta.push(i);
        }
        while(!sta.empty())
        {
            right[sta.top()] = n - 1;
            sta.pop();
        }

        int left[n];

        for(int i = n - 1; i >= 0; --i)
        {
            while(!sta.empty() && heights[i] < heights[sta.top()])
            {
                left[sta.top()] = i + 1;
                sta.pop();
            }
            sta.push(i);
        }
        while(!sta.empty())
        {
            left[sta.top()] = 0;
            sta.pop();
        }
        for(int i = 0; i < n; ++i)
        {
            ans = max(ans, heights[i] * (right[i] - left[i] + 1));
        }



        
        return ans;
    }
};