#include <iostream>

using namespace std;

int strStr(string haystack, string needle) {
    for(unsigned int i = 0; i <= haystack.size(); i++) {
        for(unsigned int j = 0; j <= needle.size(); j++) {
            if(j == needle.size())
                return i;
            if(j+i >= haystack.size())
                return -1;
            if(haystack[i+j] != needle[j])
                break;
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {

    cout << strStr("", "") << endl;
    cout << strStr("abcd", "d") << endl;
    cout << strStr("abdabcabc", "abc") << endl;
    return 0;
}
