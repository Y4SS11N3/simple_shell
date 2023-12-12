#include "main.h"

/**
 * _memcpy - Copies memory area.
 * @dest: Destination memory area.
 * @src: Source memory area.
 * @n: Number of bytes to copy.
 *
 * Return: Pointer to the destination memory area.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: Destination string.
 * @src: Source string.
 *
 * Return: Pointer to the destination string.
 */
char *_strcat(char *dest, const char *src)
{
	int i, j;

	if (!dest || !src)
	{
		return (dest);
	}

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i + j] = src[j];
	}
	dest[i + j] = '\0';
	return (dest);
}

/**
 * _strcpy - Copies a string, accepting const source.
 * @dest: Destination string.
 * @src: Source string (const).
 * Return: Pointer to the destination string.
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	if (!dest || !src)
	{
		return (dest);
	}

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strlen - Returns the length of a string.
 * @s: String to find the length of.
 *
 * Return: Length of the string.
 */
int _strlen(const char *s)
{
	int n = 0;

	if (!s)
	{
		return (0);
	}

	while (s[n] != '\0')
	{
		n++;
	}
	return (n);
}
