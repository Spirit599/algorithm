//字符串


class Solution {
public:
    bool oneEditAway(string first, string second) {

        int long_length;
        int short_length;
        string long_str;
        string short_str;
        if(first.size() >= second.size())
        {
            long_length = first.size();
            short_length = second.size();
            long_str = first;
            short_str = second;
        }
        else
        {
            long_length = second.size();
            short_length = first.size();
            long_str = second;
            short_str = first;
        }

        if(long_length - short_length > 1)
            return false;

        int pl = 0;
        int ps = 0;
        int diff = 0;
        if(long_length == short_length)
        {
            while(pl < long_length)
            {
                if(long_str[pl] != short_str[ps])
                {
                    ++diff;
                    if(diff > 1)
                        return false;
                }
                ++pl;
                ++ps;
            }
        }
        else
        {
            while(pl < long_length && ps < short_length)
            {
                if(long_str[pl] == short_str[ps])
                {
                    ++pl;
                    ++ps;
                }
                else
                {
                    ++diff;
                    if(diff > 1)
                        return false;
                    ++pl;
                }
            }
        }

        return true;
    }
};