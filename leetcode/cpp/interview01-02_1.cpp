class Solution {
public:
    bool CheckPermutation(string s1, string s2) {

        // sort(s1.begin(), s1.end());
        // sort(s2.begin(), s2.end());
        // return s1 == s2;
        unordered_map<char, int> memo1;
        unordered_map<char, int> memo2;

        int n1 = s1.size();
        for (int i = 0; i < n1; ++i)
        {
            ++memo1[s1[i]];
        }

        int n2 = s2.size();
        for (int i = 0; i < n2; ++i)
        {
            ++memo2[s2[i]];
        }

        return memo1 == memo2;
    }
};