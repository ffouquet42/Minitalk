#include <stdio.h>

int main(void)
{
	static unsigned char	c = 10;
	static unsigned char	bit = 20;

	static unsigned char	c2 = 10;
	static unsigned char	bit2 = 20;

	c |= bit;
	printf("c : %d \n", c);
	printf("bit : %d \n", c);

	c2 = c2 + bit2;
	bit2 = c2;
	printf("c2 : %d \n", c);
	printf("bit2 : %d \n", c);

	return(0);
}