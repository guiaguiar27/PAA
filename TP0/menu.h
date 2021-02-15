#include <stdio.h> 
#include <stdlib.h>  
#include <time.h>  
#define line  20  
#define column  80    
#define asteriscos_fig2 5 
#define DEBUG 1 
#define CHOSEN_LINE 0  
#define CHOSEN_COLUMN 1 
#define CHOSEN_FIG1 1 
#define CHOSEN_FIG2 2  
#define CHOSEN_FIG3 3 

typedef struct {   
    /*  *  */
    int coordinate_line; 
    int coordinate_column; 
}Figure;  



int *menu();    
void print_frame(char **frame); 
void fig1(int num); 
int fill_fig1(char **frame, int coordinate_line , int coordinate_column);
void fig2(int num);
void fig3(int num); 
void select();   
int random_coordinates(int choose, int fig);
void random_fig(int num); 
void crate_fig(int num);  
char **init_frame();