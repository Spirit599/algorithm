// 懒标记

class Solution {
public:
    unordered_map<int, int> segMentTree;
    unordered_map<int, int> lazy;

    int queryMax(int treeIndex, int left, int right, int queryLeft, int queryRight)
    {
        if(left > queryRight || right < queryLeft)
            return 0;

        auto it = lazy.find(treeIndex);
        if(it != lazy.end() && it->second != 0)
            return it->second;

        if(queryLeft <= left && right <= queryRight)
            return segMentTree[treeIndex];
        

        int mid = (left + right) >> 1;
        int leftIndex = 2 * treeIndex + 1;
        int rightIndex = 2 * treeIndex + 2;
        return max(queryMax(leftIndex, left, mid, queryLeft, queryRight),
                    queryMax(rightIndex, mid + 1, right, queryLeft, queryRight));
    }
    void updateMax(int treeIndex, int left, int right, int updateLeft, int updateRight, int val)
    {
        if(updateLeft <= left && right <= updateRight)
        {
            segMentTree[treeIndex] = val;
            lazy[treeIndex] = val;
            return;
        }
        else if(left > updateRight || right < updateLeft)
            return ;
        int mid = (left + right) >> 1;
        int leftIndex = 2 * treeIndex + 1;
        int rightIndex = 2 * treeIndex + 2;
        updateMax(leftIndex, left, mid, updateLeft, updateRight, val);
        updateMax(rightIndex, mid + 1, right, updateLeft, updateRight, val);
        int maxx = segMentTree[treeIndex] = max(segMentTree[leftIndex], segMentTree[rightIndex]);

        auto itLeft = lazy.find(leftIndex);
        auto itRight = lazy.find(rightIndex);
        if(itLeft != lazy.end() && itLeft->second != 0 &&
            itRight != lazy.end() && itRight->second != 0 && 
            itLeft->second == itRight->second)
        {
            lazy[treeIndex] = itLeft->second;
        }

        auto it = lazy.find(treeIndex);
        if(it == lazy.end())
            return ;
        if(maxx > it->second)
            it->second = 0;

    }
    vector<int> fallingSquares(vector<vector<int>>& positions) {

        vector<int> ans;
        int n = 1e8 + 1e6 + 5;
        int curMax = 0;

        for(auto& position : positions)
        {
            int leftMax = queryMax(0, 0, n, position[0], position[0] + position[1] - 1);
            int myMax = leftMax + position[1];
            updateMax(0, 0, n, position[0], position[0] + position[1] - 1, myMax);
            curMax = max(curMax, myMax);
            ans.emplace_back(curMax);
        }

        return ans;

    }
};