// #include <iostream>
// #include <vector>
// using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int> nums) {

        int ret = -1;

        for(int i = 0; i < nums.size(); i++)
        {
            int presum = 0;
            int sufsum = 0;
            for (int j = 0; j <= i - 1; ++j)
            {
                /* code */
                presum += nums[j];
            }

            for (int k = i + 1; k < nums.size(); ++k)
            {
                /* code */
                sufsum += nums[k];
            }
            if(presum == sufsum)
            {
                ret = i;
                break;
            }
        }
        cout<<ret<<endl;
        return ret;

    }
};


// int main(int argc, char const *argv[])
// {
//     Solution sol;
//     sol.findMiddleIndex({2,3,-1,8,4});
//     sol.findMiddleIndex({1,-1,4});
//     sol.findMiddleIndex({2,5});
//     sol.findMiddleIndex({1});
//     return 0;
// }