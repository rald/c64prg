/* file: gobbler.c */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

char b[3][3][3];
int s[3][3];
int h[3];
int c[3];
int pl = 0;
bool quit = false;

void init() {
    int i,j,k;
    for(k=0;k<3;k++) {
        for(j=0;j<3;j++) {
            for(i=0;i<3;i++) {
                b[k][j][i]='.';
            }
        }
    }
    
    for(j=0;j<3;j++) {
        for(i=0;i<3;i++) {
            s[j][i]=0;
        }
    }

    for(i=0;i<3;i++) {
        h[i]=2;
        c[i]=2;
    }
}

void show() {
    int i,j;
    putchar(147);
    printf("    0    1    2\n\n");
    for(j=0;j<3;j++) {
        printf("%d ",j);
        for(i=0;i<3;i++) {
            printf("[ %c ]",b[s[j][i]][j][i]);
        }
        putchar('\n');
        putchar('\n');
    }
    putchar('\n');
    printf("YOU ");
    for(j=0;j<3;j++) {
        for(i=0;i<h[j];i++) {
            putchar(j+'A');
        }
    }
    putchar('\n');
    printf("CPU ");
    for(j=0;j<3;j++) {
        for(i=0;i<h[j];i++) {
            putchar(j+'0');
        }
    }
    putchar('\n');
}

void piece_new(int pl, int sz, int r0, int c0) {
    if(pl==0) {
        if(h[sz]) b[s[r0][c0]++][r0][c0]=sz+'A';
    } else if(pl==1) {
        if(c[sz]) b[s[r0][c0]++][r0][c0]=sz+'0';
    }
}

void piece_move(int pl, int r0, int c0, int r1, int c1) {
}

void input() {
    int t,sz,r0,c0,r1,c1;
    printf("1:NEW 2:MOVE? ");
    scanf("%d",&t);
    if(t==1) {
        printf("SIZE(0-2),r,c? ");
        scanf("%d,%d,%d",&sz,&r0,&c0);
        piece_new(pl,sz,r0,c0);
    } else if(t==2) {
        printf("r0,c0,r1,c1? ");
        scanf("%d,%d,%d,%d",&r0,&c0,&r1,&c1);
        piece_move(pl,r0,c0,r1,c1);
    }
}

int main(void) {

    init(); 
    
    while(1) {  
        show();
        input();
    }
    
    return 0;
}
