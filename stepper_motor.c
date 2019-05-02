#include<reg51.h>
bit Dir=0;
void changeDir(void) interrupt 0{
    Dir=~Dir;
}
void delay(unsigned int x){
    for(;x>0;x--);
}
void main(){
    unsigned char val,i;
    EA=0x1;
    E0x=0x1;
    while(1){
        if(Dir){
            val=0x08;
            for(i=0;i<4;i++){
                P0=val;
                val=val>>1;
                delay(1000);
            }
        }
    }
}