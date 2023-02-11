#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int arr_max_limit_of_each_box[] = {2,5,8};
char **main_array;
struct starting_indices_of_box{
    int row;
    int col;
};

struct starting_indices_of_box st_i = {0, 0};

struct starting_indices_of_box get_starting_indices_of_boxes(int row, int col){
    struct starting_indices_of_box set_at_staring;
    if(row % 3 != 0)
        row -= row%3;
    if(col % 3 != 0)
        col -= col%3;
    set_at_staring.row = row;
    set_at_staring.col = col;
    return set_at_staring;
}

bool validate_arr_element_count(int *arr){
    for (int i=0; i<=8; i++)
        if(arr[i] > 1){
            // print_array(arr);  //for debugging only
            return false;
        }
    return true;
}

bool check_row(int row){
    int array_element_count_check[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int _main_arr_temp = 0;
    for (int j=0; j<=8; j++){
        if(main_array[row][j]!='.'){
            char *array;
        array = malloc(2);
        array[0] = main_array[row][j];
        array[1] = '\0';
            _main_arr_temp = atoi(array)-1;
        }
        else
            _main_arr_temp=9;
        ++array_element_count_check[_main_arr_temp];
    }
    return validate_arr_element_count(array_element_count_check);
}

bool check_column(int col){
    int array_element_count_check[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int _main_arr_temp = 0;
    for (int i=0; i<=8; i++){
        if(main_array[i][col]!='.'){
            char *array;
        array = malloc(2);
        array[0] = main_array[i][col];
        array[1] = '\0';
        _main_arr_temp = atoi(array)-1;
        }
        else
            _main_arr_temp=9;
        ++array_element_count_check[_main_arr_temp];
    }
    return validate_arr_element_count(array_element_count_check);
}

bool check_box(int row, int col){
    int array_element_count_check[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int _main_arr_temp = 0;
    struct starting_indices_of_box st_indices;
    st_indices = get_starting_indices_of_boxes(row, col);
        for(int i=0; i<=2; i++){
            for(int j=0; j<=2; j++){
                if(main_array[st_indices.row+i][st_indices.col+j]!='.'){
                    char *array;
        array = malloc(2);
        array[0] = main_array[st_indices.row+i][st_indices.col+j];
        array[1] = '\0';
                    _main_arr_temp = atoi(array)-1;
                }
                else
                     _main_arr_temp=9;
                    ++array_element_count_check[_main_arr_temp];
            }
        }
    return validate_arr_element_count(array_element_count_check);
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    main_array = board;
    int temp = 0, remainder_with_i=0;
    for( int i=0; i <= 8;i++){
        remainder_with_i = i%3;
        temp = remainder_with_i*4 + i/3;
        if(arr_max_limit_of_each_box[remainder_with_i] < temp)
            temp = arr_max_limit_of_each_box[remainder_with_i - 1] + (temp - arr_max_limit_of_each_box[remainder_with_i]);
        bool row_validated = check_row(i);
        bool column_validated = check_column(temp);
        bool box_validated = check_box(i,temp);
        if(! (row_validated && column_validated && box_validated))
            return false;
    }
    return true;
}

int main( int argc,char* argv[]){
    int *boardColSize;
    *boardColSize=9;
    char* board[]={"53..7....",
"6..195...",
".98....6.",
"8...6...3",
"4..8.3..1",
"7...2...6",
".6....28.",
"...419..5",
"....8..79"};
    printf(" final %d", isValidSudoku(board,9,boardColSize));
    return 0;
}
