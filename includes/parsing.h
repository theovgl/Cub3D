/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:56:30 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/27 10:57:40 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

int	parsing(t_config *conf, const char *argv[]);
int	check_file(t_config *conf, const char *file_path);
int	parse_settings(t_config *conf);
int	parse_colors(t_config *conf, char *line);
int	parse_map(t_config *conf);
int	save_map(t_config *conf);
int	settings_checker(t_config *conf);
int	is_map(t_config *conf, char *line, int print);
int	check_map(t_config *conf, t_map map);

#endif
