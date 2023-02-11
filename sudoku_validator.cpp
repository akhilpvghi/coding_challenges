// to compile in mobaxterm ==>gcc -g validate_sudoku.cpp -o validate_sudoku.exe -lstdc++
// to run in mobaxterm ===> ./validate_sudoku.exe

#include<map>
#include<iostream>
#include<string>

int arr_max_limit_of_each_box[] = {2,5,8};
int main_array[9][9]= {{5,3,10,10,7,10,10,10,10},   //0
                       {6,10,10,1,9,5,10,10,10},    //1
                       {10,9,8,10,10,10,10,6,10},   //2
                       {8,10,10,10,6,10,10,10,3},   //3
                       {4,10,10,8,10,3,2,10,1},    //4
                       {7,10,10,10,3,2,10,10,6},   //5
                       {10,6,10,10,10,10,2,8,10},   //6
                       {10,10,10,4,1,9,10,10,5},    //7
                       {10,10,10,10,8,10,10,7,9}};  //8
struct starting_indices_of_box{
    int row;
    int col;
};

starting_indices_of_box st_i = {0, 0};

starting_indices_of_box get_starting_indices_of_boxes(int row, int col){
    starting_indices_of_box set_at_staring;
    if(row % 3 != 0)
        row -= row%3;
    if(col % 3 != 0)
        col -= col%3;
    set_at_staring.row = row;
    set_at_staring.col = col;
    return set_at_staring;
}

void print_array(int *arr){ //for debugging only
    for (int i=0; i<=8; i++)
        std::cout<<" "<<*(arr+i);
        std::cout<<" \n";

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
        _main_arr_temp = main_array[row][j]-1;
        ++array_element_count_check[_main_arr_temp];
    }
    return validate_arr_element_count(array_element_count_check);
}

bool check_column(int col){
    int array_element_count_check[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int _main_arr_temp = 0;
    for (int i=0; i<=8; i++){
        _main_arr_temp = main_array[i][col]-1;
        ++array_element_count_check[_main_arr_temp];
    }
    return validate_arr_element_count(array_element_count_check);
}

bool check_box(int row, int col){
    int array_element_count_check[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int _main_arr_temp = 0;
    starting_indices_of_box st_indices;
    st_indices = get_starting_indices_of_boxes(row, col);
        for(int i=0; i<=2; i++){
            for(int j=0; j<=2; j++){
                _main_arr_temp = main_array[st_indices.row+i][st_indices.col+j]-1;
                ++array_element_count_check[_main_arr_temp];
            }
        }
    return validate_arr_element_count(array_element_count_check);
}

int main(int argc, char *argv[]){
    int temp = 0, remainder_with_i=0;
    for( int i=0; i <= 8;i++){
        remainder_with_i = i%3;
        temp = remainder_with_i*4 + i/3;
        if(arr_max_limit_of_each_box[remainder_with_i] < temp)
            temp = arr_max_limit_of_each_box[remainder_with_i - 1] + (temp - arr_max_limit_of_each_box[remainder_with_i]);
        std::cout<<"print ("<<i<<", "<<temp<<" ) ";
        bool row_validated = check_row(i);
        bool column_validated = check_column(temp);
        bool box_validated = check_box(i,temp);
        std::cout<<"row_validated = "<<row_validated<<" column_validated = "<<column_validated<<" box_validated = "<<box_validated<<"\n";
        
    }

    return 0;
}
