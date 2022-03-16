#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int *data;
	int size;
	int capacity;
} Intvector;

//1
Intvector *vector_new(size_t capa){
	Intvector *vector;

	vector = malloc(sizeof(Intvector));

	if(vector != NULL) {
		vector->data = malloc(capa * sizeof(int));
		if(vector->data != NULL){
			vector->size = 0;
			vector->capacity = capa;
			return vector;
		} else {
			free(vector);
			return NULL;
		}
	}
	return NULL;
}
//2
Intvector *vector_copy(const Intvector *vector){
	Intvector *cv;

	cv = vector_new(vector->capacity);

	if(cv != NULL) {
		cv->size = vector->size;
		for(int i = 0; i < vector->capacity; i++) cv->data[i] = vector->data[i];
	}
return NULL;
}
//3
void vector_free(Intvector *vector){
	if(vector != NULL){
		if(vector->data != NULL) free(vector->data);
	free(vector);
	}
	else return;
}
//4
void vector_set_item(Intvector *vector, size_t index, int item){
	if(vector != NULL){
		if(vector->data != NULL){
		vector->data[index] = item;
		vector->size++;
		}
		else return;
	}
	else return;
}
//5
int vector_get_item(const Intvector *vector, size_t index){
	if(vector != NULL){
		if(vector->data != NULL) return vector->data[index];
	}
return -1;
}
//6
size_t vector_get_size(const Intvector *vector){
	if(vector != NULL) return vector->size;
}
//7
size_t vector_get_capacity(const Intvector *vector){
	if(vector != NULL) return vector->capacity;
}
//8
int vector_reverse(Intvector *vector, size_t new_capacity){
	if(vector != NULL){
		if(vector->capacity == new_capacity || vector->capacity < new_capacity) return 0;
		else{
		vector->data = realloc(vector->data, new_capacity);
			if(vector->data != NULL) vector->capacity = new_capacity;
		return 0;
		}
	}
	return -1;
}
//09
int vector_shrink_to_fit(Intvector *vector){
	if(vector != NULL){
		if(vector->capacity > vector->size){
		vector->data = realloc(vector->data, vector->size);
			if(vector->data != NULL) vector->capacity = vector->size;
			else return -1;
		return 0;
		}
		else return -1;
	}
	return -1;
}
//10
int vector_push_back(Intvector *vector, int item){
	if(vector != NULL){
		if(vector->data != NULL){
			if(vector->size == vector->capacity){
			vector->data = realloc(vector->data, 2 * vector->capacity);
				if(vector->data != NULL) vector->capacity*=2;
			}
		vector->data[vector->size] = item;
		}
		else return -1;
	return 0;
	}
	return -1;
}
//11
void vector_pop_back(Intvector *vector){
	if(vector != NULL){
		if(vector->data != NULL){
			if(vector->size == 0) return;
		vector->size--;
		}
	}
}
//12
int vector_resize(Intvector *vector, size_t new_size){
	if (vector->size < vector->capacity){
        	if (vector->size < new_size){
            	for (int i = vector->size + 1; i < new_size; i++) vector->data[i] = 0;
        	}
        else if (vector->size == new_size) return 0;
        vector->size = new_size;
        return 0;
	}
    	else return -1;

}
