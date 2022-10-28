class ATM {
public:
    int accountSize = 5;
    vector<long long> account;
    int value[5] = {20, 50, 100, 200, 500};
    ATM() {
        account.resize(accountSize);
    }
    
    void deposit(vector<int> banknotesCount) {

        for(int i = 0; i < accountSize; ++i)
        {
            account[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {

        vector<int> tmp(5);
        for(int i = accountSize - 1; i >= 0; --i)
        {
            if(amount < value[i])
                continue;
            //printf("%d %d\n", amount, value[i]);

            bool enoughMoney = account[i] * value[i] >= amount ? true : false;
            //bool canDivided = amount % value[i] ? false : true;

            // if(enoughMoney && !canDivided)
            //     return {-1};
            if(enoughMoney)
            {
                int nums = amount / value[i];
                //account[i] -= nums;
                tmp[i] += nums;
                amount -= nums * value[i];
                //return tmp;
            }
            else if(!enoughMoney)
            {
                amount -= account[i] * value[i];
                tmp[i] = account[i];
                //account[i] = 0;     
            }
        }
        // for(int i = 0; i < accountSize; ++i)
        //     printf("%d ", account[i]);
        // printf("\n");
        if(amount == 0)
        {
            for(int i = 0; i < accountSize; ++i)
                account[i] -= tmp[i];
            return tmp;
        }
        else
            return {-1};
        
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */