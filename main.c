/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtalaver <gtalaver@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:10:39 by gtalaver          #+#    #+#             */
/*   Updated: 2020/01/24 19:43:22 by gtalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int			main(int argc, char **argv)
// {
// 	int		fd;
// 	// int		i = 0;
// 	char		*line;

// 	if (argc == 2)
// 	{
// 		fd = open(argv[1], O_RDONLY);
// 		while ((get_next_line(fd, &line)) == 1)
// 		{
// 			// printf("[%d] %s\n", i++, line);
// 		}
// 		close(fd);
// 	}
// 	return (0);
// }

int		main()
{
	int		fd;
	char	*line;
	fd = open("text.txt", O_RDONLY);
	while ((get_next_line(fd, &line)) == 1)
	{
		// printf("[%d] %s\n", i++, line);
	}
	close(fd);
	return (0);
}