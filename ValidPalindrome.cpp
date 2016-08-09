#include <iostream>

using namespace std;

bool IsAlphabetOrDigit(char c) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return true;
    return false;
}

char ToLower(char c) {
    if(c >= 'A' && c <= 'Z') {
        c += ('a' - 'A');
    }
    return c;
}

bool isPalindrome(string s) {
    int i = 0;
    int j = s.size() - 1;

    while(i < j) {
        if(!IsAlphabetOrDigit(s[i])){
            i++;
            continue;
        }
        if(!IsAlphabetOrDigit(s[j])){
            j--;
            continue;
        }
        if(ToLower(s[i]) != ToLower(s[j]))
            return false;
        i++;
        j--;
    }
    return true;
}

int main() {
    // STL testcase:
    int a, A, b, B;
    a = isalpha('a');
    cout << "a = " << a << endl;
    A = isalpha('A');
    cout << "A = " << A << endl;
    b = isalpha('b');
    cout << "b = " << b << endl;
    B = isalpha('B');
    cout << "B = " << B << endl;

    a = tolower('a');
    cout << "a = " << a << endl;
    A = tolower('A');
    cout << "A = " << A << endl;
    b = tolower('b');
    cout << "b = " << b << endl;
    B = tolower('B');
    cout << "B = " << B << endl;

    // Testcase:
    string s = "A man, a plan, a canal: Panama";
//    string s = "0p";
//    string s = "a.";
    cout << s << endl;
    if(isPalindrome(s)) {
        cout << "is a palindrome." << endl;
    } else {
        cout << "is not a palindrome." << endl;
    }
    return 0;
}

