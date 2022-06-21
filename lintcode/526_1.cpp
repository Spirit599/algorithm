// 526 · 负载均衡器

class LoadBalancer {
    vector<int> __arr;
    unordered_map<int, int> __index;
public:
    LoadBalancer() {
        
        srand((unsigned)time(NULL));
    }

    /*
     * @param server_id: add a new server to the cluster
     * @return: nothing
     */
    void add(int server_id) {
        
        __index[server_id] = __arr.size();
        __arr.push_back(server_id);
    }

    /*
     * @param server_id: server_id remove a bad server from the cluster
     * @return: nothing
     */
    void remove(int server_id) {
        
        int last_index = __arr.size() - 1;
        int last = __arr[last_index];
        int remove_index = __index[server_id];
        swap(__arr[last_index], __arr[remove_index]);
        __index[last] = remove_index;

        __arr.pop_back();
        __index.erase(server_id);
    }

    /*
     * @return: pick a server in the cluster randomly with equal probability
     */
    int pick() {
        
        return __arr[rand() % __arr.size()];
    }
};