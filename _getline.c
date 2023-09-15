#include "_getline.h"

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*copy_substr(char *str, size_t size)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc((size + 1) * sizeof(char));
	while (i < size)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

void	reader(char **str, char **buf, int fd)
{
	int		return_read;
	char	*r;

	return_read = 1;
	while (return_read > 0)
	{
		return_read = read(fd, *buf, BUFFER_SIZE);
		if (return_read > 0)
		{
			(*buf)[return_read] = '\0';
			if (!*str)
				*str = ft_strdup(*buf);
			else
			{
				r = ft_strjoin(*str, *buf);
				ft_free(str);
				*str = r;
			}
			if (ft_strchr(*str, '\n') == 1)
				break ;
		}
	}
	ft_free(buf);
}

char	*_getline(int fd)
{
	static char	*str;
	size_t		size;
	char		*tmp;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	reader(&str, &buf, fd);
	if (str == NULL)
		return (0);
	size = 0;
	while (str[size] && str[size] != '\n')
		size++;
	size++;
	tmp = copy_substr(str, size);
	buf = ft_substr(str, size, ft_strlen(str) - (size));
	ft_free(&str);
	if (*buf == '\0')
		ft_free(&buf);
	else
		str = buf;
	return (tmp);
}
