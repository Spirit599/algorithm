class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

    	int n = heights.size();
    	int left[n];
    	memset(left, -1, sizeof(left));
    	int right[n];
    	memset(right, -1, sizeof(right));

    	vector<int> upStk;
    	for(int i = 0; i < n; ++i)
    	{
    		while(!upStk.empty() && heights[upStk.back()] > heights[i])
    		{
    			right[upStk.back()] = i;
    			upStk.pop_back();
    		}
    		if(!upStk.empty())
    			left[i] = upStk.back();
    		upStk.emplace_back(i);
    	}

    	int ans = 0;
    	for(int i = 0; i < n; ++i)
    	{
    		if(right[i] == -1)
    			right[i] = n;
    		// printf("%d %d\n", left[i], right[i]);
    		ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
    	}

    	return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix[0].size();
        vector<int> arr(n);
        int ans = 0;

        for(auto& v : matrix)
        {
        	for(int i = 0; i < n; ++i)
        	{
        		if(v[i] == '0')
        			arr[i] = 0;
        		else
        			++arr[i];
        	}
        	ans = max(ans, largestRectangleArea(arr));
        }
        return ans;
    }
};