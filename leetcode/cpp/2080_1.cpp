//二分

class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> memo;
public:
    RangeFreqQuery(vector<int>& arr) {

        for (int i = 0; i < arr.size(); ++i)
        {
            memo[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {

        if(memo.count(value) != 1)
            return 0;

        vector<int>& vec = memo[value];
        auto start = lower_bound(vec.begin(), vec.end(), left);
        auto end = upper_bound(vec.begin(), vec.end(), right);

        return end - start;
    }
};

