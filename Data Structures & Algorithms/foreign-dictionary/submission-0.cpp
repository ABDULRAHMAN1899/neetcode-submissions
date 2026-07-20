class Solution {
private:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (auto neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return topo;
    }

public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();

        unordered_set<char> st;
        for (auto &word : words) {
            for (char ch : word)
                st.insert(ch);
        }

        // Use all 26 letters since you're indexing with ch-'a'
        vector<int> adj[26];

        for (int i = 0; i < n - 1; i++) {
            string &s1 = words[i];
            string &s2 = words[i + 1];

            int len = min(s1.size(), s2.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    found = true;
                    break;
                }
            }

            // Invalid prefix case
            if (!found && s1.size() > s2.size())
                return "";
        }

        vector<int> topo = topoSort(26, adj);

        string ans = "";

        // Only include characters that actually appeared
        for (int node : topo) {
            if (st.count(char(node + 'a')))
                ans += char(node + 'a');
        }

        // Cycle detection
        if (ans.size() != st.size())
            return "";

        return ans;
    }
};