#include "monty.h"

/**
 * _strcmp - Compare two strings
 * @s1: First string to compare
 * @s2: Second string to compare
 *
 * Return: an integer less than, equal to, or greater than zero if s1 is
 *         found respectively to be less than, to match or be greater than s2.
 *
 * Description: This function compares two strings character by character
 * until a difference is found or one of the strings reaches its null terminato
 */
int _strcmp(char *s1, char *s2)
{
int res = 0;

do {
res = *s1 - *s2;

if (*s1 == '\0' || *s2 == '\0')
break;

s1++;
s2++;
} while (res == 0);

return (res);
}
