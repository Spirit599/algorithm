int parent[205];

int rank[205];

int find_parent(int index)
{
    while(parent[index] != -1)
    {
        index = parent[index];
    }
    return index;
}

void union_tree(int index_1, int index_2)
{
    int p1 = find_parent(index_1);
    int p2 = find_parent(index_2);

    if(p1 != p2)
    {
        if(rank[p1] > rank[p2])
        {
            parent[p2] = p1;
        }
        else if(rank[p1] < rank[p2])
        {
            parent[p1] = p2;
        }
        else
        {
            parent[p2] = p1;
            ++rank[p1];
        }
    }
    else
    {
        printf("wrong\n");
    }
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        memset(parent, -1, sizeof(parent));
        memset(rank, 0, sizeof(rank));

        int n = isConnected.size();

        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                if(isConnected[i][j])
                {
                    union_tree(i, j);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            if(parent[i] == -1)
            {
                ++ans;
            }
        }

        return ans;
    }
};