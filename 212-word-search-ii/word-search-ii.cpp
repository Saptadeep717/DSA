class Solution {
public:
    class Node {
    public:
        char s;
        bool isTerminal;
        string word;
        unordered_map<char, Node*> children;

        Node(char s) {
            this->s = s;
            isTerminal = false;
            word = "";
        }
    };

    class Trie {
    public:
        Node* root;

        Trie() { root = new Node('\0'); }

        void add(string& word) {
            Node* temp = root;

            for (char ch : word) {
                if (!temp->children.count(ch)) {
                    temp->children[ch] = new Node(ch);
                }
                temp = temp->children[ch];
            }
            temp->isTerminal = true;
            temp->word = word;
        }
    };

    void dfs(int i, int j, vector<vector<char>>& board,
             vector<vector<int>>& vis, unordered_set<string>& st, Node* node) {
        int n = board.size(), m = board[0].size();
        char ch = board[i][j];
        // base case-> starting char not in trie
        if (!node->children.count(ch)) {
            return;
        }

        vis[i][j] = true;
        node = node->children[ch];
        if (node->isTerminal) {
            st.insert(node->word);
        }

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (auto [dx, dy] : dirs) {
            int ni = i + dx;
            int nj = j + dy;

            if (ni >= 0 && nj >= 0 && ni < n && nj < m && !vis[ni][nj]) {
                dfs(ni, nj, board, vis, st, node);
            }
        }

        vis[i][j] = false;
        return;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        int n = board.size(), m = board[0].size();
        Trie t;
        for (auto it : words) {
            t.add(it);
        }
        vector<vector<int>> vis(n, vector<int>(m, 0));
        unordered_set<string> st;
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(i, j, board, vis, st, t.root);
            }
        }

        for (auto it : st)
            ans.push_back(it);
        return ans;
    }
};