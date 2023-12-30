#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main(){
    FILE *fp = fopen("path/dataset_name.txt", "r");                                         // open your path with filename for reading
    FILE *wp = fopen("path/dataset_name.csv", "w");                                         // open your path with filename for writing
    char ch;
    char *text = (char *)malloc(sizeof(char) * 500);
    strcpy(text, "TS,ID1,ID0,LEN,DLC0,DLC1,DLC2,DLC3,DLC4,DLC5,DLC6,DLC7,target");          // columnss or features names
    fprintf(wp, "%s\n", text);
    int counter=0;                                                                          //counter counts data field present
    while (!feof(fp))    {
        fscanf(fp, "%s", text);                                                             //picking up words
        if (!strcmp(text,"Timestamp:") || !strcmp(text, "ID:") || !strcmp(text, "DLC:"))    //skiping words                         
            continue;
        counter++;
        fprintf(wp,"%s,", text);
        ch = fgetc(fp);
        if (ch == '\n'){
            if(counter<12)
                for(int i=0;i<(12-counter);i++)
                    fprintf(wp,",");
            fprintf(wp, "target_value\n");                                                     // assign target values for category
            counter=0;
        }
    }
    fclose(wp);
    fclose(fp);
}
