/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:31:20 by tvogel            #+#    #+#             */
/*   Updated: 2022/07/28 14:29:01 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_handling(t_config *conf, int return_value, char *message)
{
	conf->error = 1;
	printf("\e[1mError: %s\e[m\n", message);
	return (return_value);
}
