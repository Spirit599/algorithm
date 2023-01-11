class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> *ppq = nullptr;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        ppq = new priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.end());
        
    }
    
    int add(int val) {
        priority_queue<int, vector<int>, greater<int>>& pq = *ppq;
        pq.push(val);
        while(pq.size() > k)
        {
            printf("%d\n", pq.top());
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */