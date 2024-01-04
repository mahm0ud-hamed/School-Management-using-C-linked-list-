#include"school.h"


u8 main_menu(void)
{
    u32 op_slec ;
    printf("\n(1)for adding new student \n");
    printf("\n(2)for delete student \n");
    printf("\n(3)for edit particular student\n");
    printf("\n(4)for print students list \n");
    printf("\n(5)for update all students score\n");
    printf("\n(6) for insert student at position \n");
    printf("\n(7)for DESTROYING ALL DATA BASE (!BE CARE PLEASE)");
    fflush(stdin);
     scanf("%d",&op_slec);
    return op_slec ;//return number operation selected by the user

}//end of main menu function

void creat_list (List *pl)
{
    pl->top=NULL;// initialize list pointer to null
    pl->size = 0 ; // initialize size by 0

}//end of

char list_empty(List *pl)
{
    return pl->size==0;// return 1 if list is empty or 0 if it full

}// end of list empty function

char list_full(List *pl)
{
    return 0 ;// return zero becouse heap is larg and will not fill

}// end of list full function

void new_student(List * pl)
{
    char x ; // variable for operation
    do
    {
            StudentNode *pn ;// creating pointer of student node type
            pn=(StudentNode *)malloc(sizeof(StudentNode));// creating new node in heap
            printf("the position to insert (%d)\n",pl->size);
            printf("**-*-**-*-*-*-**-*-*-*-*--**-\n");
            fflush(stdin);

            printf("\n enter the student name \n");//ask user to enter student name
            gets(pn->student_name);//scanning name from user
            fflush(stdin);

            printf("enter student id\n");// ask user to enter student id
            scanf("%d",&pn->id);// scanning id from user
            fflush(stdin);

            printf("enter the student address \n");// asking user to enter student address
            gets(pn->student_adress);// scanning address form user
            fflush(stdin);

            printf("enter the student date of birth\n");// asking user to enter student birth date
            gets(pn->date_birth);// scanning student birth date from user
            fflush(stdin);

            printf("enter the student phone number\n");// asking user to enter student phone number
            scanf("%ld",&pn->telepone);//scanning phone number from user

            printf("enter the student score \n");// asking user to enter student score
             scanf("%d",&pn->score);// scanning student score

            pn->next=pl->top;// moving pointers to be ready for new student node
            pl->top=pn ;
            pl->size++;//increment size of list by one with every student bush

            printf("press any button for continue\n");
            printf("press e for exit\n");
            scanf(" %c",&x);
            fflush(stdin);


    }while(x!='e');

}//end of new student function
void destroy_list(List *pl)// function to delete all data in one time
{
    StudentNode *q ;// creating pointer of student node data type

    q=pl->top;// temp initialize temp pointer to first node address

    while(pl)
    {
        q=pl->top->next;   // incrementing pointer to point the next node

        free(pl);// deleting node that pl was point to

        pl->top=q ;// moving list pointer to the first node again

    }//end of while loop

    pl->size=0;// after loop finish size of list will be 0
}//end of destroy list function

void delete_student(List *pl)// function to delete student
{
    StudentNode *q , *temp;// creating pointers from student node type

    u32 id ;// integer variables

    printf("enter the id\n");// asking user to enter position
    scanf("%d",&id);//scanning position from user
    fflush(stdin);

    q =pl->top ;
    if(q->next==NULL)//if first node
    {
     temp= pl->top->next ;//holding remaining list by pointer

     free(pl->top);// remove first node

     pl->top=temp ;//link remaining list by top pointer again

    }//end of if statement
    else
    {
        q=pl->top ;// initialize pn to top address
        while(q)

        {
            if(q->next->id==id)
            {
                temp=q->next->next ;
                free(q->next);
                q->next=temp ;
            }
            q=q->next ;
        }


    }//end of else statement

    pl->size--;//reduce size by one after delete node

}//end of delete function

