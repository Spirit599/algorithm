// 378. 有序矩阵中第 K 小的元素
// 二分
typedef pair<int, int> pii;

class Solution {
public:

    bool check(int mid, vector<vector<int>>& matrix, int k, int n) 
    {
        int i = n - 1;
        int j = 0;
        int cnt = 0;

        while(i >= 0)
        {
            while(j < n && matrix[i][j] <= mid)
                ++j;
            cnt += j;
            if(cnt >= k)
                return true;
            --i;
        }

        return false;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();
        int high = matrix[n - 1][n - 1];
        int low = matrix[0][0];

        while(high != low)
        {
            int mid = (high + low) >> 1;
            if(check(mid, matrix, k, n))
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