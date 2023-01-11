class FreqStack {
public:
    FreqStack() {

    }
    
    void push(int val) {

        int cnt = ++freq[val];
        freqStk[cnt].emplace_back(val);
        maxFreq = max(maxFreq, cnt);
    }
    
    int pop() {

        auto it = freqStk.find(maxFreq);
        int ret = it->second.back();
        it->second.pop_back();
        if(it->second.empty())
            --maxFreq;
        --freq[ret];
        return ret;
    }

    unordered_map<int, vector<int>> freqStk;
    unordered_map<int, int> freq;
    int maxFreq = 0;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */