#include <stdio.h>

int getChecksum(const char hex[])
{
    int hexLength = getHexLength(hex);
    int decimalSumBytes = 0;

    for (int i = 1; i < hexLength - 2; i += 2)
    {
        if (hex[i + 1] != '\0')
        {
            decimalSumBytes += hexToDecimal(hex[i]) * 16 + hexToDecimal(hex[i + 1]);
        }
        else
        {
            decimalSumBytes += hexToDecimal(hex[i]);
        }
    }

    int lowerByte = decimalSumBytes & 0xFF;
    return 0x100 - lowerByte;
}

int main()
{
    const char hex[] = ":100050000C94450011241FBECFE5D4E0DEBFCDBF18";

    printf("Intel HEX - %s\n", hex);
    printf("Calculated checksum - %X", getChecksum(hex));
    return 0;
}
