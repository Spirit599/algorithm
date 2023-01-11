class Solution {
public:
    int toNum(int a[])
    {
        int ret = 0;
        for(int i = 1; i <= 6; ++i)
            ret = 10 * ret + a[i];
        return ret;
    }
    int slidingPuzzle(vector<vector<int>>& board) {

        unordered_set<int> vis;
        int a[7] = {-1, board[0][0], board[0][1], board[0][2],
                        board[1][0], board[1][1], board[1][2]};
        int num = toNum(a);
        printf("%d\n", num);
        vis.insert(num);
        queue<int> que;
        que.emplace(num);
        int over = 123450;
        

        int depth = 0;
        while(!que.empty())
        {
            int k = que.size();
            while(k--)
            {
                int cur = que.front();
                que.pop();
                if(cur == over)
                    return depth;
                int index = -1;
                for(int i = 6; i >= 1; --i)
                {
                    a[i] = cur % 10;
                    cur = cur / 10;
                    if(a[i] == 0)
                        index = i;
                }
                int b1 = -1;
                int b2 = -1;
                int b3 = -1;
                if(index == 1)
                {
                    b1 = 2;
                    b2 = 4;
                }
                else if(index == 2)
                {
                    b1 = 1;
                    b2 = 3;
                    b3 = 5;
                }
                else if(index == 3)
                {
                    b1 = 2;
                    b2 = 6;
                }
                else if(index == 4)
                {
                    b1 = 5;
                    b2 = 1;
                }
                else if(index == 5)
                {
                    b1 = 2;
                    b2 = 4;
                    b3 = 6;
                }
                else if(index == 6)
                {
                    b1 = 3;
                    b2 = 5;
                }

                swap(a[b1], a[index]);
                int num1 = toNum(a);
                if(vis.count(num1) == 0)
                {
                    vis.insert(num1);
                    que.emplace(num1);
                }
                swap(a[b1], a[index]);
                swap(a[b2], a[index]);
                int num2 = toNum(a);
                if(vis.count(num2) == 0)
                {
                    vis.insert(num2);
                    que.emplace(num2);
                }
                if(b3 == -1)
                    continue;
                swap(a[b2], a[index]);
                swap(a[b3], a[index]);
                int num3 = toNum(a);
                if(vis.count(num3) == 0)
                {
                    vis.insert(num3);
                    que.emplace(num3);
                }
            }
            ++depth;
        }

        return -1;
    }
};