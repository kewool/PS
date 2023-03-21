/*
문제
상근이는 트럭을 총 세 대 가지고 있다. 오늘은 트럭을 주차하는데 비용이 얼마나 필요한지 알아보려고 한다.

상근이가 이용하는 주차장은 주차하는 트럭의 수에 따라서 주차 요금을 할인해 준다.

트럭을 한 대 주차할 때는 1분에 한 대당 A원을 내야 한다. 두 대를 주차할 때는 1분에 한 대당 B원, 세 대를 주차할 때는 1분에 한 대당 C원을 내야 한다.

A, B, C가 주어지고, 상근이의 트럭이 주차장에 주차된 시간이 주어졌을 때, 주차 요금으로 얼마를 내야 하는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 문제에서 설명한 주차 요금 A, B, C가 주어진다. (1 ≤ C ≤ B ≤ A ≤ 100)

다음 세 개 줄에는 두 정수가 주어진다. 이 정수는 상근이가 가지고 있는 트럭이 주차장에 도착한 시간과 주차장에서 떠난 시간이다. 도착한 시간은 항상 떠난 시간보다 앞선다. 입력으로 주어지는 시간은 1과 100사이 이다.

출력
첫째 줄에 상근이가 내야하는 주차 요금을 출력한다.

풀이
최솟값과 최댓값을 구한 다음 그걸로 for문을 돌린다.
그 뒤 각 시간별로 if문을 돌려서 tmp에 a b c를 넣은다음 result에 더한다
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, arr[3][2] = { 0 }, maxNum = 0, minNum = 100, result = 0;
    scanf("%d %d %d", &a, &b, &c);
    for (int i = 0; i < 3; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
        maxNum = max(maxNum, arr[i][1]);
        minNum = min(minNum, arr[i][0]);
    }
    for (int i = minNum; i <= maxNum; i++) {
        int tmp = 0;
        if (arr[0][0] < i && i <= arr[0][1]) tmp = a;
        if (arr[1][0] < i && i <= arr[1][1]) {
            if (tmp == a) tmp = b * 2;
            else tmp = a;
        }
        if (arr[2][0] < i && i <= arr[2][1]) {
            if (tmp == a) tmp = b * 2;
            else if (tmp == b * 2) tmp = c * 3;
            else tmp = a;
        }
        result += tmp;
    }
    printf("%d", result);

    return 0;
}