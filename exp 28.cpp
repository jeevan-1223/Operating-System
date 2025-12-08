#include <stdio.h>
#include <string.h>
int main(int argc,char*argv[]){
    if(argc!=3){printf("usage: pattern file\n"); return 1;}
    FILE *f=fopen(argv[2],"r");
    char line[256];
    while(fgets(line,256,f)) if(strstr(line,argv[1])) printf("%s",line);
    fclose(f);
    return 0;
}
