#include "ft_fillit.h"

int		main(int argc, char const **argv)
{
	char	buf[1024];
	int		fd;
	int		i;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	printf("fd = %d\n", fd);
	i = read(fd, buf, 1024);
	printf("buf : \n%s\n", buf);
	i = tetriminos_checker(buf) * check_file(buf) * check_new(buf);
	printf("FINAL RESULT OF CHECK: %d\n", i);
	return (0);
}
