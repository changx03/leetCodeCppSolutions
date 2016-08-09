#include <iostream>

using namespace std;

bool IsVowel(char c) {
    string vowels = "aeiouAEIOU";
    for(int k = 0; k < vowels.size(); k++) {
        if(c == vowels[k]) {
            return true;
        }
    }
    return false;
}

void Swap(char& a, char& b){
    char t = a;
    a = b;
    b = t;
}

string reverseVowels(string s) {   
    int i, j;
    i = 0;
    j = s.size() - 1;
    string reverse = s;
    while(i < j) {
        if(!IsVowel(s[i])){
            i++;
            continue;
        }
        if(!IsVowel(s[j])){
            j--;
            continue;
        }
        Swap(reverse[i], reverse[j]);
        i++;
        j--;
    }    
    return reverse;
}

int main(){
    string testStr = "Hello World!";
    string resultStr = reverseVowels(testStr);
    cout << resultStr << endl;
    return 0;
}

