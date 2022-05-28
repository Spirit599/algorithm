class Solution {
public:
    int findComplement(int num) {

        int n = -1;
        int ret = 0;
        int numc = num;
        while(num != 0)
        {
            num = num / 2;
            ++n;
        }


        while(n >= 0)
        {
            cout<<(numc >> n)<<endl;
            int bit = (((numc >> n) & 1) ^ 1);
            cout<<bit<<endl;
            ret += bit << n;
            n--;
        }

        return ret;
    }
};