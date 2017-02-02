/***********************************************************
Author: Shawn Bond
Date: 1/25/2017
Effort: ~30m
Purpose: Learn and practice the use of bitwise operators
***********************************************************/
#include <stdio.h>

//function prototypes
#include <stdio.h>
void set_flag(unsigned int* flag_holder, int flag_position);
void unset_flag(unsigned int * flag_holder, int flag_position);
int check_flag(unsigned int flag_holder, int flag_position);
void display_32_flags(unsigned int flag_holder);
int main(int argc, char* argv[])
{
	unsigned int flag_holder = 0;
	set_flag(&flag_holder, 3);
	set_flag(&flag_holder, 16);
	set_flag(&flag_holder, 31);

	display_32_flags(flag_holder);
	
	unset_flag(&flag_holder, 31);
	unset_flag(&flag_holder, 3);
	set_flag(&flag_holder, 9);
	
	display_32_flags(flag_holder);
	return 0;
}
void set_flag(unsigned int* flag_holder, int flag_position) {
	//take integer and make sure nth bit is a 1
	*flag_holder |= (1 << flag_position);
}
void unset_flag(unsigned int * flag_holder, int flag_position) {
	//take integer and make sure nth bit is a 0
	//SIDE NOTE: ~ operator flips bits
	*flag_holder ^= (1 << flag_position);
}
int check_flag(unsigned int flag_holder, int flag_position) {
	//returns an integer that is 0 when the nth bit is 0, 1 when its 1
	if ((1 & (flag_holder >> flag_position)) == 1)
		return 1;
	else
		return 0;
}
void display_32_flags(unsigned int flag_holder) {
	//print the information to the screen as was given in daily3
	int i;
	for (i = 31; i >= 0; i--) {
		printf("%d", check_flag(flag_holder, i));
		if (i % 4 == 0) {
			printf(" "); //add space every 4 characters
		}
	}
	printf("\n");
}