class LockingTree {
public:

    vector<int> lock_status;
    vector<int> parent;
    vector<vector<int>> sons;
    int tree_size;

    LockingTree(vector<int>& parent) 
    {
        tree_size = parent.size();

        for(auto i = 0; i < tree_size; ++i)
        {
            lock_status.push_back(0);
        }

        sons.resize(tree_size);
        for(auto i = 1; i < tree_size; ++i)
        {
            sons[parent[i]].push_back(i);
        }

        this->parent = parent;
    }
    
    bool lock(int num, int user) 
    {

        if(lock_status[num] == 0)
        {
            lock_status[num] = user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) 
    {

        if(lock_status[num] == user)
        {
            lock_status[num] = 0;
            return true;
        }
        return false;
    }

    bool have_lock(int num) 
    {

        if(lock_status[num] == 0)
            return false;
        return true;
    }

    bool parent_have_lock(int num) 
    {

        while(parent[num] != -1) 
        {
            //cout<<parent[num]<<endl;
            if(have_lock(parent[num]))
            {
                return true;
            }
            num = parent[num];
        }

        return false;
    }

    bool sons_have_lock(int num)
    {
        bool ret = false;
        queue<int> my_sons;


        if(sons[num].size())
        {
            for (auto cur_son : sons[num])
            {
                if(have_lock(cur_son))
                {
                    lock_status[cur_son] = 0;
                    ret = true;
                }
                //cout<<cur_son<<endl;
                my_sons.push(cur_son);
            }
        }

        while(!my_sons.empty())
        {   
            int son = my_sons.front();
            for (auto cur_son : sons[son])
            {
                if(have_lock(cur_son))
                {
                    lock_status[cur_son] = 0;
                    ret = true;
                }
                //cout<<cur_son<<endl;
                my_sons.push(cur_son);
            }
            my_sons.pop();
        }

        return ret;
    }
    
    bool upgrade(int num, int user) 
    {

        if(have_lock(num))
        {
            //cout<<"have_lock"<<endl;
            return false;
        }

        if(parent_have_lock(num))
        {
            //cout<<"parent_have_lock"<<endl;
            return false;
        }

        if(!sons_have_lock(num))
        {
            //cout<<"sons have no lock"<<endl;
            return false;
        }

        lock_status[num] = user;

        return true;
    }



};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */