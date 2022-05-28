class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1, index2] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        
        unordered_map<int, int> memo;
        for(int i = 0; i < numbers.size(); ++i)
            memo[numbers[i]] = i;

        vector<int> ans;
        for(auto& kav : memo)
        {
            if(memo.count(target - kav.first) == 1)
            {
                int index1 = min(kav.second, memo[target - kav.first]);
                int index2 = max(kav.second, memo[target - kav.first]);
                ans.emplace_back(index1);
                ans.emplace_back(index2);
                break;
            }
        }

        return ans;
    }
};