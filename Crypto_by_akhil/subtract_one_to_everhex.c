// COMPILE
// gcc -g subtract_one_to_everhex.c -o subtract_one_to_everhex
// ./subtract_one_to_everhex _input_file _output_file

// COMPILE
// gcc -g add_one_to_everhex.c -o add_one_to_everhex
// ./add_one_to_everhex _input_file _output_file

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: could not open input file %s\n", argv[1]);
        return 1;
    }
    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error: could not open output file %s\n", argv[2]);
        fclose(input_file);
        return 1;
    }
    fseek(input_file, 0, SEEK_END);
    long input_file_size = ftell(input_file);
    rewind(input_file);
    char *input_data = malloc(input_file_size);
    fread(input_data, 1, input_file_size, input_file);
    fclose(input_file);
    char *output_data = malloc(input_file_size);
    for (long i = 0; i < input_file_size; i++) {
        if (input_data[i] != 0xFF) {
            output_data[i] = input_data[i] - 1;
        } else {
            output_data[i] = input_data[i];
        }
    }
    fwrite(output_data, 1, input_file_size, output_file);
    fclose(output_file);
    free(input_data);
    free(output_data);
    return 0;
}

