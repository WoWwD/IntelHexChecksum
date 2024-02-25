#include <stdio.h>

int getHexLength(const char hex[])
{
    int hexLength = 0;

    while (hex[hexLength] != '\0')
    {
        hexLength++;
    }
    return hexLength;
}

int hexToDecimal(char hex)
{
    if (hex >= '0' && hex <= '9')
    {
        return hex - '0';
    }
    return hex - 'A' + 10;
}
