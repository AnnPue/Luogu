#include<stdio.h>

int main(){
    int n, i, cnt = 0, j, flag = 0;
    char s[105];
    scanf("%d", &n);
    while(getchar() != '\n');
    fgets(s, n + 1, stdin);

    for(i = 0; i < n; i++){
        if(s[i] == 'V' && s[i + 1] == 'K'){
            s[i] = '#';
            s[i + 1] = '$';
            cnt ++;
        }
    }

    for(i = 0; i< n; i++){
        if(s[i] == s[i + 1]){
            printf("%d\n", cnt + 1);
            return 0;
        }
    }

    printf("%d\n", cnt);
    return 0;
}