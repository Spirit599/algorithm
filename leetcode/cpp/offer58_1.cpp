//字符串操作
//move

class Solution {
public:
    string reverseWords(string s) {

        // stack<string> st; 
        // string str, ans;
        // istringstream istream(s);
        // while(istream >> str)
        // {
        //     st.push(str);
        //     st.push(" ");
        // }
        // if(!st.empty())
        //     st.pop();
        // while(!st.empty())
        // {
        //     ans += st.top();
        //     st.pop();
        // }
        // return ans;

        string ans;
        int end = s.size() - 1;
        while(end >= 0)
        {
            while(end >= 0 && s[end] == ' ')
                --end;
            int start = end;
            while(start >= 0 && s[start] != ' ')
                --start;

            //ans.append(s.substr(start + 1, end - start));
            ans=std::move(ans)+std::move(s.substr(start+1,end-start))+std::move(" ");
            ans.push_back(' ');

            end = start;
        }

        while(ans.size() && ans.back() == ' ')
            ans.pop_back();
        return ans;
    }
};