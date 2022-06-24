class ValidWordAbbr {
public:
    /*
    * @param dictionary: a list of words
    */
    unordered_set<string> memo;
    ValidWordAbbr(vector<string> dictionary) {
        
        for(string str : dictionary)
        {
            if(str.size() <= 2)
            {
                cout<<str<<endl;
                memo.insert(str);
            }
            else
            {
                string k;
                k.push_back(str[0]);
                int n = str.size();
                k += to_string(n - 2);
                k.push_back(str[n - 1]);
                memo.insert(k);
                cout<<k<<endl;
            }
        }
    }

    /*
     * @param word: a string
     * @return: true if its abbreviation is unique or false
     */
    bool isUnique(string &word) {
        
        string cur;
        if(word.size() <= 2)
        {
            cur = word;
        }
        else
        {
            cur.push_back(word[0]);
            int n = word.size();
            cur += to_string(n - 2);
            cur.push_back(word[n - 1]);
        }
        cout<<cur<<endl;

        return memo.count(cur) == 0;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param = obj.isUnique(word);
 */