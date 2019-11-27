// pass
#include <cstdio>
#include <vector>
using namespace std;

long long f[21];
bool check[21];

int main(){
	int N, prob_num;
	scanf("%d", &N);
	f[0] = 1;

	for(int i=1; i<21; i++){
		f[i] = f[i-1] * i; // initialize factorial values
	}
	scanf("%d", &prob_num);
	
	if(prob_num == 1){
		long long k;
		scanf("%lld", &k);
		vector<int> vec(N);
			
		for(int i=0; i<N; i++){
			for(int j=1; j<=N; j++){
				// 순열에 이미 존재하는 숫자면 넘어간다
				if(check[j] == true) continue;
				// 패고리얼값이 k보다 작으면 k에서 팩토리얼 값을 빼준다
				if(f[N-i-1] < k)
				{
					k -= f[N-i-1];
				}
				// 팩토리얼 값이 k보다 크면 해당하는 원소의 숫자를 찾은 것,
				// vec[i]에 저장하고 순열에 존재하는 숫자를 체크해준다.
				else{
					vec[i] = j;
					check[j] = true;
					break;
				}
			}
		}
		for(int i=0; i<N; i++) printf("%d ", vec[i]);
	}
	else if(prob_num == 2){
		vector<int> vec(N);
		// input permutation numbers
		for(int i=0; i<N; i++){
			scanf("%d", &vec[i]);
		}
	
		long long ans = 0;
		for(int i=0; i<N; i++){
			for(int j=1; j<vec[i]; j++){
				if(check[j] == false){
					ans = ans + f[N-i-1];
				}
			}
			check[vec[i]] = true;
		}
		printf("%lld\n", ans+1);
	}
	return 0;
}
