class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {

        int nums = minutesToTest / minutesToDie + 1;
        int pigs = 0;
        int k = 1;

        while(k < buckets)
        {
            ++pigs;
            k *= nums;
        }

        return pigs;

    }
};