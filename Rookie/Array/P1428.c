#include <stdio.h>

int main(){
    int n, i, j, cnt = 0;
    int s[101];
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &s[i]);
        cnt = 0;
        for (j = 0; j < i; j++){
            if (s[j] < s[i]){
                cnt++;
            }
        }
        printf("%d ", cnt);
    }
    return 0;
}