#include <iostream>
#include <vector>
using namespace std;

class Anurag {
public:
    void solve() {
        int n;
        cin >> n;

        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        for (int i = 0; i < n; i++) {
            if (b[i] > a[i]) {
                int diff = b[i] - a[i];
                for (int j = 0; j < n; j++) {
                    if (i != j && a[j] - b[j] < diff) {
                        cout << "NO\n";
                        return;
                    }
                }
            }
        }
        cout << "YES\n";
    }

    void process() {
        int t;
        cin >> t;

        for (int c = 0; c < t; c++) {
            solve();
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Anurag sol;
    sol.process();

    return 0;
}
