class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {

        int n = s.size();
        for(int i = n - 2; i >= 0; --i)
            shifts[i] = (shifts[i + 1] + shifts[i]) % 26;

        for(int i = 0; i < n; ++i)
        {
            int dif = s[i] - 'a';
            dif = (dif + shifts[i]) % 26;
            s[i] = 'a' + dif;
        }
        return s;
    }
};