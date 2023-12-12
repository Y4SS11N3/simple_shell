#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: String to convert.
 *
 * Return: The converted integer.
 */
int _atoi(char *s)
{
	int n = 0;
	int g = 1;

	while (*s)
	{
		if (*s == '-')
			g = -1;
		else if (*s >= '0' && *s <= '9')
			n = n * 10 + (*s - '0');
		else if (n != 0)
			break;
		s++;
	}
	return (n * g);
}

/**
 * _strchr - Finds the first occurrence of a character in a string.
 * @s: String to search in.
 * @c: Character to search for.
 *
 * Return:Pointer to the first occurrence of the character or NULL if not found
 */
char *_strchr(const char *s, char c)
{
	while (*s != '\0' && *s != c)
	{
		s++;
	}

	return ((*s == c) ? (char *)s : NULL);
}

/**
 * _strdup - Duplicates a string.
 * @str: String to duplicate.
 *
 * Return: Pointer to the duplicated string or NULL if an error occurs.
 */
char *_strdup(const char *str)
{
	char *copy;
	int len, i;

	if (!str)
	{
		return (NULL);
	}

	for (len = 0; str[len] != '\0'; len++)
		;
	copy = malloc(len + 1);

	if (!copy)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		copy[i] = str[i];
	}

	return (copy);
}

/**
 * _strncmp - Compares two strings up to n bytes.
 * @s1: First string.
 * @s2: Second string.
 * @n: Number of bytes to compare.
 *
 * Return: Difference between the two strings.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n && s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return ((i == n) ? 0 : (s1[i] - s2[i]));
}

/**
 * _strcmp - Compares two strings.
 * @s1: First string.
 * @s2: Second string.
 *
 * Return: Difference between the two strings.
 */
int _strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
	{
		return (s1 - s2);
	}

	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
