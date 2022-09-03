// 208. 实现 Trie (前缀树)

class Trie {
private:
	class TrieNode {
	public:
		bool is_end;
		TrieNode* children[26];
		TrieNode()
		{
			is_end = false;
			memset(children, 0, sizeof(children));
		}
	};
	TrieNode* root;
	TrieNode* searchPrefix(string word)
	{
		TrieNode* p = root;
		for(char ch : word)
		{
			int i = ch - 'a';
			if(p->children[i] != nullptr)
				p = p->children[i];
			else
				return nullptr;
		}

		return p;
	}
public:
    Trie() {
    	root = new TrieNode();
    }
    
    void insert(string word) {

    	TrieNode* p = root;
    	for(char ch : word)
    	{
    		int i = ch - 'a';
    		if(p->children[i] == nullptr)
    		{
    			p->children[i] = new TrieNode();
    		}
    		p = p->children[i];
    	}
    	p->is_end = true;
    }
    
    bool search(string word) {

    	TrieNode* p = searchPrefix(word);
    	return p && p->is_end;
    }
    
    bool startsWith(string prefix) {

    	return searchPrefix(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */