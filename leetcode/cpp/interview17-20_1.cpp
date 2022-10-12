class MedianFinder {
public:
    priority_queue<int> maxInSmaller;
    priority_queue<int, vector<int>, greater<int>> minInBiger;
    int n = 0;
    MedianFinder() {

    }
    
    void addNum(int num) {

        ++n;
        if(n & 1)
        {
            maxInSmaller.push(num);
            minInBiger.push(maxInSmaller.top());
            maxInSmaller.pop();
        }
        else
        {
            minInBiger.push(num);
            maxInSmaller.push(minInBiger.top());
            minInBiger.pop();
        }
    }
    
    double findMedian() {

        if(n & 1)
        {
            return minInBiger.top();
        }
        else
        {
            return (minInBiger.top() + maxInSmaller.top()) / 2.0;
        }

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */