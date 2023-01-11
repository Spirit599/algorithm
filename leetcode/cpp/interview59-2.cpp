class MaxQueue {
public:
    deque<int> deq;
    queue<int> que;
    MaxQueue() {

    }
    
    int max_value() {

        if(deq.empty())
            return -1;
        return deq.front();
    }
    
    void push_back(int value) {

        que.emplace(value);
        while(!deq.empty() && deq.back() < value)
            deq.pop_back();
        deq.emplace_back(value);
    }
    
    int pop_front() {

        if(que.empty())
            return -1;
        int ret = que.front();
        que.pop();
        if(deq.front() == ret)
            deq.pop_front();
        return ret;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */