#include "frame.c" 
// by Guilherme Aguiar S M 

/*__________________________________________________________________________________________________________________________________*/
void select(){ 
    menu();  
    srand(time(NULL)); 
    int fig =  0; 
    int num = 0;     
     
    while(fig != 6 ){  

        printf("Digite o tipo de figura basica desejada: ");
        scanf("%d",&fig);  
        if(fig == 6) return;
        if (fig < 1  || fig > 6 )  printf("______________Digito invalido______________\n");
        
        else {
            
            printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio): ");
            scanf("%d",&num); 
            if(num >= 100 ) num = 100 ;
            if (num == 0) num = (rand() % (100 + 1 - 1 )) + 1; 
            
            printf("Valores: tipo de figura: %d, número de figuras: %d \n\n",fig,num); 

            switch (fig)
            {
            case 1:
                fig1(num);
                break;
            case 2:
                fig2(num);
                break;
            case 3:
                fig3(num);
                break;
            case 4:
                random_fig(num);
                break; 
            case 5:
                create_fig(num);
                break; 
            
            
            default:
                break;
            } 
        } 
    }
} 

/*__________________________________________________________________________________________________________________________________*/
void menu(){ 
    #if DEBUG
        printf("\n===== DEBUG ======\n");
    #endif // DEBUG 
    printf("PROGRAMA GERADOR DE OBRA DE ARTE:\n=================================\nEscolha o tipo de figura basica a ser usada para criar a obra:\n");  
    printf("1 - asterisco simples.\n2 - simbolo de soma com asteriscos.\n3 - letra X com asteriscos.\n4 - figuras aleatorias\n5 – opcao de obra de arte criada pelo aluno\n");  
    printf("6 - para SAIR\n");  

}  

/*__________________________________________________________________________________________________________________________________*/
int random_coordinates(int choose, int fig){  
    
    int lower, upper;   
    int conf = 0 ;  
    switch (fig)
    {
    case CHOSEN_FIG1:
        conf = 2 ; 
        break;
    case CHOSEN_FIG2:
        conf = 4 ; 
        break;     
    case CHOSEN_FIG3:
        conf = 4 ; 
        break;     
    case CHOSEN_FIG4:
        conf = 6 ;  
        break;    
    default:
        break;
    }  
    
    if(choose == CHOSEN_LINE){ 
        lower = 2 ;  
        upper = line - conf ;
        int num = (rand() % 
            (upper + 1 - lower )) + lower; 
        return num;
    } 
    else if(choose == CHOSEN_COLUMN){ 
        lower = 2 ;  
        upper = column - conf ;
        int num = (rand() % 
            (upper + 1 - lower )) + lower; 
        return num;
    }
    return 0 ; 
} 
/*__________________________________________________________________________________________________________________________________*/
char **init_frame(){ 
    char **frame = (char**)malloc(line *sizeof(char*)); 
    for(int i = 0 ; i < line; i++){ 
        frame[i] = (char*)malloc(column*sizeof(char));
    } 
    return frame ; 
}
