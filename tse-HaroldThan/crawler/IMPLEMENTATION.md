## 'Crawler.c'
### 'main'
	check the inputs
	return error code if applies
	run crawler()

### 'crawler'
	*crawler* uses a bag to track pages to explore, and hashtable to track pages seen; when it explores
	a page it gives the page URL to the pagefetcher, then the result to pagesaver, then to the pagescanner.
    //2. insert seedURL to bag and hashtable 
		initialize ID Count

### 'pagescanner'
	use *pagescanner* to parse the webpage to extract all its embedded URLs;
	for each extracted URL,
			 'normalize' the URL (see below)
			 if that URL is not 'internal' (see below), ignore it;
			 try to insert that URL into the *hashtable* of URLs seen
				 if it was already in the table, do nothing;
				 if it was added to the table,
					 make a new *webpage* for that URL, at depth+1
					 add the new webpage to the *bag* of webpages to be crawled

### 'pagesaver'
	makes a new file with the ID as filename
	prints the URL 
	prints the Depth 
	prints the webpage
	Free Used URL







