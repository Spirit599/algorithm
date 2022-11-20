class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();
        if(n % groupSize)
            return false;


        map<int, int> memo;
        for(int h : hand)
        {
            ++memo[h];
        }

        int k = n / groupSize;
        while(k--)
        {
            auto it = memo.begin();
            int other = groupSize - 1;
            int nextKey = it->first + 1;
            if(it->second == 1)
            {
                memo.erase(it);
            }
            else
                --(it->second);
            
            while(other--)
            {
                auto it1 = memo.find(nextKey);
                if(it1 == memo.end())
                    return false;
                nextKey = it1->first + 1;

                if(it1->second == 1)
                    memo.erase(it1);
                else
                    --(it1->second);
                

            }
        }

        return true;
    }
};