// COMPILE
// gcc -g subtract_one_to_everhex.c -o subtract_one_to_everhex
// ./subtract_one_to_everhex _input_file _output_file

#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE *input_file, *output_file;
    input_file = fopen(argv[1], "rb");
    output_file = fopen(argv[2], "wb");
    if (input_file == NULL || output_file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    unsigned char byte;
    while (fread(&byte, 1, 1, input_file) == 1)
    {
        if (byte != 0xff)
        {
            byte--;
        }
        fwrite(&byte, 1, 1, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("File processed successfully.\n");
    return 0;
}
