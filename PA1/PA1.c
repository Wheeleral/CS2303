/**
 * @file PA1.c
 * @author Alexandra Wheeler
 * @date 4 Sept 2017
 * @brief  Generates a calender based off a user inputted year (greater than 0). The program will then create the calender for the given year. 
 *
   
*/
#include <stdio.h>


 /**
*@brief prototypes for functions
*/

void printCalendar(int year);
void printMonth(int leap, int monthNumber, int startingDay, int year);
int startingDayCalc(int first, int second);
int leapYear(int year);
void weekHeader(void);
int printWeek(int startingDay, int numberOfDays);


int currday = 0; /**< Day the start of the month is, to be carried over month to month */

/** 
* @brief Main Function that prints the intial statement and obtains the user input
* @note Only works for years after 0 A.D. according to the Gregorian Calender
* @param year Year(A.D.)
*
*/
int main (void) {
  int year = 0;//initializing the variable

  printf("Welcome to the Calender! Input a year greater than 0 and hit enter: "); 
  scanf("%4d", &year);//obtain the input
  
  printCalendar(year);//print the calender

  return 0;
}

/**
* @brief Print Calender takes input of a year and utilizing other functions will print out the correct calender
* @param year Year(A.D.)
* @note Prints the header of the calender and then utilizes print month 12 times to print each month.
* @note the Loop invariant for the for function is through each run one more month(i) will be printed in the terminal from 1-12 months.
*/ 
void printCalendar(int year){

  int startingDayYear = 0;//Starting WeekDay of the Year(Sunday = 0)
  int yearCnt = 0;// Year Century, first two digits of the year
  int yearDec = 0;//Year Decade, last two digits of the year
  int leapyear = 0;// Leap Year, if the year is a leap year leap year =1 , else 0
 
  //determine if the given year is a leap year
  leapyear = leapYear(year);

  yearCnt=year / 100;
  yearDec=year % 100 - ((year % 100) % 1);
  
  //find the starting day
  startingDayYear = startingDayCalc(yearCnt, yearDec);

  printf("   ***   CALENDER for %4d  ***\n" , year);//header for the calender

  for(int i = 0; i < 12; i++){ //run through the months to print each one
    printMonth(leapyear, i, startingDayYear, year);
  }//loop invariant: after each run there will be i months printed

}

/**
* @brief leapYear takes and input of a year and checks to see if that year is a leap year. 
* @param year Year(A.D)
* @return leapyear? (1==leap year, 0= !leap year)
*/
int leapYear(int year){
  //if the year is divisible by 400, not including those divisible by 100 or by 4 it is a leap year
  if((year % 400) == 0)
    return 1;

  else if((year % 100) ==0)
    return 0;

  else if((year % 4) == 0)		
    return 1;

  else
    return 0;

}
/**
* @brief StartingDayCalc inputs the two halves of a year ans utilizes zellers rule to calculate the starting weekday of the year
* <a href="http://mathforum.org/dr.math/faq/faq.calendar.html"> More information on Zellers Rule</a>
* @param first First two digits of the year
* @param second Last two digits of the year
* @note With Zellers rule if it is the turn of the century (ie 1800), the function needs to use the previous year(ie 1799) which is done in the first if statement
* @note The function is also simplified due to the usage of januage first being the month and day.
* @return Day of the Week (Sunday = 0)
*/

int startingDayCalc(int first, int second){
  int f, t;/**< placeholders to hold number for calculations */

  if(second == 0){  //if the year is the turn of the century use the previous year
    second = 100;
    first = first - 1;
  }

  f= (29 + (second - 1) + ((second - 1) / 4)  + (first / 4 ) - (2 * first));//simplified zellers rule

  t=f % 7;// get zellers rule mod, convert it 0-6

  if(t<0){ //incase the mod is negative
    t=t+7;
  }

  return t;//returning the day the month starts on 

}

