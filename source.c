#include <at89x52.h>
#include "box.h"
unsigned int TIMEOUT = TIMEOUT_default; //  1ms
unsigned int timer_count = 0;
unsigned int min_count = 0;
unsigned int sec_count = 0;
unsigned char to_be_show_number = tomato_val;
unsigned char ten;
unsigned char single;
unsigned char left_right;
unsigned char sun_show_it;
unsigned char min_flag = 0;

void display_sun(unsigned int show_num );
void minute_do(void);
void main(void)
{
    interrupt_init();
    P0 = 0xff;
    P1 = 0xff;
    P2 = 0xff;
    P0 = 0x18;
    for(;;){
        minute_do();
        display_sun(to_be_show_number);

	}
}



void interrupt_startup(void) __interrupt(1)
{
	TH0 = TH_VAL;
	TL0 = TL_VAL;

	if (++timer_count == TIMEOUT){
		  timer_count = 0;

          if(++sec_count == time_out_1s){
              sec_count = 0;
               
              if(++min_count == time_out_1_min){
                  min_count = 0;
                  min_flag = 1;
                  --to_be_show_number;
              }  

          }
    }
}
void minute_do(void)
{
    if(min_flag){
       // P0 = ~P0;
        P0 = (to_be_show_number % 2) ? mustang : turbo;
        min_flag = 0;
    }
    if(to_be_show_number > tomato_val){
        P0 = 0;
        to_be_show_number = tomato_val;
    }


}

/*
void minute_do(void)
{
    if(min_count == time_out_1_min){
 //       to_be_show_number = to_be_show_number ? to_be_show_number :  ( tomato_val + 1 );
        if(to_be_show_number >= tomato_val || to_be_show_number <=  0){
            to_be_show_number = tomato_val + 1;
        }
        --to_be_show_number;

    }



}

*/

void display_sun(unsigned int show_num )
{
       if( (show_num >= 100) || (show_num <= 0)){
           show_num  = 99;
            ten = 9;
            single =9;
       }

        ten = show_num / 10;
        single = show_num % 10;
       

       if(left_right % 2){
            sun_show_it = num_left[ten];
       }else{
            sun_show_it = num_right[single];
       }
       P1 = sun_show_it;

       ++left_right;

}


