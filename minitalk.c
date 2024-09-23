#include "minitalk.h"

void	set_signal_types(struct sigaction *sa)
{
	if (sigaction(SIGUSR1, sa, NULL) < 0)
	{
		ft_printf("Error - could not setup SIGUSR1 \n");
		exit(1);
	}
	if (sigaction(SIGUSR2, sa, NULL) < 0)
	{
		ft_printf("Error - could not setup SIGUSR2 \n");
		exit(1);
	}
}

void	send_int(pid_t pid, int num)
{
	int		shift;
	char	bit;

	shift = (sizeof(int) * 8) - 1;
	while (shift >= 0)
	{
		bit = (num >> shift) & 1;
		send_bit(pid, bit, 1);
		shift--;
	}
}

void	send_char(pid_t pid, char c)
{
	int		shift;
	char	bit;

	shift = (sizeof(char) * 8) - 1;
	while (shift >= 0)
	{
		bit = (c >> shift) & 1;
		send_bit(pid, bit, 1);
		shift--;
	}
}


void	send_bit(pid_t pid, char bit, char flag_to_pause)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) < 0)
		{
			ft_printf("Error - sending SIGUSR1 \n");
			exit(1);
		}
	}
	else if (bit == 1)
	{
		if (kill(pid, SIGUSR2) < 0)
		{
			ft_printf("Error - sending SIGUSR2 \n");
			exit(1);
		}
	}
	if (flag_to_pause != 0)
		pause();
}
