/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtalaver <gtalaver@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:10:39 by gtalaver          #+#    #+#             */
/*   Updated: 2020/01/15 20:15:44 by gtalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int		fd;
	char	*line[5];

	
	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, line);
	close(fd);
}