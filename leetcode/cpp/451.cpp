class Solution {
public:
    string frequencySort(string s) {

    	unordered_map<char, int> memo;
    	for(char c : s)
    		++memo[c];

    	sort(s.begin(), s.end(), [&](char a, char b){
    		if(memo[a] != memo[b])
    			return memo[a] > memo[b];
    		else
    			return a > b;
    	});

    	return s;
    }
};