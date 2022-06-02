#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



string str, str2;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> str;
	str2 = str;
	reverse(str2.begin(), str2.end());

	if (str.substr(0, (str.length() / 2)) == str2.substr(0, (str.length() / 2))) cout << 1;
	else cout << 0;
	return 0;
}