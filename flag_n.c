//
// Created by mmonahan on 06.11.2020.
//

#include "corewar.h"

/*
**	Обработка флага -n
**	-n "number_player" "name_player"
*/

int	check_arg_one(char *value)
{
	int param_n;

	param_n = ft_atoi(value);
	if (param_n < 1 || param_n > MAX_PLAYERS)
	{
		printf("-- Неверный 1-й параметр [%i] флага n!--\n", param_n);
		exit (3); //ошибка, неверный первый параметр флага n
	}
	return (param_n);
}

void	check_arg_two(char *value)
{
	if (check_name_player(value))
	{
		printf("--Неверный 2-й параметр [%s] флага n!--\n", value);
		exit (4); //ошибка, неверный второй параметр флага n
	}
}

void	queue_players(t_core *core, int *queue, int adr, int value)
{
	int	i;

	i = 1;
	while (i <= MAX_PLAYERS + 1)
	{
		if (core->player[i].number == adr)
			queue[i] = value;
		i++;
	}
}

void	check_uniq_queue(int *queue)
{
	int arg;
	int pos;

	arg = 1;
	pos = 2;
	if (MAX_PLAYERS + 1 <= 1)
		return ;
	while (arg < MAX_PLAYERS + 1)
	{
		if (queue[arg] != 0)
			while (pos < MAX_PLAYERS + 1)
			{
				if ( arg != pos && queue[arg] == queue[pos])
				{
					printf("Ошибка! Значения флага -n не должны повторяться\n");
					exit (7); // Ошибка. ЗНачинея флага -n повторяются
				}
				pos++;
			}
		pos = 1;
		arg++;
	}
}

void swap_player(t_player *a, t_player *b)
{
	t_player 	c;

	c = *a;
	*a = *b;
	*b = c;
}

/*
**	Пояснение сортировки очереди!
**
**	логика:
**	игроки 	1 2 3 4
**	флаг -n	1 3 4 0
**
**	шаг	1	1 2 3 4
**	шаг 2	1 3 2 4
**	шаг 3	1 3 4 2
**	шаг 4	1 3 4 2
**
**	пример: цифры, это адреса атрибутов, имена игроков.
**	флаг -n	1 3 4 0
**	было	3 6 9 10
**	стало	3 9 10 6
*/

void	sort_queue(t_core *core, int *queue)
{
	int i;

	i = 1;
	while (i < MAX_PLAYERS + 1)
	{
		if (queue[i] != 0)
		{
			swap_player(&core->player[i], &core->player[queue[i]]);
			// не отрабатывает, когда  например -n 3 0 1 0!!!!
		}
		i++;
	}
}

void	check_flag_n(int count, char **player, t_core *core)
{
	int		i;
	int		param_n;
	int		queue[MAX_PLAYERS + 1];

	i = 1;
	param_n = 0;
	while (i < MAX_PLAYERS + 1)
		queue[i++] = 0;
	i = 1;
	while (i < count)
	{
		if (!ft_strcmp(player[i], "-n"))
		{
			if (i >= count - 2)
			{
				printf("--Неверное владение флагом -n!--\n");
				exit(5);
			}
			param_n = check_arg_one(player[i + 1]);
			check_arg_two(player[i + 2]);
			queue_players(core, queue, i + 2, param_n);
			check_uniq_queue(queue);
		}
		i++;
	}
	sort_queue(core, queue);

	i = 1;
	printf("очередь: ");
	while (i < MAX_PLAYERS + 1)
	{
		printf("%i ", queue[i]);
		i++;
	}
	printf("\n");
}