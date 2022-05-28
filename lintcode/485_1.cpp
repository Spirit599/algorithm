class Solution {
public:
    /**
     * @param size: An integer
     * @return: An integer list
     */
    vector<int> generate(int size) {
        
        vector<int> ans;

        for(int i = 1; i <= size; ++i)
            ans.push_back(i);

        return ans;
    }
};