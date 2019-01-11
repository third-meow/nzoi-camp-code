#include <iostream>
using namespace std;
int main () {
    int i, n[4];
    char l[15];
    for (i = 4; i > 0; i--)
        *(n + 4 - i) = i;
    *(n + 2) = 0xe;
    ++n[3];
    for (i = 0; i < 15; i++)
        l[i] = i + 0x41;
    int c = 3;
    cout << l[n[c]];
    for (c--; c >= 0; c--)
        cout << " " << l[n[c]];
    cout << '\n';
}
// Should print “C O D E”.
