#include <stdio.h>

int hexToDecimal(char hex)
{
    if (hex >= '0' && hex <= '9')
    {
        return hex - '0';
    }
    return hex - 'A' + 10;
}

int getChecksum(int sum) 
{
    int lowerByte = sum & 0xFF; 
    return 0x100 - lowerByte;
}

int main()
{
    const char* hex = ":100020000C9445000C9445000C9445000C9445003C";
    int hexLength = 0;
    int decimalSumBytes = 0;

    while (hex[hexLength] != '\0')
    {
        hexLength++;
    }

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

    printf("Intel HEX - %s\n", hex);
    printf("Received checksum - %X", getChecksum(decimalSumBytes));
    return 0;
}
