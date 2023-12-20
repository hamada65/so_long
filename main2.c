#include <stdio.h>

unsigned char swap_bits(unsigned char octet)
{
    return ((octet << 4) | (octet >> 4));
}

void print_bits(unsigned char octet)
{
    unsigned char bit;
    int i;

    i = 8;
    while (i--)
    {
        bit = (octet >> i & 1) + '0';
        write(1, &bit, 1);
    }
}

unsigned char reverse_bits(unsigned char octet)
{
    unsigned char result;
    int i;
    int j;

    i = 8;
    j = 0;
    while (i--)
    {
        result |= ((octet >> i & 1) << j);
    }
    return (result);
}

int main()
{
    print_bits(1);
}