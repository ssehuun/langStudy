/*
 * 완주하지 못한 선수
 * https://programmers.co.kr/learn/courses/30/lessons/42576
 * sub_task - 100
 * efficiency - 0
 */

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for(int i=0; i<completion.size(); i++){
        vector<string>::iterator it = find(participant.begin(), participant.end(), completion[i]);
        if(it != participant.end()){
            participant.erase(it);
        }
    }
    answer = participant[0];
    return answer;
}
