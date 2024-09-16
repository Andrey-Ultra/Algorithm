#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Aho {
    const int A = 26;
    int node_cnt, pattern_cnt;
    vector<vector<int>> next;
    vector<int> suf_link, terminal_link;
    vector<vector<int>> terminals;

    Aho() : node_cnt(0), pattern_cnt(0) { node(); }

    int node() {
        next.emplace_back(A);
        suf_link.emplace_back();
        terminal_link.emplace_back();
        terminals.emplace_back();
        return node_cnt++;
    }

    inline int get(char c) {
        return c - 'a';
    }

    int add_pattern(const string &s) {
        int v = 0;
        for (auto c: s) {
            if (!next[v][get(c)]) next[v][get(c)] = node();
            v = next[v][get(c)];
        }
        terminals[v].emplace_back(pattern_cnt);
        return pattern_cnt++;
    }

    void build() {
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int par = q.front();
            q.pop();
            for (int c = 0; c < A; ++c) {
                int child = next[par][c];
                if (!child) {
                    next[par][c] = next[suf_link[par]][c];
                    continue;
                }
                if (par == 0) suf_link[child] = 0;
                else suf_link[child] = next[suf_link[par]][c];

                if (terminals[suf_link[child]].empty()) terminal_link[child] = terminal_link[suf_link[child]];
                else terminal_link[child] = suf_link[child];

                q.push(child);
            }
        }
    }

    int go(int v, char c) {
        return next[v][get(c)];
    }

    vector<int> get_matches(int v) {
        vector<int> res;
        while (v) {
            for (auto match: terminals[v]) res.emplace_back(match);
            v = terminal_link[v];
        }
        return res;
    }
};


int main(){
    string  s, s1;
    cin >> s;
    int n;
    cin >> n;

    Aho a;

    for (int i = 0; i < n; ++i) {
        cin >> s1;
        a.add_pattern(s1);
        
    }

}