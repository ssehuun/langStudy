#include <iostream>
#include <deque>
#include <algorithm>

std::deque<int> dq;
void print(std::deque<int> dq){
	std::deque<int>::iterator it;
	std::cout << "print: ";
	for(it = dq.begin(); it != dq.end(); it++){
		std::cout << *it;
	}
}
int main(){
	int tc, N, M;
	std::cin >> tc;
	while(tc--){
		std::cin >> N >> M;
		dq.clear();
		int tmp;
		for(int i=0; i<N; i++){
			std::cin >> tmp;
			dq.push_back(tmp);
		}
	   	
		int chk_idx = M;
		int chk_num = dq[M];
		int ans = 0;
		while(true){
			print(dq);
			auto biggest = std::max_element(dq.begin(), dq.end());
			
			std::cout << " ans - " << ans << std::endl;
			//체크 넘버가 가장 큰 수고, 체크 인덱스가 맨앞에 있을때
			if(chk_num == *biggest && chk_idx == 0){
				ans += 1;
				break;
			}
			//맨 앞 수가 가장 크지 않거나 체크 인덱스가 0이 아닐때
			if(dq.front() != *biggest){
				dq.push_back(dq[0]);
				dq.pop_front();
				chk_idx--;
				if(chk_idx == -1){
					chk_idx = dq.size()-1;
				}
			}
			//같은 수가 여러개일 때 처리
			else if(dq.front() == *biggest && chk_idx != 0){
				dq.pop_front();
				chk_idx--;
				ans += 1;
			}
		}
		std::cout << "ans: " << ans << std::endl;
	}
	return 0;
}
