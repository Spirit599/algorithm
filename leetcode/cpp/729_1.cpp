// 线段树
// 懒标记

class MyCalendar {
    unordered_set<int> segMentTree;
    unordered_set<int> lazy;
public:

    void update(int treeIndex, int left, int right, int updateLeft, int updateRight)
    {
        if(updateLeft <= left && right <= updateRight)
        {
            segMentTree.insert(treeIndex);
            lazy.insert(treeIndex);
            return ;
        }
        else if(left > updateRight || right < updateLeft)
            return ;

        int mid = (left + right) >> 1;
        int treeLeft = 2 * treeIndex + 1;
        int treeRight = 2 * treeIndex + 2;
        update(treeLeft, left, mid, updateLeft, updateRight);
        update(treeRight, mid + 1, right, updateLeft, updateRight);
        // printf("%d %d\n", left, right);
        segMentTree.insert(treeIndex);
        if(lazy.count(treeLeft) && lazy.count(treeRight))
            lazy.insert(treeIndex);
    }

    int query(int treeIndex, int left, int right, int queryLeft, int queryRight)
    {
        if(left > queryRight || right < queryLeft)
            return 0;
        if(lazy.count(treeIndex))
            return 1;
        if(queryLeft <= left && right <= queryRight)
        {
            // printf("all %d %d %d %d\n", left, right, queryLeft, queryRight);
            return segMentTree.count(treeIndex);
        }

        int mid = (left + right) >> 1;
        int treeLeft = 2 * treeIndex + 1;
        int treeRight = 2 * treeIndex + 2;
        int ret1 = query(treeLeft, left, mid, queryLeft, queryRight);
        
        int ret2 = query(treeRight, mid + 1, right, queryLeft, queryRight);
        // printf("%d %d %d\n", left, mid, ret1);
        // printf("%d %d %d\n", mid + 1, right, ret2);
        return max(ret1, ret2);

    }

    bool book(int start, int end) {

        if(query(0, 0, 1e9, start, end - 1) == 1)
            return false;
        update(0, 0, 1e9, start, end - 1);
        return true; 
    }
};