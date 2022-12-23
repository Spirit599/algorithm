class Solution {
public:
    int* segMentTree = nullptr;
    void buildTree(vector<int>& arr, int treeIndex, int left, int right) {

        if(left == right)
        {
            segMentTree[treeIndex] = arr[left];
            return ;
        }

        int mid = (left + right) >> 1;
        int treeLeft = 2 * treeIndex + 1;
        int treeRight = 2 * treeIndex + 2;
        buildTree(arr, treeLeft, left, mid);
        buildTree(arr, treeRight, mid + 1, right);
        segMentTree[treeIndex] = segMentTree[treeLeft] & segMentTree[treeRight];
    }

    int queryVal(int treeIndex, int left, int right, int queryLeft, int queryRight) {

        if(queryLeft <= left && right <= queryRight)
            return segMentTree[treeIndex];

        int mid = (left + right) >> 1;
        int treeLeft = 2 * treeIndex + 1;
        int treeRight = 2 * treeIndex + 2;
        if(queryRight <= mid)
            return queryVal(treeLeft, left, mid, queryLeft, queryRight);
        if(queryLeft > mid)
            return queryVal(treeRight, mid + 1, right, queryLeft, queryRight);
        return queryVal(treeLeft, left, mid, queryLeft, queryRight) & queryVal(treeRight, mid + 1, right, queryLeft, queryRight);
    }
    int closestToTarget(vector<int>& arr, int target) {

        
        int n = arr.size();
        segMentTree = (int*)malloc(sizeof(int) * 4 * n);
        memset(segMentTree, 0, sizeof(int) * 4 * n);

        buildTree(arr, 0, 0, n - 1);

        int ll = 0;
        int rr = 0;
        int ans = INT_MAX;
        while(rr < n)
        {
            int req = queryVal(0, 0, n - 1, ll, rr);
            if(req < target)
                rr = max(++ll, rr);
            else
                ++rr;
            ans = min(ans, abs(req - target));
        }

        return ans;





    }
};