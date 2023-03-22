/*
문제
미친놈

입력
첫째 줄에는 도감에 수록되어 있는 포켓몬의 개수 N이랑 내가 맞춰야 하는 문제의 개수 M이 주어져. N과 M은 1보다 크거나 같고, 100,000보다 작거나 같은 자연수인데, 자연수가 뭔지는 알지? 모르면 물어봐도 괜찮아. 나는 언제든지 질문에 답해줄 준비가 되어있어.

둘째 줄부터 N개의 줄에 포켓몬의 번호가 1번인 포켓몬부터 N번에 해당하는 포켓몬까지 한 줄에 하나씩 입력으로 들어와. 포켓몬의 이름은 모두 영어로만 이루어져있고, 또, 음... 첫 글자만 대문자이고, 나머지 문자는 소문자로만 이루어져 있어. 아참! 일부 포켓몬은 마지막 문자만 대문자일 수도 있어. 포켓몬 이름의 최대 길이는 20, 최소 길이는 2야. 그 다음 줄부터 총 M개의 줄에 내가 맞춰야하는 문제가 입력으로 들어와. 문제가 알파벳으로만 들어오면 포켓몬 번호를 말해야 하고, 숫자로만 들어오면, 포켓몬 번호에 해당하는 문자를 출력해야해. 입력으로 들어오는 숫자는 반드시 1보다 크거나 같고, N보다 작거나 같고, 입력으로 들어오는 문자는 반드시 도감에 있는 포켓몬의 이름만 주어져. 그럼 화이팅!!!

출력
첫째 줄부터 차례대로 M개의 줄에 각각의 문제에 대한 답을 말해줬으면 좋겠어!!!. 입력으로 숫자가 들어왔다면 그 숫자에 해당하는 포켓몬의 이름을, 문자가 들어왔으면 그 포켓몬의 이름에 해당하는 번호를 출력하면 돼. 그럼 땡큐~

풀이
인덱스로 접근하기 위한 vector와 이름으로 접근하기 위한 hash_map을 각각 만들어주고 값을 넣어준다.
hash_map은 표준 std에선 unordered_map으로 구현되어있기에 이를 사용한다.
문자열만 있을 경우 0을 반환받기 위해 atoi에 c_str을 사용한다.
숫자면 vector에서 문자열이면 unordered_map에서 값을 출력하면 된다.
*/
#include <bits/stdc++.h>
#include <unordered_map>
#define loop(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int N, M, t;
string tmp;
unordered_map<string, int> arr1;
vector<string> arr2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    loop(i, N) {
        cin >> tmp;
        arr1[tmp] = i + 1;
        arr2.push_back(tmp);
    }
    loop(i, M) {
        cin >> tmp;
        if (t = atoi(tmp.c_str())) {
            cout << arr2[t - 1] << "\n";
        }
        else {
            cout << arr1.at(tmp) << "\n";
        }
    }
    return 0;
}