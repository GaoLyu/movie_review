/*
 *  CSC A48 - Winter 2022 - Assignment 1 starter
 * 
 *  (c) 2020-22 Francisco Estrada
 *  - No part of this code may be reproduced without written authorization
 * 
 * This is the file where you will be doing most of your work. The
 * functionality you must provide for part 1 of the assignment is described
 * in the handout. Given in detail in the comments at the head of each
 * function below. 
 * 
 * Plan your work carefully, review the notes for Unit 3, and work carefully
 * to complete the functions in this file. You can bring 
 * questions to your TAs or instructors during office hours. Please
 * remember:
 * 
 * - You should not share any part of your solution in any form
 * - You should not post any assignment code on Piazza
 * - You should definitely *help* other understand any ideas and
 *   concepts regarding linked lists that you have already mastered,
 *   but being careful not to give away parts of the solution, or
 *   descriptions of how to implement functions below.
 * - If you are not sure whether you can or can not discuss some
 *   particular aspect of the work to be done, remember it's always 
 *   safe to talk with your TAs.
 * - Obtaining external 'help' including being given code by an
 *   external party, or being tutored on how to solve
 *   the assignment constitutes an academic offense.
 * 
 * All tasks to be completed by you are clearly labeled with a
 * ***** TO DO ****** comment block, which also gives you details
 * about what you have to implement. Look carefully and make sure
 * you don't miss a thing!
 * 
 * NOTE: This file contains no main() function! you can not compile
 * it on its own to create an executable. It's meant to be used
 * together with Part1_driver.c - be sure to read that file carefully
 * to understand how to use the tests there - Any additional tests
 * you want to run on the code below should be added to Part1_driver.c
 * 
 * Before you even get starter implementing, please complete the
 * student identification section below, and check that you are aware
 * of the policy on academic honesty and plagiarism.
 */

/* Student identification:
 * 
 * Student Name (Last name, First name):Lyu Gaoyueyang
 * Student Number:1007624625
 * UTORid:lyugaoyu
 * Your instructor's name is:Purva Rajendra Gawde
 */

/* Academic Integrity Statement:
 * 
 * I hereby certify that the work contained in this file is my own, and
 * that I have not received any parts of my solution from other sources
 * including my fellow students, external tutoring services, the internet,
 * or algorithm implementations found online.
 * 
 * Sign here with your name:Gaoyueyang Lyu
 *
 *  
 */

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LEN 1024

/* Compound data type declarations */
/***************************************************************************/
/******                         TO DO                               ********/
/****** In the space below, complete the definitions of the compound *******/
/****** data types that will be needed to implement the movie review *******/
/****** linked list. This includes the MovieReview type, and the     *******/
/****** ReviewNode. Details about the contents of these can be       *******/
/****** found in the assignment handout. Read them carefully!        *******/
/******                                                              *******/
/****** AFTER completing the basic linked list, complete the CDT     *******/
/****** required to implement a list for the movie's cast.           *******/
/***************************************************************************/

typedef struct castList_struct
{    
    char name[MAX_STR_LEN];
    float salary;
    struct castList_struct *next;  
} CastList;

typedef struct movieReview_struct
{
    char movie_title[MAX_STR_LEN];
    char movie_studio[MAX_STR_LEN];
    int year;
    float BO_total;
    int score;
    CastList *cast;
    
} MovieReview;

typedef struct reviewNode_struct
{
    MovieReview review;
    struct reviewNode_struct *next;
    
} ReviewNode;

