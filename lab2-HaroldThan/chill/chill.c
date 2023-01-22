// Usage: ./chill temperature wind
//
// Input: temperature, wind
// Output: Table Of Temperature, Wind Velocity and Wind Chill
//
// Harold Than, CS50, Summer 2021


#include <stdio.h>
#include <math.h>
#include <stdlib.h> 

//Function Headers
double wind_chill (double velocity, double temperature);
int temp_error(double input_temp);
int wind_error(double input_wind);
void print_header();


//Calculate Wind Chill Function
double wind_chill(double temperature, double velocity){
    double chill= 35.74 + 0.6215*temperature - 35.75*pow(velocity,0.16) + 0.4275*temperature*pow(velocity,0.16);
    return chill;
}
// Error-Check User Input For Temperature
int temp_error(double input_temp){
    int temp_error_status=0;
    if (input_temp > 50) {
        temp_error_status++;
        fprintf(stderr, "Temperature must be less than 50 degrees Fahrenheit\n");
        return (temp_error_status);
    }
    if (input_temp < -99) {
        temp_error_status++;
        fprintf(stderr,"Temperature must be more than -99 degrees Fahrenheit\n");
        return (temp_error_status);
    }
    return 0;
}

// Error-Check User Input For Wind
int wind_error(double input_wind){
    int wind_error_status=0;
    if (input_wind < 0.5){
        wind_error_status++;
        fprintf(stderr, "Wind velocity must be greater than or equal to 0.5 MPH\n");
        return wind_error_status;
    }
    return 0;
}


void print_header(){
    printf("------------------------------------------------\n");
    printf(" Temp    Wind    Chill \n");
    printf("-----    ----    ----- \n");
}

int main(int argc, const char * argv[]){

int status=0;
if (argc == 1){ //This means if zero argument was provided. Argument-count start at 1, not 0
    print_header(); 
    for (int temp = -10; temp <= 40; temp +=10){
        for (int wind= 5; wind <= 15; wind +=5){
            printf("%5d    %4d    %5.1f\n", temp, wind, wind_chill(temp, wind));
        }
            // Print Empty Row After Every Temperature Increment
            printf("\n");
    }
    return 0;
}

// Case 2: User Provided 1 Argument: input_temp
if (argc == 2){
    double input_temp= atof(argv[1]); //When referring to user-input argument, first argument start at 1( Unlike argc, which return 2)
    
    //Check If input_temp is in range 
    if (temp_error(input_temp) != 0){
        status++;
        return status;
    }

    //Print Out Table
    print_header();
    for (int wind=5; wind <= 15; wind +=5){
        printf("%5.1f    %4d    %5.1f\n", input_temp, wind, wind_chill(input_temp, wind));
    }
    printf("\n");
}

// Case 3: User Provided 2 Arguments: input_temp and input_wind
if (argc == 3 ){
    double input_temp= atof(argv[1]); 
    double input_wind= atof(argv[2]);
    
    //Error-Check For User Inputs
    if (temp_error(input_temp) != 0){
        status++;
        return status;
    }
    if (wind_error(input_wind) != 0){
        status++;
        return status;
    }

    print_header();
    printf("%5.1f   %5.1f    %5.1f\n", input_temp, input_wind, wind_chill(input_temp, input_wind));
}
    return 0;
}
