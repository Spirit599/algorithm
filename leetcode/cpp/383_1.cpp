const int MAX_BUCKET = 225;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        int r_memo[MAX_BUCKET];
        int m_memo[MAX_BUCKET];
        memset(r_memo, 0, sizeof(r_memo));
        memset(m_memo, 0, sizeof(m_memo));

        for(char ch : ransomNote)
            ++r_memo[ch];

        for(char ch : magazine)
            ++m_memo[ch];

        for (int i = 0; i < MAX_BUCKET; ++i)
        {   
            if(r_memo[i] > m_memo[i])
                return false;
        }

        return true;
    }
};