ReviewNode *newMovieReviewNode()
{
    /*
     * This function allocates an empty ReviewNode, and initializes the
     * contents of the MovieReview for this node to reasonable (uninitialized) values.
     * The fields in the MovieReview should be set to:
     *  movie_title=""
     *  movie_studio=""
     *  year = -1
     *  BO_total = -1
     *  score = -1
     *  cast = NULL;
     * 
     * The *next pointer for the new node MUST be set to NULL
     * 
     * The function must return a pointer to the newly allocated and initialized
     * node. If something goes wrong, the function returns NULL
     */
 
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *new_node=NULL;
    new_node=(ReviewNode *)calloc(1, sizeof(ReviewNode));
    if(new_node==NULL)
    {
        return NULL;
    }
    strcpy(new_node->review.movie_title,"");
    strcpy(new_node->review.movie_studio,"");
    new_node->review.year=-1;
    new_node->review.BO_total=-1;
    new_node->review.score=-1;
    new_node->review.cast=NULL;
    new_node->next=NULL;
    return(new_node);  
}

ReviewNode *findMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head)
{
    /*
     * This function searches through the linked list for a review that matches the input query. 
     * The movie review must match the title, studio, and year provided in the 
     * parameters for this function.
     * 
     * If a review matching the query is found, this function returns the address of the node that
     * contains that review. 
     * 
     * If no such review is found, this function returns NULL
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *p=head;
    if(head==NULL)
    {
        return NULL;
    }
    while(p!=NULL)
    {
        if(strcmp(p->review.movie_title,title)==0 && strcmp(p->review.movie_studio,studio)==0 && p->review.year==year)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;  
}

ReviewNode *insertMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function inserts a new movie review into the linked list.
     * 
     * The function takes as input parameters the data neede to fill-in the review,
     * as well as apointer to the current head of the linked list.
     * 
     * If head==NULL, then the list is still empty.
     * 
     * The function inserts the new movie review *AT THE HEAD* of the linked list,
     * and returns the pointer to the new head node.
     * 
     * The function MUST check that the movie is not already in the list before
     * inserting (there should be no duplicate entries). If a movie with matching
     * title, studio, and year is already in the list, nothing is inserted and the
     * function returns the current list head.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    if(findMovieReview(title, studio, year, head)!=NULL)
    {
        return head;
    }
    ReviewNode *new_node=newMovieReviewNode();
    strcpy(new_node->review.movie_title,title);
    strcpy(new_node->review.movie_studio,studio);
    new_node->review.year=year;
    new_node->review.BO_total=BO_total;
    new_node->review.score=score;
    new_node->next=head;
    return new_node;
    //return NULL;        // Remove this before you implement your solution!
}

int countReviews(ReviewNode *head)
{
  /*
   * This function returns the number of reviews. 
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  
    ReviewNode *p=head;
    int num=0;
    while(p!=NULL)
    {
        p=p->next;
        num++;
    }
    return num;
    //return 0;    // Remove this before you implement your solution
}

void updateMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function looks for a review matching the input query [title, studio, year].
     * If such a review is found, then the function updates the Box-office total, and the score.
     * If no such review is found, the function prints out 
     * "Sorry, no such movie exists in the database"
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *p=findMovieReview(title,studio,year,head);
    if(head==NULL || p==NULL)
    {
        printf("Sorry, no such movie exists in the database\n");
    }
    else
    {
        p->review.BO_total=BO_total;
        p->review.score=score;
    }    
}

ReviewNode *deleteMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN],int year, ReviewNode *head)
{
    /*
     * This function removes a review matching the input query from the database. If no such review can
     * be found, it does nothing.
     * 
     * The function returns a pointer to the head of the linked list (which may have changed as a result
     * of the deletion process)
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    if(head==NULL)
    {
        return NULL;
    }
    ReviewNode *p=findMovieReview(title,studio,year,head);
    ReviewNode *pre=head;
    ReviewNode *q=NULL;
    if(p==NULL)
    {
        return head;
    }
    else if(p==head)
    {
        q=p->next;
        free(p);
        return q;
    }
    else
    {
        while(pre->next!=p)
        {
            pre=pre->next;
        }
        pre->next=p->next;
        free(p);
        return head;
    }
    //return NULL;      // Remove this before implementing your solution
}

float printMovieReviews(ReviewNode *head)
{
    /*
     * This function prints out all the reviews in the database, one after another.
     * Each field in the review is printed in a separate line, with *no additional text*
     * (that means, the only thing printed is the value of the corresponding field).
     * 
     * Reviews are separated from each other by a line of
     * "*******************"

     * The function also computes and returns the Box-office total, for all the
     * movies that match the query.
     * 
     * See the A1 handout for a sample of the output that should be produced
     * by this function
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    float total=0.0;
    ReviewNode *p=head;
    while(p!=NULL)
    {
        printf("%s\n",p->review.movie_title);
        printf("%s\n",p->review.movie_studio);
        printf("%d\n",p->review.year);
        printf("%f\n",p->review.BO_total);
        printf("%d\n",p->review.score);
        printf("*******************\n");
        total+=p->review.BO_total;
        p=p->next;
    }
    return total;
    //return 0;           // Remove this before you implement your solution
}

float queryReviewsByStudio(char studio[MAX_STR_LEN], ReviewNode *head)
{
    /*
     * This function looks for reviews whose studio matches the input query.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     * 
     * Additionally, it computes and returns the Box-office total, for all the
     * movies that match the query.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  
    float total=0.0;
    ReviewNode *p=NULL;
    p=head;
    while(p!=NULL)
    {
        if(strcmp(p->review.movie_studio,studio)==0)
        {
            printf("%s\n",p->review.movie_title);
            printf("%s\n",p->review.movie_studio);
            printf("%d\n",p->review.year);
            printf("%f\n",p->review.BO_total);
            printf("%d\n",p->review.score);
            printf("*******************\n");
            total+=p->review.BO_total;
        }
        p=p->next;
    }
    return total;
    //return 0;       // Remove this before you implement your solution
}

float queryReviewsByScore(int min_score, ReviewNode *head)
{
    /*
     * This function looks for reviews whose score is greater than, or equal to
     * the input 'min_score'.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     * 
     * Additionally, it computes and returns the Box-office total, for all the
     * movies that match the query.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  
    float total=0.0;
    ReviewNode *p=head;
    while(p!=NULL)
    {
        if(p->review.score>=min_score)
        {
            printf("%s\n",p->review.movie_title);
            printf("%s\n",p->review.movie_studio);
            printf("%d\n",p->review.year);
            printf("%f\n",p->review.BO_total);
            printf("%d\n",p->review.score);
            printf("*******************\n");
            total+=p->review.score;
        }
        p=p->next;
    }
    return total;
    //return 0;
}

ReviewNode *deleteReviewList(ReviewNode *head)
{
  /*
   * This function deletes the movie review database, releasing all the
   * memory allocated to the nodes in the linked list.
   * 
   * Returns a NULL pointer so that the head of the list can be set to NULL
   * after deletion.
   */
      
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/    
    ReviewNode *p=head;
    ReviewNode *q=NULL;
    CastList *m=NULL;
    CastList *n=NULL;
    while(p!=NULL)
    {
        q=p->next;
        m=p->review.cast;
        while(m!=NULL)
        {
            n=m->next;
            free(m);
            m=n;
        }
        free(p);
        p=q;
    }
    return NULL;
    //return head;        // Remove this before you implement your solution
}

