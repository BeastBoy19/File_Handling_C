#include<stdio.h>
#include<stdlib.h>
main(){
    FILE *fp = fopen("C:/Users/bikas/OneDrive/Java/Algorithms/collinear/input50.txt", "r");
    FILE *wp = fopen("C:/Users/bikas/Downloads/input.txt", "w");
    char **s = (char **)malloc(100 * sizeof(char *));
    int flag=0;
    int i=0;
    while(!feof(fp)){
        s[i] = (char *)malloc(500 * sizeof(char *));
        fscanf(fp, "%s", s[i]);
        if (flag == 0)        {
            flag = 1;
            continue;
        }
        i++;
        if(i==2){
            fprintf(wp, "(%s,%s)\n",s[0],s[1]);
            i=0;
        }
    }
    fclose(wp);
    fclose(fp);
}