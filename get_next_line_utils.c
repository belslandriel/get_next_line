/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miclandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:38:59 by miclandr          #+#    #+#             */
/*   Updated: 2024/11/28 19:39:35 by miclandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    size_t i = 0;
    while (s[i])
        i++;
    return (i);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char *result;
    size_t i, j;
    size_t len1 = ft_strlen(s1);
    size_t len2 = ft_strlen(s2);

    result = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
    if (!result)
        return (NULL);
    i = 0;
    while (i < len1)
    {
        result[i] = s1[i];
        i++;
    }
    j = 0;
    while (j < len2)
    {
        result[i + j] = s2[j];
        j++;
    }
    result[i + j] = '\0';
    return (result);
}

char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if ((char)c == '\0')
        return ((char *)s);
    return (NULL);
}

char *ft_strdup(const char *s1)
{
    char *dup;
    size_t len = ft_strlen(s1);

    dup = (char *)malloc(sizeof(char) * (len + 1));
    if (!dup)
        return (NULL);
    while (len + 1 > 0)
    {
        dup[len] = s1[len];
        len--;
    }
    return (dup);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *substr;
    size_t i;
    size_t s_len = ft_strlen(s);

    if (!s)
        return (NULL);
    if (start >= s_len)
        return (ft_strdup(""));
    if (len > s_len - start)
        len = s_len - start;
    substr = (char *)malloc(sizeof(char) * (len + 1));
    if (!substr)
        return (NULL);
    i = 0;
    while (i < len && s[start + i])
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';
    return (substr);
}
