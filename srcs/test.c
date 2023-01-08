// #include <stdio.h>

// int main(void)
// {
// 	static unsigned char	c = 10;
// 	static unsigned char	bit = 20;

// 	static unsigned char	c2 = 10;
// 	static unsigned char	bit2 = 20;

// 	c |= bit;
// 	printf("c : %d \n", c);
// 	printf("bit : %d \n", c);

// 	c2 = c2 + bit2;
// 	bit2 = c2;
// 	printf("c2 : %d \n", c);
// 	printf("bit2 : %d \n", c);

// 	return(0);
// }

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sighandler(int);

int main () {
   signal(SIGINT, sighandler);

   while(1) {
      printf("Going to sleep for a second...\n");
      sleep(1); 
   }
   return(0);
}

void sighandler(int signum) {
   printf("Caught signal %d, coming out...\n", signum);
   exit(1);
}