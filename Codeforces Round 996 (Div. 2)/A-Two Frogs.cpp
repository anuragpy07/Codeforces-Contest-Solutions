#include <iostream>
#include <cmath>
using namespace std;

class Anurag {
public:
    void s() {
        int q;
        cin >> q;
        
        while (q--) {
            int t, x, y;
            cin >> t >> x >> y;
            
            int d = abs(x - y) % 2;
            cout << (d == 0 ? "YES" : "NO") << endl;
        }
    }
};

int main() {
    Anurag a;
    a.s();
    return 0;
}
