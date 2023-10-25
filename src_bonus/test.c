#include "../inc/minitalk.h"

void	handler()
{
	write(1, "I WILL NOT BE EXECUTED :)\n", 29);
}

int	main()
{
	signal(SIGINT, handler);
	while (1)
	{
		ft_printf("Cycling ... %d\n", getpid());
		sleep(1);
	}
}