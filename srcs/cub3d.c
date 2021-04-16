/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:13:50 by yocapell          #+#    #+#             */
/*   Updated: 2020/02/19 16:13:52 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			early_destroy_and_free(t_bag *b)
{
	b->map ? free(b->map) : 0;
	b->da ? free(b->da) : 0;
	b->pro ? free(b->pro) : 0;
	return (0);
}

int			destroy_and_free(t_bag *b)
{
	b->verif->token_sprite == 2 ? free(b->da->s) : 0;
	b->verif->token_no == 2 ? free(b->da->t[NO]) : 0;
	b->verif->token_so == 2 ? free(b->da->t[SO]) : 0;
	b->verif->token_we == 2 ? free(b->da->t[WE]) : 0;
	b->verif->token_ea == 2 ? free(b->da->t[EA]) : 0;
	b->map ? free(b->map) : 0;
	b->da ? free(b->da) : 0;
	b->pro ? free(b->pro) : 0;
	free(b);
	exit(0);
}

int			init_verification(t_bag *b)
{
	if (!(b->verif = malloc(sizeof(t_verif))))
		return (ERROR);
	b->verif->token_res = 0;
	b->verif->token_cel = 0;
	b->verif->token_flo = 0;
	b->verif->token_map = 0;
	b->verif->token_sprite = 0;
	b->da->count = 0;
	b->verif->token_player = 0;
	return (0);
}

int			ft_cub3d(char *dotcub, char token)
{
	t_bag	*b;
	int		check[2];

	if (!(b = malloc(sizeof(t_bag))))
		return (ERROR);
	if (((check[0] = ft_init_parse(b)) == ERROR)
		|| ((check[1] = init_verification(b)) == ERROR))
	{
		if (check[0] == ERROR)
			early_destroy_and_free(b);
		check[1] == ERROR ? free(b->verif) : 0;
		free(b);
		ft_putstr_fd("Malloc failed.\n", 1);
		return (ERROR);
	}
	parse_dotcub(dotcub, b);
	if (global_verification(b) == ERROR)
		return (destroy_and_free(b));
	ft_init_prostruct(b);
	if (mlx_starter(b, token) == ERROR)
		return (ERROR);
	return (1);
}

int			main(int ac, char **av)
{
	char token;

	token = 0;
	if (ac != 2 && ac != 3)
		return (ft_putstrlen_fd("Error.\n", 1));
	if (ac == 3)
	{
		if (ft_strncmp("--save", av[2], 5) == 0)
			token = 1;
		else
		{
			ft_printf("\"%s\" -> is not a valid argument\n", av[2]);
			return (ERROR);
		}
	}
	if (ac == 2 || ac == 3)
		if ((ft_cub3d(av[1], token)) == ERROR)
		{
			ft_putstr_fd("Error.\n", 1);
			return (ERROR);
		}
}
