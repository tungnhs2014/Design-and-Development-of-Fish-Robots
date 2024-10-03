#include 	<mysql.h>
#include  	<stdio.h>
#include	<stdlib.h>
#include	<stdint.h>	
#include	<time.h>
#include    <wiringPi.h>
#include 	<errno.h>
#include 	<wiringSerial.h>
#include    <string.h>

int main()
{
    MYSQL *conn;
    MYSQL_RES *res1;
    MYSQL_ROW row1;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char *server = "localhost";
    char *user = "tung";
    char *password = "tunga239"; /* set me first */
    char *database = "robot_fish";
    // setup thu vien wiringPi
    //wiringPiSetup();
    int fd;
	fd = serialOpen ("/dev/ttyS0", 9600);
	char sql[200];
    // Khai bao IO, interrupt, softPWM
	char *data1;
	char *data2;
	char *ktra;
	
    while(1){
        
	    conn = mysql_init(NULL);
        mysql_real_connect(conn,server,user,password,database,0,NULL,0); 
        // kiem tra cot isUpdated
        sprintf(sql, "select * from envData where id>((select max(id) from envData)-5)");
        mysql_query(conn,sql);
        res1 = mysql_store_result(conn); 	
        row1 = mysql_fetch_row(res1);
		mysql_query(conn, sql);
        mysql_close(conn);		
		
        // ket noi database
        conn = mysql_init(NULL);
        mysql_real_connect(conn,server,user,password,database,0,NULL,0); 
        // kiem tra cot isUpdated
        sprintf(sql, "select * from settime");
        mysql_query(conn,sql);
        res = mysql_store_result(conn); 	
        row = mysql_fetch_row(res); 
        // NOTES: row la bien dang chuoi ky tu
        data1 = row[0];
		data2 = row[1];	
		ktra = row1[4];
				if(strcmp(data1, ktra)==0){ //so sanh time on
				serialPuts(fd, "1");
				serialFlush(fd);
				
				}
				if(strcmp(data2, ktra)==0){//so sanh time off
				serialPuts(fd, "0");
				serialFlush(fd);	
				}
		
		mysql_query(conn, sql);
        mysql_close(conn);	
		delay(1000);		
    }
	serialClose(fd);
    return 0;
}
//Bien dich code
/* gcc -o time $(mariadb_config --cflags) time.c $(mariadb_config --libs) -lwiringPi*/
