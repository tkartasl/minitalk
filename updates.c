#include <stdio.h>
#include <string.h>
#include <unistd.h>

void    get_string(int len, char *str)
{
	char	binary[512];
	int 	bit;
	char 	byte;
	int		i;

	i = 0;
	bit = 0;
	byte = 0;
    while (*str != 0)
    {
		if (*str == '0')
			byte &= ~(128 >> bit);
		if (*str == '1')
			byte |= (128 >> bit);
		bit++;
		if (bit > 7)
		{
			bit = 0;
			binary[i++] = byte;
			byte = 0;
		}
		if (i < len)
			str++;
 	}        
	binary[i] = 0;
	while (binary[byte] != 0)
		write(1, &binary[byte++], 1);
}

int	ft_recursive_power(int nb, int power)
{
	int	a;

	a = nb;
	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	if (power > 1)
		return (nb * ft_recursive_power(a, power - 1));
	else
		return (nb);
}

int get_len (char *binary)
{
    int     len;  
    int     bit_count;
    int     bit;

    bit_count = 31;
    len = 0;
    bit = 0;
    while (*binary != 0)
    {
        bit = *binary - '0';
        len = len + bit * ft_recursive_power(2, bit_count);
        bit = 0;
        bit_count--;
        binary++;
    }
    return (len);
}

int main()
{
    char    binary[]= "0100100001100101011011000110110001101111001000000011010000110010";
	int 	len;

	len = get_len(binary);
	get_string(len, binary);
    return (0);
}