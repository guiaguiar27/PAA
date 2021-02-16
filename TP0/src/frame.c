#include "menu.h"  
// by Guilherme Aguiar S M 
void make_frame(char **frame){ 
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
                        frame[i][j] = (char) ' '; 
                }
            }
        
        }    
}
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
     
        // verificado / problema não é aqui  

    
        if(frame[coordinate_line][coordinate_column] == ' '){ 
            frame[coordinate_line][coordinate_column] =  (char) '*';   
            return 1;  
        }
        
        else{ 
            #if DEBUG 
                printf("Lugar ocupado\n"); 
            #endif
            }    
       return 0 ; 
        
}  
/*__________________________________________________________________________________________________________________________________*/
void fig1(int num){ 
    char **frame = init_frame();  
    make_frame(frame);   
    int flag = 0, 
    count = 1;
    Figure figuras[num];
    srand(time(NULL));   
    
    
    while(count < num ){  
        if(flag == 1){ 
            count++; 
            flag = 0; 
        } 
        if(flag == 0){  
            figuras[count].coordinate_line = random_coordinates(CHOSEN_LINE, CHOSEN_FIG1);     
            figuras[count].coordinate_column = random_coordinates(CHOSEN_COLUMN,CHOSEN_FIG1);
            #if DEBUG 
                printf("coordinates: %d %d \n", figuras[count].coordinate_line , figuras[count].coordinate_column );  
            #endif // DEBUG 
            flag = fill_fig1(frame, figuras[count].coordinate_line , figuras[count].coordinate_column); 
        } 
        #if DEBUG
            printf("count: %d \n", count );   
            printf("flag: %d \n", flag );   
                  
        #endif // DEBUG 
          
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
    make_frame(frame);

    while(count < num ){  
        if(flag == 1){ 
            count++; 
            flag = 0; 
            #if DEBUG
                printf("count: %d \n", count );    
            #endif // DEBUG  
        } 
        else if(flag == 0){  
            printf("N");
            figuras[count].coordinate_line = random_coordinates(CHOSEN_LINE, CHOSEN_FIG2);     
            figuras[count].coordinate_column = random_coordinates(CHOSEN_COLUMN,CHOSEN_FIG2);
            #if DEBUG 
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
    
    // verificar espaco 
    frame[line_min][column_min] = (char) '*';  
    frame[line_min][column_max] = (char) '*'; 
    frame[line_min + 1][column_min + 1] = (char) '*';
    frame[line_max-1][column_min] = (char) '*';  
    frame[line_max-1][column_max] = (char) '*'; 
    
    flag = 1 ;   
    return flag ; 

} 
/*__________________________________________________________________________________________________________________________________*/ 
void fig3(int num){ 
    srand(time(NULL));   
    int count = 0,   
    flag = 0;
    Figure figuras[num];   
    char **frame = init_frame();  
    make_frame(frame);
   
    while(count < num ){  
        if(flag == 1){ 
            count++; 
            flag = 0; 
            #if DEBUG
                printf("count: %d \n", count );    
            #endif // DEBUG  
        } 
        else if(flag == 0){  
            figuras[count].coordinate_line = random_coordinates(CHOSEN_LINE, CHOSEN_FIG3);     
            figuras[count].coordinate_column = random_coordinates(CHOSEN_COLUMN,CHOSEN_FIG3);
            #if DEBUG 
                printf("coordinates: %d %d \n", figuras[count].coordinate_line , figuras[count].coordinate_column );  
            #endif // DEBUG 
            flag = fill_fig3(frame, figuras[count].coordinate_line , figuras[count].coordinate_column); 
        }
          
    }
    
    print_frame(frame); 
 }  

/*__________________________________________________________________________________________________________________________________*/
void random_fig(int num ){
    srand(time(NULL));   
    int count = 0,   
    flag = 0;
    Figure figuras[num];   
    char **frame = init_frame();  
    make_frame(frame); 
    int choose = 0 ; 
   
    while(count < num ){  
        if(flag == 1){ 
            count++; 
            flag = 0; 
            #if DEBUG
                printf("count: %d \n", count );    
            #endif // DEBUG  
        } 
        else if(flag == 0){  
            figuras[count].coordinate_line = random_coordinates(CHOSEN_LINE, CHOSEN_FIG3);     
            figuras[count].coordinate_column = random_coordinates(CHOSEN_COLUMN,CHOSEN_FIG3); 
            choose = (rand() % 
            (4 + 1 - 1 )) + 1;  
            #if DEBUG 
                printf("coordinates: %d %d \n", figuras[count].coordinate_line , figuras[count].coordinate_column );  
            #endif // DEBUG  
            switch (choose)
            {
            case 1: 
                flag = fill_fig1(frame, figuras[count].coordinate_line , figuras[count].coordinate_column); 
                break;
            case 2:
                flag = fill_fig2(frame, figuras[count].coordinate_line , figuras[count].coordinate_column); 
                break;
            case 3: 
                flag = fill_fig3(frame, figuras[count].coordinate_line , figuras[count].coordinate_column); 
                break; 
            case 4: 
                flag = fill_create_fig(frame, figuras[count].coordinate_line , figuras[count].coordinate_column); 
                break;
            
            
            default:
                break;
            }
            
        }
          
    }
    
    print_frame(frame); 
 }  
/*__________________________________________________________________________________________________________________________________*/
int fill_create_fig(char **frame, int coordinate_line , int coordinate_column){ 
    int line_min,  
    line_max,  
    column_min, 
    column_max, 
    flag = 0 ;   

    line_min = coordinate_line, line_max = line_min + 5; 
    column_min = coordinate_column, column_max = column_min + 5; 
    int coor_aux = 0 ; 
    

    // Arvore  
    /* 
        * 
       *** 
      ***** 
    */
    for(int i = line_max; i > line_min; i--){ 
            coor_aux = line_max  - i ;    
        for(int j = column_min + coor_aux ; j < column_max - coor_aux ; j++){  
            frame[i][j] = (char) '*';  
        } 
    }

    flag = 1 ;   
    return flag ; 

 }
/*__________________________________________________________________________________________________________________________________*/
void create_fig(int num){  
    srand(time(NULL));   
    int count = 0,   
    flag = 0;
    Figure figuras[num];   
    char **frame = init_frame();  
    make_frame(frame);
   

    while(count < num ){  
        if(flag == 1){ 
            count++; 
            flag = 0; 
            #if DEBUG
                printf("count: %d \n", count );    
            #endif // DEBUG  
        } 
        else if(flag == 0){  
            printf("N");
            figuras[count].coordinate_line = random_coordinates(CHOSEN_LINE, CHOSEN_FIG4);     
            figuras[count].coordinate_column = random_coordinates(CHOSEN_COLUMN,CHOSEN_FIG4);
            #if DEBUG 
                printf("coordinates: %d %d \n", figuras[count].coordinate_line , figuras[count].coordinate_column );  
            #endif // DEBUG 
            flag = fill_create_fig(frame, figuras[count].coordinate_line , figuras[count].coordinate_column); 
        }
          
    }
    
    print_frame(frame); 

} 

/*__________________________________________________________________________________________________________________________________*/
