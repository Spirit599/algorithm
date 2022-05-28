bool cmp(const string& str1, const string& str2)
{   
    int str1_len = str1.size();
    int str2_len = str2.size();
    if(str1_len != str2_len)
    {
        return str1_len > str2_len;
    }
    else
    {
        return str1 < str2;
    }
    
}

class Solution {
public:


    string findLongestWord(string s, vector<string>& dictionary) {

        string ret;

        sort(dictionary.begin(), dictionary.end(), cmp);
        for (int i = 0; i < dictionary.size(); ++i)
        {
            //cout<< dictionary[i] <<endl;
            if(compare(s, dictionary[i]))
                return dictionary[i];
        }
        
        return ret;

    }

    bool compare(const string& s, const string& cur_str)
    {
        int s_len = s.size();
        int cur_str_len = cur_str.size();

        if(cur_str_len > s_len)
            return false;

        int i = 0;
        int j = 0;
        while(i < cur_str_len && j < s_len)
        {
            if(cur_str[i] == s[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
            //cout<<i<<" "<<j<<endl;
        }

        if(i == cur_str_len)
            return true;
        else
            return false;
    }
};