const int MAX_NODE = 1000;


int parent[MAX_NODE];
int height[MAX_NODE];

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
        if(height[p1] > height[p2])
        {
            parent[p2] = p1;
        }
        else if(height[p1] < height[p2])
        {
            parent[p1] = p2;
        }
        else
        {
            parent[p2] = p1;
            ++height[p1];
        }
    }
    else
    {
        printf("wrong\n");
    }
}