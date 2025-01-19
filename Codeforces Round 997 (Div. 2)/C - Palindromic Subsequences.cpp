#include <bits/stdc++.h>
using namespace std;

const int MAX_LENGTH = 105;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int sql;
        cin >> sql;

        cout << "1 ";
        
        int i = 2;
        while (i <= sql - 2) {
            cout << i - 1 << " ";
            i++;
        }

        cout << "1 2\n";
    }

    return 0;
}
