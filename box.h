#ifndef __BOX_H__
#define __BOX_H__

#include <at89x52.h>

//#define	time_wheel	50000
#define	time_wheel	1000                //   1000 uS  = 1mS
#define	TH_VAL	(65536-time_wheel)/256
#define	TL_VAL	(65536-time_wheel)%256

//#define TIMEOUT_default	(20)
//#define TIMEOUT_default	(1)       // 1ms * 1
 
enum time_value  {
    TIMEOUT_default = 1000,
//    time_out_1s     = 1000,    //   1 S
    time_out_1s     = 1,    //   1 S
    time_out_1_min  = 60,
    n_ele_startup   = 13,
    tomato_val      = 25,

};
enum two_light{
    mustang = 0xf7,
    turbo   = 0xdd,

};

enum traffic_ligh{
    ALL_STOP        = 0xee,
    TB_GO_LR_SOTP   = 0x1e,
    ALL_READY       = 0x33,
    ALL_READY_2     = 0xff,
    LR_GO_TB_STOP   = 0x2d,

    LR_GO_TB_STOP_bit = 12,
    TB_GO_LR_SOTP_bit = 1,

        
};
/*
enum traffic_ligh{
    ALL_STOP        = 0x1b,
    TB_GO_LR_SOTP   = 0x1e,
    ALL_READY       = 0x2d,
    ALL_READY_2     = 0x3f,
    LR_GO_TB_STOP   = 0x33,

        
};
*/
/*
enum traffic_ligh{
    ALL_STOP        = 0xe4,
    TB_GO_LR_SOTP   = 0xe1,
    ALL_READY       = 0xd2,
    ALL_READY_2     = 0xc0,
    LR_GO_TB_STOP   = 0xcc,

        
};
*/

unsigned char __code num_left[] ={
    0x0e, 0x1e, 0x2e, 0x3e,
    0x4e, 0x5e, 0x6e, 0x7e,
    0x8e, 0x9e,
};

unsigned char __code num_right[] ={
    0x0d, 0x1d, 0x2d, 0x3d,
    0x4d, 0x5d, 0x6d, 0x7d,
    0x8d, 0x9d,
};



struct timer_ctrl {
    unsigned char display_value;
    unsigned char display_count;
};
struct timer_ctrl startup[] = {
    { ALL_STOP, 3}, { TB_GO_LR_SOTP, 20},

    { ALL_READY, 1}, { ALL_READY_2, 1},
    { ALL_READY, 1}, { ALL_READY_2, 1},
    { ALL_READY, 1}, { ALL_READY_2, 1},
    { ALL_READY, 1}, { ALL_READY_2, 1},
    { ALL_READY, 1}, { ALL_READY_2, 1},
    
    { LR_GO_TB_STOP, 20},


};


void interrupt_init(void)
{

	IE = 0x82;
	TMOD = 0x01;
	TH0 = TH_VAL;
	TL0 = TL_VAL;
	TR0 = 1;

}



#endif // __BOX_H__
