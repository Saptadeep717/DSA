class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> st(bank.begin(), bank.end());
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        char choices[4] = {'A', 'C', 'G', 'T'};
        while (!q.empty()) {
            string gene = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (gene == endGene)
                return steps;
            for (int i = 0; i < 8; i++) {
                char c = gene[i];

                for (int j = 0; j < 4; j++) {
                    if (gene[i] != choices[j]) {
                        gene[i] = choices[j];
                        if (st.count(gene)) {
                            st.erase(gene);
                            q.push({gene, steps + 1});
                        }
                    }
                }
                gene[i] = c;
            }
        }

        return -1;
    }
};