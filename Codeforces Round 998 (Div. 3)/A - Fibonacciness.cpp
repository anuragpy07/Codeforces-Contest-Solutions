#include <bits/stdc++.h>
using namespace std;

class Anurag {
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            int a1, a2, a3, a4;
            cin >> a1 >> a2 >> a3 >> a4;

            int m = 0;
            int c[] = {a3 - a2, a4 - a3};

            for (int x : c) {
                int s = 0;
                for (bool cond : {a3 == a2 + x, a4 == x + a3, x == a2 + a1}) {
                    if (cond) s++;
                }
                m = max(m, s);
            }

            cout << m << endl;
        }
    }
};

int main() {
    Anurag obj;
    obj.solve();
    return 0;
}
