class Solution {
public:
    int* segMentTree = nullptr;
    int querySum(int treeIndex, int left, int right, int queryLeft, int queryRight)
    {
        if(queryLeft <= left && right <= queryRight)
            return segMentTree[treeIndex];
        else if(left > queryRight || right < queryLeft)
            return 0;
        int mid = (left + right) >> 1;
        int treeLeft = 2 * treeIndex + 1;
        int treeRight = 2 * treeIndex + 2;
        return querySum(treeLeft, left, mid, queryLeft, queryRight) + 
                querySum(treeRight, mid + 1, right, queryLeft, queryRight);
    }

    void updateVal(int treeIndex, int left, int right, int updateIndex)
    {
        if(left == right && updateIndex == left)
        {
            ++segMentTree[treeIndex];
            return ;
        }
        else if(left > updateIndex || right < updateIndex)
            return ;

        int mid = (left + right) >> 1;
        int treeLeft = 2 * treeIndex + 1;
        int treeRight = 2 * treeIndex + 2;
        updateVal(treeLeft, left, mid, updateIndex);
        updateVal(treeRight, mid + 1, right, updateIndex);
        segMentTree[treeIndex] = segMentTree[treeLeft] + segMentTree[treeRight];
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int mapping[n];
        for(int i = 0; i < n; ++i)
            mapping[nums1[i]] = i;

        segMentTree = (int*)malloc(sizeof(int) * 4 * n);
        memset(segMentTree, 0, sizeof(int) * 4 * n);

        updateVal(0, 0, n - 1, mapping[nums2[0]]);

        long long ans = 0;
        for(int i = 1; i < n; ++i)
        {
            int num = mapping[nums2[i]];
            int lessCnt = querySum(0, 0, n - 1, 0, num - 1);
            updateVal(0, 0, n - 1, num);
            int greaterCnt = (n - num - 1 - (i - lessCnt));
            ans += 1ll * lessCnt * greaterCnt;
        }

        return ans;


    }
};