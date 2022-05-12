/*
문제
다음 소스는 N번째 피보나치 수를 구하는 C++ 함수이다.

int fibonacci(int n) {
    if (n == 0) {
        printf("0");
        return 0;
    } else if (n == 1) {
        printf("1");
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
fibonacci(3)을 호출하면 다음과 같은 일이 일어난다.

fibonacci(3)은 fibonacci(2)와 fibonacci(1) (첫 번째 호출)을 호출한다.
fibonacci(2)는 fibonacci(1) (두 번째 호출)과 fibonacci(0)을 호출한다.
두 번째 호출한 fibonacci(1)은 1을 출력하고 1을 리턴한다.
fibonacci(0)은 0을 출력하고, 0을 리턴한다.
fibonacci(2)는 fibonacci(1)과 fibonacci(0)의 결과를 얻고, 1을 리턴한다.
첫 번째 호출한 fibonacci(1)은 1을 출력하고, 1을 리턴한다.
fibonacci(3)은 fibonacci(2)와 fibonacci(1)의 결과를 얻고, 2를 리턴한다.
1은 2번 출력되고, 0은 1번 출력된다. N이 주어졌을 때, fibonacci(N)을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다.

각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다. N은 40보다 작거나 같은 자연수 또는 0이다.

출력
각 테스트 케이스마다 0이 출력되는 횟수와 1이 출력되는 횟수를 공백으로 구분해서 출력한다.

풀이
먼저 규칙을 찾아보면
N == 0: 1 0
N == 1: 0 1
N == 2: 1 1
N == 3: 1 2
N == 4: 2 3
N == 5: 3 5
N == 6: 5 8
이렇게 피보나치 수열이 반복된다.
가로로도 피보나치 수열이 반복되기에 0일 땐 1 0 을 출력하게 하고 1 이상일 땐 피보나치 수열이 출력되게 하면 된다.
*/

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int arr[41] = { 0,1 };
 
int f(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (!arr[n]) return arr[n] = f(n - 1) + f(n - 2);
    return arr[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, n;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        if (n == 0) cout << "1 0\n";
        else cout << f(n-1) << " " << f(n) << "\n";
    }
    return 0;
}