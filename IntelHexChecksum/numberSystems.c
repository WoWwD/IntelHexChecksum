#include <stdio.h>

int hexToDecimal(char hex)
{
    if (hex >= '0' && hex <= '9')
    {
        return hex - '0';
    }
    return hex - 'A' + 10;
}

void decimalToHex(int n, char *result)
{
    char hex[33];
    int i = 0;

    while (n != 0) {
        int remainder = n % 16;
        if (remainder < 10) 
        {
            hex[i++] = '0' + remainder;
        }
        else {
            hex[i++] = 'A' + (remainder - 10);
        }
        n /= 16;
    }

    for (int j = i - 1; j >= 0; j--) 
    {
        result += hex[j];
    }
}