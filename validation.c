/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:18:13 by mmonahan          #+#    #+#             */
/*   Updated: 2020/11/09 06:39:16 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	validation(int count, char **players, t_core *core)
{
	if (count)
		;
	int	i;

	i = 1;
	while (core->player[i].number > 0)
	{
		printf("- %i -", core->player[i].number);
		printf(" [%s] \n", players[core->player[i].number]);
		i++;
	}

	int fd;
	fd = 0;
	fd = open(players[1], O_RDONLY);
	if (fd < 0 || fd > 10240)
	{
		printf("Ошибка! Файл не найден! [%i]\n", fd);
		close(fd);
		exit (8);
	}
	printf("Файл открыт! [%i]\n", fd);

	int buf = 0;

	buf = read(fd, core->player[1].header.prog_name, PROG_NAME_LENGTH);
	printf("%s - [%i]\n", core->player[1].header.prog_name, buf);

	close(fd);
	printf("Файл закрыт! [%i]\n", fd);
}
