/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:18:13 by mmonahan          #+#    #+#             */
/*   Updated: 2020/11/10 06:56:27 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
	*n = ((*n << 24) |
		(*n >> 24) |
		((*n >> 16) << 24) >> 16 |
		((*n >> 8) << 24) >> 8);
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
	bytes = read_step(fd, (char *)&core->player[num].header.magic,
				   SIZE_MAGIC_FIELD);

	printf("magic после: ");
	check_magic(&core->player[num].header.magic);

	printf(" = [%i vs %i]\n", SIZE_MAGIC_FIELD, bytes);

	//----- имя игрока
	printf("\nИмя: ");
	read_step(fd, core->player[num].header.prog_name, PROG_NAME_LENGTH);

	//----- пропуск области
	read_skip(fd, SIZE_SKIP_FIELD);

	//----- комментрий игрока
	read_step(fd, core->player[num].header.comment, COMMENT_LENGTH);
	printf("\n[%c]\n", core->player[num].header.comment[0]);
	//траблы!!!


	//-----
	close(fd);
	printf("\nФайл закрыт! [fd = %i]\n", fd);
	//-----
}

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

	read_champ(1, players[1], core);

}
