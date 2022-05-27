#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main(void)
{
	char	*line;
	int fd = open("file", O_RDONLY);

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		printf("%s", line);
		free (line);
	}
	close (fd);
	return (0);

// 	char *test3 = get_next_line(fd);
// 	printf("%s", test3);
// 	free(test3);
// 	char *test4 = get_next_line(fd);
// 	printf("%s", test4);
// 	free(test4);
// 		char *test5 = get_next_line(fd);
// 	printf("%s",test5);
// 	free(test5);
// 	char *test6 = get_next_line(fd);
// 	printf("%s", test6);
// 	free(test6);
// 		char *test7 = get_next_line(fd);
// 	printf("%s",test7);
// 	free(test7);
// 	char *test8 = get_next_line(fd);
// 	printf("%s",test8);
// 	free(test8);
// 	test8 = get_next_line(fd);
// 	printf("%s",test8);
// 	free(test8);
// test8 = get_next_line(fd);
// 	printf("%s",test8);
// 	free(test8);
// 	test8 = get_next_line(fd);
// 	printf("%s",test8);
// 	free(test8);
}
