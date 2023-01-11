class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        priority_queue<int> pq;
        int ans = 0;
        int n = arr.size();
        for(int i = 0; i < n; ++i)
        {
            pq.push(arr[i]);
            if(pq.top() == i)
                ++ans;
        }
        return ans;
    }
};