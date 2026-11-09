#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

// made looking only at https://github.com/BaseMax/ArrayListC/blob/main/ArrayList.h header file
// for reference

typedef struct {
	size_t size;
	uint32_t capacity;
	int* data;
} ArrayList;

ArrayList* createArray(uint32_t capacity) {
	if (capacity == 0) exit(-1);
	ArrayList* list = (ArrayList*) malloc(sizeof(ArrayList));
	if (&list == NULL) exit(-1);
	list->size = 0;
	list->capacity = capacity;
	list->data = malloc(sizeof(int) * capacity);
	if (list->data == NULL) exit(-1);
	return list;
}

char isArrayFull(ArrayList* list) {
	if (list->size < list->capacity) return 0;
	else {
		printf("The array is full\n");
		return 1;
	}
}

void appendToArray(ArrayList* list, int value) {
	if (isArrayFull(list)) {
		return;
	}
	*(list->data + list->size) = value;
	list->size += 1;
}

int getArrayElement(ArrayList* list, size_t position) {
	if (list->size > 0 && position < list->capacity) {
		return *(list->data + position);
	}
}

void insertInArrayAt(ArrayList* list, size_t position, int value) {
	if (isArrayFull(list)) {
		return;
	}
	if (!(position < list->capacity)) {
		printf("Index for insert is out of range");
		return;
	}
	for (int i = list->size; i > position; i--) {
		list->data[i] = list->data[i-1];
	}
	list->data[position] = value;
	list->size += 1;
}

int main(void) {
	int test = 15;
	ArrayList* list = createArray(3);

	appendToArray(list, test);
	int element = getArrayElement(list, 0);
	printf("%d\n", element);
	appendToArray(list, 800000);
	insertInArrayAt(list, 1, 69);
	printf("%d\n", getArrayElement(list, 1));
	printf("%d\n", getArrayElement(list, 2));
	appendToArray(list, 1);
	free(list->data);
	free(list);
	return 0;
}
