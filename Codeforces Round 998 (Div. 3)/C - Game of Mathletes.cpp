#include <bits/stdc++.h>
using namespace std;

class Anurag {
public:
    void solve() {
        int t;
        cin >> t;

        while (t--) {
            int n, s;
            cin >> n >> s;

            vector<int> a(n);
            int minVal = INT_MAX, maxVal = INT_MIN;

            int i = 0;
            while (i < n) {
                cin >> a[i];
                minVal = min(minVal, a[i]);
                maxVal = max(maxVal, a[i]);
                ++i;
            }

            int offset = -minVal;
            vector<int> freq(maxVal - minVal + 1, 0);

            i = 0;
            while (i < n) freq[a[i++] + offset]++;

            int r = 0, v = 0;

            while (v < freq.size()) {
                int value = v - offset, complement = s - value;
                if (complement >= minVal && complement <= maxVal) {
                    int cIndex = complement + offset;
                    if (cIndex >= 0 && cIndex < freq.size()) {
                        if (complement == value) {
                            r += freq[v] / 2;
                            freq[v] = 0;
                        } else if (freq[cIndex] > 0) {
                            int p = min(freq[v], freq[cIndex]);
                            r += p;
                            freq[v] -= p;
                            freq[cIndex] -= p;
                        }
                    }
                }
                ++v;
            }

            cout << r << endl;
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    Anurag().solve();
    return 0;
}
