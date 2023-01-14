class Solution {
public:
    int trap(vector<int>& height) {

    	int n = height.size();
    	if(n == 0)
    		return 0;
    	int leftMax = height[0];
    	int rightMax = height[n - 1];
    	int left = 0;
    	int right = n - 1;
    	int ans = 0;

    	while(left != right)
    	{
    		if(leftMax < rightMax)
    		{
    			++left;
    			if(height[left] > leftMax)
    				leftMax = height[left];
    			else
    				ans += leftMax - height[left];
    		}
    		else
    		{
    			--right;
    			if(height[right] > rightMax)
    				rightMax = height[right];
    			else
    				ans += rightMax - height[right];
    		}
    	}

    	return ans;
    }
};