//洗牌
//随机

class Solution {
    vector<int> origin;
    vector<int> random;
public:
    Solution(vector<int>& nums) : origin(nums), random(nums)
    {

    }
    
    vector<int> reset() {

        return origin;
    }
    
    vector<int> shuffle() {

        int n = random.size();
        for (int i = 0; i < n; ++i)
        {
            int ra = i + rand() % (n - i);
            swap(random[ra], random[i]);
        }
        return random;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */