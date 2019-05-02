#include<reg51.h>
void delay(){
    unsigned int i,j;
    for(i=0;i<3000;i++)
        for(j=0;j<100;j++);
}
void main(){
    unsigned char i,k;
    while(1){
        for(i=0x00;i<0x04;i++){
            k=i<<4;
            P2=k;
            delay();
        }
    }
}