void edit_student(List*pl)// function to edit student data
{
    StudentNode *q;//creating pointer from student node type

    q=pl->top;//initialize pointer to top address

    u8 x;// variable for complete data at do while

    u32  id , op;// int variables

    if (list_empty(pl))
    {
        printf("the list is empty\n");//check list empty or not
        return;
    }//end of if statement

    else
    {
       printf("enter student id to search\n");//asking user to enter id

       scanf("%d",&id);//scanning id from user
       fflush(stdin);

    }//end of else

    while(q)
    {
        if(q->id==id)//checking id exist or not
        {

        do
        {
         printf("enter the operation to select\n ");// asking select operation
         printf("*-*-*-*-*-*---*-*-*-*-*-*-*-*-*-*\n");
         printf("(1)for editing name\n");
         printf("(2)for editing id\n");
         printf("(3)for editing date of birth\n");
         printf("(4)for editing telephone number\n");
         printf("(5)for editing score\n");
         printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
         scanf("%d",&op);

          switch(op)
         {
             case 1 :
                 printf("enter student new name\n");//ask for new name

                 gets(q->student_name);//scan new name
                 fflush(stdin);
                 break;

             case 2 :
                printf("enter student new id\n");//ask new id

                scanf("%d",&q->id);//scan new id
                 fflush(stdin);
                break;

             case 3 :
                printf("enter student new birth day\n");//ask new birth day

                gets(q->date_birth);//scan new birth day
                 fflush(stdin);
                break;

             case 4 :
                 printf("enter student new phone number\n");//asking new phone number

                 scanf("%ld",&q->telepone);//scanning new phone number
                 fflush(stdin);
                 break;

             case 5 :
                printf("enter student new score\n");// asking for new score

                scanf("%d",&q->score);//scanning for new score
                 fflush(stdin);
                break;
         }//end of switch

            printf("enter any button if you need to reedit any data\n");
            printf("enter (e) for exit\n");
            scanf(" %c",&x);
             fflush(stdin);

        }while(x!='e');//end of do while by user enter e char

        }//end of if statement

        else
        {
            q=q->next;//move if id not exist

        }//end of else


    }//end of while

}// end of edit function


void ranked_sort(List *pl)
{
    StudentNode *temp=(StudentNode *)malloc(sizeof(StudentNode));
    StudentNode *q , *p ;

    int i ,j  ;

    if(list_empty(pl))
    {
        printf("no student information available\n");
        return ;
    }
    else
    {


        for(i=0 ; i < pl->size-1; i++)
        {
            q=pl->top ;//stand on first node
            p=q->next ;//stand on second node

            for(j=0 ; j<pl->size-i-1 ; j++)
            {
                if((q->score) < (p->score))
                {
                    /*putting node data on temo node*/
                    strcpy(temp->student_name,p->student_name );
                    strcpy(temp->date_birth,p->date_birth);
                    temp->id = p->id ;
                    temp->score = p->score ;
                    strcpy(temp->student_adress,p->student_adress);
                    temp->telepone = p->telepone ;
                    /* ************ */
                    /*swap two student data */
                    strcpy(p->student_name ,q->student_name);
                    strcpy(p->date_birth,q->date_birth);
                    p->id = q->id ;
                    p->score = q->score ;
                    strcpy(p->student_adress,q->student_adress);
                    p->telepone = q->telepone;
                    ////////
                    /*put temp data in student node */
                    strcpy( q->student_name,temp->student_name);
                    strcpy(q->date_birth ,temp->date_birth);

                    q->id =temp->id;
                    q->score=temp->score ;
                    strcpy(q->student_adress,temp->student_adress);
                    q->telepone=temp->telepone;
                }
                p=p->next ;
                q=q->next;
            }
            free(temp);
        }
    }



        /*for()
         if(q->score < temp1->score)
        {
            q->next= temp1->next ;
            temp1->next = temp2 ;
            temp2->next= temp1;
        }

      // while(temp)
        {
            temp2=temp->next ;
            while(temp2)
            {
              if(temp->score > temp2->score)
              {
                  swap_temp= temp2->next ;
                  temp2->next = temp ;
                  temp= swap_temp;
              }
              temp2=temp2->next ;

            }
            temp=temp->next;


        }*/

}
void alphapet_sort(List *pl)
{
    /*allocate place on heap as temp  */
    StudentNode *temp=(StudentNode *)malloc(sizeof(StudentNode));
    StudentNode *q , *p ;// create  pointers student node type

    int i ,j  ;// loops counters

    if(list_empty(pl))
    {
        printf("no student information available\n");
        return ;
    }
    else
    {


        for(i=0 ; i < pl->size-1; i++)
        {
            q=pl->top ;//stand on first node
            p=q->next ;//stand on second node

            for(j=0 ; j<pl->size-i-1 ; j++)
            {
                if(strcmp(strupr(q->student_name),strupr(p->student_name))>0)
                {
                    /*putting node data on temo node*/
                    strcpy(temp->student_name,p->student_name );
                    strcpy(temp->date_birth,p->date_birth);
                    temp->id = p->id ;
                    temp->score = p->score ;
                    strcpy(temp->student_adress,p->student_adress);
                    temp->telepone = p->telepone ;

                    /*swap two student data */
                    strcpy(p->student_name ,q->student_name);
                    strcpy(p->date_birth,q->date_birth);
                    p->id = q->id ;
                    p->score = q->score ;
                    strcpy(p->student_adress,q->student_adress);
                    p->telepone = q->telepone;

                    /*put temp data in student node */
                    strcpy( q->student_name,temp->student_name);
                    strcpy(q->date_birth ,temp->date_birth);
                    q->id =temp->id;
                    q->score=temp->score ;
                    strcpy(q->student_adress,temp->student_adress);
                    q->telepone=temp->telepone;
                }
                p=p->next ;//increment pointer p
                q=q->next;//increment pointer q
            }
            free(temp);// free temp after finish
        }
    }
}

