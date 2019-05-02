#include<reg51.h>
unsigned char sine_tab[49]={}
//x=(2.5+2.5*siny)/0.01953125
char count;
void main(){
    while(1){
        for(count=0;count<49;count++)
            P0=sin_tab[count];
    }
}