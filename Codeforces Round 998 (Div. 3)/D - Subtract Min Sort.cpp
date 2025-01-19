#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 300005;

class Anurag {
public:
    int l, q;
    vector<int> a;
    void solve() {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int t;
        cin >> t;
        while (t--) {
            cin >> l;
            a.resize(l);
            for (int i = 0; i < l; ++i) cin >> a[i];
            bool p = 1;
            int i = 1;
            while (i < l) {
                if (i == 1 || a[i - 2] == 0) {
                    int m = min(a[i - 1], a[i]);
                    a[i] -= m, a[i - 1] -= m;
                }
                i++;
            }
            i = 1;
            while (i < l) p &= (a[i] >= a[i - 1]), i++;
            cout << (p ? "YES" : "NO") << endl;
        }
    }
};

int main() {
    Anurag obj;
    obj.solve();
}
