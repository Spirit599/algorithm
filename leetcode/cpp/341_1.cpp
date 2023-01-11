/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    // vector<int> curIndex;
    // int listIndex = 0;
    // int listSize = 0;
    // int n;
    // int depth = -1;
    // vector<NestedInteger>* myList = nullptr;
    NestedIterator(vector<NestedInteger> &nestedList) 
    {
        myList = &nestedList;
        vector<NestedInteger>* p = myList;

        while(p)
        {
            ++depth;
            curIndex.push_back(0);
            if( ((*p)[0].isInteger()) == false)
            {
                p = &((*p)[0].getList());
                listSize = (*p).size();
                listIndex = 0;
            }
            else
                p = nullptr;
        }
    }
    
    int next() {
        
        // vector<NestedInteger>* p = myList;
        // int i = 0;
        // int ret = 0;
        // while(i != depth) {
        //     p = &((*p)[curIndex[i]].getList());
        //     ret = (*p)[listIndex].getInteger();
        //     ++i;
        // }
        // ++listIndex;
        // if(listIndex == listSize)
        // {
            
        // }
        // printf("%d\n", ret);

        return ret;
    }
    
    bool hasNext() {

        return curIndex[0] < n;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */