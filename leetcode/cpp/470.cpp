// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        
        int k;
        while(1)
        {
            k = (rand7() - 1) * 7 + rand7() - 1;
            if(k <= 39)
                break;
        }

        return k % 10 + 1;

    }
};