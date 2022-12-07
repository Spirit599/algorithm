typedef pair<int, string> pis;
struct cmp1 {
    bool operator()(const pis& p1, const pis& p2)
    {
        if(p1.first != p2.first)
            return p1.first < p2.first;
        else
            return p1.second > p2.second;
    }
};
struct cmp2 {
    bool operator()(const pis& p1, const pis& p2)
    {
        if(p1.first != p2.first)
            return p1.first > p2.first;
        else
            return p1.second < p2.second;
    }
};

class SORTracker {
public:

    priority_queue<pis, vector<pis>, cmp2> topK;
    priority_queue<pis, vector<pis>, cmp1> buttonK;
    SORTracker() {

    }
    
    void add(string name, int score) {

        topK.emplace(score, name);
        buttonK.emplace(topK.top());
        topK.pop();
    }
    
    string get() {

        topK.emplace(buttonK.top());
        buttonK.pop();
        return topK.top().second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */