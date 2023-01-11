// 直方图的水量

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        if(n == 0)
            return 0;

        int left = 0;
        int right = n - 1;
        int rightMax = height[right];
        int leftMax = height[left];

        int ans = 0;
        while(left != right)
        {
            if(leftMax < rightMax)
            {
                ++left;
                if(leftMax > height[left])
                    ans += leftMax - height[left];
                else
                    leftMax = height[left];
            }
            else
            {
                --right;
                if(rightMax > height[right])
                    ans += rightMax - height[right];
                else
                    rightMax = height[right];
            }
        }

        return ans;
    }
};