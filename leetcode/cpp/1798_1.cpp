//动态规划
//脑洞
//数学

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {

        sort(coins.begin(), coins.end());

        int can_arrive = 0; //当前能到达的范围[0, can_arrive]

        for(int cur : coins)
        {
            if(cur <= can_arrive + 1)
            {
                can_arrive += cur;//[0, can_arrive]并上[cur, cur + can_arrive]
            }
            else
            {
                break;//如果can_arrive + 1 小于 cur 那就并不上,中间会有缝隙
            }
        }

        return can_arrive;

    }
};