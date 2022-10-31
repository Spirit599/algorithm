// 贪心


class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();
        int right[n];
        memset(right, 0, sizeof(right));

        for(int i = 1; i < n; ++i)
        {
            if(ratings[i] > ratings[i - 1])
                right[i] = right[i - 1] + 1;
            else
                right[i] = 0;
        }

        int left[n];
        memset(left, 0, sizeof(left));
        for(int i = n - 2; i >= 0; --i)
        {
            if(ratings[i] > ratings[i + 1])
                left[i] = left[i + 1] + 1;
            else
                left[i] = 0;
        }
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            ans += max(right[i], left[i]) + 1;
            //printf("%d ", right[i]);
        }
        // printf("\n");
        // for(int i = 0; i < n; ++i)
        //     printf("%d ", left[i]);
        // printf("\n");
        return ans;
    }
};