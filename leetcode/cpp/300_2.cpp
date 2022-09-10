// 300. 最长递增子序列

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> ret;
        for(int num : nums)
        {
            int index = find_index(num, ret);
            if(index != ret.size())
                ret[index] = num;
            else
                ret.push_back(num);
        }


        return ret.size();
    }

    int find_index(int num, vector<int>& ret) {

        int low = 0;
        int high = ret.size();

        while(low != high) 
        {
            
            int mid = (high - low) / 2 + low;
            if(ret[mid] > num) 
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }

        }

        return low;
    }
};