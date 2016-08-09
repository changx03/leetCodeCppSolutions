#include <iostream>

using namespace std;

int getSum(int a, int b) {
    while(b){
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

int main() {
    cout << getSum(4, 4) << endl;
    return 0;
}

