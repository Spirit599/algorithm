// 1724 · 环形子数组的最大和

class Solution {
public:
    /**
     * @param a: the array
     * @return: Maximum Sum Circular Subarray
     */
    int maxSubarraySumCircular(vector<int> &a) {
        
        int sum = 0;
        int maxx = -0x7fffffff;
        int cur_max = 0;
        int minn = 0x7fffffff;
        int cur_min = 0;
        int n = a.size();
        for(int i = 0; i < n; ++i)
        {
            sum += a[i];

            if(cur_max < 0)
                cur_max = 0;
            cur_max += a[i];
            maxx = max(maxx, cur_max);

            if(cur_min > 0)
                cur_min = 0;
            cur_min += a[i];
            minn = min(minn, cur_min);
        }

        if(minn != sum)
            return max(maxx, sum - minn);
        else
            return maxx;

    }
};