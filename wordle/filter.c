#include <stdio.h>
#include <string.h>

int main() {

    char line[4][256];

    FILE *fp=fopen("wordlist.txt","r");

    int k=1000;
    for(int j=0;j<212/4;j++) {
        for(int i=0;i<4;i++) {
            fgets(line[i],256,fp);
            char *p=strchr(line[i],'\n'); if(p) *p='\0';
        }
        printf("%d DATA \"%s\",\"%s\",\"%s\",\"%s\"\n",k++,line[0],line[1],line[2],line[3]);
    }

    return 0;
}
