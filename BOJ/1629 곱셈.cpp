/*
문제
자연수 A를 B번 곱한 수를 알고 싶다. 단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 A, B, C가 빈 칸을 사이에 두고 순서대로 주어진다. A, B, C는 모두 2,147,483,647 이하의 자연수이다.

출력
첫째 줄에 A를 B번 곱한 수를 C로 나눈 나머지를 출력한다.

풀이
빠른 거듭제곱법을 이용한다.
*/
#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

ll A, B, C, res = 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B >> C;


    while (B > 1) {
        if (B & 1) res = res * A % C;
        A = A * A % C;
        B = B >> 1;
    }

    cout << A * res % C;

    return 0;
}
