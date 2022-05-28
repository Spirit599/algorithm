class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {

        string memo[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        set<string> ret;

        for(string& str : words)
        {
            string tmp;
            for(char c : str)
            {
                tmp += memo[c - 'a'];
            }
            ret.insert(tmp);
        }

        int ans = 0;
        for(auto& str : ret)
        {
            ++ans;
        }

        return ans;
    }
};