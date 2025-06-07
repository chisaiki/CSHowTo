# Working With Shell Script

## How to Create a Shell Script in Linux
    $touch <script_name>.sh #Creates File
    $chmod +x <script_name>.sh #Gives execution permissions to the file

NOTE: $touch by default does not allow executable permissions to files

## Example of a Shell Script

    #!/bin/bash

    if [ $# == 2 ]
    then
        seq $1 | shuf >| $2.txt
    else
        echo 'Error: Not enough arguments.'
    fi
