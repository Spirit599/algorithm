class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {

        string num2;
        string num1;
        string ans;
        int sumYu = 0;

        for(int num : digits)
        {
            if(num % 3 == 2)
                num2.push_back(num + '0');
            else if(num % 3 == 1)
                num1.push_back(num + '0');
            else
                ans.push_back(num + '0');

            sumYu = (sumYu + num) % 3;
        }

        sort(num1.begin(), num1.end(), greater<char>());
        sort(num2.begin(), num2.end(), greater<char>());
        
        int n1 = num1.size();
        int n2 = num2.size();
        if(sumYu == 0)
        {
            ans += num1;
            ans += num2;
        }
        else if(sumYu == 1)
        {
            if(n1 >= 1)
            {
                num1.pop_back();
                ans += num1;
                ans += num2;
            }
            else if(n2 >= 2)
            {
                num2.pop_back();
                num2.pop_back();
                ans += num1;
                ans += num2;
            }
        }
        else if(sumYu == 2)
        {
            if(n2 >= 1)
            {
                num2.pop_back();
                ans += num1;
                ans += num2;
            }
            else if(n1 >= 2)
            {
                num1.pop_back();
                num1.pop_back();
                ans += num1;
                ans += num2;
            }
        }
        

        sort(ans.begin(), ans.end(), greater<char>());

        if(ans == "")
            return "";
        else if(ans[0] == '0')
            return "0";
        else
             return ans;
    }
};