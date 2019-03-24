#define MAX (0xffffffff)
//MAX :the highest value long int can contain
#include "ex4.h"
#include <stdio.h>
#include <math.h>
/**************************
Student name : hilla halevi
Student : 208953083
Course Exercise Group : 01
Exercise name : ex4.c
***************************/
//function 1
/****************************************************************************************
* Function Name:Collatz
* Input:long int n
* Output:no return value
* Function Operation:the function demenstrate the collatz conjecture  by taking a given number
and applys the collatz algorrithem(simple arithmatic functions) until we get the number 1.
the function prints:the whole process,the number of steps it took,and also the total number
 of steps the whole program has done so far
******************************************************************************************/
void Collatz(long int n)
{
	long int count = 0;
	/*creating a static variable to keep all the steps the  main program did so far;
	the function is called several times and each time the data is initialzied*/
	static long int totalCount = 0;
	//printing the starting point
	printf("%ld", n);
	/*
	this while loop will execute the collatz algorithem until we get 1
	start with given positive integer n. Then each term is obtained from the previous term as follows:
	if the previous term is even, the next term is half the previous term.
	Otherwise, the next term is 3 times the previous term plus 1
	this loops until we get the number 1.
	also,we save the numbr of steps it took by updating the counter by one after each time
	the total number of steps is monitored by a static varible called totalCount.
	*/
	//when n==1 the algorithem was finished seccesfully and showed that the conjucture is right
	while (n > 1)
	{
			//if the number is even
			if (n % 2 == 0)
			{ 
				n /= 2; 
				//printing the current n
				printf("->%ld", n); 
			} 
			//otherwise
			else 
			{
				n = (3 * n) + 1;
				//printing the current n
				printf("->%ld", n);
			}
			//updating the amount of steps the process took
			count++;
			//updeating the total amount of steps the program ever did
			totalCount++;
	}
	//printing the total amount of steps this number took
	printf("\nnum of steps: %ld \n", count);
	//printing the total number of steps this progeram has done so far
	printf("total num of steps: %ld \n", totalCount);	
}


//function 2
/**********************************************************************************************************
* Function Name:CollatzNoPrint
* Input:long int n
* Output:int (value betwin 0-MAX)
* Function Operation:the function checks if the number of steps the number needs to apply(from collatz algorithem)
is valid:count<MAX,if its valid it returns the number of steps otherwise returns 0
***********************************************************************************************************/
unsigned long int CollatzNoPrint(long int n)
{
	/*this while loop will execute the collatz algorithem until we get 1
	start with given positive integer n.Then each term is obtained from the previous term as follows :
	if the previous term is even, the next term is 0.5the previous term.
	Otherwise, the next term is 3 times the previous term plus 1
	this loops until we get the number 1  the loop also counts the amount of steps it needed .*/
	long int count = 0;
	while (n != 1) 
	{
		//if the number is even
		if (n % 2 == 0) 
		{
			n /= 2;
		}
		//otherwise
		else 
		{
			n = (3 * n) + 1;
		}
		//adding 1 to the steps counter
		count++;
	}
	//checks if the count is in the right range
	//4294967295-(0xffffffff) is the largers number long int can contain
	if (count<MAX)
	{
		return count;
	}
	//if not returns 0
	else
	{
		return 0;
	}
}

//function 3
/**********************************************************************************************************
* Function Name:ProofCollatzUntillt
* Input:long int n
* Output:no return value
* Function Operation:the function prints the reasults of the CollatzNoPrint for the numbers betwin 1-n
if the function finds a number that beyond the range of long int it prints out a wining offer
***********************************************************************************************************/
void ProofCollatzUntill(long int n)
{
	long int div = 0;
	// eliminats a specific case were n=1 
	if (n == 1) { printf("passed: %d (num of steps: 0)\n", n); }
	//in this function we only deal with numbers equal to 1 or higher
	if (n>1)
	{
		/*for loop that runs on all the numbers from 1 - n and for each and evey one calls for the "collazNoPrint"
		and prints their reasults.
		in case the the function finds a number that beyond the range of long int it prints out a wining offer .*/
		for (div = 1; div < n; div++)
		{
			//checks if the number valid
			if (CollatzNoPrint(div) == 0 && div != 1)
			{
				//if CollazNoPrint returns 0 it means the number is out of range
				printf("you might wanna check %d and win 500$ :)\n", div);

			}
			else
			{
				// prints div and the number of steps it requaiers
				printf("passed: %ld (num of steps: %ld)\n", div, CollatzNoPrint(div));
			}

		}
	}
	

}

