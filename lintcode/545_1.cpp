// 545 · 前K大数 II

class Solution {
public:

	set<int, greater<int>> __ordered;
	int __k;
    /*
    * @param k: An integer
    */Solution(int k) : __k(k)
    {
        // do intialization if necessary
    }

    /*
     * @param num: Number to be added
     * @return: nothing
     */
    void add(int num) {

    	
        
        if(__ordered.size() < __k)
        {
        	__ordered.insert(num);
        }
        else if(__ordered.size() == __k)
        {
        	auto _end = __ordered.end();
        	--_end;
        	if(*_end < num)
        	{
        		__ordered.erase(_end);
        		__ordered.insert(num);
        	}
        }
    }

    /*
     * @return: Top k element
     */
    vector<int> topk() {
        
        vector<int> ans(__ordered.begin(), __ordered.end());
        return ans;
    }
};