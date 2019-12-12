// 수 정렬하기 - 난이도 1
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    std::vector<int> vec;
    scanf("%d", &N);

    while(N--){
        int num;
        scanf("%d", &num);
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());
    N = vec.size();
    int i=0;
    while(N--){
        printf("%d\n", vec[i]);
        i++;
    }
    return 0;
}
