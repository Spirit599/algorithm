//中位数
//优先队列
//堆

class MedianFinder {
    priority_queue<int> small_heap;
    priority_queue<int, vector<int>, greater<int>> big_heap;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {

        if(small_heap.size() == big_heap.size())
        {
            small_heap.push(num);
            big_heap.push(small_heap.top());
            small_heap.pop();
        }
        else
        {
            big_heap.push(num);
            small_heap.push(big_heap.top());
            big_heap.pop();
        }
    }
    
    double findMedian() {

        
        if((small_heap.size() + big_heap.size()) & 1)
            return big_heap.top();
        else
        {
            return (big_heap.top() + small_heap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */