#include <iostream>
#include <cstring>
using namespace std;

int lengthOfLongestSubstring(string s) {
    bool existTab[256];
    memset(existTab, 0, 256);
    int idxStart = 0;
    int maxLen = 0;
    for(int idxCur = 0; idxCur < s.size(); idxCur++) {
        while(existTab[(int)s[idxCur]]) {
            existTab[(int)s[idxStart]] = false;
            idxStart++;
        }
        existTab[(int)s[idxCur]] = true;
        maxLen = max(idxCur-idxStart+1, maxLen);
    }
    return maxLen;
}

int main(int argc, char *argv[]) {
    string str = "abcbb";
    cout << lengthOfLongestSubstring(str) << endl;
    return 0;
}
