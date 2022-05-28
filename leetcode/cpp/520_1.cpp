class Solution {
public:
    bool detectCapitalUse(string word) {

        int n = word.size();
        if(n == 1)
            return true;

        bool first_is_lower = (word[0] >= 'a' && word[0] <= 'z') ? true : false;
        bool second_is_lower = (word[1] >= 'a' && word[1] <= 'z') ? true : false;

        if(first_is_lower && !second_is_lower)
            return false;

        for (int i = 2; i < n; ++i)
        {
            if(first_is_lower && (word[i] <= 'Z' && word[i] >= 'A'))
                return false;
            if(!first_is_lower && !second_is_lower && (word[i] <= 'z' && word[i] >= 'a'))
                return false;
            if(!first_is_lower && second_is_lower && (word[i] <= 'Z' && word[i] >= 'A'))
                return false;

        }
        return true;
    }
};