/**
* @brief PrintMonth will printf the month given in the input
* @param leap LeapYear?(1 = leap year, 0 = not)
* @param monthNumber, number of the month (Januar = 0)
* @param startingDay Starting WeekDay of the Year(Sunday = 0)
* @param year Year(A.D)
* @note Switch statement will output different weeks utilizing printWeek and weekHeader.
*/ 

void printMonth(int leap, int monthNumber, int startingDay,int year){


  switch(monthNumber){//print the specified month
    case 0:
	printf("January  %4d \n", year); //header
        weekHeader(); //header
	currday = printWeek(startingDay, 31); //print the numbers of the weeks
        printf("\n \n");//seperate the months
    break;

    case 1:
        printf("Feburary  %4d \n", year);
        weekHeader(); 
        if(leap==1){ //if the year is a leap year modify if it as 29 or 28 days
	  currday = printWeek(currday, 29);
        } else{
	  currday = printWeek(currday, 28);
        }
	printf("\n \n");
    break;

    case 2:
	printf("March  %4d \n", year); 
        weekHeader();
	currday = printWeek(currday, 31);
        printf("\n \n");
    break;

    case 3:
	printf("April  %4d \n", year); 
        weekHeader();
	currday = printWeek(currday, 30);
        printf("\n \n");
    break;

    case 4:
	printf("May  %4d \n", year); 
        weekHeader();
	currday = printWeek(currday, 31);
        printf("\n \n");
    break;

    case 5:
	printf("June  %4d \n", year); 
        weekHeader();
	currday = printWeek(currday, 30);
        printf("\n \n");
    break;

    case 6:
	printf("July  %4d \n", year); 
        weekHeader();
	currday = printWeek(currday, 31);
        printf("\n \n");
    break;

    case 7:
	printf("August  %4d \n", year); 
        weekHeader();
	currday = printWeek(currday, 31);
        printf("\n \n");
    break;

    case 8:
	printf("September  %4d \n", year); 
        weekHeader();
	currday = printWeek(currday, 31);
        printf("\n \n");
    break;

    case 9:
	printf("October  %4d \n", year); 
        weekHeader();
	currday = printWeek(currday, 31);
        printf("\n \n");
    break;

    case 10:
	printf("November  %4d \n", year); 
        weekHeader();
	currday = printWeek(currday, 31);
        printf("\n \n");
    break;

    case 11:
	printf("December  %4d \n", year); 
        weekHeader();
	currday = printWeek(currday, 31);
        printf("\n \n");
    break;

  }

}

/**
* @brief weekHeader prints the header of the week
*/

void weekHeader(void){
  printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat \n");
}

/**
* @brief printWeek takes the starting day fo the month and the number of says and prints the calender in the correct format
* @param startingDay WeekDay the month starts on
* @param numberOfDays Number of Days the month is
* @return Weekday the month ends on(sunday = 0);
*/
int printWeek(int startingDay, int numberOfDays){
  int i = 0; /**<first for loop, and used in second for loop as a placeholder for the day of the week*/
  int j = 1; /**< second for loop, to run through the number of days in the week*/

  for(i = 0; i < startingDay; i++){ //correct starting place for the first day of the month
    if(i==0){
      printf("   ");
    }
    else{    
	printf("     ");
    }
  } //loop invariant: at end of the loop will output 3 or 5 spaces each iteration. It will never output more than 28 spaces.
 

  for(j = 1; j <= numberOfDays; j++){ //print out the weeks 
    if(i==0){ //print out only one spaces for sunday then the two digit number
      printf("%3d", j);
      i++;
    }
    else if(i<7){ //print out 3 spaces then the two digit number
      printf("%5d", j);
      i++;
    }
    else if(i==7 && j==1){ //reset i value if starting day is sunday, so it doesn't print an extra line space
      j--;
      i = 0;
    } 
    else{//jumps the calender to next week
     printf("\n");
      i = 0;
      j--;
    } 
  } //loop invariant: 0<=i<=7, i will increase by one until it is 6 and then go back down to 0. It can only be seven during the first iteration of the month. 

  if(i==7){ //returns the day of th week the month ends on
    return 0;
  } else{
    return i;
  } 


}




