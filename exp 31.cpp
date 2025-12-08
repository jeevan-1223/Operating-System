#include <stdio.h>
int main(){
    int pages[]={1,3,0,3,5,6,3},n=7,f=3;
    int frame[f],i,j=0,cnt=0;
    int k;
    for(i=0;i<f;i++) frame[i]=-1;
    for(i=0;i<n;i++){
        int hit=0;
        for(k=0;k<f;k++) if(frame[k]==pages[i]) hit=1;
        if(!hit){frame[j]=pages[i]; j=(j+1)%f; cnt++;}
        printf("Page %d: ",pages[i]);
        for(k=0;k<f;k++) printf("%d ",frame[k]);
        printf("\n");
    }
    printf("Faults=%d\n",cnt);
    return 0;
}
