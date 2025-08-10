class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if (startGene == endGene) return 0;

        unordered_set<string> dict(bank.begin(), bank.end());
        if (!dict.count(endGene)) return -1;  

        queue<pair<string,int>> q;
        q.push({startGene, 0});

        // mark visited by removing from dict as soon as we enqueue
        if (dict.count(startGene)) dict.erase(startGene);

        static const char bases[4] = {'A','C','G','T'};

        while (!q.empty()) {
            auto [cur, steps] = q.front(); q.pop();
            if (cur == endGene) return steps;

            for (int i = 0; i < 8; ++i) {
                char orig = cur[i];
                for (char b : bases) {
                    if (b == orig) continue;
                    cur[i] = b;
                    if (dict.count(cur)) {
                        dict.erase(cur);
                        q.push({cur, steps + 1});
                    }
                }
                cur[i] = orig; // restore
            }
        }
        return -1;
    }
};
