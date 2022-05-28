class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {

        vector<vector<int>> anss;
        int nums = target;
        //cout<<nums<<endl;

        while(nums >= 2)
        {
            double k = target / double(nums);
            if(nums & 1)
            {
                if(k == (int)k)
                {
                    vector<int> ans;
                    int start = k - nums / 2;
                    if(start <= 0)
                    {
                        --nums;
                        continue;
                    }
                    //cout<<"dan "<<k<<" "<<nums<<endl;
                    int nums_copy = nums;
                    while(nums_copy--)
                    {
                        ans.push_back(start);
                        ++start;
                    }
                    anss.push_back(ans);
                }
            }
            else
            {
                if(k != (int)k && 2 * k == (int)(2 * k))
                {        
                    vector<int> ans;
                    int start = (int)k - nums / 2 + 1;
                    if(start <= 0)
                    {
                        --nums;
                        continue;
                    }
                    //cout<<"shuang "<<k<<" "<<nums<<endl;
                    int nums_copy = nums;
                    while(nums_copy--)
                    {
                        ans.push_back(start);
                        ++start;
                    }
                    anss.push_back(ans);
                }
            }
            --nums;
        }

        return anss;
    }
};