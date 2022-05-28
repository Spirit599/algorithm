//排序栈
//延迟更新

class SortedStack {
public:
    stack<int> big;
    stack<int> small;
    SortedStack() {

    }
    
    void push(int val) {

        while(!small.empty() && small.top() > val)
        {
            big.puah(small.top());
            small.pop();
        }
        while(!big.empty() && big.top() < val)
        {
            small.push(big.top());
            big.pop();
        }
        big.push(val);
    }
    
    void pop() {
        while(!small.empty() && small.top() > val)
        {
            big.puah(small.top());
            small.pop();
        }
        if(!big.empty())
            big.pop();

    }
    
    int peek() {
        while(!small.empty() && small.top() > val)
        {
            big.puah(small.top());
            small.pop();
        }
        if(!big.empty())
            return big.top();
        return -1;
    }
    
    bool isEmpty() {

        return big.empty() && small.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */