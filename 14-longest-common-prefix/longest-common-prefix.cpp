class TrieNode{
public:
	TrieNode *children[26];
	bool isTerminal=false;

	TrieNode(){
		for(int i=0;i<26;i++)children[i]=NULL;
	}
};

class Trie{
public:
	TrieNode* root;
	Trie(){
		this->root = new TrieNode();
	}

	void insert(string &word){
		TrieNode* node = root;
		for(char c : word){
			int idx = c-'a';
			if(!node->children[idx]){
				node->children[idx] = new TrieNode();
			}
			node = node->children[idx];
		}
		node->isTerminal = true;
	}


	bool search(string &word){
		TrieNode* node = root;
		for(char c : word){
			int idx = c-'a';
			if(!node->children[idx]){
				return false;
			}
			node = node->children[idx];
		}
		return node->isTerminal;
	}


	bool startsWith(string &word){
		TrieNode* node = root;
		for(char c : word){
			int idx = c-'a';
			if(!node->children[idx]){
				return false;
			}
			node = node->children[idx];
		}
		return true;
	}

    string longestCommonPrefix(){
        TrieNode* node = root;
        string ans = "";
        while(1){
            int childCnt = 0;
            int childIdx = -1;
            for(int i=0;i<26;i++){
                if(node->children[i]){
                    childCnt++;
                    childIdx = i;
                }
            }
            if(childCnt > 1 || node->isTerminal) break;
            ans.push_back(char('a'+ childIdx));
            node = node->children[childIdx];
        }
        return ans;
    }


};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie t;

        for(auto &it : strs){
            t.insert(it);
        }

        return t.longestCommonPrefix();
    }
};