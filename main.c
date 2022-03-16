#include <stdio.h>
#include <stdlib.h>
#include "test.h"

int main(void){
	Intvector *vector;
	Intvector *cv;
	int item;
	size_t size;
	size_t capacity;

	vector = vector_new(10);
	for(int i = 0; i < vector->capacity - 5; i++) vector_set_item(vector, i, i);
	cv = vector_copy(vector);
	item = vector_get_item(vector, 2);
	//printf("%d\n", item);
	size = vector_get_size(vector);
	capacity = vector_get_capacity(vector);
	vector_reverse(vector, 15);
	vector_push_back(vector, 6);
	vector_shrink_to_fit(vector);
	vector_pop_back(vector);
	vector_resize(vector, 20);
	vector_free(vector);
return 0;
}
