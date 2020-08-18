/*
https://www.acmicpc.net/problem/11399
접근법 - 시간의 합의 최소값을 구하기 위해서는 돈을 인출하는 시간이 적은 사람부터 앞에 와야 그 다음 사람의 인출시간이 적어진다.
sort 함수로 정렬 후 앞 사람의 인출 시간의 합과 본인 인출 시간을 더해가면 최종 인출시간이 나온다.
*/
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int num, wait, sum_min;
    vector<int> wait_vec;
    wait_vec.clear();
    
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        // scanf("%d", &wait);
        // wait_vec[i] = wait;
        cin >> wait;
        wait_vec.push_back(wait);
    }
    sort(wait_vec.begin(), wait_vec.end());
    sum_min = 0;
    int prev = 0;
    for(auto i:wait_vec){
        prev += i;
        sum_min += prev;
    }
    printf("%d", sum_min);
    return 0;
}
