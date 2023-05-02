/* strcmp関数の実現例 */

int strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2) {
		if (*s1 == '\0')		/* 等しい */
			return 0;
		s1++;
		s2++;
	}
	return (unsigned char)*s1 - (unsigned char)*s2;
}
