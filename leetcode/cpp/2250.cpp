class Solution {
public:
    int *segMentTree = nullptr;
    void update(int treeIndex, int left, int right, int index, int addVal)
    {

        if(left == right && index == left)
        {
            segMentTree[treeIndex] += addVal;
            return ;
        }
        else if(left > index || right < index)
            return;

        int mid = (left + right) >> 1;
        int leftIndex = 2 * treeIndex + 1;
        int rightIndex = 2 * treeIndex + 2;
        update(leftIndex, left, mid, index, addVal);
        update(rightIndex, mid + 1, right, index, addVal);
        segMentTree[treeIndex] = segMentTree[leftIndex] + segMentTree[rightIndex];
    }
    int query(int treeIndex, int left, int right, int queryLeft, int queryRight)
    {
        if(queryLeft <= left && right <= queryRight)
            return segMentTree[treeIndex];
        else if(left > queryRight || right < queryLeft)
            return 0;
        int mid = (left + right) >> 1;
        int leftIndex = 2 * treeIndex + 1;
        int rightIndex = 2 * treeIndex + 2;
        int ret = query(leftIndex, left, mid, queryLeft, queryRight);
        ret += query(rightIndex, mid + 1, right, queryLeft, queryRight);
        return ret;

    }
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        
        int n = 101;
        segMentTree = (int*)malloc(sizeof(int) * 4 * n);
        memset(segMentTree, 0, sizeof(int) * 4 * n);

        int rectSize = rectangles.size();
        int pointSize = points.size();

        for(int i = 0; i < pointSize; ++i)
        {
            points[i].push_back(i);
        }

        sort(rectangles.begin(), rectangles.end(), greater<vector<int>>());
        sort(points.begin(), points.end(), greater<vector<int>>());

        vector<int> ans(pointSize);
        int j = 0;
        for(int i = 0; i < pointSize; ++i)
        {
            
            while(j < rectSize && rectangles[j][0] >= points[i][0])
            {
                update(0, 0, n, rectangles[j][1], 1);
                ++j;
            }
            ans[points[i][2]] = query(0, 0, n, points[i][1], n);
        }
        return ans;
    }
};