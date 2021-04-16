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

/*
 * vector, sort 사용
 * sub_task - 100
 * efficiency - 100
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for(int i=0; i<completion.size(); i++){
        if(participant[i] != completion[i]){
            return participant[i];
        }
    }
    return participant[participant.size()-1];
}

/*
 * vector, unordered_map 사용(문제의도)
 * sub_task - 100
 * efficiency - 100
 */
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> tmp;
    for(string name : participant){
        tmp[name]++;
    }
    for(string name : completion){
        tmp[name]--;
    }
    for(auto name : tmp){
        if(name.second != 0) return name.first;
    }
}
/* python
 * sub_task - 100
 * effiecincy - 100
 * dictionary, get(key, default_value) - if not key return default_value
 *
def solution(participant, completion):
    answer = {}
    for i in participant:
        answer[i] = answer.get(i, 0)+1
    for j in completion:
        answer[j] = answer[j]-1
    for k in answer:
        if answer[k]: return k
*/
