/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:18:13 by mmonahan          #+#    #+#             */
/*   Updated: 2020/11/13 18:29:26 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Обработка флага -n
**	-n "number_player" "name_player"
*/

int	check_arg_one(char *value, int count_players)
{
	int param_n;

	param_n = ft_atoi(value);
	if (param_n < 1 || param_n > count_players)
	{
		printf("-- Неверный 1-й параметр [%i] флага n!--\n", param_n);
		exit (ERROR_INVALID_FLAG); //ошибка, неверный первый параметр флага n
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
	while (i <= core->count + 1)
	{
		if (CHAMP[i].arg == adr)
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
				if (arg != pos && queue[arg] == queue[pos])
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
**
**	флаг -n	3 0 1 0
**	было	3 6 9 10
**	стало	9 6 3 10
*/

void	sort_queue(t_core *core, int *queue)
{
	int		i;
	t_champ c;

	i = 1;
	while (i < core->count + 1)
	{
		if (queue[i] != 0)
		{
			if (queue[i] != CHAMP[i].id)
			{
				c = CHAMP[i];
				CHAMP[i] = CHAMP[queue[i]];
				CHAMP[queue[i]] = c;
			}
		}
		i++;
	}
}

void	check_flag_n(int count, char **player, t_core *core)
{
	int		i;
	int		param_n;
	int		queue[core->count + 1];

	i = 1;
	param_n = 0;
	while (i < core->count + 1)
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
			param_n = check_arg_one(player[i + 1], core->count);
			check_arg_two(player[i + 2]);
			queue_players(core, queue, i + 2, param_n);
			check_uniq_queue(queue);
		}
		i++;
	}
	sort_queue(core, queue);

	i = 1;
	printf("очередь: ");
	while (i < core->count + 1)
	{
		printf("%i ", queue[i]);
		i++;
	}
	printf("\n");
}