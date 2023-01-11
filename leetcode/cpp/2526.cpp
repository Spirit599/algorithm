class DataStream {
public:
    int consecNum = 0;
    int value;
    int k;
    DataStream(int valu, int kk) {
        value = valu;
        k = kk;
    }
    
    bool consec(int num) {

        if(num == value)
        {
            ++consecNum;
            if(consecNum >= k)
                return true;
            else
                return false;
        }
        else
        {
            consecNum = 0;
            return false;
        }
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */