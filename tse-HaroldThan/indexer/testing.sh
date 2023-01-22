#Testing Script for Indexer and Indextest

printf "Make New Data Dir\n"
make clean
rm -rf data
mkdir data

printf "Make Indexer and Indexertest:\n"
make all

printf "1.Testing Inputs\n"
./indexer
./indextest
./indexer wrong format lol
./indexer ../data2 oldIndexFilename

printf "2.Test Indexer\n"
cd ../indexer
./indexer ../data2 ../data2/oldIndexFilename

printf "3. Use Indextest to write(load) from data/oldIndexFilename to data/newIndexFilename...\n"
./indextest ../data2/oldIndexFilename ../data2/newIndexFilename

printf "4. Sort Files Before Comparison\n"
sort ../data2/oldIndexFilename -o ../data2/oldIndexFilename
sort ../data2/newIndexFilename -o ../data2/newIndexFilename

printf "COMPARING OLD VS NEW:\n"
if cmp --silent -- ../data2/oldIndexFilename ../data2/newIndexFilename
then
   echo "PASSED: OLD AND NEW FILES MATCHED"
else
   echo "FILES MATCHING FAILED"
fi

sort ../data2/correctIndexFilename -o ../data2/correctIndexFilename
printf "5. COMPARING TO PROF'S PROVIDED INDEXFILE\n"
if cmp --silent -- ../data2/oldIndexFilename ../data2/correctIndexFilename
then
   echo "PASSED: MATCHED THE PROF'S PROVIDED OUTPUT"
else
   echo "FILES MATCHING FAILED"
fi

printf "\n\n\n\n\n\n\nTA TEST CASES \n"

#!/bin/bash
# 
# testing.sh - testing indexer functionality 
#
# usage: ./testing.sh
#
# 2021 Summer 

######## file comparison function
compare_file() {
	echo "======= COMPARE TO TSE OUTPUT ======="
	sort "$1" > $1.s
	sort "$2" > $2.s
	if diff "$1.s" "$2.s" > "$1.diffs"
	then
	    echo "nice! $1 matches TSE output!"
	    return 0
	else
	    echo "hmm... the index differs from TSE output; see $1.diffs."
	    return 1
	fi	
}

##########
# an index file for testing
testindex=testing.index
datadir=/thayerfs/courses/21summer/cosc050/cs50tse/tse-output 


#### testing invalid parameters 
echo "==== TESTING INVALID INPUTS ===="
./indexer
./indexer $datadir/data3 
./indexer $datadir/cs50-depth-0
./indexer $datadir/cs50-depth-0 $datadir/cs50-index-0 more
./indexer . $datadir/cs50-index-0
./indexer $datadir/cs50-index-0 /indexFile
./indexer $datadir/cs50-depth-0 /indexFile

# testing unwritable indexfile:
rm -f $testindex
touch $testindex
chmod -w $testindex
./indexer  $datadir/wikipedia-depth-0 $testindex
rm -f $testindex

#### testing valid parameters

# index a depth-0 crawl of `wikipedia`
echo "=== TEST CASE 1: Wikipedia depth 0 ==="
./indextest.sh $datadir/wikipedia-depth-0 $testindex
compare_file $testindex $datadir/wikipedia-index-0

# index a depth-3 crawl of `letters`
echo "=== TEST CASE 2: letters depth 3 ==="
./indextest.sh $datadir/letters-depth-3 $testindex
compare_file $testindex $datadir/letters-index-3

# index a depth-1 crawl of `wikipedia`
echo "=== TEST CASE 3: Wikipedia depth 1 ==="
./indextest.sh $datadir/wikipedia-depth-1 $testindex
compare_file $testindex $datadir/wikipedia-index-1

# index a depth-2 crawl of `toscrape`
echo "=== TEST CASE 4: toscrape depth 2 ==="
./indextest.sh $datadir/toscrape-depth-2 $testindex
compare_file $testindex $datadir/toscrape-index-2

# index a depth-2 crawl of `toscrape`
echo "=== TEST CASE 5: Wikipedia depth 2 ==="
./indextest.sh $datadir/wikipedia-depth-2 $testindex
compare_file $testindex $datadir/wikipedia-index-2


#### valgrind test
echo "==== MEMORY TEST ===="
VALGRIND='valgrind --leak-check=full --show-leak-kinds=all'
$VALGRIND ./indexer $datadir/letters-depth-3 $testindex
$VALGRIND ./indextest $testindex $testindex.tmp

# clean up
rm -f $testindex $testindex.tmp $testindex.diffs