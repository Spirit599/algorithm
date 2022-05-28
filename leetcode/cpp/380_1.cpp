class RandomizedSet {
public:
    RandomizedSet() {
        
        srand((unsigned int)time(NULL));
    }
    
    bool insert(int val) {

        auto it = hash.find(val);
        if(it != hash.end())
        {
            return false;
        }
        else
        {
            index_to_num.emplace_back(val);
            hash[val] = index_to_num.size() - 1;
            return true;
        }
    }
    
    bool remove(int val) {

        auto it = hash.find(val);
        if(it != hash.end())
        {
            //cout<<"index_to_num.back() = "<<index_to_num.back()<<" "<<hash[val]<<endl;
            index_to_num[hash[val]] = index_to_num.back();
            hash[index_to_num.back()] = hash[val];

            index_to_num.pop_back();
            hash.erase(val);
            return true;
        }
        else
        {
            return false;
        }
        
    }
    
    int getRandom() {

        //cout<<index_to_num.size()<<endl;
        int rand_index = rand() % index_to_num.size();
        return index_to_num[rand_index];
    }
private:
    unordered_map<int, int> hash;
    vector<int> index_to_num;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */