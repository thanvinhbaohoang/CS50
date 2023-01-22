#
# Usage: ./regress.sh dirname testfilename...
#
#

#The script verifies the validity of its arguments (exit with non-zero status on any error):
status=0;

if (( "$#" < "2" )); then
    echo "Error: There Must Be At Least 2 Arguments"
    exit 1;
fi

#if something by the name dirname exists, it must be a directory
if [ ! -d $1 ]; then
    echo "Directory $1 Does Not Exist"
    exit 1;
fi

dirname=$1;
shift;
#each testfilename must be a regular file and be readable.
for file
do
    if [[ ! -r $file ]]; then
        echo "$file Must Be A File And Be Readable";
        exit 1;
    fi
done

#After checking its arguments, the script creates new directory whose name has the form YYYYMMDD.HHMMSS, 
current_time=$(date +%Y%m%d.%H%M%S);  #representing the current date and time (For example, 20200705.000016.) 
new_folder_name=$current_time;

mkdir $new_folder_name
#If any error, exit with non-zero status.
if [ $? -ne 0 ] ; then
    echo Can Not Make New Directory With Current Time
    exit 1;
fi

#The script then runs each test case with bash, redirecting stdin from /dev/null, producing three files for each case:
for file
do
    #YYYYMMDD.HHMMSS/testfilename.test - a copy of testfilename
    touch $new_folder_name/$file.test
    cat $file > $new_folder_name/$file.test

    #YYYYMMDD.HHMMSS/testfilename.status - the exit status of bash testfilename
    touch $new_folder_name/$file.status
    echo $? > $new_folder_name/$file.status

    #YYYYMMDD.HHMMSS/testfilename.output - the stdout and stderr from bash testfilename
    touch $new_folder_name/$file.output
    ./$file &> $new_folder_name/$file.output
done

#If the directory dirname does not exist, YYYYMMDD.HHMMSS is renamed dirname. 
if [ ! -d $dirname ]; then
    $new_folder_name= $dirname
    #Exit 0 if success, non-zero if any error.
    if [ ! $? -eq 0 ]; then
        echo Error: Cannot Make "$new_folder_name= $dirname"
        exit 1;
    else    
        exit 0;
    fi   
#If the directory dirname already exists, YYYYMMDD.HHMMSS is compared with dirname to provide a brief listing of any differences 
#- or the simple statement “no differences”. Exit 0 if no differences, non-zero if differences.
    elif [ -d $dirname ]; then
        differences=$(diff --brief -r $new_folder_name/ $dirname/)
fi

if (( $differences > "0" )); then
    exit 1;
else 
    echo No Differences;
    exit 0;
fi