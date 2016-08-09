#include <iostream>
#include <vector>

using namespace std;

vector<int> Kmp(string S, string W){
    vector<int> T(W.size() + 1, -1);
    vector<int> matches;

    if(W.size() == 0){
        matches.push_back(0);
        return matches;
    }
    for(int i = 1; i <= W.size(); i++){
        int j = T[i - 1];
        while(j != -1 && W[j] != W[i - 1])
            j = T[j];
        T[i] = j + 1;
    }

    int si = 0;
    int wi = 0;
    while(si < S.size()){
        while(wi != -1 && (wi == W.size() || W[wi] != S[si]))
            wi = T[wi];
        wi++;
        si++;
        if(wi == W.size())
            matches.push_back(si - W.size());
    }
    return matches;
}

int main(){
    string s = "ABC ABCDAB ABCDABCDABDE ABCDABD";
    string k = "ABCDABD";

    vector<int> result = Kmp(s, k);

    cout << "Result:" << endl;
    for(int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
        else cout << endl;
    }
    return 0;
}

