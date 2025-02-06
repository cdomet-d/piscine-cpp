#usr/bin/bash

for ((i = 0; i < 1000; i++)); do
	make run >> 1000test.log
done

echo "Total number of tests: $i"
echo -n "Success: "
cat 1000test.log | grep "successfully sorted" | wc -l 
echo -n "Failure: "
cat 1000test.log | grep "not sorted" | wc -l

# rm 1000test.log