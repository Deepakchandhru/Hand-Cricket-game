#include <stdio.h>
#include <stdlib.h>

struct noderec{
int info;
char isout;
struct noderec *next;
};
typedef struct noderec *node;

node new,temp;
typedef node header;
header h;

void createlist(){
h=(header) malloc(sizeof(struct noderec));
h->next=h;
}

int isEmpty(){
return(h->next==h);
}

void insert(int x,char out){
    new=(node) malloc(sizeof(struct noderec));
    new->info=x;
    new->isout=out;
    temp=h;
    while(temp->next!=h){
        temp=temp->next;
    }
    temp->next=new;
    new->next=h;
}

void totalmatches(){
    if(!isEmpty()){
        temp=h->next;
        int i=1;
        while(temp->next!=h){
            i++;
            temp=temp->next;
        }
        printf("No.of matches Played: %d\n",i);
    }else{
        printf("Please play the game at least once .\n");
    }
}

void scorehistory(){
    if(!isEmpty()){
        totalmatches();
        temp = h->next;
        int totalruns = 0;
        int totalinnings = 0;
        int i = 1;
        while(temp != h){
            printf("Match:%d \t\t Score: %d", i, temp->info);
            if(temp->isout=='N'){
                printf("*");
            }else{ 
                totalinnings++;
            }
            printf("\n");
            totalruns += temp->info;
            temp = temp->next;
            i++;
        }

        printf("\n");

        if(totalinnings == 0){
            printf("Average Score: %.2f\n", (float)totalruns / 1.00);
        }else{
            printf("Average Score: %.2f\n", (float)totalruns / (float)totalinnings);
        }

        printf("No.of Unbeaten Knocks: %d\n", i - totalinnings - 1);

        printf("\n");
    }else{
        printf("Please play the game at least once .\n");
    }
}


int highscore(){
    if(!isEmpty()){
        temp=h->next;
        int max=temp->info;
        while(temp!=h){
            if(temp->info > max){
                max=temp->info;
            }
            temp=temp->next;
        }
        return max;
    }else{
        printf("Please play the game at least once .\n");
        return 0;
    }
}