//function 4
/**********************************************************************************************************
* Function Name:Fermat
* Input: int n,int stop
* Output:no return value
* Function Operation:the function demonstrats fermats last rool,by trying to find pythagoras trios .
 in a given range and with a given power.
 the trios it finds will be printed and if there are no trios to be found it will print "meh:("
***********************************************************************************************************/
void Fermat(int n, int stop)
{
	int a =0;
	int b =0;
	int c =0;
	int sum = 0;
	int total = 0;
	int noTrios = 1;
	//looping on the first parmeter
	for (a = 1 ; a < stop; a++) 
	{
		//looping on the second parmeter
		for (b =1; b < stop; b++)
		{
			//one side of the equation
			sum = pow(a, n) + pow(b, n);
			//in case the power is 2 i can use a sqrt function to increase efficancy
			if (n==2)
			{
			//insted of checking each number for the c paramter i calculate the squre root of the sum of a^+b^2
			c = sqrt(sum);
			//if we get a whole number that solves the equation we print it (only when b>a to avoid duplicate reasults)
			if (b>a && c%1==0 && c<stop &&pow(c,2)==sum )
			{
				printf("Eureka! %d^%d + %d^%d = %d^%d \n", a, n, b, n, c, n);
				noTrios = 0;
			}
			
			}
			//all other cases
			else
			{   //looping on the third parmeter
				for (c = b + 1; c < stop; c++)
				{
					//the other side of the equation
					int total = pow(c, n);
					//cheacks if the sides are equae(only when b>a to avoid duplicate reasults)
					if (b == 1 && a == 1 && sum == total)
					{	//
						printf("Eureka! %d^%d + %d^%d = %d^%d \n", a, n, b, n, c, n);
						noTrios = 0;
					}
					if (b > a && sum == total)
					{
						printf("Eureka! %d^%d + %d^%d = %d^%d \n", a, n, b, n, c, n);
						noTrios = 0;
					}

				}

			}
			
			
		}
	}
	
	if (noTrios == 1) printf("meh :( \n");
} 

//help function 5
/**********************************************************************************************************
* Function Name: Modulo3
* Input: int num,int sum
* Output:int value (0,1,2)
* Function Operation:the function works recursevly,getting a number and a sum ,each time finding one digit
and calculating the sum and the digit in module 3 - the function stops when there are no more digits to add
***********************************************************************************************************/
int Modulo3(long int num,int sum) 
{
	int digit = 0;
	//stoping conditon
	if (num==0)
	{	//returns the total sum of the digits module 3
		return sum;
	}
	//finding the last digit from right of the current num
	digit = num % 10;
	switch (digit)
		//here i am doing the action of modulo3 and updating the sum  
	{	case(1)://if the digit =1
		if (sum==0)
		{//(1+0)%3=1
			sum = 1;
			break;
		}
		if (sum == 1)
		{//(1+1)%3=2
			sum = 2;
			break;
		}
		if (sum == 2)
		{//(1+2)%3=0
			sum = 0;
			break;
		}
		
	case(2)://if the digit =2
		if (sum == 0)
		{//(2+0)%3=2
			sum = 2;
			break;
		}
		if (sum == 1)
		{//(2+1)%3=0
			sum = 0;
			break;
		}
		if (sum == 2)
		{//(2+2)%3=1
			sum = 1;
			break;
		}
	default://if the digit =3
		if (sum == 0)
		{//(3+0)%3=3
			sum = 0;
			break;
		}
		if (sum == 1)
		{//(3+1)%3=1
			sum = 1;
			break;
		}
		if (sum == 2)
		{//(3+2)%3=2
			sum = 2;
			break;
		}
		break;
	}
	//repeating the function untill all the digits sum up 
	Modulo3(num / 10, sum);
	
}
//function 5
/**********************************************************************************************************
* Function Name:IsDividedBy3Rec
* Input: long int n
* Output:int value (1,0)
* Function Operation:the function gets an integer and checks if it has a clean devision by 3
if it does returns 1,otherwise return 0
***********************************************************************************************************/
int IsDividedBy3Rec(long int n)
{
	int total = 0;
	//sending it to external help function that calculates the total sum of all the digits %3 
	total=Modulo3(n, 0);
	////to check if a number is devisable by 3 you can check if the sum of its digit is devisable by 3
	//if total%3 = 0 then the number has a clean devision by 3
	if (total==0)
		{
			return 1;
		}
	//else - the number is not devisable by 3
	else
		{
			return 0;
		}
	
	
}

