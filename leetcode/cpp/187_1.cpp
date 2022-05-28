class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        vector<string> ret;
        unordered_map<string, int> hash;

        int s_size = s.size();
        for(int i = 0; i + 9 < s_size; ++i)
        {
            string key = s.substr(i, 10);
            auto it = hash.find(key);
            if(it != hash.end())
            {
                if(it->second == 1)
                    ret.push_back(key);
                ++(it->second);
            }
            else
            {
                hash[key] = 1;
            }
        }

        return ret;
    }
};