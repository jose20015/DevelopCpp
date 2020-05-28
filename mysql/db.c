/*
gcc db.c -o  1 `mysql_config --cflags --libs`

*/

#include<stdio.h>
#include<mysql.h>

void versaomysql();
int conexaodb( char user[100], char pass[100] );
void criardb( char user[100], char pass[100] );

int main(int argc, char **argv ){

    //versaomysql();
    
    //conexaodb("root", "c");
    criardb("root", "c" );
   

return 0;
}


void versaomysql(){
    printf("\n\n\t\tMysql cliente version: %s\n\n ", mysql_get_client_info());
}

int conexaodb( char user[100], char pass[100] ){
    
    
  MYSQL *con = mysql_init(NULL);
  
  if (con == NULL) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
  }

  if (mysql_real_connect(con, "localhost", user, pass, NULL, 0, NULL, 0) == NULL) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }
  
  return 1;      
}

void criardb( char user[100], char pass[100] ){
    
    int conexaodb( char user[100], char pass[100] );
    
    
    if( conexaodb() == 1 ){
    
         if (mysql_query(con, "CREATE DATABASE testdb")){
          fprintf(stderr, "%s\n", mysql_error(con));
          mysql_close(con);
          exit(1);
        }

         mysql_close(con);
    
    }
    else{ printf("\t\t\n\nErro na Conexão\n\n");}
}
