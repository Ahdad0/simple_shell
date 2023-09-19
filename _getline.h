#ifndef GET_LINE_H
# define GET_LINE_H
# include<unistd.h>
# include<stdlib.h>
# define BUFFER_SIZE 1
char	*_getline(int fd);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	reader(char **str, char **buf, int fd);
void	ft_free(char **str);
char	*copy_substr(char *str, size_t size);
int		ft_strchr(char *str, char c);
#endif
