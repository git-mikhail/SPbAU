#! /bin/bash

# Mikhail Mitrofanov, 2015 
# Вывести на экран все уникальные строки из файла, перемешав их
# случайным образом и перенумеровав в порядке вывода.

if (( $# < 1))
then echo "Invalid arguments!"; exit 1
fi

COUNTER=0

for i in $(sort -u $1 | shuf); do
    COUNTER=`expr $COUNTER + 1`
    echo "$COUNTER - $i"
done

