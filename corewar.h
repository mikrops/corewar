/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:35:51 by mmonahan          #+#    #+#             */
/*   Updated: 2020/02/15 11:37:18 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_COREWAR_H
# define COREWAR_COREWAR_H

# include <stdio.h> // УДАЛИТЬ, ЗЛОЙ ПРИНТФ!

# include "libft/libft.h"
# include "op.h"

typedef struct		s_core
{
	int 			number_player[MAX_PLAYERS];
	unsigned char	memory[MEM_SIZE];
}					t_core;

void 				check_param(int count, char **players);
void				validation(t_core *core);

#endif //COREWAR_COREWAR_H
