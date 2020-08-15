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
