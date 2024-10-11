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

void Insert(int index, int data, int IndexList){
	for(int i=0; i<index-1; i++){
		IndexList=IndexList -> neighbor;
	}
	node * TemporaryList = IndexList->neighbor;
	IndexList -> neighbor = create(data);
	IndexList -> neighbor -> neighbor = TemporaryList;

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
			IndexList -> neighbor=NULL;
		}
		else{
			IndexList -> neighbor = IndexList -> neighbor -> neighbor;
		}
	}
	ListSize-=1;
}

int main(){
	node* list = create(5);
	add(10, list);
	add(15, list);
	WriteLine(list);
	DelIndex(0, list);
	WriteLine(list);
	

	return 0;
}
