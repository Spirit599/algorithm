class Solution {
public:
    bool isItPossible(string word1, string word2) {
        
        unordered_map<char, int> memo1;
        for(int c : word1)
            ++memo1[c];
        unordered_map<char, int> memo2;
        for(int c : word2)
            ++memo2[c];


        for(auto& kv : memo1)
        {
            char k = kv.first;
            int v = kv.second;
            for(auto& kv2 : memo2)
            {
                char k2 = kv2.first;
                int v2 = kv2.second;
                if(k == k2)
                {
                    if(memo1.size() == memo2.size())
                        return true;
                }
                else
                {
                    if(memo1.size() - (memo1[k] == 1) + (memo1.count(k2) == 0) == memo2.size() - (memo2[k2] == 1) + (memo2.count(k) == 0))
                        return true;
                }
            }
        }
        

        return false;
    }
};