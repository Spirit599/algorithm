class Solution {
public:
    int trap(vector<int>& height) {

    	int n = height.size();
        vector<int> stk;

        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            while(!stk.empty() && height[stk.back()] <= height[i])
            {
                int midIdx = stk.back();
                stk.pop_back();
                if(stk.empty())
                    break;
                int leftIdx = stk.back();
                int depth = min(height[leftIdx], height[i]) - height[midIdx];
                int width = i - leftIdx - 1;
                // printf("%d %d %d %d %d\n",leftIdx,midIdx,i,depth,width);
                ans += depth * width;
            }
            stk.push_back(i);
        }
        return ans;
    }
};