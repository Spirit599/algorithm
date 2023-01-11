class LUPrefix {
public:
    bool* vis = nullptr;
    int ret = 0;
    int n = 0;
    LUPrefix(int n) {
        this->n = n;
        vis = (bool*)malloc(sizeof(bool) * (n + 1));
        memset(vis, 0, sizeof(bool) * (n + 1));
    }
    
    void upload(int video) {

        vis[video] = true;
        while(ret + 1 <= n && vis[ret + 1])
            ++ret;
    }
    
    int longest() {
        return ret;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */