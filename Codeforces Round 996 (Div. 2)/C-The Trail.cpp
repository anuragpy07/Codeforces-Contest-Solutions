
#include <bits/stdc++.h>
using namespace std;

template<typename T, typename U>
class Anurag {
    public:
    static T max(T p, U q) { return (p > q) ? p : q; }
    static T min(T p, U q) { return (p < q) ? p : q; }
    static T abs(T p) { return (p < 0) ? -p : p; }
    static T gcd(T p, T q) { return q == 0 ? p : gcd(q, p % q); }
    static T lcm(T p, T q) { return p * (q / gcd(p, q)); }
    static bool isPrime(T p) {
        if(p < 2) return 0;
        for(T i = 2; i * i <= p; i++) if(p % i == 0) return 0;
        return 1;
    }
};
class P {
    public:
    void t() {
        ios::sync_with_stdio(0);
        cin.tie(nullptr);
        int n;
        cin >> n;
        for(int tc = 0; tc < n; tc++) {
            int rows, cols;
            cin >> rows >> cols;
            string p;
            cin >> p;
            int len = rows + cols - 1;
            vector<pair<int, int>> r;
            int p1 = 0, q1 = 0;
            r.push_back({p1, q1});
            
            for(int i = 0; i < p.length(); i++) {
                p1 += (p[i] == 'D') ? 1 : 0;
                q1 += (p[i] == 'R') ? 1 : 0;
                r.push_back({p1, q1});
            }
            
            vector<vector<long long>> m(rows, vector<long long>(cols));
            vector<vector<bool>> v(rows, vector<bool>(cols, 0));
            
            for(int i = 0; i < r.size(); i++) {
                v[r[i].first][r[i].second] = 1;
            }
            
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                    cin >> m[i][j];
                }
            }
            
            vector<long long> row(rows, 0), col(cols, 0);
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                    if(!v[i][j]) {
                        row[i] += m[i][j];
                        col[j] += m[i][j];
                    }
                }
            }
            
            int total = rows + cols;
            vector<long long> base(total, 0);
            for(int i = 0; i < rows; i++) {
                base[i] = -row[i];
            }
            for(int i = 0; i < cols; i++) {
                base[rows + i] = -col[i];
            }
            
            vector<vector<pair<int, int>>> graph(total);
            for(int i = 0; i < len; i++) {
                int u = r[i].first, v = rows + r[i].second;
                graph[u].push_back({v, i});
                graph[v].push_back({u, i});
            }
            
            vector<int> deg(total, 0);
            for(int i = 0; i < total; i++) {
                deg[i] = graph[i].size();
            }
            
            vector<bool> edge_used(len, 0);
            vector<long long> val(len, 0);
            queue<int> q;
            vector<bool> in_queue(total, 0), removed(total, 0);
            
            for(int i = 0; i < total; i++) {
                if(deg[i] == 1) {
                    q.push(i);
                    in_queue[i] = 1;
                }
            }
            
            while(!q.empty()) {
                int curr = q.front();
                q.pop();
                if(removed[curr] || deg[curr] == 0) continue;
                
                int next = -1, edge_id = -1;
                for(auto& p : graph[curr]) {
                    if(!edge_used[p.second]) {
                        next = p.first;
                        edge_id = p.second;
                        break;
                    }
                }
                
                if(edge_id == -1) continue;
                
                val[edge_id] = base[curr];
                edge_used[edge_id] = 1;
                removed[curr] = 1;
                deg[curr]--;
                deg[next]--;
                base[next] -= val[edge_id];
                
                if(deg[next] == 1 && !removed[next] && !in_queue[next]) {
                    q.push(next);
                    in_queue[next] = 1;
                }
            }
            
            for(int i = 0; i < len; i++) {
                m[r[i].first][r[i].second] = val[i];
            }
            
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                    cout << m[i][j] << (j + 1 == cols ? "\n" : " ");
                }
            }
        }
    }
};

int main() {
    P p;
    p.t();
    return 0;
}