class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> memo;
    vector<int> nums;


    RandomizedCollection() {

    }
    
    bool insert(int val) {


        auto it = memo.find(val);
        bool ret = (it == memo.end() || it->second.size() == 0);
        nums.emplace_back(val);
        memo[val].emplace(nums.size() - 1);
        
        return ret;
    }
    
    bool remove(int val) {


        auto itVal = memo.find(val);
        if(itVal == memo.end() || itVal->second.size() == 0)
            return false;

        int last = nums.back();

        if(val == last)
        {
            itVal->second.erase(nums.size() - 1);
            nums.pop_back();
            return true;
        }

        auto itReIdx = itVal->second.begin();
        int reIdx = *itReIdx;
        itVal->second.erase(itReIdx);
        int lastIdx = nums.size() - 1;
        swap(nums[reIdx], nums[lastIdx]);
        auto itLast = memo.find(last);
        itLast->second.erase(lastIdx);
        itLast->second.insert(reIdx);
        nums.pop_back();

        return true;
    }
    
    int getRandom() {

        int randIndex = rand() % nums.size();
        return nums[randIndex];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */