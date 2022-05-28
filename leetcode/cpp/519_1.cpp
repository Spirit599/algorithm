//随机
//抽样

class Solution {
public:
    int _total;
    int _m;
    int _n;
    unordered_map<int, int> _um;
    Solution(int m, int n) : _m(m), _n(n), _total(m * n) 
    {
        srand(time(nullptr));
    }
    
    vector<int> flip() {

        int k = rand() % _total;

        vector<int> ans(2);
        if(_um.count(k) != 1)
            ans = {k / _n, k % _n};
        else
            ans = {_um[k] / _n, _um[k] % _n};

        --_total;
        if(_um.count(_total) != 1)
            _um[k] = _total;
        else
            _um[k] = _um[_total];

        return ans;
    }
    
    void reset() {

        _total = _m * _n;
        _um.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */