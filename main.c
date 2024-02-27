// #include "get_next_line.h"

// int main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;
// 	(void)argc;

// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Errore nell'apertura del file");
// 		return 1;
// 	}

// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	return 0;
// }
#include "get_next_line.h"

int main() {
    int fd = open("/Users/cchiodi/Desktop/get_next_line_git_git/file.txt", O_RDONLY); // Sostituisci "test.txt" con il percorso del tuo file di test
    if (fd < 0) {
        perror("Errore nell'apertura del file");
        return 1;
    }
    char *line;
    line = get_next_line(fd);
    while (line != NULL) {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    return 0;
}
