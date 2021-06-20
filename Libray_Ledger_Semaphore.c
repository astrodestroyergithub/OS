
// Library ledger maintenance using semaphore

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Total number of students are 10
int N = 10;

// Total number of books are 5
int B = 5;

// Students details aggregation
struct students {
  char sname[100];
  int sid;
};

// Books details aggregation
struct books {
  char bname[100];
  int bid;
};

// Semaphore initialized to the number of books available initially
int S = 5;

// Ledger officially stores the records and current status of the books
struct ledger {
  struct books book;
  struct students student;
  int borr_flag;
};

int main() 
{
	int i,j;
	
    struct ledger rec[N];
    for (i = 0; i < N; i++) 
    {
        strcpy(rec[i].book.bname, "null");
        rec[i].book.bid = -1;
        rec[i].borr_flag = 0;
        strcpy(rec[i].student.sname, "null");
        rec[i].student.sid = -1;
    }
    int size = B;
    struct books book1[size];
    for (i = 0; i < B; i++) 
    {
        strcpy(book1[i].bname, "OS");
        book1[i].bid = B - i;
    }
    int top = B - 1;
    // V for signal processing (Verhogen)
    void ret(int id) 
    {
        if (top == size - 1) 
        {
            printf("Don't have extra space to accomodate more books!!!\n ");
            S++;
        } 
        else 
        {
            top++;
            S++;
            book1[top].bid = id;
        }
    }
    // P for wait operation (Proberen)
    int borrow() 
    {
        if (top == -1) 
        {
            S--;
            return -1;
        } 
        else 
        {
            int id = book1[top].bid;
            top--;
            S--;
            return id;
        }
    }
    int choice;
    printf("*********** WELCOME TO THE LIBRARY ***********\n");
    while (1) 
    {
        printf("\n|******************* MENU *******************|");
        printf("\n| 1. BORROW |");
        printf("\n| 2. RETURN |");
        printf("\n| 3. CHECK STATUS |");
        printf("\n| 4. EXIT |");
        printf("\n\n| ENTER YOUR CHOICE : ");
        scanf("%d", & choice);
        if (choice == 1) 
        {
            int borr_no;
            printf("| ENTER THE NUMBER OF BORROWERS : |\n");
            scanf("%d", & borr_no);
            printf("ENTER THE NAMES OF %d STUDENTS : ", borr_no);
            int k = 0;
            while (k < borr_no) 
            {
                if (S > 0) 
                {
                    scanf("%s", & rec[k % N].student.sname);
                    rec[k % N].book.bid = borrow();
                    rec[k % N].borr_flag = 1;
                } 
                else 
                {
                    scanf("%s", & rec[k % N].student.sname);
                    rec[k % N].book.bid = borrow();
                    rec[k % N].borr_flag = 0;
                }
                k++;
            }   
        } 
        else if (choice == 2) 
        {
            int ret_no;
            printf("| ENTER THE NUMBER OF RETURNERS : |\n");
            scanf("%d", & ret_no);
            printf("ENTER THE NAMES OF %d STUDENTS : ", ret_no);
            int k = 0;
            while (k < ret_no) 
            {
                if (S < B) 
                {
                    char name1[100];
                    scanf("%s", & name1);
                    int id2;
                    for (j = 0; j < N; j++) 
                    {
                        if (rec[j].borr_flag == 1 &&
                        strcmp(rec[j].student.sname, name1) == 0) 
                        {
                            int a = rec[j].book.bid;
                            rec[j].book.bid = -1;
                            strcpy(rec[j].student.sname, "null");
                            ret(a);
                            rec[j].borr_flag = 0;
                            break;
                        }
                    }
                }
                k++;
            }
        } 
        else if (choice == 3) 
        {
            if (S > 0) 
            {
                printf("NO. OF AVAILABLE BOOKS = %d\n", S);
                printf("NO. OF STUDENTS WAITING TO BORROW A BOOK = 0\n ");
            }
            else if (S == 0) 
            {
                printf("NO. OF AVAILABLE BOOKS = 0\n");
                printf("NO. OF STUDENTS WAITING TO BORROW A BOOK = 0\n ");
            }
            else if (S < 0) 
            {
                printf("NO. OF AVAILABLE BOOKS = 0\n");
                printf("NO. OF STUDENTS WAITING TO BORROW A BOOK = %d\n ",abs(S));
            }
        } 
        else 
        {
            printf("\n\n|*************** VISIT AGAIN ****************|\n\n");
            exit(0);
        }
    }
    return 0;
}
