#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;

    while (true) {
        cin >> a >> b;
        if (a == "0" && b == "0")
            break;

        if (a.length() > b.length())
            b = string(a.length() - b.length(), '0') + b;
        else
            a = string(b.length() - a.length(), '0') + a;

        int cnt = 0, carry = 0;

        for (int i = a.length() - 1; i >= 0; --i) {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            if (sum >= 10) {
                cnt++;
                carry = 1;
            } else {
                carry = 0;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
