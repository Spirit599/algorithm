#define MIN (-2147483649)


class Solution {
public:
    int thirdMax(vector<int>& nums) {

        long long fisrt_max = MIN;
        long long second_max = MIN;
        long long third_max = MIN;

        for(auto i : nums)
        {
            if(i > fisrt_max)
            {
                third_max = second_max;
                second_max = fisrt_max;
                fisrt_max = i;
            }
            else if(i < fisrt_max)
            {
                if(i > second_max)
                {
                    third_max = second_max;
                    second_max = i;
                }
                else if(i < second_max)
                {
                    if(i > third_max)
                    {
                        third_max = i;
                    }
                }
            }
        }
        if(third_max != MIN)
            return third_max;
        else
            return fisrt_max;
    }
};