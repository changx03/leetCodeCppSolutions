#include <iostream>

using namespace std;

bool isDigit(char c) {
    if(c >= '0' && c <= '9')
        return true;
    else
        return false;
}

bool isNumber(string s) {
    if(s.size() == 0) {
        return false;
    }
    int i = 0;
    int j = s.size() - 1;
    while(i <= j){
        if(s[i] == ' ') i++;
        if(s[j] == ' ') j--;
        if(s[i] != ' ' && s[j] != ' ') break;
    }
    if((s[i] == '+' || s[i] == '-') && (i <= j)) i++;
    bool isNumeric = false;
    while(i <= j && isDigit(s[i])) {
        isNumeric = true;
        i++;
    }
    if((s[i] == '.') && (i <= j)) {
        i++;
        while(i <= j && isDigit(s[i])){
            isNumeric = true;
            i++;
        }
    }
    if((s[i] == 'e' || s[i] == 'E') && isNumeric){
        isNumeric = false;
        i++;
        if((s[i] == '+' || s[i] == '-') && (i <= j)) i++;
        while(i <= j){
            if(isDigit(s[i])) {
                i++;
                isNumeric = true;
            } else {
                return false;
            }
        }
    }
    while(i <= j){
        if(isDigit(s[i])) {
            i++;
            isNumeric = true;
        } else {
            return false;
        }
    }
    return isNumeric;
}


int main(int argc, char *argv[]) {
//     string str = " A ";
    //    string str = " 0 ";
    //    string str = "6e6.5";
    //    string str = " +88 ";
    //    string str = " -8A8  ";
    //    string str = "  -6.8";
//        string str = " +.55";
//    string str = "9.";  // expected answer: True!
//    string str = "0..";
//    string str = "0e.4";
//    string str = " ";
//    string str = "e";
//    string str = ".1";
    string str = "46.e3";  // expected answer: True!
    //string str = " 005047e+6  ";
    //string str = " 005047e+  ";
    bool num = isNumber(str);
    cout << str << " is digit: " << num << endl;
    return 0;
}
