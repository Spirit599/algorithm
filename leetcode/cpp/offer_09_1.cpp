class CQueue {
private:
    stack<int> s1;
    stack<int> s2;
    int size = 0;
public:
    CQueue() {

    }
    
    void appendTail(int value) {

        s1.push(value);
        ++size;

    }
    
    int deleteHead() {

        int ret = -1;

        if(!s2.empty())
        {
            ret = s2.top();
            s2.pop();
            return ret;
        }
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            if(!s2.empty())
            {
                ret = s2.top();
                s2.pop();
            }
            return ret;
        }

    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */