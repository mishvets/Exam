/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:06:17 by mshvets           #+#    #+#             */
/*   Updated: 2019/02/11 14:06:20 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(int arc, char **argv)
{
//	brainfuck(argv[1]);
//	ft_check_mate(arc, argv); // ".P..." "PKP.." ".A.Q." "R.R.." "RRRBR"

//rostring start
	if (arc == 2) //"   aaaaaa  bbbbbb   ccccc d e "
	{
		rostring(argv[1]);
		write(1, "\n", 1);
	}
//rostring finish
	system("leaks Exam -q");
}
