/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:18:13 by mmonahan          #+#    #+#             */
/*   Updated: 2020/11/12 06:36:05 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Возвращает количество игроков
*/

int	check_count_players(int count, char **player, t_core *core)
{
	int	i;
	int max_p;

	i = 1;
	max_p = 0;
	while (i < count)
	{
		if (!check_name_player(player[i]))
		{
			max_p++;
			CHAMP[max_p].id = max_p;
			CHAMP[max_p].arg = i;
		}
		if (max_p > MAX_PLAYERS)
		{
			printf("--Слишком много игроков!--\n");
			exit(1);
		}
		i++;
	}
	if (max_p < 1)
	{
		printf("--Слишком мало игроков!--\n");
		exit (2);
	}
	return (max_p);
}

/*
**	Проверка аргументов
**	Обработка флагов
*/

void	check_param(int count, char **players, t_core *core)
{
	printf("--%i--%s--\n", __LINE__, __FUNCTION__);
	core->count = check_count_players(count, players, core);
	int i = 1;
	while (i <= core->count)
	{
		printf("p%i - [%i] ", i, CHAMP[i].arg);
		i++;
	}
	printf("\n");

	check_flag_n(count, players, core);
	i = 1;
	while (i <= core->count)
	{
		printf("p%i - [%i] ", i, CHAMP[i].arg);
		i++;
	}
	printf("\nКоличество игроков: [%i]\n", core->count);
}

/*
 * проверяем на имя файла
 * * +1 к игроку
 * * задать номер
 * * запоминаем каой он по номеру в аргументах
 * проверяем на тег
 * * + кол-во параметров
 * * + кол-во шагов, но главное не перепрыгнуть общее кол-во
 * * обрабатываем номер игрока, если флаг -n
 * иначе ошибка

 * */