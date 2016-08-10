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
    while(i < j){
        if(s[i] == ' ') i++;
        if(s[j] == ' ') j--;
        if(s[i] != ' ' && s[j] != ' ') break;
    }
    if((s[i] == '+' || s[i] == '-') && (i < j)) i++;
    bool isFloat = false;
    bool anyNum = false;
    while(i <= j) {
        if(!isDigit(s[i])){
            if(s[i] == '.'&& !isFloat) {
                i++;
                isFloat = true;
                continue;
            } else if((s[i] == 'e' || s[i] == 'E') && anyNum && (i<j)) {
                if(s[i+1] == '+' || s[i+1] == '-') i = i+ 2;
                else i++;
                anyNum = false;
                while(i<= j) {
                    if(isDigit(s[i])){
                        anyNum = true;
                        i++;
                    }else
                        return false;
                }
            } else
                return false;
        } else{
            anyNum = true;
        }
        i++;
    }
    return anyNum;
}


int main(int argc, char *argv[]) {
    //string str = " 0 ";
    //string str = "6e6.5";
    //string str = " +88 ";
    //string str = " -8A8  ";
    //string str = "  -6.8";
    //string str = " +.55";
    //string str = " 9999999999999999.";
    //string str = "0. ";
    //string str = "0e4";
    //string str = "0e.4";
    //string str = " ";
    //string str = "e";
    //string str = ".1";
    //string str = "46.e3";
    //string str = " 005047e+6  ";
    //string str = " 005047e+  ";
    string str = "6e6.5";
    bool num = isNumber(str);
    cout << str << " is digit: " << num << endl;
    return 0;
}
