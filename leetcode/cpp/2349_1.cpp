class NumberContainers {
public:
	unordered_map<int, int> index_to_num;
	unordered_map<int, set<int>> num_to_index;
    NumberContainers() {

    }
    
    void change(int index, int number) {

    	auto it = index_to_num.find(index);
    	if(it != index_to_num.end())
    	{
    		int num = it->second;
    		it->second = number;
    		auto it1 = num_to_index.find(num);
    		set<int>& old_set = it1->second;
    		old_set.erase(index);
    		if(old_set.size() == 0)
    			num_to_index.erase(it1);
    		num_to_index[number].insert(index);
    	}
    	else
    	{
    		index_to_num[index] = number;
    		num_to_index[number].insert(index);
    	}
    }
    
    int find(int number) {

    	auto it = num_to_index.find(number);
    	if(it != num_to_index.end())
    	{
    		return *(it->second.begin());
    	}
    	else
    	{
    		return -1;
    	}
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */