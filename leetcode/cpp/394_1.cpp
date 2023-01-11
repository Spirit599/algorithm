// 394. 字符串解码
// 栈
class Solution {
public:
    string decodeString(string str) {
        
        string ret;
        string tmp;
        int num = 0;
        stack<int> staInt;
        stack<string> staString;



        for(char c : str)
        {
            if(isalpha(c))
                tmp.push_back(c);
            else if(isdigit(c))
                num = 10 * num + c - '0';
            else if(c == '[')
            {
                if(num == 0)
                    num = 1;
                staInt.push(num);
                staString.push(tmp);
                num = 0;
                tmp = "";
            }
            else
            {
                int num = staInt.top();
                staInt.pop();
                string pre = staString.top();
                staString.pop();

                string kk;
                while(num--)
                    kk += tmp;
                tmp = pre + kk;
            }
        }

        return tmp;
    }
};