#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]) {
    // number to string
    int num = 50;
    ostringstream oconvert;
    oconvert << num;
    string numStr = oconvert.str();

    cout << numStr <<endl;

    // string to number
    string text = "    456.123";
    double value;
    istringstream iconvert(text);
    if(!(iconvert >> value))
        value = 0;
    cout << value << endl;
    return 0;
}
