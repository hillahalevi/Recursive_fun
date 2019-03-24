
/**************************
Student name : hilla halevi
Student : 208953083
Course Exercise Group : 01
Exercise name : ex4.h
***************************/

//function 1
/*******************************************************************************************
* Function Name:Collatz
* Input:long int n
* Output:no return value
* Function Operation:the function demenstrate the collatz sequence by taking a given number
and applys the collatz algorrithem(simple arithmatic functions) until we get the number 1.
the function prints:the whole process,the number of steps it took,and also the total number
of steps the whole program has done so far
********************************************************************************************/
void Collatz(long int n);


//function 3
/**********************************************************************************************************
* Function Name:ProofCollatzUntillt
* Input:long int n
* Output:no return value
* Function Operation:the function prints the reasults of the CollatzNoPrint for the numbers betwin 1-n
if the function finds a number that beyond the range of long int it prints out a wining offer
***********************************************************************************************************/
void ProofCollatzUntill(long int n);

//function 4
/**********************************************************************************************************
* Function Name:Fermat
* Input: int n,int stop
* Output:no return value
* Function Operation:the function demonstrats fermats last rool,by trying to find pythagoras trios .
in a given range and and with a given power.
the trios it finds will be printed and if there are no trios at all it will print "meh:("
***********************************************************************************************************/
void Fermat(int n, int stop);

//function 5
/**********************************************************************************************************
* Function Name:IsDividedBy3Rec
* Input: long int n
* Output:int value (1,0)
* Function Operation:the function gets an integer and checks if it has a clean devision by 3
if it does returns 1,otherwise return 0
***********************************************************************************************************/
int IsDividedBy3Rec(long int n);

//function 6
/**********************************************************************************************************
* Function Name:IsDividedBy3Iter
* Input: long int n
* Output:int value (1,0)
* Function Operation:the function gets an integer and checks if it has a clean devision by 3
if it does returns 1,otherwise return 0
**********************************************************************************************************/
int IsDividedBy3Iter(long int n);

//function 7
/**********************************************************************************************************
* Function Name:FindCommonDigit
* Input: long int n1, long int n2
* Output:int value (-1,9)
* Function Operation:the function tries to find common digit in two given numbers,if it finds more than one
digit it returns the one on the right,if it cant find a common digit it will return -1
***********************************************************************************************************/
int FindCommonDigit(long int n1, long int n2);

//function 8
/**********************************************************************************************************
* Function Name:CountDigit
* Input: long long int n, int d
* Output:int value (0-20)
* Function Operation:the function takes a number and a digit and returns the amount of times the digit is in
the number
***********************************************************************************************************/
int CountDigit(long int n, int d);

//function 9
/**********************************************************************************************************
* Function Name:PrintReverse
* Input: long int n
* Output:no return value
* Function Operation:the function takes a number and prints it in reverse order
***********************************************************************************************************/
void PrintReverse(long int n);
