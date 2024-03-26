#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NOK -1
#define OK 1
struct mystr{
	struct mystr *next,*prev;
	int age;
	char *name;
} *head;
int addNode(char *name, int age){
	struct mystr *new,*last;

	if( (new=malloc(sizeof(struct mystr))) == NULL)
		return (NOK);
	new->next = new->prev = 0;
	new->age=age;
	new->name=malloc(18);
	strcpy(new->name,name);

	if(head==0){
		head=new;
		return (OK);
	}
	for(last=head;last->next!=0;last=last->next)
		;
	last->next=new;
	new->prev=last;
	return (OK);
}
	
	
	
void printNodes(){
	struct mystr *ptr;
	for(ptr=head;ptr!=0;ptr=ptr->next)
		printf("%d %s\n",ptr->age, ptr->name);
}
void printReverse(){
	struct mystr *last,*next,*current;
	//if(head==0)
		//return 0;
	for(last=head;last->next!=0;last=last->next)
		;
	current=head;
	while( current != NULL){
		next=current->next;
		current->next=current->prev;
		current->prev=next;
		current=next;
	}
	head=last;
	printNodes();
}

int findAge(char *name){
	struct mystr *ptr;
	int min;
	for(ptr=head;ptr!=0;ptr=ptr->next){
		if(!strcmp(ptr->name,name)){
			min=ptr->age;
			return min;
		}
	}
	return -1;
}

int swapNodes(char *name1, char *name2){
	struct mystr *ptr,*ptr2,*tmp1,*tmp2,*tmp;
	tmp=malloc(sizeof(struct mystr));
	for(ptr=head;ptr!=0;tmp1=ptr,ptr=ptr->next)
		if(!strcmp(ptr->name,name1))
			break;
	for(ptr2=head;ptr2!=0;tmp2=ptr2,ptr2=ptr2->next)
		if(!strcmp(ptr2->name,name2))
			break;
	strcpy(tmp->name,tmp1->name);
	strcpy(tmp1->name,tmp2->name);
	strcpy(tmp2->name,tmp->name);
	

}
int main(){
	addNode("kim",20);
	addNode("park", 21);
	addNode("choi", 22);
	addNode("ahn", 23);
	printNodes();
	//printReverse();
	//printf("%d\n", findAge("choi") );
	//printf("%d\n", findAge("hong") );
	printf("--------------\n");
	swapNodes("kim", "park");
	printNodes();
}
/////////////////////////////////////////////////////
int insert(char* toName, char* name, int age) {
	struct mystr* newNode = malloc(sizeof(struct mystr));
	if (!newNode) {
		return -1;  // Memory allocation failed
	}

	// Set the values for the new node
	newNode->next = newNode->prev = NULL;
	newNode->age = age;
	strcpy(newNode->name, name);
	newNode->message = malloc(MSG_SIZE);
	strcpy(newNode->message, "");  // Empty message for the new node

	struct mystr* ptr;
	int found = 0;

	// Find the nodes with toName and insert the new node before them
	for (ptr = head; ptr; ptr = ptr->next) {
		if (!strcmp(ptr->name, toName)) {
			if (ptr->prev) {
				ptr->prev->next = newNode;
			}
			else {
				head = newNode;
			}
			newNode->prev = ptr->prev;
			newNode->next = ptr;
			ptr->prev = newNode;
			found = 1;
		}
	}

	if (!found) {
		free(newNode->message);
		free(newNode);
		return -1;  // No nodes with toName found
	}

	return 1;
}mmary>

/// ///////////////////////////////////////////////////////////

int insert(char* toName, char* name, int age) {
	struct mystr* newNode = malloc(sizeof(struct mystr));
	if (!newNode) {
		return -1;  // Memory allocation failed
	}

	// Set the values for the new node
	newNode->next = NULL;
	newNode->age = age;
	strcpy(newNode->name, name);
	newNode->message = malloc(MSG_SIZE);
	strcpy(newNode->message, "");  // Empty message for the new node

	struct mystr* ptr;
	int found = 0;

	// Find the nodes with toName and insert the new node before them
	for (ptr = head; ptr; ptr = ptr->next) {
		if (!strcmp(ptr->name, toName)) {
			newNode->next = ptr;
			if (ptr == head) {
				head = newNode;
			}
			else {
				struct mystr* prevNode = head;
				while (prevNode->next != ptr) {
					prevNode = prevNode->next;
				}
				prevNode->next = newNode;
			}
			found = 1;
			break;
		}
	}

	if (!found) {
		free(newNode->message);
		free(newNode);
		return -1;  // No nodes with toName found
	}

	return 1;
}

void printAgedNodes(int age) {
	struct mystr* ptr;

	for (ptr = head; ptr; ptr = ptr->next) {
		if (ptr->age == age) {
			printf("\tname: %s \tmessage: %s \tage: %d\n", ptr->name, ptr->message, ptr->age);
		}
	}
}
int delNodes(int position, int count) {
	if (position < 0 || count <= 0) {
		return -1;  // Invalid position or count
	}

	struct mystr* ptr = head;
	int nodeIndex = 0;

	// Traverse to the position node
	while (ptr && nodeIndex < position) {
		ptr = ptr->next;
		nodeIndex++;
	}

	if (!ptr) {
		return -1;  // Position node not found
	}

	// Delete the nodes starting from the position node
	for (int i = 0; i < count && ptr; i++) {
		struct mystr* nextNode = ptr->next;

		if (ptr->prev) {
			ptr->prev->next = nextNode;
		}
		else {
			head = nextNode;
		}

		if (nextNode) {
			nextNode->prev = ptr->prev;
		}

		free(ptr->message);
		free(ptr);

		ptr = nextNode;
	}

	if (count > 0 && nodeIndex >= position) {
		return 1;  // Nodes deleted successfully
	}

	return -1;  // Deletion failed
}
int delodds() {
	struct mystr* ptr = head;
	int nodeIndex = 0;

	while (ptr) {
		if (nodeIndex % 2 == 1) {
			struct mystr* nextNode = ptr->next;

			if (ptr->prev) {
				ptr->prev->next = nextNode;
			}
			else {
				head = nextNode;
			}

			if (nextNode) {
				nextNode->prev = ptr->prev;
			}

			free(ptr->message);
			free(ptr);

			ptr = nextNode;
		}
		else {
			ptr = ptr->next;
		}

		nodeIndex++;
	}

	return 1;  // Nodes deleted successfully
}
	int insertLast(int val) {
		struct mystr* newNode = malloc(sizeof(struct mystr));
		if (!newNode) {
			return -1;  // Memory allocation failed
		}

		// Set the values for the new node
		newNode->next = NULL;
		newNode->prev = NULL;
		newNode->age = val;
		newNode->message = malloc(MSG_SIZE);
		strcpy(newNode->message, "");  // Empty message for the new node

		if (!head) {
			head = newNode;
		}
		else {
			struct mystr* ptr = head;
			while (ptr->next) {
				ptr = ptr->next;
			}
			ptr->next = newNode;
			newNode->prev = ptr;
		}

		return 1;  // Node inserted successfully at the end
	}

	int insertFirst(int val) {
		struct mystr* newNode = malloc(sizeof(struct mystr));
		if (!newNode) {
			return -1;  // Memory allocation failed
		}

		// Set the values for the new node
		newNode->next = NULL;
		newNode->prev = NULL;
		newNode->age = val;
		newNode->message = malloc(MSG_SIZE);
		strcpy(newNode->message, "");  // Empty message for the new node

		if (!head) {
			head = newNode;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}

		return 1;  // Node inserted successfully at the beginning
	}