//function 6
/**********************************************************************************************************
* Function Name:IsDividedBy3Iter
* Input: long int n
* Output:int value (1,0)
* Function Operation:the function gets an integer and checks if it has a clean devision by 3
if it does returns 1,otherwise return 0
***********************************************************************************************************/
int IsDividedBy3Iter(long int n) 
{
	int digit = 0;
	//initialzing the sum to 11 (higher than 10) so it will enter the first time to the loop
	int sum = 11;
	if (n<10)
	{
		//in case n <10 it has only one digit so it doesent need the adding algorithem
		sum = n;
	}
	//we want to use this adding algorithem until we get one digited sum (<10)
	while (sum > 10) 
	{
		//initialzing the sum back to zero
		sum = 0;	
		//when n clean devision by 10 is 0 ,the number is over, no more digits to go over
		while (n > 0)
		{	//finds the right digit in this current n
			digit = n % 10;
			//add it to the sum of the number's digits
			sum = sum + digit;
			//devide n by 10 to go over to the next digit
			n = n / 10;
		}
		//changing n to equel to the sum of its digits
		n = sum;
	
	}

	//to check if a number is devisable by 3 you can check if the sum of its digit is devisable by 3
	if (sum == 3 || sum == 6 || sum == 9 )
	{
		//than the number  is devisable by three (3,6,9 are devisable by 3)
		return 1;
	}
	else
	{	//the number is not devisable
		return 0;
	}


}


//help function 7
/**********************************************************************************************************
* Function Name:DigitN2
* Input: int digit1, long int n2
* Output:int value (-1,9)
* Function Operation:the function gets an integer and a digit and searches if the digit acuure in the number
if the digit is found it returns the digit if not it returns -1
***********************************************************************************************************/
int DigitN2(int digit1, long int n2)
{
	int digit2 = 0;
	//until n2 clean devision by 10 is zero-the number is over,no more digits to go over
	if (n2>0)
	{	//getting the right digit of the current n2
		digit2 = n2 % 10;
		if (digit1>digit2)
		{
		//if the digit we got is bigger than the right digit of n2 than this digit wont have a much in n2(increasing order )
			return -1;
		}
		else
		{
			//checks if the digit equel to the right digit of the integer
			if (digit1 == n2 % 10)
			{	//if found the function returns the digit
				return digit1;
			}
			else
			{	//repeat the function on n2/10,moving to the next digit in the integer
				DigitN2(digit1, n2 / 10);
			}
		}
		
	}
	else
	{	//if the digit wasnt found return -1
		return -1;
	}
}
//function 7
/**********************************************************************************************************
* Function Name:FindCommonDigit
* Input: long int n1, long int n2
* Output:int value (-1,9)
* Function Operation:the function tries to find common digit in two given numbers,if it finds more than one
digit it returns the one on the right,if it cant find a common digit it will return -1
***********************************************************************************************************/
int FindCommonDigit(long int n1, long int n2) 
{
	//until n1 clean devision by 10 is zero-the number is over,no more digits to go over
	if (n1>0)
	{
		int digit1 = 0;
		//digit1 equels to the most right digit in the current n1
		digit1 = n1 % 10;
		//if digit1 was found in n2
		if (DigitN2(digit1, n2) == digit1)
		{	//the function returns digit1
			return digit1;
		}
		else
		{	//the function repeat itself n1/10,moving to the next digit in n1
			FindCommonDigit(n1 / 10, n2);
		}
	}
	else
	{//if the number is over with no common digit found-return -1
		return -1;
	}
	

	}

///help function 8
/**********************************************************************************************************
* Function Name:Counter
* Input: long long int n, int d
* Output:int value (0-20)
* Function Operation:the function takes a number and a digit and calculate how many times the digit apears 
in an number
***********************************************************************************************************/
int Counter(long int n, int d)
{
	//until the number is over,its devision in 10=0
	if (n > 0)
	{	//checks if the right digit == d
		if (n % 10 == d)
		{	//returns 1+the reasult of going threw again the function-now on the next digit 
			return 1 + Counter(n / 10, d);
		}
		else
		{	//moviong on to the next digit
			return Counter(n / 10, d);
		}
	}
	else
	{
		//the number is over return 0
		return 0;
	}
}
//function 8
/**********************************************************************************************************
* Function Name:CountDigit
* Input: long long int n, int d
* Output:int value (0-20)
* Function Operation:the function takes a number and a digit and returns the amount of times the digit is in
the number
***********************************************************************************************************/
int CountDigit(long int n, int d)
{
	long int number = n;
	int digit = d;
	int sum = 0;
	//sending the factors to an external function that calculate the number of times a digit acuure o=in the number
	sum = Counter(number, digit);
	return sum;
}

//function 9
/**********************************************************************************************************
* Function Name:PrintReverse
* Input: long int n
* Output:no return value
* Function Operation:the function takes a number and prints it in reverse order
**********************************************************************************************************/
void PrintReverse(long int n)
{
	 int leftover = 0;
	 //when n/10=0 = base of the recursive function=the reversing operation is finished
	 if (n>0)
	 {
			//printing the most right digit in the number by calculating the remaining number after dividing by 10 
			leftover = n % 10;
			//printing the number digit by digit
			printf("%d", leftover);
			//dividing the number by 10 to continue to the next digit from lef
			PrintReverse(n / 10);
		}
	 //after printing the reversed number printing a "\n" to start a new line
	 else 
	 {
			printf("\n");
			}
}