class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        int n = arr.size();
        int rightMin[n + 1];
        rightMin[n] = INT_MAX;
        for(int i = n - 1; i >= 0; --i)
            rightMin[i] = min(rightMin[i + 1], arr[i]);

        int ans = 0;
        int chunkMax = -1;
        for(int i = 0; i < n; ++i)
        {
            chunkMax = max(chunkMax, arr[i]);
            if(chunkMax <= rightMin[i + 1])
            {
                ++ans;
                chunkMax = -1;
            }
        }

        return ans;
    }
};