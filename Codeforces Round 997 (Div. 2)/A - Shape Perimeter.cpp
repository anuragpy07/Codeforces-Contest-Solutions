#include <bits/stdc++.h>
using namespace std;

class Anurag {
    public:
        vector<int> a, b;
        int t, n, m;
        
        void input() {
            cin >> t;
            while (t > 0) {
                cin >> n >> m;
                a.resize(n);
                b.resize(n);
                int i = 0;
                while (i < n) {
                    cin >> a[i] >> b[i];
                    i++;
                }
                calculate_result();
                t--;
            }
        }
        
        void calculate_result() {
            int r = 4 * m * n;
            int i = 1;
            while (i < n) {
                int da = m - a[i];
                int db = m - b[i];
                r -= 2 * (da + db);
                i++;
            }
            cout << r << endl;
        }
        
        void run() {
            input();
        }
};

int main() {
    Anurag obj;
    obj.run();
    return 0;
}
