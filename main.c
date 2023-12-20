#include <unistd.h>
#include <stdio.h>

unsigned char swap_bits(unsigned char octet)
{
    return ((octet >> 4) | (octet << 4));
}

void print_bits(unsigned char octet)
{
    unsigned char tmp;
    int i;

    i = 8;
    while (i--)
    {
        tmp = (octet >> i & 1) + '0';
        write(1, &tmp, 1);
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
        j++;
    }
    return (result);
}

int main()
{
    printf("%d\n", reverse_bits(1));
    return 0;
}

// unsigned char reverse_bits(unsigned char octet)
// {
//     unsigned char result;
//     int i;
//     int j;

//     i = 8;
//     j = 0;
//     while (i--)
//     {
//         result |= ((octet >> i & 1) << j);
//         j++;
//     }
//     return (result);
// }