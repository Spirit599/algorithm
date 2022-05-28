class Solution {
public:
    string reversePrefix(string word, char ch) {


        for (std::string::iterator i = word.begin(); i != word.end(); ++i)
        {
            if(*i == ch)
            {
                reverse(word.begin(), i);
                return word;
            }
        }

        //reverse(word.begin(), i);
        return word;
    }   
};