#include <iostream>

using namespace std;

int reverse(int x) {
    double rev = 0.0;
    while(x != 0) {
        rev = rev*10 + x%10;
        if(rev > INT_MAX || rev < INT_MIN) {
            return 0;
        }
        x /= 10;
    }
    return (int)rev;
}

int main(int argc, char *argv[]) {
    int x = -2147483648;
    cout << reverse(x) << endl;
    return 0;
}
