README FILE

PA1.c

Alexandra Wheeler
09/05/2017

README FILE


CONTENTS
I.	DESCRIPTION
II.	HOW TO RUN EXAMPLE
III.	LOOP INVARIANTS


I. Description
  This program is designed to take a user input and print out a calender for the given input. The calender is based of the Gregorian calender put in place in 1582. So for years prior to acceptance of the Gregorian calender, those calenders will be as if the Gregorian calender was put in place. The calender only works for year 1A.D. and above. The user input must also be a a integer up to four digits. The calender will give the correct start day of the week and accurately be able to accommodate leap years in printing the calender. 
  During the coding process the issues with the assignment were due to the calculation of the starting date. With utilizing zellers rule(http://mathforum.org/dr.math/faq/faq.calendar.html)  the dates cannot exceed 9999, also since we are using January as the start date for the program, it needs to use the previous years digits in the formula. For years such as 1800 and such where it is the turn of the century, the number needed to be 1799, which then needed a special case to subtract the number. 
  This program also can't detect an invalid input. It takes four digits, so if a number greater than 9999 is inputed then it only counts the first four digits. 

II. How to Run and the Example
  In the Terminal cd to where the PA1.c is. Then type: 
          gcc -Wall -o PA1 PA1.c
  Then run ./a.out
  This will then give the output:
          "Welcome to the Calender! Input a year greater than 0A.D. and hit enter:"
  If it doesn't give an output the run gcc -Wall PA1.c and rerun ./a.out
  
  Afterwards just type a number such as "2015" and hit enter.
  This will create an output such as:

   ***   CALENDER for 2015  ***
January  2015 
Sun  Mon  Tue  Wed  Thu  Fri  Sat 
                      1    2    3
  4    5    6    7    8    9   10
 11   12   13   14   15   16   17
 18   19   20   21   22   23   24
 25   26   27   28   29   30   31
 
Feburary  2015 
Sun  Mon  Tue  Wed  Thu  Fri  Sat 
  1    2    3    4    5    6    7
  8    9   10   11   12   13   14
 15   16   17   18   19   20   21
 22   23   24   25   26   27   28
 
March  2015 
Sun  Mon  Tue  Wed  Thu  Fri  Sat 
  1    2    3    4    5    6    7
  8    9   10   11   12   13   14
 15   16   17   18   19   20   21
 22   23   24   25   26   27   28
 29   30   31
 
April  2015 
Sun  Mon  Tue  Wed  Thu  Fri  Sat 
                 1    2    3    4
  5    6    7    8    9   10   11
 12   13   14   15   16   17   18
 19   20   21   22   23   24   25
 26   27   28   29   30
 
May  2015 
Sun  Mon  Tue  Wed  Thu  Fri  Sat 
                           1    2
  3    4    5    6    7    8    9
 10   11   12   13   14   15   16
 17   18   19   20   21   22   23
 24   25   26   27   28   29   30
 31
 
June  2015 
Sun  Mon  Tue  Wed  Thu  Fri  Sat 
       1    2    3    4    5    6
  7    8    9   10   11   12   13
 14   15   16   17   18   19   20
 21   22   23   24   25   26   27
 28   29   30
 
July  2015 
Sun  Mon  Tue  Wed  Thu  Fri  Sat 
                 1    2    3    4
  5    6    7    8    9   10   11
 12   13   14   15   16   17   18
 19   20   21   22   23   24   25
 26   27   28   29   30   31
 
August  2015 
Sun  Mon  Tue  Wed  Thu  Fri  Sat 
                                1
  2    3    4    5    6    7    8
  9   10   11   12   13   14   15
 16   17   18   19   20   21   22
 23   24   25   26   27   28   29
 30   31
 
September  2015 
Sun  Mon  Tue  Wed  Thu  Fri  Sat 
            1    2    3    4    5
  6    7    8    9   10   11   12
 13   14   15   16   17   18   19
 20   21   22   23   24   25   26
 27   28   29   30   31
 
October  2015 
Sun  Mon  Tue  Wed  Thu  Fri  Sat 
                           1    2
  3    4    5    6    7    8    9
 10   11   12   13   14   15   16
 17   18   19   20   21   22   23
 24   25   26   27   28   29   30
 31
 
November  2015 
Sun  Mon  Tue  Wed  Thu  Fri  Sat 
       1    2    3    4    5    6
  7    8    9   10   11   12   13
 14   15   16   17   18   19   20
 21   22   23   24   25   26   27
 28   29   30   31
 
December  2015 
Sun  Mon  Tue  Wed  Thu  Fri  Sat 
                      1    2    3
  4    5    6    7    8    9   10
 11   12   13   14   15   16   17
 18   19   20   21   22   23   24
 25   26   27   28   29   30   31
 


III. Loop Invariants

  There are three loop invariants in the program. The first one is in the function printCalender( int year). In this case the loop invariant for the for loop is at the end of the for loop another month(i+1) will be printed in the terminal. There will be 1-12 months printed in total.
  The other two loop invariants are in the function printWeek(int startingDay, int numberOfDays). The first for loop has the function of padding spaces onto were the first day of the month is to be. In example it will put 8 spaces if the month is to start on a tuesday. The loop invariant for this is that either 3 or 5 spaces (n+3|n+5) will be added after each run of the loop. If the for loop doesn't run 0 spaces will be added. The second for loop has the loop invariant of 0<=i<=7, i will increase by one until it is 6 and then go back down to 0. It can only be seven during the first iteration of the month. 



 

