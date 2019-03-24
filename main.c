#include "ex4.h"
#include <stdio.h>

int main() {
	Collatz(7);
	Collatz(1);
	Collatz(130);
	ProofCollatzUntill(1);
	ProofCollatzUntill(7);
	//ProofCollatzUntill(543216);
	Fermat(1,20);
	Fermat(3, 1000);
	printf("%d\n", IsDividedBy3Rec(2));
	printf("%d\n", IsDividedBy3Rec(123232323232));
	printf("%d\n", IsDividedBy3Iter(100));
	printf("%d\n", IsDividedBy3Iter(6));
	printf("%d\n", FindCommonDigit(111999, 2224488));
	printf("%d\n", FindCommonDigit(111355577, 222344668));
	printf("%d\n", FindCommonDigit(111222333444555, 111222333444555));
	printf("%d\n", CountDigit(125827620123, 2));
	printf("%d\n", CountDigit(123432123432, 7));
	PrintReverse(123456789);
	PrintReverse(1002);
	return 0;
}
