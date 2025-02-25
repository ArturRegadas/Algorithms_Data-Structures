#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node* neighbor;

}node;

int ListSize = 0 ;


node* create(int data){
	node * TemporaryList=malloc(sizeof(node));
	TemporaryList -> value = data;
	TemporaryList -> neighbor = NULL;
	ListSize+=1;
	return TemporaryList;
}

void add(int data, node* current){
	while(current -> neighbor != NULL){
		current = current -> neighbor;
	}
	current -> neighbor = create(data);
}

void WriteLine(node * PrintedLine){
	while(PrintedLine -> neighbor != NULL){
		printf("%d\n", PrintedLine -> value);
		PrintedLine = PrintedLine -> neighbor;
	}
	printf("%d\n", PrintedLine -> value);
}

int Index(int index ,node* IndexList){
	for(int i=0; i<index; i++){
		IndexList=IndexList -> neighbor;
	}
	return IndexList -> value;
}

void Insert(int index, int data, node** IndexList){
	if (index > ListSize-1 | index < 0){
		printf("Error\n");
	
	}
	else if(index == 0){
		node* TemporaryList = create(data);
		TemporaryList->neighbor = *IndexList;
        *IndexList = TemporaryList;
	}
	else{
		node * current = *IndexList;
		for(int i=0; i<index-1; i++){
			current = current ->neighbor;
		}
		node* TemporaryList = create(data);
		TemporaryList -> neighbor = current -> neighbor;
		current -> neighbor = TemporaryList;
		*IndexList = current;
	}

}


void DelIndex(int index, node* IndexList){
	if (index > ListSize-1 | index < 0){
		printf("Error\n");
	
	}
	else if(index == 0){
		*IndexList =*IndexList -> neighbor;
	}
	else{
		for(int i=0; i<index-1; i++){
			IndexList=IndexList -> neighbor;
		}	
		if (index == ListSize-1){
			free(IndexList -> neighbor);
			IndexList -> neighbor=NULL;
		}
		else{
			node* DelPointer = IndexList->neighbor;
			IndexList -> neighbor = IndexList -> neighbor -> neighbor;
			free(DelPointer);			
		}
	}
	ListSize-=1;
}

int main(){
	node* list = create(5);
	add(10, list);
	add(15, list);
	DelIndex(0, list);
	WriteLine(list);
	

	return 0;
}
