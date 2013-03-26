// By Korey Conway and Tanzeel Rana

#include <hcs12dp256.h>
#include <stdio.h>
#include "../lib/keyboard.c"

int main()
{
	char key;
	
	// Setup terminal
	setbaud(BAUD19K);
	
	keyboard_init();
	INTR_ON();
	
	while ( 1 ) {
		if ( key = keyboard_getchar() ) {
			putchar(key);
			
			if ( key == '0' ) {
				break;
			}
			
			keyboard_clearchar();
		}
	}
	
	return 0;
}