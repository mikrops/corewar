/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:18:13 by mmonahan          #+#    #+#             */
/*   Updated: 2020/11/12 04:47:41 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check_magic(unsigned int *n)
{
	ft_reverse_uint(n);
	if (*n != COREWAR_EXEC_MAGIC)
		printf("Ошибка! Магическое число не верно!\n");
}

int		read_step(int fd, char *buffer, size_t size)
{
	int bytes;

	bytes = read(fd, buffer, size);
	if (bytes < (int)size)
		printf("Ошибка! Считано не полностью!\n");
	return (bytes);
}

void	read_skip(int fd, size_t size)
{
	char	*buffer;
	int		bytes;

	buffer = ft_memalloc(size + 1);
	bytes = read(fd, buffer, size);
	if (ft_check_empty_srt(buffer, size))
		printf("Ошибка! Error. 1 Invalid pass size after NAME.\n");
	free(buffer);
	if (bytes < (int)size)
		printf("Ошибка! Error. 2 Invalid pass size after NAME.\n");
}

void	read_champ(int num, char *player, t_core *core)
{
	int				fd;
	unsigned int	nbr;

	fd = open(player, O_RDONLY);
	if (fd < 0 || fd >= 10240)
	{
		printf("Ошибка! Файл не найден! [%i]\n", fd);
		close(fd);
		exit (8);
	}
	read_step(fd, (char *)&CHAMP[num].header.magic, SIZE_MAGIC);
	check_magic(&CHAMP[num].header.magic);
	read_step(fd, CHAMP[num].header.prog_name, PROG_NAME_LENGTH);
	read_skip(fd, SIZE_NULL);
	read_step(fd, (char *)&CHAMP[num].header.prog_size, SIZE_CODE);
	ft_reverse_uint(&CHAMP[num].header.prog_size);
	read_step(fd, CHAMP[num].header.comment, COMMENT_LENGTH);
	read_skip(fd, SIZE_NULL);
	read_step(fd, (char *)CHAMP[num].code, CHAMP[num].header.prog_size);
	nbr = CHAMP[num].header.prog_size;
	if (read(fd, (char *)&nbr, 1) != 0)
		printf("Ошибка! 1 Не правильный размер кода. nbr = [%x]\n", nbr);
	if (nbr > CHAMP_MAX_SIZE)
		printf("Ошибка! 2 Не правильный размер кода. nbr = [%x]\n", nbr);
	close(fd);
}

void	validation(char **players, t_core *core)
{
	printf("--%i--%s--\n", __LINE__, __FUNCTION__);
	int	i;

	i = 1;
	while (CHAMP[i].arg > 0)
	{
		printf("- i:%i - num:%i -", i, CHAMP[i].arg);
		printf(" name:[%s] \n", players[CHAMP[i].arg]);
		i++;
	}

	i = 1;
	while (i <= core->count)
	{
		printf("----------%i--%i--------\n", i, CHAMP[i].arg);
		read_champ(i, players[CHAMP[i].arg], core);
		i++;
	}

	i = 1;
	while (i <= core->count)
	{
		printf("----------%i-----------\n", i);
		printf("Номер: [%i]\n", CHAMP[i].arg);
		printf("Имя: [%s]\n", CHAMP[i].header.prog_name);
		printf("Коммент: [%s]\n", CHAMP[i].header.comment);
		printf("Размер: [%i]\n", CHAMP[i].header.prog_size);
		printf("Код: [%s]\n", CHAMP[i].code);
		i++;
	}
	printf("----------end----------\n");
}
