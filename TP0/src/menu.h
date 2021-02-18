#include <stdio.h> 
#include <stdlib.h>  
#include <time.h>  
                                    /** Defines */
#define line  20  
#define column  80    
#define DEBUG 0
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
/** 
 * \brief Initialize the frame and define the possible coordinates of the figure in the table 
 */
void fig1(int num); 
/** 
 * \brief fills the figure from the frame given by reference 
 * \param frame frame  
 * \param coordinate random points of line and column 
 */
int fill_fig1(char **frame, int coordinate_line , int coordinate_column); 
/** 
 * \brief Initialize the frame and define the possible coordinates of the figure in the table 
 */
void fig2(int num); 
/** 
 * \brief fills the figure from the frame given by reference 
 * \param frame frame  
 * \param coordinate random points of line and column 
 */
int fill_fig2(char **frame, int coordinate_line , int coordinate_column);  
/** 
 * \brief Initialize the frame and define the possible coordinates of the figure in the table 
 */
void fig3(int num);   
/** 
 * \brief fills the figure from the frame given by reference 
 * \param frame frame  
 * \param coordinate random points of line and column 
 */
int fill_fig3(char **frame, int coordinate_line , int coordinate_column);  
/** 
 * \brief Initialize the framem, define the possible coordinates of the figure in the table and select by random which figure will be printed 
 */
void random_fig(int num);  
/** 
 * \brief Initialize the frame and define the possible coordinates of the figure in the table 
 */
void crate_fig(int num);  
/** 
 * \brief fills the figure from the frame given by reference 
 * \param frame frame  
 * \param coordinate random points of line and column 
 */
int fill_create_fig(char **frame, int coordinate_line , int coordinate_column);
/** 
 * 
 */
                    /*          *  Menu funcions  */ 
/** 
 * \brief define which action the program will do 
 */
void select(); 
/** 
 * \brief Select the possible values for coordinates keeping the boundaries   
 *  \param choose select wich dimension the value will go , line or column
 *  \param fig 
 */
int random_coordinates(int choose, int fig);  
/** 
 * \brief Print options 
 */
void menu(); 

                    /**  Frame funcions  */ 
/** 
 * \brief allocate the frame 
 */
char **init_frame();  
/** 
 * \brief draw the column and line frame's
 */
void make_frame(char **frame);  
/** 
 * \brief show frame
 */ 
void print_frame(char **frame); 

