// 85. 最大矩形

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {



    	int m = matrix.size();
    	int n = matrix[0].size();

    	vector<vector<int>> arr(m, vector<int>(n));
    	for(int i = 0; i < m; ++i)
    	{
    		for(int j = 0; j < n; ++j)
    		{
    			arr[i][j] = matrix[i][j] - '0';
    		}
    	}

    	for(int i = 1; i < m; ++i)
    	{
    		for(int j = 0; j < n; ++j)
    		{
    			if(arr[i][j] == 1)
    				arr[i][j] = arr[i - 1][j] + 1;
    		}
    	}

    	int ans = 0;
    	for(int i = 0; i < m; ++i)
    		ans = max(ans, largestRectangleArea(arr[i]));


    	return ans;
    }

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        
        int left[n];
        stack<int> sta;
        for(int i = 0; i < n; ++i)
        {
            
            while(!sta.empty() && heights[sta.top()] >= heights[i])
            {
                sta.pop();
            }
            if(!sta.empty())
                left[i] = sta.top() + 1;
            else
                left[i] = 0;
            
            sta.push(i);
        }

        int right[n];
        stack<int> sta1;
        for(int i = n - 1; i >= 0; --i)
        {
            while(!sta1.empty() && heights[sta1.top()] >= heights[i])
            {
                sta1.pop();
            }
            if(!sta1.empty())
                right[i] = sta1.top() - 1;
            else
                right[i] = n - 1;

            sta1.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; ++i)
            ans = max(ans, heights[i] * (right[i] - left[i] + 1));

        return ans;

    }
};