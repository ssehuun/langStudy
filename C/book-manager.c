/*
<Book Manager Auto System>

1. functions
book_manage
book_rental //keep:1, not:0
book_return
book_search
book_register
-------------
custinfo_manage
custinfo_register
custinfo_search
custinfo_update
custinfo_delete

2. View structure
- book_manage, custinfo_manage, exit
- book_rental, book_return, book_search, book_register, previous
- custinfo_register, custinfo_search, custinfo_update, custinfo_delete, previous

3. Data list with specific work - related with DB
book list - Bookid, Bookname, Press, Author, Rental
rental list - Bookid, Customerid, Rentaldate
custinfo list- Customertid, Customername, Customertelno
*/
#include<stdio.h>
#include<stdlib.h>

// book info struct
typedef struct booktype{
    char bookid[5];
    char bookname[30];
    char press[20];
    char author[20];
    char category[4];
    char rental;
    struct booktype* next;
}BOOKTYPE;

// rental info struct
typedef struct rentaltype{
    char bookid[5];
    char customerid[10];
    time_t rentalDate;
    struct rentaltype* next;
}RENTALTYPE;

// customer info struct
typedef struct customertype{
    char customerid[10];
    char customername[20];
    char customertelno[20]
    struct customertype* next;
}CUSTOMERTYPE;

//book manage functions
void book_manage(BOOKTYPE** bookhead, RENTALTYPE** rentalhead, CUSTOMERTYPE* customerhead);
int book_register(BOOKTYPE** bookhead);
void book_all_print(BOOKTYPE** bookhead);
BOOKTYPE* search(BOOKTYPE* bookhead, char node);
void book_print(BOOKTYPE* temp);
int book_rental(RENTALTYPE** rentalhead, BOOKTYPE** bookhead);
int book_return(RENTALTYPE** rentalhead, BOOKTYPE** bookhead, CUSTOMERTYPE** customerhead);

// customer manager functions
char custinfo_manage(CUSTOMERTYPE** custhead);
void custinfo_register(CUSTOMERTYPE** custhead);
void custinfo_update(CUSTOMERTYPE** custhead);
CUSTOMERTYPE* custinfo_search(CUSTOMERTYPE* custhead, char node);
void custinfo_delete(CUSTOMERTYPE** custhead);
void customer_all_print(CUSTOMERTYPE** custhead);

#define BOOKID 1
#define BOOKNAME 2

int main(){
    int choice;
    BOOKTYPE* BOOKHEAD = NULL;
    RENTALTYPE* RENTALHEAD = NULL;
    CUSTOMERTYPE* CUSTHEAD = NULL;
    
    do{
        printf("1. Book Manage\n");
        printf("2. Customer Manage\n");
        printf("3. Exit\n");
        printf("Choose --> ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                book_manage(&BOOKHEAD, &RENTALHEAD, CUSTHEAD);
                break;
            case 2:
                cust_manage(&CUSTHEAD);
                break;
            case 3:
                break;
            default:
                printf("Wrong Choice\n");
                break;
        }
    }while(choice!=3);
    return 0;
}
void book_manage(BOOKTYPE** bookhead, RENTALTYPE** rentalhead, CUSTOMERTYPE* customerhead)
{
    int choice;
    char sname[40];
    BOOKTYPE* temp;
    
    do{
        printf("1. book rent\n");
        printf("2. book return\n");
        printf("3. book register\n");
        printf("4. book search\n");
        printf("5. previous page\n");
        printf("Choose: ----> ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if(book_rental(rentalhead, *bookhead, custhead) != 0)
                    printf("rent fail\n");
                else:
                    printf("rent success\n");
                break;
            case 2:
                book_rental(rentalhead, bookhead);
                break;
            case 3:
                book_register(bookhead);
                book_all_print(*bookhead);
                break;
            case 4:
                temp = book_search(*bookhead, BOOKNAME);
                if(temp == NULL)
                    printf("Not found book, %c\n", sname);
                else:
                    printf("Found %c\n", sname);
            case 5:
                break;
            default:
                break;
        }
    }while(choice!=5)
}
int book_register(BOOKTYPE** bookhead)
{
    
}
