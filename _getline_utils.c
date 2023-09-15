#include "_getline.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size;
	char	*s3;
	size_t	size_s1;
	size_t	size_s2;
	size_t	i;

	if (!s1 && !s2)
		return (0);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	size = size_s1 + size_s2;
	s3 = (char *)malloc(sizeof(char) * (size + 1));
	if (!s3)
		return (0);
	i = 0;
	while (*s1)
		s3[i++] = *s1++;
	while (*s2)
		s3[i++] = *s2++;
	s3[i] = '\0';
	return (s3);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	len_str;

	if (!s)
		return (0);
	len_str = ft_strlen(s);
	if (start > len_str)
		start = len_str;
	if (len + start >= len_str)
		len = len_str - start;
	new_str = (char *) malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (0);
	i = 0;
	if (len_str > start)
	{
		while (i < len && s[start])
			new_str[i++] = s[start++];
	}
	new_str[i] = 0;
	return (new_str);
}

void	ft_free(char **str)
{	
	free(*str);
	*str = NULL;
}
