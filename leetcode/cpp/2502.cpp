class Allocator {
public:
    int n;
    vector<int> blocks;
    Allocator(int n) {

        this->n = n;
        blocks.resize(n);
    }

    int fillBlocks(int start, int len, int mID) {

        int end = start + len - 1;
        for(int i = start; i <= end; ++i)
            blocks[i] = mID;
        return start;
    }
    
    int allocate(int size, int mID) {

        if (size > n) 
            return -1;

        int k = 0;
        for(int i = 0; i < size; ++i)
            k += blocks[i];
        if(k == 0)
            return fillBlocks(0, size, mID);

        for(int i = size; i < n; ++i)
        {
            k += blocks[i] - blocks[i - size];
            if(k == 0)
                return fillBlocks(i - size + 1, size, mID);
        }

        return -1;
    }
    
    int free(int mID) {

        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            if(blocks[i] == mID)
            {
                blocks[i] = 0;
                ++ans;
            }
        }
        return ans;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */