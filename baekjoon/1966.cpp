#include <iostream>
#include <deque>
#include <algorithm>

int main(){
	int tc, N, M;
	std::cin >> tc;
	while(tc--){
		std::cin >> N >> M;
		std::deque<int> dq;
		//dq[0] = 1;
		int tmp;
		for(int i=0; i<N; i++){	
			std::cin >> tmp;
			dq.push_back(tmp);
		}
		for(int i=0; i<N; i++){
			std::cout << dq[i];
		}
		
		int chk_idx = M;
		int chk_num = dq[M];
		int ans = 0;
		while(true){
			auto biggest = std::max_element(dq.begin(), dq.end());
			//if(chk_num == *biggest && chk_num == dq.front()){
			//	ans += 1;
			//	break;
			//}
			if(dq[0] == *biggest){
				ans += 1;
				std::cout << dq.front();
				dq.pop_front();
			}
			else{
				dq.push_back(dq[0]);
				dq.pop_front();
				ans += 1;
			}
		}
		std::cout << ans << std::endl;
	}
	return 0;
}
