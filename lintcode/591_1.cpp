// 591 · 连接图 III
// 并查集
int find_father(vector<int>& father, int index)
{
	while(father[index] != -1)
	{
		index = father[index];
	}
	return index;
}

class ConnectingGraph3 {
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
	vector<int> father;
	vector<int> height;
	int num;
    ConnectingGraph3(int n) : num(n)
    {
        
        father.resize(n + 1, -1);
        height.resize(n + 1, 1);
    }
    void connect(int a, int b) {
        
        int fa = find_father(father, a);
        int fb = find_father(father, b);

        if(fa != fb)
        {
        	if(height[fa] > height[fb])
        	{
        		father[fb] = fa;
        	}
        	else
        	{
        		father[fa] = fb;
        	}
        	--num;
        }
    }

    /**
     * @return: An integer
     */
    int query() {

    	return num;
    }
};