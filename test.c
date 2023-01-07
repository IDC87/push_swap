/* #include <stdio.h>
#include <limits.h>
#include <stdlib.h>

static int ft_is_digit(int c)
{
	return (c >= '0' && c <= '9');
}
static int ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
	c == '\v' || c == '\f' || c == '\r');
}

long int t_atoi(char *str)
{
	int sign;
	unsigned long int result;

	sign = 1;
	result = 0;
	while (ft_is_whitespace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while ((*str != '\0') && ft_is_digit(*str))
	{
		if (result >= 9223372036854775807 && sign == 1)
			return (-1);
		else if (result > 9223372036854775807 && sign == -1)
			return (0);
		result = (result * 10) + (*str - '0');
		str++;
	}
	return ((long int)(result * sign));
}

int main(int argc, char* argv[]) {
    // Check if the user provided an argument
    if (argc < 2) {
        printf("Error: no argument provided.\n");
        return 1;
    }
    
    // Convert the argument to an int
   long int value = t_atoi(argv[1]);
	printf("\n\nVALUE FROM ATOI %ld\n\n", value);
    
    // Check if the value is within range
    if (value >= INT_MIN && value <= INT_MAX) {
        printf("The value is within range.\n");
    } else {
        printf("The value is out of range.\n");
    }
    
    return 0;
} */