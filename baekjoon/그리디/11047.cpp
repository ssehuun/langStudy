#include <cstdio>

int main()
{
    int N, K;
    int min_sum = 0;
    
    scanf("%d %d", &N, &K);
    int arr[N] = {0,};
    
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    int tmp;
    tmp = K;
    for(int i=N-1; i>=0; i--){
        if(tmp/arr[i] == 0){
            continue;
        }else{
            int k;
            k = tmp / arr[i];
            min_sum += k;
            tmp -= arr[i] * k;
        }
    }
    printf("%d", min_sum);
    return 0;
}
