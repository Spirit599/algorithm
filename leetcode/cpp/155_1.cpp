#define MAX_INT (2147483647)

class MinStack {
private:
    stack<int> cur_stack; 
    stack<int> min_stack; 

public:
    /** initialize your data structure here. */
    MinStack() {
        min_stack.push(MAX_INT);
    }
    
    void push(int val) {

        min_stack.push(min(val, min_stack.top()));
        cur_stack.push(val);
    }
    
    void pop() {

        min_stack.pop();
        cur_stack.pop();

    }
    
    int top() {

        return cur_stack.top();
    }
    
    int getMin() {

        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */