// 315. 计算右侧小于当前元素的个数
// to be improve 归并排序
class Solution {
public:
    int* segMentTree = nullptr;

    // void buildTree(int treeIndex, int left, int right, vector<int>& nums)
    // {
    //     if(left == right)
    // }
    void updateTree(int treeIndex, int left, int right, int updateIndex)
    {

        printf("%d %d %d\n", left, right, updateIndex);
        if(left == updateIndex && right == updateIndex)
        {
            ++segMentTree[treeIndex];
            return ;
        }
        else if(left > updateIndex || right < updateIndex)
            return ;

        int leftIndex = 2 * treeIndex + 1;
        int rightIndex = 2 * treeIndex + 2;
        int mid = (left + right) >> 1;

        updateTree(leftIndex, left, mid, updateIndex);
        updateTree(rightIndex, mid + 1, right, updateIndex);
        segMentTree[treeIndex] = segMentTree[leftIndex] + segMentTree[rightIndex];
        return ;
    }

    int queryTree(int treeIndex, int left, int right, int queryLeft, int queryRight)
    {
        if(queryLeft <= left && right <= queryRight)
            return segMentTree[treeIndex];
        else if(left > queryRight || right < queryLeft)
            return 0;

        int leftIndex = 2 * treeIndex + 1;
        int rightIndex = 2 * treeIndex + 2;
        int mid = (left + right) >> 1;

        int ret = queryTree(leftIndex, left, mid, queryLeft, queryRight);
        ret += queryTree(rightIndex, mid + 1, right, queryLeft, queryRight);
        return ret;
    }
    vector<int> countSmaller(vector<int>& nums) 
    {

        int add = 10000;
        int maxx = 0;
        for(int& num : nums)
        {
            num += add;
            maxx = max(maxx, num);
        }

        int n = nums.size();
        segMentTree = (int*)malloc(sizeof(int) * 4 * maxx);
        memset(segMentTree, 0, sizeof(int) * 4 * maxx);


        vector<int> ans(n);
        for(int i = n - 1; i >= 0; --i)
        {
            ans[i] = queryTree(0, 0, maxx, 0, nums[i] - 1);
            updateTree(0, 0, maxx, nums[i]);
            printf("%d\n", segMentTree[0]);
        }

        return ans;
    }
};