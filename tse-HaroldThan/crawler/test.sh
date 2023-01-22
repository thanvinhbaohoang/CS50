# # TESTING SCRIPT FOR CRAWLER.C

echo "1. Test the crawler with a seedURL that points to a non-existent server."
make clean
make crawler
./crawler "Fake URL" "../data" 2 

echo "2. Test the crawler with a seedURL that points to a non-internal server."
./crawler "http.//www.google.com" "../data" 2

echo "3. Test the crawler with a seedURL that points to a valid server but non-existent page."
./crawler "http://cs50tse.cs.dartmouth.edu/tse/fakepage" "../data" 2 

echo "4. Crawl a simple, closed set of cross-linked web pages and explore at depths 0, 1, 2, 3, 4, 5."
# Verify that the files created match expectations.
URL = http://cs50tse.cs.dartmouth.edu/tse/letters/index.html
 
make clean
make crawler
rm -r ../data/*
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ../data 0
if [ $(ls ../data | wc -l) -eq 1 ]; then
	echo "$URL good at depth 0"
else
	echo "$URL failed at depth 0"
fi

rm -r ../data/*
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ../data 1
if [ $(ls ../data | wc -l) -eq 2 ]; then
	echo "$URL good at depth 1"
else
	echo "$URL failed at depth 1"
fi

rm -r ../data/*
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ../data 2
if [ $(ls ../data | wc -l) -eq 3 ]; then
	echo "$URL good at depth 2"
else
	echo "$URL failed at depth 2"
fi

rm -r ../data/*
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ../data 3
if [ $(ls ../data | wc -l) -eq 6 ]; then
	echo "$URL good at depth 3"
else
	echo "$URL failed at depth 3"
fi

rm -r ../data/*
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ../data 4
if [ $(ls ../data | wc -l) -eq 8 ]; then
	echo "$URL good at depth 4"
else
	echo "$URL failed at depth 4"
fi

rm -r ../data/*
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ../data 5
if [ $(ls ../data | wc -l) -eq 9 ]; then
	echo "$URL good at depth 5"
else
	echo "$URL failed at depth 5"
fi



echo "Point the crawler at our Wikipedia playground."
# (It takes a long time to run at depth 2 or higher!) Verify that the files created match expectations.
wikiURL = 'http://cs50tse.cs.dartmouth.edu/tse/wikipedia/index.html'
mkdir ../wiki
rm -r ../wiki/*
for i in 0 1 2
do 
	make clean
	make crawler
	./crawler http://cs50tse.cs.dartmouth.edu/tse/wikipedia/index.html ../wiki 1 
	if [ $(ls ../data | wc -l) -eq 7 ]; then
		echo "$wikiURL good at depth 1"
	else
		echo "$wikiURL failed at depth 1"
	fi
done


