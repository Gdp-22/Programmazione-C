// file run_test_ordina_array.c

# include <stdio.h>
# include <stdlib.h>
# include "vettore.h"
# include <string.h>

# define M 20

int run_test_case(char *tc_id, int n){
    char *input_fname,* output_fname,* oracle_fname;	

    // costruiamo i nomi dei file
    input_fname="_input.txt";
     output_fname="_output.txt";
    oracle_fname="_oracle.txt";
   char *input,*output,*oracle; 
  input=strcat(tc_id,input_fname);
  output=strcat(tc_id, output_fname);
  oracle=strcat(tc_id, oracle_fname);

    // allochiamo memoria per array di input
    int *array=calloc(n,sizeof(int));
 
    // carica file di input
    finput_array(input,array,n);
    // ordina array
    ordina(array,n);
    //  scrive file di output
   foutput_array(output,array,n);
 
    // allochiamo memoria per array oracolo
    int *array_oracle=calloc(n,sizeof(int));

    // carichiamo oracolo
    finput_array(oracle,array_oracle,n);
    // confrontiamo array
          

    return confronta_array(array,array_oracle,n);	    
}

int main(int argc, char *argv[]) 
{ 	
    FILE *test_suite;
    FILE *result;  
    char tc_id[M];  // stringa contenente l'identificativo del test case
    int n, pass;
    
    if(argc < 3){
         printf("Nomi dei file mancanti \n");
         exit(1);
    }    
    
    test_suite = fopen(argv[1],"rt");  // apro file contenente test suite               
    result = fopen(argv[2], "wt");   // apro file contenente risultati test        
    
  if( test_suite==NULL || result == NULL ) {
        printf("Errore in apertura dei file \n");    
       exit(1);
    }
     
    /* Scansione del file di input nel ciclo while. 
    Ad ogni iterazione si leggono i due elementi di una riga:
    l'identificativo del test case tc_id e il numero n di elementi
    da ordinare */
    
    while(fscanf(test_suite, "%s%d", tc_id, &n) == 2){
         pass = run_test_case(tc_id, n);
    
         fprintf(result,"%s ", tc_id);
         if(pass == 1)
               fprintf(result, "PASS \n");
         else   
               fprintf(result, "FAIL \n");			
         }	
    
    fclose(test_suite);  // chiusura file di input
    fclose(result);         // chiusura file di output
}


