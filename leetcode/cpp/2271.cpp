class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        
        sort(tiles.begin(), tiles.end());
        int n = tiles.size();

        long long pre[n + 1];
        pre[0] = 0;
        for(int i = 0; i < n; ++i)
            pre[i + 1] = pre[i] + tiles[i][1] - tiles[i][0] + 1;

        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            int start = tiles[i][0];
            int end = start + carpetLen - 1;
            int longestIndex = binarySearch(i, n - 1, end, tiles);
            
            int preSum = pre[longestIndex] - pre[i];
            int suffix = min(end, tiles[longestIndex][1]) - tiles[longestIndex][0] + 1;
            printf("%d %d\n", preSum, suffix);
            ans = max(ans, preSum + suffix);
        }
        return ans;
    }

    int binarySearch(int low, int high, int end, vector<vector<int>>& tiles) {

        while(low != high)
        {

            int mid = (low + high + 1) >> 1;
            //printf("%d %d %d\n", low, high, mid);
            if(end >= tiles[mid][0])
                low = mid;
            else
                high = mid - 1;
        }
        return low;
    }
};