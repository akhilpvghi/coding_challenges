#!/bin/bash
# !Author AKHIL
# Description : to encrypt any file simply
# _m_e_ indicates modified encrypted
# _m_d_on_ indicates modified decrypted on encrypted
# obj_e indicates encrypted file
# obj_d indicates decrypted file
# usage: ./_do_crypto.sh _spilit_files_dir enc/dec
# e.g. ./_do_crypto.sh "/drives/c/Extra/_2/ENC" enc
# e.g. ./_do_crypto.sh "/drives/c/Extra/_1/_encryption_process/" dec

file_count=$(ls $dir_path | wc -l)
# echo $dir_path
# echo $2
dir=$1
binary_directory="$(pwd)"
_encryption_process=_encryption_process/
_m_e_=_m_e_
FINAL_EXTENSION=.FILE


#!/bin/bash
echo "$dir"
cd $dir
full_path_of_spilit_content_dir="$(pwd)"
if [ $2 = "enc" ]
then
    for file in *; do
        # Check if the file is a regular file
        if [ -f "$file" ]; then
            # Print the name of the file (without the directory)
            # echo "$(basename "$file")"
            echo "binary_directory $binary_directory"
            echo "full_path_of_spilit_content_dir $full_path_of_spilit_content_dir"
            mkdir -p $full_path_of_spilit_content_dir/$_encryption_process
            $binary_directory/add_one_to_everyhex $full_path_of_spilit_content_dir/$file $full_path_of_spilit_content_dir/$_encryption_process/$_m_e_$file$FINAL_EXTENSION
        fi
    done
else
    for file in *; do
        # Check if the file is a regular file
        if [ -f "$file" ]; then
            # Print the name of the file (without the directory)
            echo "$(basename "$file")"
            mkdir -p $full_path_of_spilit_content_dir/_decryption_process
            $binary_directory/subtract_one_to_everhex $full_path_of_spilit_content_dir/$file $full_path_of_spilit_content_dir/_decryption_process/_m_d_on_$file
        fi
    done
    cd $full_path_of_spilit_content_dir/_decryption_process
    # cat _m_d_on_* >> obj_d
fi
cd -


# ================================================
# if [ $2 = "enc" ]
# then
#     if [ -d $dir ]; then
#     file_count=$(ls -1 $dir | wc -l)
#     echo "Found $file_count files in directory $dir"
    
#     for file in $dir/*; do
#         if [ -f $file ]; then
#         echo "Processing encryption on file  $file..."
#         mkdir $dir/_encryption_process
#         ./add_one_to_everyhex $file $dir/_encryption_process/_m_e_$file_count
#         file_count=$file_count-1
#         fi
#     done
#     cat $dir/_encryption_process/_m_e_* > obj_e
#     else
#     echo "Directory $dir not found."
#     fi
# else
#     if [ -d $dir ]; then
#     file_count=$(ls -1 $dir | wc -l)
#     echo "Found $file_count files in directory $dir"
    
#     for file in $dir/*; do
#         if [ -f $file ]; then
#         echo "Processing decryption on file  $file..."
#         ./subtract_one_to_everhex $file $dir_path_m_d_on_$file
#         fi
#     done
#     cat _m_d_on_* > obj_d
#     else
#     echo "Directory $dir not found."
#     fi
# fi
