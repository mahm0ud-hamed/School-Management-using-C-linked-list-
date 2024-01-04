
/* @file linked_list.c
 *  @brief The linked list.
 *
 *  This is the implementation of the linked list.
 *  Important details about its implementation should go in these comments.
 *
 *  @author mahmoudmohamedhmd@gmail.com
 */
#ifndef SCHOOL_H_INCLUDED
#define SCHOOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define date_max 10
#define name_max 50
#define adress_max 50
typedef unsigned char u8 ;// assigning char to represent by u8

typedef unsigned int u32 ;// assigning char to represent by u32

/*struct student data type
include all student data
student name , student id
student date of birth
student address , student score
student phone number
and pointer to the net student node */
typedef struct student
{
    char student_name[name_max];
    int id ;
    char date_birth[date_max];
    char student_adress[adress_max];
    int score ;
    long telepone ;
    struct student *next ;

}StudentNode ;

/* struct list that contain pointer
to the whole list
and size variable to count list size  */

typedef struct list
{
    StudentNode *top ;
     int size ;
}List ;

u8 main_menu(void);
/* @brief showing main menu
 *  @return char
 */

void creat_list (List *pl);
/* @brief create linked list
 *  @param pl a pointer to struct of type list
 *  @return void
 */

char list_empty(List *pl);
/* @brief checking linked list is empty or not
 *  @param pl a pointer to struct of type list
 *  @return char
 */

char list_full(List *pl);
/* @brief checking linked list is full or not
 *  @param pl a pointer to struct of type list
 *  @return char
 */

void new_student(List * pl);
/* @brief adding new student to the linked list
 *  @param pl a pointer to struct of type list
 *  @return void
 */

void delete_student(List *pl);
/* @brief deleting student from  linked list
 *  @param pl a pointer to struct of type list
 *  @return void
 */

void edit_student(List *pl);
/* @brief editing student information on the  linked list
 *  @param pl a pointer to struct of type list
 *  @return void
 */

void destroy_list(List *pl);
/* @brief destroying whole linked list
 *  @param pl a pointer to struct of type list
 *  @return void
 */

//void alphapet_sort(List *pl);

void print_student_list(List *pl);
/* @brief print all student information on the  linked list
 *  @param pl a pointer to struct of type list
 *  @return void
 */

void edit_students_score(List *pl);
/* @brief editing whole students score on the linked list
 *  @param pl a pointer to struct of type list
 *  @return void
 */

 void inser_student(List * pl);
 /* @brief  insert student at position on  linked list
 *  @param pl a pointer to struct of type list
 *  @return void
 */
#endif // SCHOOL_H_INCLUDED
