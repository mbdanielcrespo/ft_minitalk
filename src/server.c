#include "../inc/minitalk.h"

void	init_var(int *i)
{
	if (!i)
		i = 0;
}

void	recive_len(int signal, int *rec_len, int *len_flag, char **final_str)
{
	static int	i;

	init_var(&i);
	if (i < 31 && signal == 1)
		*rec_len = *rec_len + ft_pow(2, i);
	else if (i == 31)
	{
		*final_str = malloc((sizeof(char) * *rec_len) + 1);
		if (!final_str)
			return ;
		*len_flag = 1;
	}
	i++;
	//printf("Signal: %d, Iteration: %d, Flag: %d\n", signal, i, *len_flag);
}

void	recive_str(int signal, int message_len, int *message_flag, char **final_str)
{
	static int	i;
	static int	c;
	static char	ch;

	init_var(&i);
	init_var(&c);
	//printf("Signal: %d, Iteration: %d, Character %d\n", signal, i, c);
	if (i < 8 && signal == 1)
		ch = ch + (char)ft_pow(2, i);
	i++;
	if (i == 8)
	{
		i = 0;
		//printf("Added char: %c\n", ch);
		(*final_str)[c] = ch;
		ch = 0;
		c++;
	}
	if (c == message_len)
	{
		(*final_str)[c] = '\0';
		*message_flag = 1;
	}
}

void	recive_client_data(int signal)
{
	static int	message_len;
	static int  len_flag;
	static int	message_flag;
	static char	*final_str;

	init_var(&message_len);
	init_var(&len_flag);
	init_var(&message_flag);
	if (len_flag == 0)
		recive_len(signal, &message_len, &len_flag, &final_str);
	else
		recive_str(signal, message_len, &message_flag, &final_str);
	if (message_flag == 1)
	{
		ft_printf("%s\n", final_str);
		message_flag = 0;
	}

}

int main(int ac, char **av)
{
    int pid;
	static int i;

	init_var(&i);
	//test_str = "101000000000000000000000000000000001011010100110001101100011011011110110";
	//test_str_len = 32 + 8 * n_chars;
	if (ac == 2)
		ft_printf("Two parametres!\n");
    pid = (int)(getpid());
	ft_printf("%d\n", pid);
	//ft_printf("\nTest str: %s\n", test_str);
	//ft_printf("Test str len: %d\n", test_str_len);
	while (i < (int)ft_strlen(av[1]))
	{
		recive_client_data(av[1][i] - '0');
		i++;
	}
	//signal(SIGUSR1, recive_client_data); 
	//signal(SIGUSR2, recive_client_data);
	
	while (1)
		usleep(WAIT);
}