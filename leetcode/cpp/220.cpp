// 线段树
// 偏序


typedef pair<long long, int> plli;

class Solution {
public:

    int* segMentTree = nullptr;

    void updateTree(int treeIndex, int left, int right, int index, int val)
    {
        if(left == right && left == index)
        {
            segMentTree[treeIndex] = val;
            return ;
        }
        else if(left > index || right < index)
            return ;

        int mid = (left + right) >> 1;
        int leftIndex = 2 * treeIndex + 1;
        int rightIndex = 2 * treeIndex + 2;
        updateTree(leftIndex, left, mid, index, val);
        updateTree(rightIndex, mid + 1, right, index, val);
        segMentTree[treeIndex] = segMentTree[leftIndex] + segMentTree[rightIndex];
    }

    int querySum(int treeIndex, int left, int right, int queryLeft, int queryRight)
    {
        if(queryLeft <= left && right <= queryRight)
            return segMentTree[treeIndex];
        else if(queryLeft > right || queryRight < left)
            return 0;
        int mid = (left + right) >> 1;
        int leftIndex = 2 * treeIndex + 1;
        int rightIndex = 2 * treeIndex + 2;
        int ret = querySum(leftIndex, left, mid, queryLeft, queryRight);
        ret += querySum(rightIndex, mid + 1, right, queryLeft, queryRight);
        return ret;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        
        int n = nums.size();
        vector<plli> arr(n);

        segMentTree = (int*)malloc(sizeof(int) * 4 * n);
        memset(segMentTree, 0, sizeof(int) * 4 * n);

        for(int i = 0; i < n; ++i)
        {
            arr[i] = make_pair(nums[i], i);
        }
        sort(arr.begin(), arr.end());

        int numLeftIndex = 0;

        for(int i = 0; i < n; ++i)
        {   
            long long num = arr[i].first;
            int index = arr[i].second;

            while(numLeftIndex < i && num > arr[numLeftIndex].first + valueDiff)
            {
                updateTree(0, 0, n - 1, arr[numLeftIndex].second ,0);
                ++numLeftIndex;
            }
            
            int queryLeft = max(index - indexDiff, 0);
            int queryRight = min(index + indexDiff, n - 1);
            if(querySum(0, 0, n - 1, queryLeft, queryRight))
                return true;

            updateTree(0, 0, n - 1, index, 1);
        }

        return false;
    }
};