//669 · 换硬币
//BFS
class Solution {
public:
    /**
     * @param coins: a list of integer
     * @param amount: a total amount of money amount
     * @return: the fewest number of coins that you need to make up
     */
    int coinChange(vector<int> &coins, int amount) {

        if(amount == 0)
            return 0;
        
        bool visited[amount + 1];
        memset(visited, 0, sizeof(visited));

        queue<int> que;
        que.push(0);
        visited[0] = true;
        int depth = 0;

        while(!que.empty())
        {
            int k = que.size();
            ++depth;

            while(k--)
            {
                int cur = que.front();
                que.pop();

                for(int coin : coins)
                {
                    if(!visited[cur + coin] && cur + coin < amount)
                    {
                        visited[cur + coin] = true;
                        que.push(cur + coin);
                    }
                    else if(cur + coin == amount)
                    {
                        return depth;
                    }
                }
            }
        }

        return -1;
    }
};