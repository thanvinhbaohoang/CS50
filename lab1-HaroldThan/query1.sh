# CS50, Summer 2021
#!/bin/bash
# Harold Than, 7/3/2021
# query.sh- Return Number Of Vaccinated People In A Certain State 
#
# usage: ./query.sh [statename] ["date"]
# 
# input: [statename]; or [statename] ["date"]
# output: number of vaccinated people of the State From Latest Data; or from specified date
#
# CS50, Summer 2021

latest_date=$(cut -d "," -f 1 vaccine.csv| awk 'NR>1'| head -1)


# 1.Your script should print an error and exit non-zero if the number of arguments is 
# less than 1 or greater than 2.
if [ "$#" == "0" ]; then
    	echo "No arguments provided"
    exit 1

elif (( "$#" > 2 )); then
	echo "Can Not Provide More Than 2 Arguments"
    exit 1
fi


#2.Your script should print an error and exit non-zero if vaccine.csv is not existing
if [ ! -f "vaccine.csv" ]
then
    echo "vaccine.csv does not exist"
fi

###################WORKING CODE###########################

if (( "$#" == "1" )); then
# 3.Your script should print an error and exit non-zero if 
# it does not find the state specified by the first parameter.
	if [[ `cut -d "," -f 4 vaccine.csv| grep -q "$1" != 0` ]]; then
    		echo "State '$1' does not exist!!"
		exit 1
	else
#Find the State's Vaccination Number From Latest_date
	echo $1; grep $latest_date vaccine.csv| grep $1| cut -d ',' -f 7| awk 'NR>1'| awk -F, '{ sum += $1; } END { print sum}'
	exit 0
	fi
fi



#4.Your script should print an error and exit non-zero if it does not find the date 
#specified by the second parameter.
if [[ `cut -d "," -f 1 vaccine.csv| grep -q "$2" != 0` ]]; then
    	echo "This Date does not exist!!"
	exit 1
else 
	echo $1 $2; grep $2 vaccine.csv| grep $1| cut -d "," -f 1| awk 'NR>1'| awk -F, '{ sum += $1; } END { print sum}'
	exit 0
# 5.Your script should exit with zero status, otherwise.
fi

exit 0
