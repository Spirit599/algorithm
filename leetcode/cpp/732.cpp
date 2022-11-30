class MyCalendarThree {
public:
    unordered_map<int, pair<int, int>> segMentTree;
    void updateMax(int treeIndex, int left, int right, int updateLeft, int updateRight)
    {
        if(updateLeft <= left && right <= updateRight)
        {
            ++(segMentTree[treeIndex].first);
            ++(segMentTree[treeIndex].second);
            return ;
        }
        else if(left > updateRight || right < updateLeft)
        {
            return ;
        }

        int mid = (left + right) >> 1;
        int treeLeft = 2 * treeIndex + 1;
        int treeRight = 2 * treeIndex + 2;
        updateMax(treeLeft, left, mid, updateLeft, updateRight);
        updateMax(treeRight, mid + 1, right, updateLeft, updateRight);
        segMentTree[treeIndex].first = segMentTree[treeIndex].second + max(segMentTree[treeLeft].first, segMentTree[treeRight].first);
    }
    MyCalendarThree() {

    }
    
    int book(int startTime, int endTime) {

        updateMax(0, 0, 1e9, startTime, endTime - 1);
        return segMentTree[0].first;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */