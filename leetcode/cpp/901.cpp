// 单调栈

class StockSpanner {
public:
    vector<pair<int, int>> stk;
    int index = 0;
    StockSpanner() {

    }
    
    int next(int price) {

        int ret;
        while(!stk.empty() && stk.back().first <= price)
        {
            stk.pop_back();
        }
        if(!stk.empty())
            ret = index - stk.back().second;
        else
            ret = index + 1;
        stk.emplace_back(price, index++);
        return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */