/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 09:52:35 by yocapell          #+#    #+#             */
/*   Updated: 2020/02/19 13:58:24 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_parse_dispatcher(char *tmp, t_bag *b)
{
	int i;

	i = 0;
	if ((i = skip_white_space(tmp)) == ERROR)
		return (0);
	tmp += i;
	if (*tmp == 'R' || *tmp == 'C' || *tmp == 'F' || *tmp == '1' || *tmp == '0')
		catch_flag(tmp, b);
	else if (ft_strncmp(tmp, "NO", 1) == 0)
		b->verif->token_no = 1;
	else if (ft_strncmp(tmp, "SO", 1) == 0)
		b->verif->token_so = 1;
	else if (ft_strncmp(tmp, "WE", 1) == 0)
		b->verif->token_we = 1;
	else if (ft_strncmp(tmp, "EA", 1) == 0)
		b->verif->token_ea = 1;
	else if (ft_strncmp(tmp, "S ", 1) == 0)
		b->verif->token_sprite = 1;
	if (b->verif->token_ea == 1 || b->verif->token_we == 1
		|| b->verif->token_so == 1 || b->verif->token_no == 1
			|| b->verif->token_sprite == 1)
		catch_texture(tmp, b);
	return (0);
}

int		parse_dotcub(char *dotcub, t_bag *b)
{
	int		fd;
	char	*tmp;
	int		ret;

	if ((fd = open(dotcub, O_RDONLY)) == ERROR)
		return (ERROR);
	if (point_cub(dotcub) == ERROR)
		return (ERROR);
	while ((ret = get_next_line(fd, &tmp)) >= 0)
	{
		if (ret == ERROR)
			return (ERROR);
		if (ft_parse_dispatcher(tmp, b) == ERROR)
			return (ERROR);
		if (ret == 0)
			break ;
		free(tmp);
	}
	close(fd);
	return (0);
}

int		check_token_tex_sprite(t_bag *b)
{
	if (b->verif->token_no != 2)
		return (ERROR);
	if (b->verif->token_so != 2)
		return (ERROR);
	if (b->verif->token_we != 2)
		return (ERROR);
	if (b->verif->token_ea != 2)
		return (ERROR);
	if (b->verif->token_sprite != 2)
		return (ERROR);
	return (1);
}

int		global_verification(t_bag *b)
{
	if (check_token_tex_sprite(b) == ERROR)
	{
		ft_putstr_fd("Error.\nDont forget the path\n", 1);
		return (ERROR);
	}
	check_max_value(b);
	rgb_max_value(b);
	if (ft_map_to_tab(b) == ERROR)
	{
		ft_putstr_fd("Map Invalid", 1);
		return (ERROR);
	}
	if (map_verification(b) == ERROR)
	{
		return (ERROR);
	}
	return (0);
}
