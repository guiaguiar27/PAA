#include <stdio.h> 
#include <stdlib.h>  
#include <time.h>  
                                    /** Defines */
#define line  20  
#define column  80    
#define DEBUG 1
#define CHOSEN_LINE 0  
#define CHOSEN_COLUMN 1 
#define CHOSEN_FIG1 1 
#define CHOSEN_FIG2 2  
#define CHOSEN_FIG3 3  
#define CHOSEN_FIG4 4 



                                    /** Structs  */
typedef struct {   
    /*  *  */
    int coordinate_line; 
    int coordinate_column; 
}Figure;  



                                    /** Funciots */
   

/**  Figure funcions  */
void fig1(int num); 
int fill_fig1(char **frame, int coordinate_line , int coordinate_column);
void fig2(int num); 
int fill_fig2(char **frame, int coordinate_line , int coordinate_column); 
void fig3(int num);  
int fill_fig3(char **frame, int coordinate_line , int coordinate_column); 
void random_fig(int num); 
void crate_fig(int num);   
int fill_create_fig(char **frame, int coordinate_line , int coordinate_column);

/**  Menu funcions  */
void select();   
int random_coordinates(int choose, int fig); 
int *menu(); 

/**  Frame funcions  */
char **init_frame(); 
void make_frame(char **frame);  
void print_frame(char **frame); 

