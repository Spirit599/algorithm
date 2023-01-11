class Solution {
public:
    long long convertToPail(long long num) {

        string str(to_string(num));
        int n = str.size();

        for(int i = 0, j = n - 1; i < j; ++i, --j)
            str[j] = str[i];

        return stoll(str);
    }
    string nearestPalindromic(string n) {

        long long num = stoll(n);
        if(num == 11)
            return "9";
        long long small = num;
        long long big = num;

        for(int i = 0; small >= num; ++i)
            small = convertToPail(num - pow(10, i));
        for(int i = 0; big <= num; ++i)
            big = convertToPail(num + pow(10, i));

        // cout<<small<<" "<<big<<endl;

        if(big - num < num - small)
            return to_string(big);
        else
            return to_string(small);
    }
};