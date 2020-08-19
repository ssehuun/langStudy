/*
https://www.acmicpc.net/problem/2875
틀린 접근법(정답률 올라가다 틀림) - 여학생 2, 남학생 1이 팀을 이루고 여학생이 더 많은 수가 필요학기 때문에
인턴수를 여학생에서 빼면서 남학생에서도 같이 빼간다.
반례 1, 100, 0 입력 -> boy가 음수가 됨.

정답 접근법 - 여학생, 남학생은 적어도 2명, 1명 이상이어야 한 팀이 만들어지기 떄문에, 인턴수 K는 N-2+M-1 이하일 때
팀이 만들어지고, 동시에 N>=2, M>=1 인 조건이 필요하다.
*/

#include<iostream>
using namespace std;

/*
int main(void)
{
	int N, M, K, max_team;
	cin >> N >> M >> K;


	for (int i = K; i >= 0; --i) {
		int girl = N - i;
		int boy = M - (K - i);
		if (boy * 2 <= girl) {
			max_team = boy;
			break;
		}
	}
	cout << max_team;
	return 0;
}
*/

int main(void)
{
	int N, M, K, max_team = 0;
	cin >> N >> M >> K;

	while (1) {
		if (K <= (N -2 + M - 1) && N >= 2 && M >= 1) {
			N -= 2;
			M -= 1;
			++max_team;
		}
		else break;
	}
	cout << max_team;
	return 0;
}