/* CRUNCHY SECTION! Do not work on the functions below until
 * your basic linked list is working properly and is fully tested!
 */ 


// ReviewNode *sortReviewsByTitle(ReviewNode *head)
// {
//   /*
//    * This function sorts the list of movie reviews in ascending order of movie
//    * title. If duplicate movie titles exist, the order is arbitrary (i.e. you
//    * can choose which one goes first).
//    * 
//    * However you implement this function, it must return a pointer to the head
//    * node of the sorted list.
//    */

//     /***************************************************************************/
//     /**********  TO DO: Complete this function *********************************/
//     /***************************************************************************/      
//     if(head==NULL)
//     {
//         return NULL;
//     }
//     ReviewNode *p=head;
//     ReviewNode *copy;
//     int num=0;
//     int i,j;
//     char title1[MAX_STR_LEN],title2[MAX_STR_LEN];
//     while(p!=NULL)
//     {
//         p=p->next;
//         num++;
//     }
//     ReviewNode *nodes[num];
//     num=0;
//     p=head;
//     while(p!=NULL)
//     {
//         nodes[num]=p;
//         p=p->next;
//         num++;
//     }
//     for(i=0;i<num-1;i++)
//     {
//         for(j=i+1;j<num;j++)
//         {
//             strcpy(title1,nodes[i]->review.movie_title);
//             strcpy(title2,nodes[j]->review.movie_title);
//             if(strcmp(title1,title2)>0)
//             {
//                 copy=nodes[i];
//                 nodes[i]=nodes[j];
//                 nodes[j]=copy;
//             }
//         }
//     }
//     //sorted in an array
//     for(i=0;i<num-1;i++)
//     {
//         nodes[i]->next=nodes[i+1];
//     }
//     nodes[i]->next=NULL;
//     head=nodes[0];
//     return head;
// }

