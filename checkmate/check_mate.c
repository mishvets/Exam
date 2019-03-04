/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:36:31 by mshvets           #+#    #+#             */
/*   Updated: 2019/02/11 15:36:33 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checkmate.h"

static int ft_check(char **argv, t_crd fig, t_crd inc, t_crd fin)
{
	int i;
	int j;

	i = fig.i;
	j = fig.j;
	i += inc.i;
	j += inc.j;
	while (i != fin.i && j != fin.j)
	{
		if (argv[i][j] == 'K')
			return (1);
		else if (argv[i][j] == 'R' || argv[i][j] == 'P' || argv[i][j] == 'B'
				 || argv[i][j] == 'Q')
			break ;
		i += inc.i;
		j += inc.j;
	}
	return (0);
}

static int ft_rook(char **argv, t_crd fig, int size)
{
	t_crd inc;
	t_crd fin;

	inc.i = -1;
	inc.j = 0;
	fin.i = 0;
	fin.j = -1;
	if(ft_check(argv, fig, inc, fin))
		return (1);
	inc.i = 1;
	fin.i = size + 1;
	if(ft_check(argv, fig, inc, fin))
		return (1);
	inc.i = 0;
	inc.j = -1;
	if(ft_check(argv, fig, inc, fin))
		return (1);
	inc.j = 1;
	fin.j = size;
	if(ft_check(argv, fig, inc, fin))
		return (1);
	return (0);
}

static int ft_pawn(char **argv, t_crd fig, int size)
{
	t_crd inc;
	t_crd fin;

	inc.i = -1;
	inc.j = -1;
	fin.i = fin.i > 1 ? fig.i - 2 : 1;
	fin.j = fin.j > 0 ? fig.j - 2 : 0;
	if(ft_check(argv, fig, inc, fin))
		return (1);
	inc.j = 1;
	fin.j = fig.j < size ? fig.j + 2 : size;
	if(ft_check(argv, fig, inc, fin))
		return (1);
	inc.i = 1;
	fin.i = fig.i < size + 1 ? fig.i + 2 : size + 1;
	if(ft_check(argv, fig, inc, fin))
		return (1);
	inc.j = -1;
	fin.j = fig.i > 0 ? fig.j - 2 : 0;
	if(ft_check(argv, fig, inc, fin))
		return (1);
	return (0);
}

static int ft_bishop(char **argv, t_crd fig, int size)
{
	t_crd inc;
	t_crd fin;

	inc.i = -1;
	inc.j = -1;
	fin.i = 0;
	fin.j = -1;
	if(ft_check(argv, fig, inc, fin))
		return (1);
	inc.j = 1;
	fin.j = size;
	if(ft_check(argv, fig, inc, fin))
		return (1);
	inc.i = 1;
	fin.i = size + 1;
	if(ft_check(argv, fig, inc, fin))
		return (1);
	inc.j = -1;
	fin.j = -1;
	if(ft_check(argv, fig, inc, fin))
		return (1);
	return (0);
}

static int ft_queen(char **argv, t_crd fig, int size)
{
	if (ft_bishop(argv, fig, size))
		return (1);
	if (ft_rook(argv, fig, size))
		return (1);
	return (0);
}

void ft_check_mate(int arc, char **argv)
{
	int size;
	t_crd fig;
	int end;

	fig.i = 0;
	end = 0;
	if (!(size = arc - 1))
		return ;
	while (++fig.i < size + 1)
	{
		fig.j = -1;
		while (++fig.j < size)
		{
			if (argv[fig.i][fig.j] == 'R')
				end = ft_rook(argv, fig, size);
			else if (argv[fig.i][fig.j] == 'P')
				end = ft_pawn(argv, fig, size);
			else if (argv[fig.i][fig.j] == 'B')
				end = ft_bishop(argv, fig, size);
			else if (argv[fig.i][fig.j] == 'Q')
				end = ft_queen(argv, fig, size);
			if (end)
			{
				write(1, "Success\n", 8);
				return ;
			}
		}
	}
	write(1, "Fail\n", 5);
}