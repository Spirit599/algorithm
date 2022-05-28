int const MAX_SIZE = 9;

class Solution {
private:
    char checkerboard[MAX_SIZE][MAX_SIZE];
    vector<vector<string>> ans;
public:
    void dfs(char checkerboard[MAX_SIZE][MAX_SIZE], int n, int depth, int index)
    {
        if(depth == n)
        {
            //cout<<"nice"<<endl;
            vector<string> anss;
            for (int k = 0; k < n; ++k)
            {
                string str;
                for (int l = 0; l < n; ++l)
                {
                    //cout<<checkerboard[k][l]<<" ";
                    str.push_back(checkerboard[k][l]);
                }
                anss.push_back(str);
                //cout<<endl;
            }
            ans.push_back(anss);
            //cout<<"---------"<<endl;
            return ;
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if(checkerboard[i][j] == 'X')
                {
                    if(i * n + j < index)
                        continue;
                    
                    char tmp[MAX_SIZE][MAX_SIZE];
                    memcpy(tmp, checkerboard, sizeof(tmp));

                    checkerboard[i][j] = 'Q';
                    for (int k = 0; k < n; ++k)
                    {
                        for (int l = 0; l < n; ++l)
                        {
                            if(checkerboard[k][l] == 'X' && 
                                (k == i || l == j || k - i == l - j || k - i == j - l))
                            {
                                checkerboard[k][l] = '.';
                            }
                        }
                    }
                    dfs(checkerboard, n, depth + 1, i * n + j + 1);

                    memcpy(checkerboard, tmp, sizeof(tmp));
                }
            }
        }


    }
    vector<vector<string>> solveNQueens(int n) {

        //memset(checkerboard, 0, sizeof(checkerboard));
        for (int i = 0; i < MAX_SIZE; ++i)
        {
            for (int j = 0; j < MAX_SIZE; ++j)
            {
                checkerboard[i][j] = 'X';
            }
        }
        dfs(checkerboard, n, 0, 0);

        return ans;
    }
};