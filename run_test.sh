#!/bin/bash

if [ "$#" -ne 2 ]; then
	echo "Sintax: $0 BUFFER_SIZE file_name"
	exit 1
fi

BUFFER_SIZE=$1
FILE=$2

if [ ! -f "$FILE" ]; then
	echo "ERROR: file '$FILE' does not exist!"
	exit 1
fi

make fclean > /dev/null
make BUFFER_SIZE=$BUFFER_SIZE > /dev/null

echo "Running test with BUFFER_SIZE=$BUFFER_SIZE and file=$FILE"
./gnl "$FILE"
# valgrind --leak-check=full ./gnl