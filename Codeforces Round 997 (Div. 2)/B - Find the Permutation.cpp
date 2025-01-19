#include <bits/stdc++.h>
using namespace std;

class Anurag {
private:
    vector<string> res;

    int compareResults(int x, int y) const {
        if (x >= res.size() || y >= res.size() || x < 0 || y < 0)
            return 0;
        if (x < y) {
            return (res[x][y] == '1') ? 1 : -1;
        }
        return (res[y][x] == '0') ? 1 : -1;
    }

public:
    void solve() {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int t;
        cin >> t;
        
        while (t--) {
            int s;
            cin >> s;

            res.clear();
            res.resize(s);

            for (int i = 0; i < s; i++) {
                cin >> res[i];
                if (res[i].length() != s) {
                    cout << "Invalid input\n";
                    return;
                }
            }

            vector<int> rankings(s);
            for (int i = 0; i < s; i++) {
                rankings[i] = i;
            }

            sort(rankings.begin(), rankings.begin() + s,
                [this](int a, int b) {
                    return this->compareResults(a, b) > 0;
                });

            for (int i = 0; i < s; i++) {
                cout << rankings[i] + 1;
                if (i < s - 1) cout << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Anurag solution;
    solution.solve();
    return 0;
}
