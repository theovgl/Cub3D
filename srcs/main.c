/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:55:30 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/21 16:48:01 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char const *argv[])
{
	t_config	conf;

	if (argc != 2)
		return (error_handling(&conf, 1, "Illegal number of arguments"));
	init(&conf);
	if (parsing(&conf, argv) == 1)
		return (1);
	if (start(&conf, &conf.graph))
		return (1);
	return (0);
}
