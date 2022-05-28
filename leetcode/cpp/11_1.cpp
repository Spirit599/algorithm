class Solution {
public:
    int maxArea(vector<int>& height) {

        int low = 0;
        int high = height.size() - 1;
        long long ret = 0;

        while(low != high)
        {
            long long cur = (long long)(high - low) * min(height[low], height[high]);
            if(cur > ret)
            {
                ret = cur;
            }

            if(height[low] < height[high])
                low++;
            else
                high--;
        }

        return ret;
    }
};