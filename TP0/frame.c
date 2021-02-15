#include "menu.h"  
// by Guilherme Aguiar S M 

void print_frame(char **frame){ 
    for(int i = 0 ; i < line ; i++){ 
              for(int j = 0 ; j < column ; j++){  
                  printf("%c",frame[i][j]);
              } 
            printf("\n");
        }
}
/*__________________________________________________________________________________________________________________________________*/
int fill_fig1(char **frame, int coordinate_line , int coordinate_column){  
    int flag = 0 ;  
    for(int i = 0 ; i < line ; i++){  
            if(i == 0 || i == line - 1){ 
                for(int j = 0; j < column ; j++){ 
                    if (j < column - 1 && j >= 0)
                    frame[i][j] = (char) '-'; 
                     
                }
            } 
             
            if(i > 0 && i < line - 1){ 
                for(int j = 0; j < column ; j++){ 
                    if(j == column - 1 || j == 0)
                        frame[i][j] = (char) '|';  
                    else 
                        if(i == coordinate_line && j ==  coordinate_column) { 
                            frame[i][j] = (char) '*'; 
                            flag = 1 ; 
                        
                        }  
                        else frame[i][j] = (char) ' '; 
                }
            }
        
        }  
        
    return flag ; 
}  
/*__________________________________________________________________________________________________________________________________*/
void fig1(int num){ 
    char **frame = init_frame(); 
    int flag = 0, 
    count = 0;
    Figure figuras[num];
    srand(time(NULL));   
    
    
    while(count < num ){  
        if(flag == 1){ 
            count++; 
            flag = 0 ; 
            #ifdef DEBUG
                printf("count: %d \n", count );    
            #endif // DEBUG  
        } 
        else if(flag == 0){ 
            figuras[count].coordinate_line = random_coordinates(CHOSEN_LINE, CHOSEN_FIG1);     
            figuras[count].coordinate_column = random_coordinates(CHOSEN_COLUMN,CHOSEN_FIG1);
            #ifdef DEBUG 
                printf("coordinates: %d %d \n", figuras[count].coordinate_line , figuras[count].coordinate_column );  
            #endif // DEBUG 
            flag = fill_fig1(frame, figuras[count].coordinate_line , figuras[count].coordinate_column); 
        }
          
    }
    
    print_frame(frame); 
    
}    
/*__________________________________________________________________________________________________________________________________*/
void fig2(int num){   
    srand(time(NULL));   
    int count = 0,    
    line_min,  
    line_max,  
    column_min, 
    column_max, 
    flag = 0;
    Figure figuras[num];  
   
    
    for(int i = 0 ; i < num ; i++){   
        figuras[i].coordinate_line =  random_coordinates(CHOSEN_LINE,CHOSEN_FIG2);     
        figuras[i].coordinate_column =  random_coordinates(CHOSEN_COLUMN,CHOSEN_FIG2);
        #ifdef DEBUG
            printf("coordinates: %d %d \n", figuras[i].coordinate_line , figuras[i].coordinate_column );    
        #endif // DEBUG   
    } 
    

    for(int i = 0 ; i < line ; i++){ 
        
        line_min = figuras[count].coordinate_line, line_max = line_min + 3; 
        column_min = figuras[count].coordinate_column, column_max = column_min + 3 ; 
        if(i == line_min || i == line_max - 1){  
            for(int j = 0; j < column  ;j++){     
                if(j == column_min + 1) 
                    printf("*");  
                
                // if(j == column - 1 || j == 0)
                //     printf("|"); 
                else
                  printf(" ");
                } 
            
        }
         
        if(i == line_min + 1 ){  
            // esse primeiro if sera importante se o sorteio da coordenada nao for delimitado 
            if(column_min > 0 && column_max < column - 1){  
            for(int j = 0; j < column ; j++){ 
                if(j >= column_min && j < column_max)
                    printf("*"); 
                // if(j == column - 1 || j == 0)
                //     printf("|"); 
                else 
                    printf(" ");  
                

                } 
            }
        }  
        if(i == 0 || i == line - 1)
            for(int j = 0; j < column ; j++)
                printf("-");  
                
        
        else 
            for(int j = 0; j < column ;j++){ 
                if(j == column - 1 || j == 0)
                    printf("|"); 
                else  
                    printf(" ");
            }     
                 
        printf("\n"); 
       
    } 

    

 }  

/*__________________________________________________________________________________________________________________________________*/
void fig3(int num){ }  

/*__________________________________________________________________________________________________________________________________*/
void random_fig(int num ){ }  

/*__________________________________________________________________________________________________________________________________*/
void create_fig(int num){ } 

/*__________________________________________________________________________________________________________________________________*/
