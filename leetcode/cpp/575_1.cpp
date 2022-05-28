class Solution {
public:
    int distributeCandies(vector<int>& candyType) {

        unordered_set<int> us;
        for(int i : candyType)
        {
            us.insert(i);
        }
        
        return min(us.size(), candyType.size() / 2);
    }
};