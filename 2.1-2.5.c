#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <string.h>

void ex01() {	//Execrise 2.1
	printf("unsigned char: %d\nsigned char max: %d\t signed char min: %d\n", UCHAR_MAX, SCHAR_MAX, SCHAR_MIN);
	printf("unsigned short: %d\nsigned short max: %d\t signed short min: %d\n", USHRT_MAX, SHRT_MAX, SHRT_MIN);
	printf("unsigned int: %d\nsigned int max: %d\t signed int min: %d\n", UINT_MAX, INT_MAX, INT_MIN);
	printf("unsigned long: %d\nsigned long max: %d\t signed long min: %d\n", ULONG_MAX, LONG_MAX, LONG_MIN);
	printf("floating-point max: %d\t floating-point min: %d \n", FLT_MAX, FLT_MIN);
}

void ex02() {	//Exercise 2.2
	int i, c;
	int lim = 10;
	int s[10];

	for (i = 0; i < lim - 1; ++i) {
		while ((c = getchar()) != '\n') {
			while ((c = getchar()) != EOF) {
				s[i] = c;
			}
		}
	}
}

int get_int_value(char c) {
	if (isalpha(c)) {
		return toupper(c) - 'A' + 10;
	}
	return c -'0';
}

int htoi(char *s) {	//Exercise 2.3
	int length = strlen(s)-1;
	int exponent = 1;
	int decimal = 0;
	int i;

	for (i = length; i >= 0; --i) {
		decimal = decimal + get_int_value(s[i]) * exponent;
		exponent = exponent* 16;
	}
	printf("%d", decimal);
	return decimal;
}

void squeeze(char s1[],char s2[]) {	//Exercise 2.4
	int i, j, k;
	for (i = j = 0; s1[i] != '\0'; ++i) {
		for(k=0; s2[k] != '\0';k++){
			if (s1[i] != s2[k]) {
				s1[j++] = s1[i];
			}
		}
	}
	s1[j] = '\0';
}

int any(char s1[],char s2[]) {	//Exercise 2.5
	int found = 0;
	int i, j;
	for (i = 0; s1[i] != '\0'; ++i) {
		for (j = 0; s2[j] != '\0'; ++j) {
			if (s1[i] == s2[j]) {
				found = i;
				return found;
			}
		}
	}
	found = -1;
	return found;
}

void test_exercises(char s1[], char s2[], char * hex) {
	ex01();
	ex02();
	htoi(hex);
	squeeze(s1, s2);
	any(s1, s2);
}

void array_fill(char s[], int size) {
	printf("fill the array");
	int i;
	for (i = 0; i < (size - 1); ++i) {
		s[i] = getchar();
	}
	s[size] = '\0';
}

int main() {
	char* hexa = "ABC";
	char arr1[10];
	char arr2[10];
	array_fill(arr1, 10);
	array_fill(arr2, 10);
	test_exercises(arr1, arr2, hexa);
	return 0;
}
