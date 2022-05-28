class Solution {
private:
    int max_unmatching_left_parenthesis_num = 0;
    int min_unmatching_left_parenthesis_num = 0;
public:
    bool checkValidString(string s) {

        int i = 0;
        int str_size = s.size();
        while(i < str_size)
        {
            if(s[i] == '(')
            {
                max_unmatching_left_parenthesis_num++;
                min_unmatching_left_parenthesis_num++;
            }
            else if(s[i] == ')')
            {
                max_unmatching_left_parenthesis_num--;
                min_unmatching_left_parenthesis_num = max(min_unmatching_left_parenthesis_num - 1, 0);
                if(max_unmatching_left_parenthesis_num < 0)
                    return false;
            }
            else
            {
                min_unmatching_left_parenthesis_num = max(min_unmatching_left_parenthesis_num - 1, 0);
                max_unmatching_left_parenthesis_num++;
            }
            i++;
        }

        return min_unmatching_left_parenthesis_num == 0;
    }
};