/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:29:40 by mmonahan          #+#    #+#             */
/*   Updated: 2020/11/13 19:31:13 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_exception(char *errors[ERROR_MAX_PLAYERS])
{
	errors[ERROR_MAX_PLAYERS] = "Error. Number of players above maximum.";
	errors[ERROR_ZERO_PLAYERS] = "Error. No players.";
	errors[ERROR_INVALID_FLAG] =
		"Error. Attention!!! Attempted to enter an invalid flag.";
}

void	exception(int error)
{
	char	*errors[COUNT_ERRORS];

	init_exception(errors);
	printf(RED_PRINT);
	printf("%s\n", errors[error]);
	printf(RESET_PRINT);
	exit (error);
}
