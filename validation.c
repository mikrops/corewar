/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:18:13 by mmonahan          #+#    #+#             */
/*   Updated: 2020/11/11 07:39:49 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	reverse_uint(unsigned int *n)
{
	*n = ((*n << 24) |
		(*n >> 24) |
		((*n >> 16) << 24) >> 16 |
		((*n >> 8) << 24) >> 8);
}

int	ft_check_empty_srt(char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		if (str[i++])
			return (1);
	return (0);
}

void	check_magic(unsigned int *n)
{
	//*n = rev_uint(*n);
	reverse_uint(n);
	if (*n != COREWAR_EXEC_MAGIC)
		printf("Ошибка! Магическое число не верно!\n");
	printf("[%x]", *n);
}

int	read_step(int fd, char *buffer, size_t size)
{
	int bytes;

	bytes = read(fd, buffer, size);
	if (bytes < (int)size)
		printf("Ошибка! Считано не полностью!\n");
	printf("[%s] - [%i vs %i]\n", buffer, (int)size, bytes);
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
	int fd;

	fd = open(player, O_RDONLY);
	if (fd < 0 || fd >= 10240)
	{
		printf("Ошибка! Файл не найден! [%i]\n", fd);
		close(fd);
		exit (8);
	}
	printf("Файл открыт! [fd = %i]\n", fd);

	//----- магическое число
	int bytes;
	printf("\nmagic до: ");
	read_step(fd, (char *)&core->champ[num].header.magic, SIZE_MAGIC);
	printf("magic после: ");
	check_magic(&core->champ[num].header.magic);

	//----- имя игрока
	printf("\n\nИмя: ");
	read_step(fd, core->champ[num].header.prog_name, PROG_NAME_LENGTH);

	//----- пропуск NULL области
	read_skip(fd, SIZE_NULL);

	//----- размер кода
	printf("\nРазмер: ");
	read_step(fd, (char *)&core->champ[num].header.prog_size, SIZE_CODE);
	reverse_uint(&core->champ[num].header.prog_size);
	printf("[%i]\n", core->champ[num].header.prog_size);

	//----- комментрий игрока
	printf("\nКомментарий: ");
	read_step(fd, core->champ[num].header.comment, COMMENT_LENGTH);


	//----- пропуск NULL области
	read_skip(fd, SIZE_NULL);

//	reverse_uint(&core->champ[num].header.prog_size);
	//----- код игрока
	printf("\nКод: ");
	read_step(fd, (char *)core->champ[num].code, core->champ[num].header.prog_size);
	printf("[%s]\n", core->champ[num].code);


	//----- проверка кода размера
	unsigned int	nbr = core->champ[num].header.prog_size;
	printf("nbr = [%ld]\n", nbr);
	if (read(fd, (char *)&nbr, 1) != 0)
		printf("Ошибка! 1 Не правильный размер кода. nbr = [%x]\n", nbr);
	if (nbr > CHAMP_MAX_SIZE)
		printf("Ошибка! 2 Не правильный размер кода. nbr = [%x]\n", nbr);

	//-----
	close(fd);
	printf("\nФайл закрыт! [fd = %i]\n", fd);
	//-----
}

void	validation(char **players, t_core *core)
{
	int	i;

	i = 1;
	while (CHAMP[i].number > 0)
	{
		printf("- %i -", CHAMP[i].number);
		printf(" [%s] \n", players[CHAMP[i].number]);
		i++;
	}

	i = 1;
	while (i <= core->count)
	{
		printf("----------%i--%i--------\n", i, CHAMP[i].number);
		read_champ(i, players[CHAMP[i].number], core);
		i++;
	}
	//read_champ(1, players[1], core);


	i = 1;
	while (i <= core->count)
	{
		printf("----------%i-----------\n", i);
		printf("Номер: [%i]\n", CHAMP[i].number);
		printf("Имя: [%s]\n", CHAMP[i].header.prog_name);
		printf("Коммент: [%s]\n", CHAMP[i].header.comment);
		printf("Размер: [%i]\n", CHAMP[i].header.prog_size);
		printf("Код: [%s]\n", CHAMP[i].code);
		i++;
	}
	printf("----------end----------\n");
}
