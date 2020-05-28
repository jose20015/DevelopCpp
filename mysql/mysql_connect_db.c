#include<stdio.h>
#include<mysql.h>

int main(int argc, char **argv)
{
	printf("Mysql Client version: %s\n", mysql_get_client_info());

return 0;
}
