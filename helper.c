
/**************************
Student name : hilla halevi
Student : 208953083
Course Exercise Group : 01
Exercise name : Exercise ex3
***************************
#include <stdio.h>
#include<math.h>
int main()
{
	void Collatz(long int n) {
		int count = 0;
		static int totalCount = 0;
		while (n != 1) {
			printf("%ld", n);
			if (n % 2 == 0) {
				n /= 2;
				printf("->%ld", n);
			}
			else {
				n = (3 * n) + 1;
				printf("->%ld", n);
			}
			count++;
			totalCount++;

		}


	}

	return 0;
}
*/