/*
 * https://programmers.co.kr/skill_checks/271227?challenge_id=2567
 * sub_task - 100
 * Efficiency - 0
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 0;
int solution(vector<int> scoville, int K) {
    do {
        sort(scoville.begin(), scoville.end());
        if(scoville.size() == 1 && scoville[0] < K) return -1;
        if(scoville[0] >= K) break;
        
        int min = scoville[0];
        int min2 = scoville[1];
        int new_s = min + min2 * 2;
        scoville.push_back(new_s);
        scoville.erase(scoville.begin());
        scoville.erase(scoville.begin());
        ++answer;
        sort(scoville.begin(), scoville.end());
    } while(scoville[0] < K);
  
    return answer;
}

