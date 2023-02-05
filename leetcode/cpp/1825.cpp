typedef pair<int, int>  pii;

class MKAverage {
public:
	priority_queue<pii> buttonK;
	priority_queue<pii, vector<pii>, greater<pii>> topK;
	int m;
	int k;
	int n;
	long long allSum = 0;
	long long buttonKSum = 0;
	long long topKSum = 0;
	long long rmSum = 0;
	int idx = 0;
    MKAverage(int mm, int kk) {

    	m = mm;
    	k = kk;
    	n = m - 2 * k;
    }
    
    void addElement(int num) {

    	int buttonSize = buttonK.size();
    	int topSize = topK.size();
    	if(buttonSize > topKSize)
    	{

    		buttonK.emplace(num, idx);
    		buttonKSum += num;
    		auto [val, index] = buttonK.top();

    		topKSum += val;
    		topK.emplace(val, index);
    		buttonKSum -= val;
    		buttonK.pop();
    	}
    	else
    	{
    		topK.emplace(num, idx);
    		buttonKSum += num;
    		auto [val, index] = topK.top();

    		buttonKSum += val;
    		buttonK.emplace(val, index);
    		topKSum -= val;
    		topK.pop();
    	}

    	if()

    	++idx;
    	allSum += num;
    }
    
    int calculateMKAverage() {

    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */