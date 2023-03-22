//main
#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}

vector<string> split(string input, string delimeter) {
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while ((pos = input.find(delimeter)) != string::npos) {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimeter.length());
    }
    ret.push_back(input);
    return ret;
}
