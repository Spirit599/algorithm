#include <numeric>

class Solution {
public:
    /**
     * @param arr: an array of non-negative integers
     * @return: minimum number of elements
     */
    int minElements(vector<int> &arr) {
        // write your code here

        int sum = accumulate(arr.begin(), arr.end(), 0);

        priority_queue<int, vector<int>, less<int>> pq(arr.begin(), arr.end());

        int cur_sum = 0;
        int ans = 0;
        while(!pq.empty())
        {
            int cur = pq.top();
            cur_sum += cur;
            ++ans;

            if(cur_sum > sum - cur_sum)
                break;
        }

        return ans;

    }
};