ReviewNode *loop(ReviewNode *head, int time)
{
    
    ReviewNode *p=head;
    for(int i=0;i<time-1;i++)
    {
            p=p->next;
    }
    
    return p;
}

ReviewNode *sortReviewsByTitle(ReviewNode *head)
{
  /*
   * This function sorts the list of movie reviews in ascending order of movie
   * title. If duplicate movie titles exist, the order is arbitrary (i.e. you
   * can choose which one goes first).
   * 
   * However you implement this function, it must return a pointer to the head
   * node of the sorted list.
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/      
    if(head==NULL)
    {
        return NULL;
    }
    int num=0;
    int i=0;
    char title[MAX_STR_LEN];
    char smallest[MAX_STR_LEN];
    ReviewNode *p=head;
    ReviewNode *s=head;
    ReviewNode *pre=NULL;
    ReviewNode *sp;
    while(p!=NULL)
    {
        p=p->next;
        num++;
    }
    
    for(i=0;i<num-1;i++)
    {
        pre=NULL;
        sp=NULL;
        p=loop(head,i+1);
        s=p;
        strcpy(smallest,p->review.movie_title);
        while(p!=NULL)
        {
            strcpy(title,p->review.movie_title);
            if(strcmp(title,smallest)<0)
            {
                s=p;
                strcpy(smallest,title);
                sp=pre;
            }
            pre=p;
            p=p->next;
        }
        if(sp!=NULL)
        {
            sp->next=s->next;
            s->next=loop(head,i+1);
            if(i!=0)
            {
                loop(head,i)->next=s;
            }
            
        }
        if(i==0)
        {
            head=s;
        }

    }
    return head;
}

void insertCastMember(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head, char name[MAX_STR_LEN], float salary)
{
  /*
   * This function inserts the name of a cast member for the given movie into the
   * linked list of cast members. The new cast member must go to the end of the list.
   * 
   * Duplicate names are allowed - this time! 
   * 
   * Notice the function receives the title, studio, and year for the movie, as
   * well as a pointer to the movie DB linked list. The function must find the 
   * correct movie and if such a movie exists, add the cast member's name to its
   * cast list.
   * 
   * If no such movie is found, this function does nothing.
   * 
   * You're free to add helper functions to insert the cast member's name
   * into the cast list.
   */   

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/      
    ReviewNode *p=NULL;
    CastList *one_cast;
    CastList *q=NULL;
    p=findMovieReview(title,studio,year,head);
    if(p!=NULL)
    {
        q=p->review.cast;
        one_cast=(CastList *)calloc(1,sizeof(CastList));
        strcpy(one_cast->name,name);
        one_cast->salary=salary;
        one_cast->next=NULL;
        if(q==NULL)
        {
            p->review.cast=one_cast;
        }
        else
        {
            while(q->next!=NULL)
            {
                q=q->next;
            }
            q->next=one_cast;
        }
    }
}

typedef struct cast_earning
{
    char name[MAX_STR_LEN];
    float earning;
    int film_num;
    struct cast_earning *next;
}cast_earning;

