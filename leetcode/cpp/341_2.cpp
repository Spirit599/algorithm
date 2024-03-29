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
    vector<int> arr;
    int n;
    int cur = 0;
    void dfs(vector<NestedInteger> &nestedList)
    {
        int n = nestedList.size();
        for(int i = 0; i < n; ++i)
        {
            if(nestedList[i].isInteger())
                arr.push_back(nestedList[i].getInteger());
            else
                dfs(nestedList[i].getList());
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) 
    {
        dfs(nestedList);
        n = arr.size();
    }
    
    int next() {
        
        return arr[cur++];
    }
    
    bool hasNext() {

        return cur < n;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */