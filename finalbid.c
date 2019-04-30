#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
//START OF NAME ROSTER
struct node_name{
    struct node_name *next;
    int b_no;
    char b_name[50];
}*start_name = NULL;
char *search_name(int top_bid , char b_bidder[]){              //to display name of bidder after final bid call
    struct node_name *ptr_search_name;
    ptr_search_name = start_name; 
    while(ptr_search_name->b_no != top_bid)
        ptr_search_name = ptr_search_name->next;
    strcpy(b_bidder , ptr_search_name->b_name);
        return b_bidder;
}
void create_ll_name(){
    fflush(stdin);
    struct node_name *ptr_name , *new_node_name;
    int n;
    char name[50];
    printf("\nEnter bidding number :"); scanf("%d",&n);
    printf("\nEnter -1 to end");    // Terminate create_ll()
    while(n != -1){
        fflush(stdin);
        printf("\nEnter bidder name : "); 
        gets(name);
        new_node_name = (struct node_name *)malloc(sizeof(struct node_name));
        new_node_name->b_no = n;
        strcpy(new_node_name->b_name , name);
        new_node_name->next = NULL;
        if(start_name == NULL)            
            start_name = new_node_name;
        else{
            ptr_name = start_name;
            while(ptr_name->next != NULL)
                ptr_name = ptr_name->next;
            ptr_name->next = new_node_name;
        }
        printf("\nEnter bidding number :"); 
        scanf("%d",&n);
    }
}
void display_name(){
    struct node_name *ptr_name;
    if(start_name == NULL)
        printf("\nRoster is empty");
    else{
        ptr_name = start_name ;
        printf("\nBIDDER NAME\tBIDDER NO.");
        while(ptr_name != NULL){
            printf("\n%s\t\t%d", ptr_name->b_name , ptr_name->b_no);
            ptr_name = ptr_name->next;
        }
    }
}
void create_roster_name(){
    int option;
    do{
        printf("\n*******************************");
        printf("\n*                             *");
        printf("\n*        BIDDER ROSTER        *");
        printf("\n*                             *");
        printf("\n*******************************");
        printf("\n1.)Create Roster");
        printf("\n2.)Display Roster");
        printf("\n3.)EXIT");
        printf("\nEnter your option : ");
        scanf("%d",&option);
        switch(option){
            case 1:create_ll_name();    break;
            case 2:display_name();      break;
        }
    }while(option != 3);
}
//END OF NAME ROSTER
//START OF ITEM ROSTER
struct node_item{
    int price;
    char i_name[100];
    char i_description[100];
    struct node_item *next ;
}*top_item = NULL;
void push_item(){
    struct node_item *new_node_item;
    int p;
    char i_n[100] , i_d[100];
    fflush(stdin);
    printf("\nEnter item name : ");
    gets(i_n);  //input item name
    printf("\nEnter item price :");  
    scanf("%d",&p);  //input item price 
    fflush(stdin);
    printf("\nEnter item desciption: "); 
    gets(i_d);  //input item description
    new_node_item = (struct node_item *)malloc(sizeof(struct node_item));
    new_node_item->price = p;
    strcpy(new_node_item->i_name , i_n);
    strcpy(new_node_item->i_description , i_d);
    if(top_item == NULL){
        new_node_item->next = NULL;
        top_item = new_node_item;
    }
    else{
        new_node_item->next = top_item;
        top_item = new_node_item;
    }
}
void pop_item(){
    struct node_item *ptr_item ;
    if(top_item == NULL)
        printf("\nStack empty");
    else{
        ptr_item = top_item;
        top_item = top_item->next;
        free(ptr_item);
    }
}
void peep_item(){
    if(top_item == NULL)
        printf("\nStack empty");
    else{
        printf("\nItem at top of roster is ");
        printf("\n%s",top_item->i_name);
        printf("\n%d",top_item->price);
        printf("\n%s",top_item->i_description);
    }
}
void display_item(){
    struct node_item *ptr_item;
    if(top_item == NULL)
        printf("\nStack is empty");
    else{
        ptr_item = top_item ;
        printf("\nItem Name\tItem price\tItem Description");
        while(ptr_item != NULL){
            printf("\n%s\t\t%d\t\t%s", ptr_item->i_name , ptr_item->price , ptr_item->i_description);
            ptr_item = ptr_item->next;
        }
    }
}
void create_roster_item(){
    int option;
    do{
        printf("\n*******************************");
        printf("\n*                             *");
        printf("\n*         ITEM ROSTER         *");
        printf("\n*                             *");
        printf("\n*******************************");
        printf("\nEnter roster :");
        printf("\n1.)PUSH");
        printf("\n2.)POP");
        printf("\n3.)PEEP");
        printf("\n4.)DISPLAY");
        printf("\n5.)EXIT");
        printf("\nEnter your option :");
        scanf("%d",&option);
        switch(option){
            case 1: push_item();    break;
            case 2: pop_item();     break;
            case 3: peep_item();    break;
            case 4: display_item(); break;
        }
    }while(option != 5);
}
//END OF ITEM ROSTER
//final ownership roster
struct node_bid{
    int bid_price;
    char bid_item[100];
    char bid_owner[100];
    struct node_bid *next_bid;
}*start_bid = NULL;
void push_bid(int x , char y[] , char z[]){         //x = bid price y = item name z = item owner
    struct node_bid *ptr_bid , *new_node_bid;
    new_node_bid = (struct node_bid *)malloc(sizeof(struct node_bid));
    new_node_bid->bid_price = x;
    strcpy(new_node_bid->bid_item , y);
    strcpy(new_node_bid->bid_owner , z);
    new_node_bid->next_bid = NULL;
    if(start_bid == NULL)
        start_bid = new_node_bid;
    else{
        ptr_bid = start_bid;
        while(ptr_bid->next_bid != NULL)
            ptr_bid = ptr_bid->next_bid;
        ptr_bid->next_bid = new_node_bid;
    }
}
void display_bid(){
    struct node_bid *ptr_display;
    if(start_bid == NULL)
        printf("\nEMPTY");    
    else{
        ptr_display = start_bid;
        printf("\nItem Name\tItem Price\tItem Owner");
        while(ptr_display != NULL){
            printf("\n%s" , ptr_display->bid_item);
            printf("\t\t%d", ptr_display->bid_price);
            printf("\t\t%s", ptr_display->bid_owner); ptr_display = ptr_display->next_bid;
        }
    }
    printf("\n");
}
//
//START OF BIDDING PROGRAM
char get_char(float time_limit){        //function for keyboard hit while auction call
	int i = 1;
    time_t start = time(NULL); //start the clock
	while(!kbhit()){
		printf("\nGOING FOR %d",i);
        sleep(1);
		if((time(NULL) - start) >= time_limit)         //compare the clock with current time, if it exceeds return -1; 
        	return -1;       
        i++;
	}
	return getch();    //else return the value stored in keyboard buffer.
}
struct node_stack{
    int top_bid;
    struct node_stack *next;
}*top = NULL;
void push_stack(int node_bid_no){
    struct node_stack *new_node_stack; 
    new_node_stack = (struct node_stack *)malloc(sizeof(struct node_stack));
    new_node_stack->top_bid = node_bid_no;
    if(top == NULL){
        new_node_stack->next = NULL;
        top = new_node_stack;
    }
    else{
        new_node_stack->next = top;
        top = new_node_stack;
    }
}
void bidding(){
    int node_bid_no = 0 , c = 0 , raised_price , flag = 1;
    char b_bidder[100] , b; 
    strcpy(b_bidder,"");   
    printf("_____________________________________________________________\n");
    printf("\nItem on roster : ");
    printf("\nItem name :%s",top_item->i_name);
    printf("\nItem price :%d",top_item->price);
    printf("\nItem description :%s",top_item->i_description);
    printf("\n_____________________________________________________________\n");
    printf("\nBidding starts in 7 seconds: \n");
    sleep(7);
    while(flag == 1){      
        b = get_char(10);
        if((b == -1) && (node_bid_no == 0))
            goto label_pop;      
        else if((b == -1) && (node_bid_no != 0)){
            printf("\nItem still being held by %d",node_bid_no);
            sleep(3);
            goto label_final;
        }
        else{
            if(c != 0){
                if(top_item->price <= 10000)
                    top_item->price = top_item->price + 100;
                else if(top_item->price <= 100000)
                    top_item->price = top_item->price + 1000;
                else if(top_item->price <= 1000000)
                    top_item->price = top_item->price + 10000;
                else if(top_item->price >= 5000000)   
                    top_item->price = top_item->price + 100000;
            }
            printf("\nEnter your bid no: ");
            scanf("%d",&node_bid_no);
            push_stack(node_bid_no);                 //ONE BID SO PUSH BID NO ON STACK
            sleep(2);
            printf("\nItem %s held by bidder number : %d at price %d", top_item->i_name , top->top_bid , top_item->price);
            c++;                
        }
    }
    printf("\nEnd bidding");
    if(top == NULL){
        label_pop:
        push_bid(top_item->price , top_item->i_name , "NONE");
        pop_item();
        printf("\nITEM NOT SOLD\n");
    }
    else{
        label_final:
        push_bid(top_item->price , top_item->i_name , search_name(top->top_bid , b_bidder));
        printf("\nItem %s sold to bidder number : %d ",top_item->i_name,top->top_bid);
        printf("i.e. -> %s at price: %d", search_name(top->top_bid , b_bidder) ,top_item->price);
        pop_item();
        sleep(5);
    }
}

void auction(){     //carry out auction within time limit of three minutes
    time_t start = time(NULL);
    label_time_check:
    if((top_item != NULL) && ((time(NULL) - start) <= 180)){
        bidding();
        printf("\nBIDDING FOR NEXT ITEM ON LIST WILL BEGIN IN 6 SECONDS\n\n");
        sleep(6);
        goto label_time_check;
    }
    else
        return;
}
//END OF BIDDING PROGRAM
int main(){
    int option;
    do{
        printf("\n*******************************");
        printf("\n*                             *");
        printf("\n*      WELCOME TO AUCTION     *");
        printf("\n*                             *");
        printf("\n*******************************");
        printf("\n1.)Create item roster ");
        printf("\n2.)Create bidder roster ");
        printf("\n3.)Start Bidding");
        printf("\n4.)Final Ownership");
        printf("\n5.)EXIT");
        printf("\nEnter your choice: ");
        scanf("%d",&option);
        switch(option){
            case 1:create_roster_item();    break;
            case 2:create_roster_name();    break;
            case 3:auction();               break;
            case 4:display_bid();           break;
        }
    }while(option != 5);
    return 0;
}
