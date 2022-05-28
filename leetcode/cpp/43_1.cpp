
class Solution {

public:
    string multiply(string num1, string num2) {

        string zero = "0";
        if(num1 == zero || num2 == zero)
            return zero;

        string ret;

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int num1_len = num1.size();
        int num2_len = num2.size();

        int i = 0;
        while(i < num2_len)
        {
            string temp;

            int j = 0;
            while(j < i)
            {
                temp.push_back('0');
                j++;
            }

            temp += multiply_single(num1, num2[i]);       

            //cout<<temp<<endl;

            ret = add(ret, temp);

            i++;
        }

        reverse(ret.begin(), ret.end());

        return ret;

    }

    string multiply_single(string num1, char num2)
    {
        int ones = 0;
        int tens = 0;

        int num1_len = num1.size();
        int i = 0;

        string ret;

        while(i < num1_len)
        {
            int sum = (num1[i] - '0') * (num2 - '0') + tens;
            ones = sum % 10;
            tens = sum / 10;
            ret.push_back(ones + '0');
            i++;
        }

        if(tens)
            ret.push_back(tens + '0');

        //reverse(ret.begin(), ret.end());

        return ret;

    }

    string add(string num1, string num2)
    {
        int num1_len = num1.size();
        int num2_len = num2.size();

        
        string ret;
        
        int ones = 0;
        int tens = 0;

        if(num1_len < num2_len)
        {
            swap(num1_len, num2_len);
            swap(num1, num2);
        }

        int i = 0;
        while(i < num2_len)
        {
            int sum = num1[i] + num2[i] + tens - '0' - '0';
            ones = sum % 10;
            tens = sum / 10;
            //cout<<sum<<endl;
            //cout<<tens<<endl;
            ret.push_back(ones + '0');
            i++;
        }

        while(i < num1_len)
        {
            int sum = num1[i] + tens - '0';
            ones = sum % 10;
            tens = sum / 10;
            ret.push_back(ones + '0');
            i++;
        }

        if(tens)
            ret.push_back(tens + '0');

        //reverse(ret.begin(), ret.end());

        return ret;
    }
};