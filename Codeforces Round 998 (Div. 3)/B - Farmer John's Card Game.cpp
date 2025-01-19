#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2005;

class Anurag {
public:
    int n, m, ans[MAX_N], nxt[MAX_N];
    priority_queue<int, vector<int>, greater<int>> pq[MAX_N];
    bool mk[MAX_N];

    void solve() {
        cin >> n >> m;

        int i = 0;
        while (i < n) {
            while (!pq[i].empty()) pq[i].pop();
            i++;
        }

        fill(nxt, nxt + MAX_N, -1);
        fill(mk, mk + MAX_N, 0);

        i = 0;
        while (i < n) {
            int x, j = 0;
            while (j < m) {
                cin >> x;
                pq[i].push(x);
                j++;
            }
            nxt[pq[i].top()] = i;
            i++;
        }

        int k = n * m;
        int ok = 1;
        i = 0;

        while (i < k) {
            if (i < n) {
                if (nxt[i] == -1) {
                    ok = 0;
                    break;
                }
                ans[i] = nxt[i];
                pq[nxt[i]].pop();
                if (!pq[nxt[i]].empty())
                    nxt[pq[nxt[i]].top()] = nxt[i];
                if (mk[nxt[i]]) {
                    ok = 0;
                }
                mk[nxt[i]] = 1;
            } else {
                if (nxt[i] == -1 || ans[i % n] != nxt[i]) {
                    ok = 0;
                    break;
                }
                pq[nxt[i]].pop();
                if (!pq[nxt[i]].empty())
                    nxt[pq[nxt[i]].top()] = nxt[i];
            }
            i++;
        }

        if (ok) {
            i = 0;
            while (i < n) {
                cout << ans[i] + 1 << ' ';
                i++;
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        Anurag obj;
        obj.solve();
    }

    return 0;
}
