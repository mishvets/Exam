/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:03:48 by mshvets           #+#    #+#             */
/*   Updated: 2019/02/11 14:03:51 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"

static void	ft_brcopen(char *str, int *j, char *argv, int *i)
{
	int brc;

	brc = 0;
	if (!str[*j])
	{
		++brc;
		while (brc)
		{
			++(*i);
			if (argv[*i] == '[')
				++brc;
			else if (argv[*i] == ']')
				--brc;
		}
	}
	else
		;
}

static void	ft_brcclose(char *str, int *j, char *argv, int *i)
{
	int brc;

	brc = 0;
	if (!str[*j])
		;
	else
	{
		if (argv[*i] == ']')
			++brc;
		while (brc)
		{
			--(*i);
			if (argv[*i] == ']')
				++brc;
			else if (argv[*i] == '[')
				--brc;
		}
		--(*i);
	}
}

void	brainfuck(char *argv)
{
	char	*str;
	int		i;
	int 	j;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(*str) * 2049);
	while (j < 2049)
		str[j++] = 0;
	str[j] = '\0';
	j = 0;
	while (argv[i])
	{
		if (argv[i] == '>')
			++j;
		else if (argv[i] == '<')
			--j;
		else if (argv[i] == '+')
			++str[j];
		else if (argv[i] == '-')
			--str[j];
		else if (argv[i] == '.')
			write(1, &str[j], 1);
		else if (argv[i] == '[')
			ft_brcopen(str, &j, argv, &i);
		else if (argv[i] == ']')
			ft_brcclose(str, &j, argv, &i);
		++i;
	}
	free(str);
}