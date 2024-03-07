/* 
	Noah Gerard
	COP 3502 Section 003
	Lab 7
	3/7/2004
*/

#include <stdio.h>

typedef struct {
	int val;
	int swaps;
} Element;

int bubbleSort(Element array[9]);
int selectionSort(Element array[9]);
void resetArrays(Element array1[9], Element array2[9]);
void printArray(Element array[9]);
void swap(Element *e1, Element *e2);

int main() {
	Element array1[9];
	Element array2[9];

	int swaps = 0;

	// Init arrays
	resetArrays(array1, array2);

	// Bubble sort array1
	printf("Array1 Bubble Sort:\n");
	swaps = bubbleSort(array1);
	printArray(array1);
	printf("%d\n", swaps);

	// Bubble sort array2
	printf("\nArray2 Bubble Sort:\n");
	swaps = bubbleSort(array2);	
	printArray(array2);
	printf("%d\n", swaps);

	// Reset array values
	resetArrays(array1, array2);

	// Selection sort array1
	printf("\nArray1 Selection Sort:\n");
	swaps = selectionSort(array1);
	printArray(array1);
	printf("%d\n", swaps);

	// Selection sort array2
	printf("\nArray2 Selection Sort:\n");
	swaps = selectionSort(array2);	
	printArray(array2);
	printf("%d\n", swaps);

	return 0;
}

// Function to swap elements
void swap(Element *e1, Element *e2) {
	Element temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}

// Function to print element array
void printArray(Element array[9]) {
	for (int i = 0; i < 9; i++)
		printf("%d: %d\n", array[i].val, array[i].swaps);
}

// Function to reset arrays
void resetArrays(Element array1[9], Element array2[9]) {
	// Reset swaps for each array's elements
	for (int i = 0; i < 9; i++) {
		array1[i].swaps = 0;
		array2[i].swaps = 0;
	}

	array1[0].val = 97;
	array1[1].val = 16;
	array1[2].val = 45;
	array1[3].val = 63;
	array1[4].val = 13;
	array1[5].val = 22;
	array1[6].val = 7;
	array1[7].val = 58;
	array1[8].val = 72;

	array2[0].val = 90;
	array2[1].val = 80;
	array2[2].val = 70;
	array2[3].val = 60;
	array2[4].val = 50;
	array2[5].val = 40;
	array2[6].val = 30;
	array2[7].val = 20;
	array2[8].val = 10;
}

// Function to bubble sort an array
int bubbleSort(Element array[9]) {
	int total = 0;					// Total swaps
	for (int i = 0; i < 9; i++) {
		for (int n = 0; n < 8 - i; n++) {
			// If current element is greater than next
			if (array[n].val > array[n + 1].val) {
				// Swap current and next element
				Element temp = array[n];
				array[n] = array[n + 1];
				array[n + 1] = temp;

				// Increment swaps
				array[n].swaps++;
				array[n + 1].swaps++;
				total++;
			}
		}
	}

	return total;
}

// Function to selection sort an array
int selectionSort(Element array[9]) {
    int total = 0;					// Total swaps
    int index = 0;					// Index of smallest

    for (int i = 0; i < 8; i++) {
        // Find smallest elem in array
        index = i;

        for (int j = i+1; j < 9; j++) 
            if (array[j].val < array[index].val) 
                index = j; 
  
        // Swap the found minimum element with the first element 
        if(index != i) {
            swap(&array[index], &array[i]);
            total++;
            array[index].swaps++;
            array[i].swaps++;
        }
    }

    return total;
}