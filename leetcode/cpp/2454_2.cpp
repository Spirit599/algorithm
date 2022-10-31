// 线段树二分
// 偏序第k大
typedef pair<int, int> pii;

class Solution {
public:
    int *segMentTree = nullptr;
    void update(int treeIndex, int left, int right, int index, int addVal)
    {
        if(left == right && left == index)
        {
            segMentTree[treeIndex] += addVal;
            return ;
        }
        else if(left > index || right < index)
            return ;

        int mid = (left + right) >> 1;
        int leftIndex = 2 * treeIndex + 1;
        int rightIndex = 2 * treeIndex + 2;
        update(leftIndex, left, mid, index, addVal);
        update(rightIndex, mid + 1, right, index, addVal);
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
        int ret = querySum(leftIndex, left ,mid, queryLeft, queryRight);
        ret += querySum(rightIndex, mid + 1, right, queryLeft, queryRight);
        return ret;
    }
    int queryIndex(int treeIndex, int left, int right, int sum)
    {
        if(left == right && segMentTree[treeIndex] == sum)
            return right;

        int mid = (left + right) >> 1;
        int leftIndex = 2 * treeIndex + 1;
        int rightIndex = 2 * treeIndex + 2;

        int leftSum = segMentTree[leftIndex];
        if(leftSum >= sum)
            return queryIndex(leftIndex, left, mid, sum);
        else
            return queryIndex(rightIndex, mid + 1, right, sum - leftSum);
    }
    vector<int> secondGreaterElement(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n, -1);
        set<int> st;
        int k = 2;


        vector<pii> arr;
        for(int i = 0; i < n; ++i)
            arr.push_back(make_pair(-nums[i], i));
        sort(arr.begin(), arr.end());

        segMentTree = (int*)malloc(sizeof(int) * 4 * n);
        memset(segMentTree, 0, sizeof(int) * 4 * n);

        for(int i = 0; i < n; ++i)
        {
            int index = arr[i].second;

            int sum = querySum(0, 0, n - 1, 0, index);
            int allSum = segMentTree[0];
            if(allSum < sum + k)
                ans[index] = -1;
            else
                ans[index] = nums[queryIndex(0, 0, n - 1, sum + k)];
            
            update(0, 0, n - 1, index, 1);
        }

        return ans;
    }
};