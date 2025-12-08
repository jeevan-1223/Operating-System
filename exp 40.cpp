#include <stdio.h>
#include <sys/stat.h>
int main(){
    struct stat st;
    stat("test.txt",&st);
    printf("Owner permissions: %o\n",st.st_mode & 0700);
    printf("Group permissions: %o\n",st.st_mode & 0070);
    printf("Other permissions: %o\n",st.st_mode & 0007);
    return 0;
}
