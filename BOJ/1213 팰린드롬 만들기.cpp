/*
문제
임한수와 임문빈은 서로 사랑하는 사이이다.

임한수는 세상에서 팰린드롬인 문자열을 너무 좋아하기 때문에, 둘의 백일을 기념해서 임문빈은 팰린드롬을 선물해주려고 한다.

임문빈은 임한수의 영어 이름으로 팰린드롬을 만들려고 하는데, 임한수의 영어 이름의 알파벳 순서를 적절히 바꿔서 팰린드롬을 만들려고 한다.

임문빈을 도와 임한수의 영어 이름을 팰린드롬으로 바꾸는 프로그램을 작성하시오.

입력
첫째 줄에 임한수의 영어 이름이 있다. 알파벳 대문자로만 된 최대 50글자이다.

출력
첫째 줄에 문제의 정답을 출력한다. 만약 불가능할 때는 "I'm Sorry Hansoo"를 출력한다. 정답이 여러 개일 경우에는 사전순으로 앞서는 것을 출력한다.

풀이
카운팅 배열과 누적합을 이용해서 단순 구현했다.
*/
#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

string str;
int arr[27], arr2[27], flag, max_odd;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> str;

    vector<int> s(str.begin(), str.end());

    sort(s.begin(), s.end());
    for (auto iter : s) {
        arr[iter - 64]++;
        arr2[iter - 64]++;
    }
    for (int i = 1; i < 27; i++) {
        if (arr[i] % 2) flag++;
        arr[i] += arr[i - 1];
        if (arr2[i] % 2) {
            max_odd = i;
        }
    }
    if (flag > 1) {
        cout << "I'm Sorry Hansoo";
    }
    else {
        for (int i = 1; i < 27; i++) {
            flag = arr2[i] / 2;
            if (arr2[i] % 2 && arr2[i] != 1 && !max_odd) flag = 2;
            while (arr2[i] / 2 && flag--) {
                cout << (char)s[arr[i] - arr2[i]];
                arr2[i]--;
            }
        }
        if (max_odd) {
            cout << (char)s[arr[max_odd] - arr2[max_odd]];
            arr2[max_odd]--;
        }
        for (int i = 26; i > 0; i--) {
            while (arr2[i]) {
                cout << (char)s[arr[i] - arr2[i]];
                arr2[i]--;
            }
        }
    }

    return 0;
}