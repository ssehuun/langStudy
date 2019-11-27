//1722 - output answer ok, but runtime error
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int N, prob_num, k;
	scanf("%d", &N);
	scanf("%d", &prob_num);
	vector<int> permu_vec(N);
	permu_vec.clear();
	
	for(int i=1; i<=N; i++){
		permu_vec.push_back(i);
	}
	if(prob_num == 1){
		int tmp1 = 1;
		scanf("%d", &k);
		do{
			if(tmp1 == k) break;
			tmp1++;
		}while(next_permutation(permu_vec.begin(), permu_vec.end()));	
		for(int i=0; i<N; i++) printf("%d ", permu_vec[i]);
	}
	else if(prob_num == 2){
		int tmp2;
		int ans = 1;
		vector<int> tmp(N);
		tmp.clear();
		for(int i=0; i<N; i++){
			scanf("%d", &tmp[i]);
		}
		
		do{
			tmp2 = 0; // check tmp vector and permu_vec each elements 
			for(int i=0; i<N; i++){
				if(permu_vec[i] == tmp[i])tmp2++;
			}
			if(tmp2 == N) break;
			//if(permu_vec == tmp) break; // compare 2 vectors
			ans++;
		}while(next_permutation(permu_vec.begin(), permu_vec.end()));
		printf("%d\n", ans);
	}
	return 0;
}
