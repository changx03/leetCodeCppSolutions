#include <iostream>
#include <vector>

using namespace std;

bool IsAlphabetOrDigit(char c) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return true;
    return false;
}

void reverseWords(string &s) {
    string reverse = "";
    int j = s.size();
    for(int i = s.size() - 1; i >= 0; i--) {
        if(s[i] == ' ') {
            j = i;
        }
        else if(i == 0 || s[i-1] == ' ') {
            if(reverse.size() != 0) {
                reverse += " ";
            }
            reverse += s.substr(i, j - i);
        }
    }
    s = reverse;
}

int main(int argc, char *argv[]) {
    string s = "   Hello World!";
//    s = " a";
    cout << s << endl;
    reverseWords(s);
    cout << s << endl;
    return 0;
}
