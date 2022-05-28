class Solution {
public:
    /**
     * @param target: the target
     * @param array: an array
     * @return: the closest value
     */
    int closestTargetValue(int target, vector<int> &array) {
        
        sort(array.begin(), array.end());

        int maxx = -(0x3f3f3f3f);
        int start = 0;
        int end = array.size() - 1;

        while(start != end)
        {
            int sum = array[start] + array[end];

            if(sum > target)
            {
                --end;
            }
            else if(sum < target)
            {
                maxx = max(maxx, sum);
                ++start;
            }
            else
            {
                return target;
            }
        }

        if(maxx != -(0x3f3f3f3f))
            return maxx;
        else
            return -1;
    }
};