class Solution {
public:
	vector<string> convertVec(string sentence) {

		istringstream istream(sentence);
		string word;
		vector<string> ret;
		while(istream >> word)
		{
			ret.emplace_back(word);
		}
		return ret;
	}
    bool areSentencesSimilar(string sentence1, string sentence2) {

    	auto v1 = convertVec(sentence1);
    	auto v2 = convertVec(sentence2);
    	if(v1.size() > v2.size())
    		swap(v1, v2);

    	int n1 = v1.size();
    	int n2 = v2.size();
    	int ll = 0;
    	int rr = v1.size() - 1;

    	int idx = 0;
    	while(idx < n2 && ll - 1 != rr && v1[ll] == v2[idx])
    	{
    		++ll;
    		++idx;
    	}

    	idx = n2 - 1;
    	while(idx >= 0 && ll - 1 != rr && v1[rr] == v2[idx])
    	{
    		--rr;
    		--idx;
    	}


    	return ll - 1 == rr;
    }
};