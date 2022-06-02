/*
문제
알파벳 소문자로만 이루어진 단어 S가 주어진다. 각 알파벳이 단어에 몇 개가 포함되어 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 단어 S가 주어진다. 단어의 길이는 100을 넘지 않으며, 알파벳 소문자로만 이루어져 있다.

출력
단어에 포함되어 있는 a의 개수, b의 개수, …, z의 개수를 공백으로 구분해서 출력한다.

풀이
소문자만 입력받기에 문자열 길이만큼 반복을 돌리고 각 문자 - 97을 한 값을 배열의 인덱스로 사용하여 1 더한다.
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int arr[27];
string str;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		arr[str[i] - 97]++;
	}
	for (int i = 0; i < 26; i++) cout << arr[i] << " ";

	return 0;
}