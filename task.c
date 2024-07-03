#include <stdio.h>
#include <string.h>
#include "task.h"
#define INCORRECTINPUT -1
#define NOSUCHFILE -2
#define INCORRECTFORMAT -3
int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Incorrect input \n");
        return INCORRECTINPUT;
    }
    return printBMP(argv[1]);
}
int checkformat(FILE *file)
{
    char signature[3];
    fread(&signature, 2, 1, file);
    signature[2] = '\0';
    if (strcmp(signature, "BM\0") != 0)
    {
        return INCORRECTFORMAT;
    }
    return 0;
}
int printBMP(const char *src)
{
    int bytes[14] = {4, 4, 4, 4, 4, 4, 2, 2, 4, 4, 4, 4, 4, 4}; // number of bytes to read each header
    char *headernames[14] = {"File size: ", "Reserved: ", "Data offset: ", "Size: ", "Width: ", "Height: ", "Planes: ", "Bits/pixel: ", "Compression: ", "Image size: ", "Pixels/meter (horizontal): ", "Pixels/meter (vertical): ", "Colors used: ", "Important colors: "};
    char *compression[3] = {"none", "BI_RLE8", "BI_RLE4"}; // compression types
    FILE *file = fopen(src, "rb");
    if (!file)
    {
        printf("No such file \n");
        return NOSUCHFILE;
    }
    if (checkformat(file) == INCORRECTFORMAT)
    {
        printf("Incorrect file format \n");
        fclose(file);
        return INCORRECTFORMAT;
    }
    int value;
    for (int i = 0; i < 14; i++)
    {
        fread(&value, bytes[i], 1, file);
        if (i == 8) // index of compression
        {
            printf("%s%s \n", headernames[i], compression[value]);
            continue;
        }
        printf("%s%d \n", headernames[i], value);
    }
    fclose(file);
    return 0;
}