void print_student_list(List *pl)//function for printing list
{

     StudentNode *temp ; // temp pointer student node type

      short x ; // variable for choosing type of sort

     temp= pl->top; // assigning th temp pointer to the first student node

     short  counter= 1 ; // show every student number

     if(list_empty(pl))
     {
         printf("no student information\n"); //check list full or not
         return;
     }//end of if

       /*ask user to chose sort type*/
     printf("press 1 for alphabetic  sort\n");
     printf("press 2  for score sort \n");
     fflush(stdin);
     scanf("%d",&x);
     if(x==1)
        alphapet_sort(pl);
     else
        ranked_sort(pl);

    printf("the list of (%d) students \n",pl->size);//print total students

    while(temp!=NULL)

    {
       printf("the student number (%d)\n",counter);//print student number in list

       printf("name: %s\n",temp->student_name);//print student name

       printf("ID:%d\n",temp->id);// print student id

       printf("phone number:%ld\n",temp->telepone);//print student phone number

       printf("address: %s\n",temp->student_adress);//print student address

       printf("score:%d\n",temp->score);// print student score

       printf("birth data : %s\n",temp->date_birth);//print birth date

       printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**-*");
       counter++ ;// counter for student number in list

       temp=temp->next;//move to next student node

    }// end of while loop

}// end of print function

void edit_students_score(List *pl)// function for edit score
{
    StudentNode * q ;// pointer form student node type

    q=pl->top; // assigning pointer to the address to the list address

    if(list_empty(pl))//check is empty or not
    {
        printf("the list is empty \n");//check is empty or not
        return ;
    }//end of if statement

    else
    {
        while(q)
        {
            printf("name: %s\n",q->student_name);//print student name

            printf("ID: %d\n",q->id);//print student id

            printf("enter th new score \n");//asking for new score
            scanf("%d",&q->score);//scanning new score

            q=q->next ;//move to next  student node

        }//end of while

    }//end of else

}//end of edit all student score function


void inser_student(List * pl)
{
    StudentNode *pn , *q;// creating pointer of student node type
    int pos ;
    pn=(StudentNode *)malloc(sizeof(StudentNode));// creating new node in heap
    printf("the position to insert (%d)\n",pl->size);
    printf("**-*-**-*-*-*-**-*-*-*-*--**-\n");

    printf("\n enter the student name \n");//ask user to enter student name
    gets(pn->student_name);//scanning name from user
    fflush(stdin);

    printf("enter student id\n");// ask user to enter student id
    scanf("%d",&pn->id);// scanning id from user
    fflush(stdin);

    printf("enter the student address \n");// asking user to enter student address
    gets(pn->student_adress);// scanning address form user
    fflush(stdin);

    printf("enter the student date of birth\n");// asking user to enter student birth date
    gets(pn->date_birth);// scanning student birth date from user
    fflush(stdin);

    printf("enter the student phone number\n");// asking user to enter student phone number
    scanf("%ld",&pn->telepone);//scanning phone number from user
    fflush(stdin);

    printf("enter the student score \n");// asking user to enter student score
    scanf("%d",&pn->score);// scanning student score
     fflush(stdin);

    printf("enter position of inserting\n");//ask user to enter insert position
    scanf("%d",&pos);
    fflush(stdin);

    if(pos==0)//if insert position 0
    {
        pn->next=pl->top;
        pl->top=pn ;
    }
    else//if not the 0 position
    {
        int i ;
        q=pl->top ;
        for(i=0 ; i<pos-1; i++)
        {
            q=q->next;
        }
        pn->next=q->next ;
        q->next = pn ;
    }
        pl->size++;//increment size of list by one with every student bush
}//end of insert  student function

