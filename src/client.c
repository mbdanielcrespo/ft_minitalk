
#include "../inc/minitalk.h"

// This function checks for the possible errors that the provided PID may have and rules out any chance of a wrong PID

int pid_error(int ac, char **av)
{
	int i;

	if (ac != 3)
		return (1);
	i = -1;
	while (av[1][++i])
	{
		if (!ft_strchr("0123456789", av[1][i]))
			return (1);
	}
	if (ft_atoi(av[1]) <= 0)
		return (1);
	return (0);
}

void    send_ch_by_bit(unsigned int c, int pid)
{
	int i;

	i = -1;
	while (++i < 8)
	{
		if (c & 0x01)
			//kill(pid, SIGUSR1);
			printf("1");
		else
			//kill(pid, SIGUSR2);
			printf("0");
		c = c >> 1;
		usleep(WAIT);
	}
	
}

void    send_len_by_bit(int str_len, int pid)
{
	int i;

	i = -1;
	while (++i < 32)
	{
		if (str_len & 0x01)
			//kill(pid, SIGUSR1);
			printf("1");
		else 
			//kill(pid, SIGUSR2);
			printf("0");
		str_len = str_len >> 1;
		usleep(WAIT);
	}
	
}

int main(int ac, char **av)
{
	int     pid;
	char    *str_to_send;
	int     len;
	int     i;

	if (pid_error(ac, av))
	{
		ft_printf("PID error\n");
		return (-1);
	}
	pid = ft_atoi(av[1]);
	str_to_send = av[2];
	len = ft_strlen(str_to_send);
	//ft_printf("PID found: %d!\n", pid);
	//ft_printf("Lenght: %d\n", len);
	//ft_printf("String: %s\n", str_to_send);
	i = -1;
	send_len_by_bit(ft_strlen(str_to_send), pid);
	while (str_to_send[++i])
	{
		ft_printf(" Sending ... ch = %c\n", str_to_send[i]);
		send_ch_by_bit(str_to_send[i], pid);
	}
    return (0);
}