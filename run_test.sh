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

echo "Running test with BUFFER_SIZE=$BUFFER_SIZE and file=$FILE
"
./gnl "$FILE"
./gnl "$FILE" > out.txt
if diff -q out.txt $FILE > /dev/null; then
	echo "
	✅ $FILE and BUFFER_SIZE=$BUFFER_SIZE: OK"
else
	echo "
	❌ $FILE and BUFFER_SIZE=$BUFFER_SIZE: KO"
fi
# valgrind --leak-check=full ./gnl

rm -f out.txt