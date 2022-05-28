//栈
//逆波兰
class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> nums;
        //stack<char> symbols;

        for(string str : tokens)
        {
            if(str == "*")
            {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                nums.push(num2 * num1);
            }
            else if(str == "/")
            {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                nums.push(num2 / num1);
            }
            else if(str == "+")
            {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                nums.push(num2 + num1);
            }
            else if(str == "-")
            {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                nums.push(num2 - num1);
            }
            else
            {
                nums.push(atoi(str.c_str()));
            }

        }

        return nums.top();

    }
};