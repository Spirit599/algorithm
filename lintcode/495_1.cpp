class Stack {
public:
    /*
     * @param x: An integer
     * @return: nothing
     */
    int _stack[100005];
    int _top = -1;

    Stack() {

    }
    void push(int x) {
        
        _stack[++_top] = x;
    }

    /*
     * @return: nothing
     */
    void pop() {
        
        --_top;
    }

    /*
     * @return: An integer
     */
    int top() {
        
        return _stack[_top];
    }

    /*
     * @return: True if the stack is empty
     */
    bool isEmpty() {
        
        return _top == -1;
    }
};