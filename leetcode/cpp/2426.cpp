class Solution {
public:
    int* segMentTree = nullptr;
    int query(int treeIndex, int left, int right, int queryLeft, int queryRight)
    {
        if(queryLeft <= left && right <= queryRight)
            return segMentTree[treeIndex];
        else if(left > queryRight || right < queryLeft)
            return 0;
        int mid = (left + right) >> 1;
        int treeLeft = 2 * treeIndex + 1;
        int treeRight = 2 * treeIndex + 2;
        int ret = query(treeLeft, left, mid, queryLeft, queryRight);
        ret += query(treeRight, mid + 1, right, queryLeft, queryRight);
        return ret;
    }
    void update(int treeIndex, int left, int right, int updateIndex)
    {
        if(updateIndex == left && updateIndex == right)
        {
            ++segMentTree[treeIndex];
            return ;
        }
        else if(left > updateIndex || right < updateIndex)
            return ;

        int mid = (left + right) >> 1;
        int treeLeft = 2 * treeIndex + 1;
        int treeRight = 2 * treeIndex + 2;
        update(treeLeft, left, mid, updateIndex);
        update(treeRight, mid + 1, right, updateIndex);
        segMentTree[treeIndex] = segMentTree[treeLeft] + segMentTree[treeRight];
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        
        int n = nums1.size();
        int arr[n];
        int minn = INT_MAX;
        int maxx = INT_MIN;
        for(int i = 0; i < n; ++i)
        {
            arr[i] = nums1[i] - nums2[i];
            minn = min(minn, arr[i]);
            maxx = max(maxx, arr[i]);
        }

        if(minn < 0)
        {
            for(int i = 0; i < n; ++i)
                arr[i] -= minn;
            maxx -= minn;
        }


        segMentTree = (int*)malloc(sizeof(int) * (4 * maxx + 1));
        memset(segMentTree, 0, sizeof(int) * (4 * maxx + 1));
        printf("%d\n", maxx);

        long long ans = 0;
        for(int i = 0; i < n; ++i)
        {

            ans += query(0, 0, maxx, 0, min(maxx, arr[i] + diff));
            update(0, 0, maxx, arr[i]);
        }
        return ans;

    }
};