<<<<<<< HEAD
#include "shell.h"

/**
 * ft_strchr - Find a character in a string.
 * @str: The input string.
 * @c: The character to find.
 *
 * Return: 1 if 'c' is found in 'str', 0 otherwise.
 */
int ft_strchr(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * copy_substr - Copy a substring from a string.
 * @str: The input string.
 * @size: The size of the substring to copy.
 *
 * Return: A newly allocated string containing the copied substring.
 */
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

/**
 * reader - Read data from a file descriptor into a buffer.
 * @str: A pointer to the buffer where data is stored and concatenated.
 * @buf: A pointer to the temporary buffer for reading data.
 * @fd: The file descriptor to read from.
 *
 * This function reads data from 'fd' into 'buf', concatenates it with 'str',
 * and updates 'str' with the concatenated data.
 */
void	reader(char **str, char **buf, int fd)
{
	int rtn_read;
	char *r;

	rtn_read = 1;
	while (rtn_read > 0)
	{
		rtn_read = read(fd, *buf, BUFFER_SIZE);
		if (rtn_read > 0)
		{
			(*buf)[rtn_read] = '\0';
			if (!*str)
				*str = ft_strdup(*buf);
			else
			{
				r = ft_strjoin(*str, *buf);
				ft_free(str);
				*str = r;
			}
			if (ft_strchr(*str, '\n') == 1)
				break;
		}
	}
	ft_free(buf);
}

/**
 * _getline - Custom getline function to read lines from a file descriptor.
 * @fd: The file descriptor to read from.
 *
 * Return: A line read from 'fd' or NULL if an error occurs.
 */
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
=======
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
>>>>>>> 0b207e3 (done)
