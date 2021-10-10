/*
 ============================================================================
 Name        : Matrix.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	// Variable Declarations
//	FILE *ptr_myfile; // For testing
	FILE *ptr_aBin;
	FILE *ptr_bBin;
	FILE *ptr_cBin;
//	long long counter = 0, x = 0; // For testing
	long long a = 0, b = 0, c = 0;  // 32 bit signed
	long long **arrayA = NULL, **arrayB = NULL, **arrayC = NULL;

	int width = 0; // Will store width or matrix


	//Read in command line argument
	if( argc == 2 ) { // Check in command line argument is given
		if (sscanf (argv[1], "%i", &width) != 1) {  // Check if what was input was an integer and print error of not an integer
			fprintf(stderr, "error - not an integer");
			return 2;
		}
	} else {  // Print error of no input
		printf("Error!   Please enter the matrix width as an argument.\n<program-name> <matrix-width>\n");
		return 3;
	}

	arrayA = malloc(width * sizeof(long long *));
	arrayB = malloc(width * sizeof(long long *));
	arrayC = malloc(width * sizeof(long long *));
	if(arrayA == NULL || arrayB == NULL || arrayC == NULL){
		fprintf(stderr, "out of memory\n");
		return 4;
	}


	// open binary files
	ptr_aBin=fopen("a.bin","rb");  //open file to read in binary
	if (!ptr_aBin) {  // Print error opening file
		printf("Unable to open a.bin!");
		return 1;
	}
	ptr_bBin=fopen("b.bin","rb");  //open file to read in binary
	if (!ptr_bBin) {  // Print error opening file
		printf("Unable to open b.bin!");
		return 1;
	}
	ptr_cBin=fopen("c.bin","wb");  //open file to read in binary
	if (!ptr_cBin) {  // Print error opening file
		printf("Unable to open c.bin!");
		return 1;
	}


	for ( int i = 0; i < width; i++) {  //
		//for (int j = 1; j <= width; j++) {
		//fread(&a, sizeof(a), 1, ptr_aBin);
		//fread(&b, sizeof(b), 1, ptr_bBin);
		//}
		arrayA[i] = malloc(width * sizeof(a));
		arrayB[i] = malloc(width * sizeof(b));
		arrayC[i] = malloc(width * sizeof(b));
	}

	for ( int i = 0; i < width; i++) {  //
		for (int j = 0; j < width; j++) {
			fread(&a, sizeof(a), 1, ptr_aBin);
			fread(&b, sizeof(b), 1, ptr_bBin);
			arrayA[i][j] = a;
			arrayB[i][j] = b;
			arrayC[i][j] = 0;
			//printf("%I64d ",arrayA[i][j]); // **Test** verify that array is being built correctly
		}
		//		printf("\n");
	}


	for(int i = 0; i < width; i++) {
		for(int j = 0; j < width; j++) {
			c = 0;
			for(int k = 0; k < width; k++) {
				c = c + (arrayA[i][k] * arrayB[k][j]);
			}
			fwrite(&c, sizeof(c), 1, ptr_cBin);
			arrayC[i][j] = c;
//			printf("%I64d  ", c);  // For testing

		}
//		printf("\n");  // For testing
	}





	//	for(int i = 0; i < width; i++) {
	//		for(int j = 0; j < width; j++) {
	//			printf("%I64d ", arrayC[i][j]); // **Test** verify that array is being built correctly
	//		}
	//		printf("\n");
	//	}

//	printf("-----------\n\n\n");  // For testing


	fclose(ptr_aBin);
	fclose(ptr_bBin);
	fclose(ptr_cBin);

//	ptr_myfile=fopen("c.bin","rb");  //open file to read in binary  // For testing
//	if (!ptr_myfile) {  // Print error opening file  // For testing
//		printf("Unable to open file!");  // For testing
//		return 1;  // For testing
//	}  // For testing
//	for ( counter=1; counter <= width; counter++) {  //  **TEST** Read in the bytes we just wrote and print double the value  // For testing
//		for (int i = 0; i < width; i ++) {  // For testing
//			fread(&x, sizeof(x), 1, ptr_myfile);  // For testing
//			printf("%I64d  ",(x));
//		}  // For testing
//		printf("\n");  // For testing
//	}  // For testing
//	fclose(ptr_myfile);  // For testing


	return 0;
}
