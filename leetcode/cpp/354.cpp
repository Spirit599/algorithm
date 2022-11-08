// 最长上升子序列

class Solution {
public:
    int* segMentTree = nullptr;
    int queryMax(int treeIndex, int left, int right, int queryLeft, int queryRight)
    {
        if(queryLeft <= left && right <= queryRight)
            return segMentTree[treeIndex];
        else if(queryLeft > right || queryRight < left)
            return 0;
        int mid = (left + right) >> 1;
        int leftIndex = 2 * treeIndex + 1;
        int rightIndex = 2 * treeIndex + 2;
        int ret = queryMax(leftIndex, left, mid, queryLeft, queryRight);
        ret = max(ret, queryMax(rightIndex, mid + 1, right, queryLeft, queryRight));
        return ret;
    }
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
        segMentTree[treeIndex] = max(segMentTree[leftIndex], segMentTree[rightIndex]);
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {

        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& v1, const vector<int>& v2) {

            if(v1[0] != v2[0])
                return v1[0] < v2[0];
            else
                return v1[1] > v2[1]; 
        });
        int ans = 0;

        int maxHi = 0;
        for(auto& vec : envelopes)
            maxHi = max(maxHi, vec[1]);

        int n = maxHi + 1;
        segMentTree = (int*)malloc(sizeof(int) * 4 * (n + 1));
        memset(segMentTree, 0, sizeof(int) * 4 * (n + 1));

        for(auto& vec : envelopes)
        {
            int hi = vec[1];
            int queryRet = queryMax(0, 0, n, 0, hi - 1);
            updateTree(0, 0, n, hi, queryRet + 1);
            ans = max(ans, queryRet + 1);
        }

        return ans;
    }
};