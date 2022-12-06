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

    int createSortedArray(vector<int>& instructions) {

        int n = *max_element(instructions.begin(), instructions.end());
        segMentTree = (int*)malloc(sizeof(int) * 4 * (n + 1));
        memset(segMentTree, 0, sizeof(int) * 4 * (n + 1));

        long long ans = 0;
        for(int num : instructions)
        {
            int smaller = querySum(0, 0, n, 0, num - 1);
            int bigger = querySum(0, 0, n, num + 1, n);
            ans += min(smaller, bigger);
            updateVal(0, 0, n, num);
        }

        int mod = 1e9 + 7;
        return ans % mod;
    }
};