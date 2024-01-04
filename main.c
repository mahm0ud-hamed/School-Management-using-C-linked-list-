#include"school.h"
int main()
{
    List s ;// storing struct at memory

    creat_list(&s);// pass

    printf("welcome to the school system\n");
    printf("enter the number of operation you need\n");
    while(1)
    {
        switch(main_menu())//calling main menu function
        {
            case 1 :new_student(&s);
                break ;
            case 2 :delete_student(&s);
                break;
            case 3 :edit_student(&s);
                break;
            case 4 :print_student_list(&s);
                break;
            case 5 :edit_students_score(&s);
                break;
            case 6 :destroy_list(&s);
                break;
            case 7 : inser_student(&s);
                break ;
            default:
                printf("**************************************\n");
                printf("you entered wrong operation number(try again)\n");
                printf("**************************************\n");
               main_menu();
            break;
        }
    }
    return 0;
}
