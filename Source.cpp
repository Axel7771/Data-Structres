//
//
//Brandon Garcia
// 10/24/21
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void sort(char** names, int n)
{
	int i, j;

	// Perform sort operation using bubble sort
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (strcmp(names[j], names[j + 1]) > 0) {
				char* temp;
				temp = (char*)calloc(30, sizeof(char));
				strcpy(temp, names[j]);
				strcpy(names[j], names[j + 1]);
				strcpy(names[j + 1], temp);
			}
}


int main()
{

	FILE* fp;
	char names[x][y];
	int list;
	int i,j;

	fp = fopen("List.txt", "r");
	if(fp == 0) {
		printf("Cannot open file");
	}
	else {

		// allocating memory for 1st dimension
		names = (char**)calloc(n, sizeof(char*));

		for (i = 0; i < n; i++)
		// allocating memory for 2nd dimension
		{
			names[i] = (char*)calloc(30, sizeof(char));
			scanf("%s", names[i]);
		}
			list = sizeof(names)/sizeof(names[0]);
			sort(names, list);
		while (!feof(fp)) {
			fgets(names[list], 30, fp);
			printf(names[list]);
			list++;
		}
	}
	printf("\n\n");
	return 0;

}