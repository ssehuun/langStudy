#include <iostream>
#include <deque>
#include <algorithm>

int main(){
	int tc, N, M;
	std::cin >> tc;
	while(tc--){
		std::cin >> N >> M;
		std::deque<int> dq(N);

		for(int i=0; i<N; i++){
			std::cin >> dq[i];
		}
		int chk_idx = M;
		int chk_num = dq[M];

		while(true){
			int ans = 0;
			auto biggest = std::max_element(dq.begin(), dq.end();
			//std::cout << *biggest;
			if(chk_num == biggest && dq.at(chk_num) == 0){
				std::cout << ans << endl;
				dq.push(dq[0]);
				dq.pop_front();
			}else{
				
			}
		}
	}
	return 0;
}
