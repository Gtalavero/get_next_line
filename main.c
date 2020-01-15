/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtalaver <gtalaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:10:39 by gtalaver          #+#    #+#             */
/*   Updated: 2020/01/15 17:45:05 by gtalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main()
{
	char	buf[4096];
	int		fd;

	fd = open("text.txt", O_RDONLY);
	read(fd, buf, 1025);
	printf("%s", buf);
	close(fd);
}