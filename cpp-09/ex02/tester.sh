#!usr/bin/bash

if [ -z "$1" ] || [ -z "$2" ]; then
	echo "Usage: bash 1000tests.sh <iterations> <value range>"
	exit 1
fi

echo "Running $1 tests for $2 values"

for ((i = 0; i < $1; i++)); do
	./PmergeMe $(shuf -i 0-"$2" -n "$2" | tr "\n" " ") >> 1000test.log
done

echo "Total number of tests: $i"
echo -n "Success: "
cat <1000test.log | grep -c "successfully sorted"
echo -n "Failure: "
cat <1000test.log | grep -c "not sorted"
