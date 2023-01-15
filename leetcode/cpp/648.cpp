class Trie
{
public:
	class trieNode
	{
	public:
		bool isEnd;
		trieNode* children[26];
		trieNode()
		{
			isEnd = false;
			memset(children, 0, sizeof(children));
		}
	};
	trieNode* root = new trieNode();
	void insert(const string& word) {

		trieNode *p = root;
		for(char c : word)
		{
			int next = c - 'a';
			if(p->children[next] == nullptr)
				p->children[next] = new trieNode();
			p = p->children[next];
		}
		p->isEnd = true;
	}
	string replaceWord(const string& word) {

		int n = word.size();
		trieNode *p = root;
		for(int i = 0; i < n; ++i)
		{
			int next = word[i] - 'a';
			if(p->children[next] == nullptr)
				return word;
			p = p->children[next];
			if(p->isEnd)
				return word.substr(0, i + 1);
		}
		return word;
	}
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {

    	Trie trie;
    	for(auto& word : dictionary)
    		trie.insert(word);

    	istringstream istream(sentence);
    	string word;
    	string ans;
    	while(istream >> word)
    	{
    		ans.append(trie.replaceWord(word) + " ");
    	}
    	ans.pop_back();
    	return ans;
    }
};