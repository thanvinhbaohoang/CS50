<h1> Solution For LAB 1</h1>


A: grep -E 'NH' vaccine.csv | grep -E 0[5]{1}/[0-9]{2}/[0-9]{4}

B: awk -F ',' '{print $4","$5","$6}' vaccine.csv| awk 'NR>1'             

C: grep -E 05/1[5-7]{1}/[0-9]{4} vaccine.csv

D: latest_date=$(cut -d "," -f 1 vaccine.csv| awk 'NR>1'| head -1); grep $latest_date vaccine.csv| grep CA | awk -F , '$6 =="0"'| cut -d "," -f 4       

E: latest_date=$(cut -d "," -f 1 vaccine.csv| awk 'NR>1'| head -1); grep $latest_date vaccine.csv | awk -F , '$6 =="0"' | cut -d "," -f 5,6 | sort | uniq -c | sort -nr #Sort numeric-reverse

F: latest_date=$(cut -d "," -f 1 vaccine.csv| awk 'NR>1'| head -1); grep -E $latest_date vaccine.csv| sort -t, -k6,6 -nr| awk -F ',' '{print $4","$5","$6}'| head -10      

G: latest_date=$(cut -d "," -f 1 vaccine.csv| awk 'NR>1'| head -1); echo "|Country|State|Fully-Vaccinated People|"; grep -E $latest_date vaccine.csv| sort -t, -k6,6 -nr| awk -F ',' '{print "|"$4"|"$5"|"$6"|"}'| head -10   

