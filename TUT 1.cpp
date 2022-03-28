#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct player{
	char nickname[100];
	char gameid[100];
	int membershiplvl;
	
	player* next;
	player* prev;
}*head, *tail;

player* createplayer(char nickname[], char gameid[], int membershiplvl){
	player* newplayer = (player*)malloc(sizeof(player));
	
	strcpy(newplayer->nickname, nickname);
	strcpy(newplayer->gameid, gameid);
	newplayer->membershiplvl=membershiplvl;
	
	newplayer->next = newplayer->prev = NULL;
	
	return newplayer;
}

void pushHead(char nickname[], char gameid[], int membershiplvl){
	player* newplayer = createplayer(nickname, gameid, membershiplvl);
	
	if (head == NULL){
		head = tail = newplayer;
		return;
	}
	else{
		newplayer->next = head;
		head->prev = newplayer;
		head = newplayer;
	}
return;
}

void pushTail(char nickname[], char gameid[], int membershiplvl){
	player* newplayer = createplayer(nickname, gameid, membershiplvl);
	
	if (tail == NULL){
		head = tail = newplayer;
		return;
	}
	
	else {
		tail->next = newplayer;
		newplayer->prev = tail;
		
		tail = newplayer;
	}
return;
}

void pushMid(char nickname[], char gameid[], int membershiplvl){
	
	
	if (head == NULL){
		head = tail = createplayer(nickname, gameid, membershiplvl);
	}
	else{
		if (membershiplvl > head->membershiplvl){
			pushHead(nickname, gameid, membershiplvl);
			return;
		}
		else if (membershiplvl <= tail->membershiplvl){
			pushTail(nickname, gameid, membershiplvl);
			return;
		}
		else{
			player* newplayer = createplayer(nickname, gameid, membershiplvl);
			player *curr = head;
			while(curr->next && curr->next->membershiplvl >= membershiplvl){
				curr= curr->next;
			}
			curr->next->prev = newplayer;
			newplayer->next = curr->next;
			curr->next = newplayer;
			newplayer->prev = curr;
		}
	}

}

void Queue(){
	char nickname[100];
	char gameid[100];
	int membershiplvl;
	int nicklen;
	int idlen;
	
	do{
		printf("Insert your Nickname : ");
		scanf("%s", nickname);
		nicklen = strlen(nickname);
		getchar();
	}while(nicklen > 16);
	
	do{
		printf("Insert your Game ID : ");
		scanf("%s", gameid);
		idlen = strlen(gameid);
		getchar();
	}while(idlen != 8);
	
	do{
		printf("Insert your Membership Level : ");
		scanf("%d", &membershiplvl);
		getchar();
	}while(membershiplvl != 1 && membershiplvl != 2 && membershiplvl != 3);
	
	pushMid(nickname, gameid, membershiplvl);
	
	printf("Please Wait to enter the game\n");
	printf("Or press enter to go back");
	getchar();
return;
}

void view(){
	int n;
	if (head == NULL){
		printf("You are the first player here!\n");
		puts("");
	}
	else {
		printf("Here is the Player Queue : \n");
		player *curr = head;
		int x = 1;
		while(curr != NULL){
			puts("");
			printf("No %d\n", x);
			printf("Nickname : %s\n", curr->nickname);
			printf("Game ID : %s\n", curr->gameid);
			printf("Membership Level : %d\n", curr->membershiplvl);
			curr = curr->next;
			x++;
			puts("");
		}

	}
return;
}

void search(){
	char nickname[100];
	if (head == NULL){
		printf("There is no player here!\n");
		puts("");
	}
	
	else {
		printf("Enter your nickname : ");
		scanf("%s", nickname);
		puts("");
		player* curr = head;
		int n = 1;
		while(curr!=NULL && strcmp(curr->nickname, nickname) != 0){
			curr=curr->next;
			n++;
		}
		if (curr == NULL){
			printf("Nickname Not Found\n");
		}
		else {
			printf("You are at position number %d\n", n);
		}
		return;
	}
}

void menu(){
	printf("Player Menu\n");
	puts("");
	printf("1. Queue to the game\n");
	printf("2. View Queue\n");
	printf("3. Search Player Position\n");
	printf("4. Exit\n");
	printf("Input your choice ");
return;
}

int main(){
	int choice;
	while (true){
		menu();
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				Queue();
				break;
				
			case 2:
				view();
				break;
				
			case 3:
				search();
				break;
				
			case 4:
				exit(0);
		}
	}
	return 0;
}