struct cast_earning *new_cast(void)
{
    cast_earning *new_cast=NULL;
    new_cast=(struct cast_earning *)calloc(1,sizeof(struct cast_earning));
    strcpy(new_cast->name,"");
    new_cast->earning=0.0;
    new_cast->film_num=0;
    new_cast->next=NULL;
    return new_cast;
}

struct cast_earning *insert(cast_earning *new_cast, cast_earning *e_head)
{
    new_cast->next=e_head;
    return new_cast;
}

struct cast_earning *find_cast(const char name_key[MAX_STR_LEN],cast_earning *e_head)
{
    cast_earning *p=e_head;
    while(p!=NULL)
    {
        if(strcmp(p->name,name_key)==0)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;
}

void whosTheStar(ReviewNode *head)
{
  /*
   *  This function goes through the movie database and determines who is
   * the cast members whose movies have the greatest average earnings.
   *
   * Earnings are defined as the box office total minus the salaries of all
   * cast members involved with the movie.
   *
   *  You're free to implement this function however you like, use any of
   * the code you wrote for other parts of the assignment, and write any
   * helper functions that you need. But:
   *
   *  You can not import extra libraries (no additional #include), and
   * all the implementation here should be your own. 
   *
   *  The function simply prints out:
   *
   *  Name of cast member
   *  Average movie earnings (as a floating point number)
   *
   *  For the cast member whose movies make the greatest average earnings
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/      
    //假设一个movie里的cast都不重复

    ReviewNode *p=NULL;
    CastList *q=NULL;
    cast_earning *e_head=NULL;
    cast_earning *one_cast=NULL;
    cast_earning *greatest_cast=NULL;
    cast_earning *m=NULL;
    float total_salary,total_earning,average;
    char name[MAX_STR_LEN];
    p=head;
    while(p!=NULL)
    {
        q=p->review.cast;
        while(q!=NULL)
        {
            strcpy(name,q->name);
            if(find_cast(name,e_head)==NULL)
            {
                one_cast=new_cast();
                strcpy(one_cast->name,name);
                e_head=insert(one_cast,e_head);
            }
            q=q->next;
        }
        p=p->next;
    }
    //we have stored all casts' names in the cast_earning list
    if(e_head!=NULL)
    {
        p=head;
        while(p!=NULL)
        {
            total_salary=0.0;
            q=p->review.cast;
            while(q!=NULL)
            {
                total_salary+=q->salary;
                q=q->next;
            }
            total_earning=(p->review.BO_total) - total_salary;
            q=p->review.cast;
            while(q!=NULL)
            {
                strcpy(name,q->name);
                one_cast=find_cast(name,e_head);
                one_cast->earning += total_earning;
                one_cast->film_num ++;
                q=q->next;
            }
            p=p->next;
        }
        one_cast=e_head;
        while(one_cast!=NULL)
        {
            average=(one_cast->earning)/(one_cast->film_num);
            one_cast->earning=average;
            one_cast=one_cast->next;
        }
        one_cast=e_head;
        greatest_cast=e_head;
        while(one_cast!=NULL)
        {
            if((one_cast->earning)>(greatest_cast->earning))
            {
                greatest_cast=one_cast;
            }
            one_cast=one_cast->next;
        }
        printf("%s\n",greatest_cast->name);
        printf("%f\n",greatest_cast->earning);
        //free memory
        one_cast=e_head;
        while(one_cast!=NULL)
        {
            m=one_cast->next;
            free(one_cast);
            one_cast=m;
        }
    }
}

void printNames(ReviewNode *movie)
{
    // Prints out names of cast members for this movie
    CastList *p;

    if (movie==NULL||movie->review.cast==NULL) return;

    p=movie->review.cast;
    printf("The cast for this movie are:\n");
    while (p!=NULL)
    {
        printf("Cast Member: %s, Salary: %f\n",p->name,p->salary);
        p=p->next;
    }
}
