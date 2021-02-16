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
                            if(frame[i][j] == ' '){ 
                                frame[i][j] = (char) '*'; 
                                flag = 1 ;
                            }  
                        
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
            printf("N");
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
int fill_fig2(char **frame, int coordinate_line , int coordinate_column){ 
    int line_min,  
    line_max,  
    column_min, 
    column_max, 
    flag = 0 ;   

    line_min = coordinate_line, line_max = line_min + 3; 
    column_min = coordinate_column, column_max = column_min + 3 ;
    
    for(int i = 0 ; i < line ; i++){ 
        
        if(i == 0 || i == line - 1)
            for(int j = 0; j < column ; j++)
                frame[i][j] = (char) '-';  
                
        else 
            for(int j = 0; j < column ;j++){ 
                if(j == column - 1 || j == 0)
                    frame[i][j] = (char) '|';  
                else  
                    frame[i][j] = (char) ' ';  
            }     
    }   
    //verificar o espaço  
    if(frame[line_min][column_min + 1] != ' '  
    || frame[line_max-1][column_min + 1] != ' '   
    || frame[line_min + 1][column_min] != ' '  
    || frame[line_min + 1][column_max - 1] != ' ' ){ 
        return flag ;
    } 

    frame[line_min][column_min + 1 ] = (char) '*'; 
    frame[line_max - 1][column_min + 1] = (char) '*';
    for(int i = column_min; i < column_max; i++){ 
        frame[line_min+1][i] = (char) '*';
    }
    flag = 1 ;  


    return flag; 

} 
/*__________________________________________________________________________________________________________________________________*/
void fig2(int num){   
    srand(time(NULL));   
    int count = 0,   
    flag = 0;
    Figure figuras[num];   
    char **frame = init_frame(); 
   

    while(count < num ){  
        if(flag == 1){ 
            count++; 
            flag = 0; 
            #ifdef DEBUG
                printf("count: %d \n", count );    
            #endif // DEBUG  
        } 
        else if(flag == 0){  
            printf("N");
            figuras[count].coordinate_line = random_coordinates(CHOSEN_LINE, CHOSEN_FIG2);     
            figuras[count].coordinate_column = random_coordinates(CHOSEN_COLUMN,CHOSEN_FIG2);
            #ifdef DEBUG 
                printf("coordinates: %d %d \n", figuras[count].coordinate_line , figuras[count].coordinate_column );  
            #endif // DEBUG 
            flag = fill_fig2(frame, figuras[count].coordinate_line , figuras[count].coordinate_column); 
        }
          
    }
    
    print_frame(frame); 
    


    

 }  

/*__________________________________________________________________________________________________________________________________*/ 
int fill_fig3(char **frame, int coordinate_line , int coordinate_column){ 
    int line_min,  
    line_max,  
    column_min, 
    column_max, 
    flag = 0 ;   

    line_min = coordinate_line, line_max = line_min + 3; 
    column_min = coordinate_column, column_max = column_min + 3 ;
    
    for(int i = 0 ; i < line ; i++){ 
        
        if(i == 0 || i == line - 1)
            for(int j = 0; j < column ; j++)
                frame[i][j] = (char) '-';  
                
        else 
            for(int j = 0; j < column ;j++){ 
                if(j == column - 1 || j == 0)
                    frame[i][j] = (char) '|';  
                else  
                    frame[i][j] = (char) ' ';  
            }     
    }   

    // verificar espaco 
    frame[line_min][column_min] = (char) '*';  
    frame[line_min][column_max] = (char) '*'; 
    frame[line_min + 1][column_min + 1] = (char) '*';
    frame[line_max-1][column_min] = (char) '*';  
    frame[line_max-1][column_max] = (char) '*'; 
    
    flag = 1 ;   
    return flag ; 

}
void fig3(int num){ 
    srand(time(NULL));   
    int count = 0,   
    flag = 0;
    Figure figuras[num];   
    char **frame = init_frame(); 
   

    while(count < num ){  
        if(flag == 1){ 
            count++; 
            flag = 0; 
            #ifdef DEBUG
                printf("count: %d \n", count );    
            #endif // DEBUG  
        } 
        else if(flag == 0){  
            printf("N");
            figuras[count].coordinate_line = random_coordinates(CHOSEN_LINE, CHOSEN_FIG3);     
            figuras[count].coordinate_column = random_coordinates(CHOSEN_COLUMN,CHOSEN_FIG3);
            #ifdef DEBUG 
                printf("coordinates: %d %d \n", figuras[count].coordinate_line , figuras[count].coordinate_column );  
            #endif // DEBUG 
            flag = fill_fig3(frame, figuras[count].coordinate_line , figuras[count].coordinate_column); 
        }
          
    }
    
    print_frame(frame); 
 }  

/*__________________________________________________________________________________________________________________________________*/
void random_fig(int num ){ }  

/*__________________________________________________________________________________________________________________________________*/
void create_fig(int num){ } 

/*__________________________________________________________________________________________________________________________________*/
