#include "stm32l0xx_hal.h"
//#include "mxconstants.h"
void initialize();
void cmd(char);
void dat(char);
void string_dat(char*);
void blanks_dat(char count);
void number_dat(int num);