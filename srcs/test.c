#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

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

// void sighandler(int);

// int main () {
//    signal(SIGINT, sighandler);

//    while(1) {
//       printf("Going to sleep for a second...\n");
//       sleep(1); 
//    }
//    return(0);
// }

// void sighandler(int signum) {
//    printf("Caught signal %d, coming out...\n", signum);
//    exit(1);
// }

int main()
{
	int	i;
	char c;

	c = 'a';

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			printf("1");
		else
			printf("0");
		i--;
	}
	printf("\n");
}

// void	ft_send_char(int pid, char c)
// {
// 	int	i;

// 	i = 7; // 8 bits
// 	while (i >= 0)
// 	{
// 		if ((c >> i) & 1) // check si 1 ou 0
// 			kill(pid, SIGUSR1); // 1
// 		else
// 			kill(pid, SIGUSR2); // 0
// 		sleep(1);
// 		while (!g_data.received_bit)
// 		{
// 			pause();
// 			g_data.received_bit = 0;
// 		}
// 		i--;
// 	}
// }