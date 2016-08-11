#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    vector<int> pOne = digits;
    int i = digits.size() - 1;
    while(i >= 0) {
        if(digits[i] < 9) {
            pOne[i] += 1;
            break;
        } else {
            pOne[i] = 0;
        }
         i--;
    }
    if(i < 0 && pOne[0] == 0) {
        pOne.insert(pOne.begin(), 1);
    }
    return pOne;
}

int main(int argc, char *argv[]) {
    vector<int> digits = {9, 9, 9, 9};
    plusOne(digits);
    return 0;
}
