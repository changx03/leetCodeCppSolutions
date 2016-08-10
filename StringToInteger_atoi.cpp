#include <iostream>

using namespace std;

int myAtoi(string str) {
    int num = 0;
    double d = 0.0;
    bool isStarted = false;
    int sign = 1;
    for(unsigned int i = 0; i < str.size(); i++) {
        if(str[i] == ' ' && !isStarted) {
            continue;
        } else if(str[i] == '+' && !isStarted) {
            isStarted = true;
            continue;
        } else if(str[i] == '-' && !isStarted) {
            sign = -sign;
            isStarted = true;
            continue;
        } else if(!(str[i] >= '0' && str[i] <= '9')) {
            num = d;
            break;
        }

        isStarted = true;
        d = d*10 + (int)(str[i] - '0');
        if((sign * d) >= INT_MAX) {
            return INT_MAX;
        } else if ((sign * d) <= INT_MIN) {
            return INT_MIN;
        } else {
            num = (int)d;
        }
    }
    return sign * num;
}

int main(int argc, char *argv[]){
//    string str = "  88999AAA";
//    string str = " --++88";
//    string str = "+88";
//    string str = " -8A";
//    string str = "  -6.8";
    string str = " +1A.46T";
//    string str = " 9999999999999999.A";
    int num = myAtoi(str);
    cout << str << " = " << num << endl;
    return 0;
}
