// 2407. 最长递增子序列 II

class Solution {
public:
    int* segMentTree = nullptr;
    //vector<int> segMentTree;
    void modify(int treeIndex, int left, int right, int updateIndex, int val) {

        if(left == updateIndex && right == updateIndex)
        {
            segMentTree[treeIndex] = val;
            return ;
        }
        else if(left > updateIndex || right < updateIndex)
        {
            return ;
        }

        int leftIndex = 2 * treeIndex;
        int rightIndex = 2 * treeIndex + 1;
        int mid = (left + right) >> 1;
        modify(leftIndex, left, mid, updateIndex, val);
        modify(rightIndex, mid + 1, right, updateIndex, val);

        segMentTree[treeIndex] = max(segMentTree[leftIndex], segMentTree[rightIndex]);
    }

    int query(int treeIndex, int left, int right, int queryLeft, int queryRight)
    {
        if(queryLeft <= left && right <= queryRight)
            return segMentTree[treeIndex];
        else if(queryLeft > right || queryRight < left)
            return 0;
        
        int ret = 0;
        int mid = (left + right) >> 1;
        int leftIndex = 2 * treeIndex;
        int rightIndex = 2 * treeIndex + 1;

        ret = query(leftIndex, left, mid, queryLeft, queryRight);
        ret = max(ret, query(rightIndex, mid + 1, right, queryLeft, queryRight));

        return ret;
    } 
    int lengthOfLIS(vector<int>& nums, int k) {
        
        int n = *max_element(nums.begin(), nums.end());
        segMentTree = (int*)malloc(sizeof(int) * 4 * n);
        memset(segMentTree, 0, sizeof(int) * 4 * n);

        for(int num : nums)
        {

            if(num == 1) {
                modify(1, 1, n, 1, 1);
            }
            else {
                int ret = query(1, 1, n, max(num - k, 1), num - 1);
                modify(1, 1, n, num, ret + 1);
            }
        }

        return segMentTree[1];
    }


};