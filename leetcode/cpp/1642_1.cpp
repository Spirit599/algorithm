//贪心
//优先队列

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

        int i = 1;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (i = 1; i < heights.size(); ++i)
        {
            int detal = heights[i] - heights[i - 1];
            if(detal > 0)
            {
                pq.push(detal);
                if(pq.size() > ladders)
                {
                    int cur = pq.top();
                    pq.pop();
                    if(cur <= bricks)
                        bricks -= cur;
                    else
                        break;
                }
            }
        }

        return i - 1; 
    }
};