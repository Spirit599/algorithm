class Solution {
public:
    int ans = 0x3f3f3f3f;
    unordered_map<string, bool> vis;

    void dfs(string& board, string& hand, bool visit[], int depth)
    {

        //cout<<board<<endl;
        if(depth > ans)
            return ;

        if(board == "")
            ans = min(ans, depth);

        if(vis.count(board) == 1)
            return ;
        vis[board] = true;

        for (int i = 0; i < hand.size(); ++i)
        {
            if(!visit[i])
            {
                visit[i] = true;
                for (int j = 0; j < board.size(); ++j)
                {
                    // if(hand[i] != board[j])
                    //     continue;
                    board.insert(j, 1, hand[i]);
                    //cout<<board<<endl;
                    string tmp = board;
                    for (int k = 0; k + 2 < board.size(); ++k)
                    {
                        //cout<<k<<endl;
                        if(board[k] == board[k + 1] && board[k] == board[k + 2])
                        {
                            int length = 3;
                            for (int l = k + 3; l < board.size(); ++l)
                            {
                                if(board[l] == board[k])
                                    ++length;
                                else
                                    break;
                            }
                            //cout<<k<<" "<<board<<" "<<length<<endl;
                            board.erase(k, length);
                            k = max(-1, k - 3);
                        }
                    }
                    dfs(board, hand, visit, depth + 1);
                    board = tmp;
                    board.erase(j, 1);
                }
                visit[i] = false;
            }
        }
    }

    int findMinStep(string board, string hand) {

        bool visit[hand.size()];
        memset(visit, 0, sizeof(visit));

        dfs(board, hand, visit, 0);

        if(ans != 0x3f3f3f3f)
            return ans;
        else
            return -1;
    }
};