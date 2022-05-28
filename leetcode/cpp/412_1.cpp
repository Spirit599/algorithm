class Solution {
public:
    vector<string> fizzBuzz(int n) {

        vector<string> ret(n);
        
        for(int i = 0; i < n; ++i)
        {
            if((i + 1) % 15 == 0)
                ret[i] = "FizzBuzz";
            else if((i + 1) % 5 == 0)
                ret[i] = "Buzz";
            else if((i + 1) % 3 == 0)
                ret[i] = "Fizz";
            else
                ret[i] = to_string(i + 1);
        }

        return ret;
    }
};