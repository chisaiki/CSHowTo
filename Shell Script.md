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

### What does this script do?

    #!/bin/bash      #The shebang, is used in scripts to instruct the operating system to use bash as a command interpreter; specifies the path to the shell interpreter (bash in this case) to execute the script.
    if [ $# == 2 ]   #Checks if there are two arguments on the command line, this program is expecting a whole number for the first argument and a filename for second
    seq $1           #Will produce whole numbers counting up from 1 to the whole number inputted as the first argument    
    | shuf           #The output of the sequence is then pipelined as the input for shuffle (shuf), which scrambles the order of the number
    >| $2.txt        #The shuffled numbers are then pipelined as input for the text file, and written into the file. File name is created using the string in the second argument

    NOTE: >| instructs the bash interpreter to write over noclobber
    [The noclobber option, when enabled, prevents accidental overwriting of files when using redirection operators like >. It's a safety mechanism that helps protect existing files from being unintentionally altered.]
