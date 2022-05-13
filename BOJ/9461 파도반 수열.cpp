/*
문제
오른쪽 그림과 같이 삼각형이 나선 모양으로 놓여져 있다. 첫 삼각형은 정삼각형으로 변의 길이는 1이다. 그 다음에는 다음과 같은 과정으로 정삼각형을 계속 추가한다. 나선에서 가장 긴 변의 길이를 k라 했을 때, 그 변에 길이가 k인 정삼각형을 추가한다.

파도반 수열 P(N)은 나선에 있는 정삼각형의 변의 길이이다. P(1)부터 P(10)까지 첫 10개 숫자는 1, 1, 1, 2, 2, 3, 4, 5, 7, 9이다.

N이 주어졌을 때, P(N)을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다. (1 ≤ N ≤ 100)

출력
각 테스트 케이스마다 P(N)을 출력한다.

풀이
N = 1: 1
N = 2: 1
N = 3: 1
N = 4: 2
N = 5: 2
N = 6: 3
N = 7: 4
N = 8: 5
N = 9: 7
N = 10: 9
N = 11: 12
N = 12: 16
N = 13: 21
N = 14: 28
N = 15: 37
N = 16: 49
N = 17: 65
규칙은 이렇게 나오며 점화식을 짜보면 P(N) = P(N-2) + P(N-3)이 나온다. 3 이하는 1을 리턴하고 4부터 연산하게 한다.
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll arr[101] = { 1,1,1 };

//ll f(ll n) {
//    if (n <= 3) return 1;
//    if (arr[n - 1]) return arr[n - 1];
//    return arr[n - 1] = f(n - 2) + f(n - 3);
//} //top down

ll f(ll n) {
    for (int i = 3; i < n; i++) {
        arr[i] = arr[i - 2] + arr[i - 3];
    }
    return arr[n - 1];
} //bottom up

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll N;
    int T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << f(N) << "\n";
    }
    return 0;
}