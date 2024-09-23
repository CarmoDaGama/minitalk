
#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <unistd.h> 
# include <signal.h>
# include <stdlib.h> 

void	set_signal_types(struct sigaction *sa);
void	send_int(pid_t pid, int num);
void	send_char(pid_t pid, char c);
void	send_bit(pid_t pid, char bit, char flag_to_pause);

typedef struct s_info
{
	int		bits;
	int		data;
	int		flag;
	char	*message;
}			t_info;

#endif
