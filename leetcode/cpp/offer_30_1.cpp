class MinStack {
private:
    stack<int> st;
    stack<int> min_st;
public:
    /** initialize your data structure here. */
    MinStack() {
        min_st.push(0x7fffffff);
    }
    
    void push(int x) {
        //cout<<"push "<<x<<endl;
        st.push(x);
        if(min_st.top() >= x)
            min_st.push(x);
    }
    
    void pop() {
        //cout<<"pop"<<endl;
        if(min_st.top() == st.top())
            min_st.pop();
        st.pop();
    }
    
    int top() {
        //cout<<"top"<<endl;
        return st.top();
    }
    
    int min() {
        //cout<<"min "<<min_st.size()<<endl;
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */