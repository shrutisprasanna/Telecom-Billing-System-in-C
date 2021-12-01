
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>

struct client
{
char no[10];
char name[50];
float amt; //To be calculated
int type;
int min;

}s;

void insert();
void display();
void modify();
void modify1();
void del();
int search(char *);
int pack1(int);
int pack2(int);
int pack3(int);
int selectpack();
void payment();
//char get;




void main()
{
   system("cls");
   printf("\n\n\n\n\n\n\n\n\n**************************************************************");
   printf("\n\t\t------TELECOM BILLING MANAGEMENT SYSTEM---");
   printf("\n\t\t****************************************************************");
   printf(“\n\t\t\t\t\t\t\t\t\t\t By : Keerthana S - 132”);
    printf(“\n\t\t\t\t\t\t\t\t\t\t By : Shruti S.P - 107”);
   printf(“\n\t\t\t\t\t\t\t\t\t\t By : Subha R - 112”);
  
   Sleep(2000);
   getch();
   system("cls");
   int z,ch;
   char password[20],no[10]; 
   printf("\n\n\n 1.LOGIN as ADMIN \n\n\n 2.LOGIN as USER \n\n\n 3.EXIT \n\n\n Enter     choice:");
   scanf("%d",&z);
   switch(z)
   {
      case 1:
             passwd:
             printf("Enter password:\n"); 
             int p=0; 
             do{ 
                     password[p]=getch(); 
                     if(password[p]!='\r')
                     { 
                         printf("*"); 
                     } 
                     p++; 
                }while(password[p-1]!='\r'); 
              password[p-1]='\0'; 
              if(strcmp(password,"pass")!=0)
              {
                  printf("\n Wrong password..Access denied!!Try again..");
                  goto passwd;
              }
              else
              {
                  do
                  {
                            system("cls");
		     printf("\n 1 : For adding new records.\n 2 : for list of records");
		     printf("\n 3 : for modifying records.");
		     printf("\n 4 : for searching records.");
		     printf("\n 5 : for deleting records.\n 6 : To log out \n Enter choice:");
                            scanf("%d",&ch);
                            switch(ch)
		     {
			case 1:
				insert();break;
			case 2:
				display();break;
			case 3:
				modify1();break;
			
			case 4:
                                               printf("Enter Phone Number to search in our database");
	                                   scanf("%s", no);
				int z1=search(no);break;
			case 5:
				del();break;
			case 6:
				system("cls");
				printf("\n\n\t\t\t\tTHANK YOU");
				Sleep(2000);
				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\nAny key to continue");
				getch();
                       }
                    }while(ch!=7);
                 }
                 break;
      case 2:
                  do
                  {
                        system("cls");
	             printf("\n 1 : For name and pack modification");
		 printf(“\n 2 : Display user details”);
	             printf("\n 3 : Exit \n Enter choice:");
	             scanf("%d",&ch);
                         switch(ch)
		     {
			case 1:modify();break;
			case 2: 
			printf(“Enter phone number of user:”);
			scanf(“%s”,&no);
int search(char* no)
break;
			
			case 3:
                                               system("cls");
				printf("\n\n\t\t\t\tTHANK YOU");
				printf("\n\n\n\n\n:\n\tFOR USING OUR SERVICE");
				Sleep(2000);
				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\nAny key to continue");
				getch();
                      }
                 }while(ch!=3);
                 break;
       case 3:
		system("cls");
		printf("\n\n\t\t\t\tTHANK YOU");
		Sleep(2000);
		exit(0);
		break;
           default:
		system("cls");
		printf("Incorrect Input");
		printf("\nAny key to continue");
		getch();
  }
}
void insert()
{
	FILE *f;
	char test;
	f=fopen("c:/file.ojs","ab+");
	if(f==0)
	{           f=fopen("c:/file.ojs","wb+");
		system("cls");
		printf("please wait while we configure your computer");
		printf("/npress any key to continue");
		getch();
	}
	while(1)
	{
		system("cls");
		printf("\n Enter phone number:");
		scanf("%s",&s.no);
                       int z=search(s.no);
                       if(z==0)
                       {
		printf("\n Enter name:");
		fflush(stdin);      
		scanf("%[^\n]",&s.name);  //Inputting a line
		printf("\n Enter pack type:");
		s.type=selectpack();
		printf("\n Enter talk-time minutes:");
		scanf("%d",&s.min);
		fwrite(&s,sizeof(s),1,f);
                       }
                       else
                           printf(“\n Number already found!!Cannot add record”);
		fflush(stdin);
		system("cls");
		printf("Record added");
		printf("\n Press esc key to exit, any other key to add other record:");
		test=getche();
		if(test==27)   //Ascii value of escape character
			break;
	}
	fclose(f);
}
void display()
{
	FILE *f;
	int i;
	if((f=fopen("c:/file.ojs","rb"))==NULL)
		exit(0);
	system("cls");
	printf("Phone Number\t\tUser Name\t\tPack Type\t\tTalk-time Minutes\t\tAmount\n");
	for(i=0;i<79;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1)
	{
		printf("\n%-10s\t\t%-10s\t\tPack %d\t\t%d minutes\t\tRs. %.2f /n",s.no,s.name,s.type,s.min,s.amount);  //slight edit
	}
	printf("\n");
	for(i=0;i<79;i++)
		printf("-");

fclose(f);
getch();
}
void del()
{
	FILE *f,*t;
	int i=1;
	char no[10];
	if((t=fopen("c:/temp.ojs","w+"))==NULL)
	exit(0);
	if((f=fopen("c:/file.ojs","rb"))==NULL)
	exit(0);
	system("cls");
	printf("Enter the phone number to be deleted from the Database");
	fflush(stdin);
	scanf("%[^\n]",no);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.no,no)==0)
		{       i=0;
			continue;

		}
		else
			fwrite(&s,sizeof(s),1,t);   
	}
	if(i==1)
	{       system("cls");
		printf("Phone number \"%s\" not found",no);
		remove("c:/file.ojs");
		rename("c:/temp.ojs","c:/file.ojs");
		getch();
		fclose(f);
		fclose(t);
		main();
	}
	remove("c:/file.ojs");
	rename("c:/temp.ojs","c:/file.ojs");
	system("cls");
	printf("Client Number %s Deleted!!",no);
	fclose(f);
	fclose(t);
	getch();
}
int search(char* no)
{
	FILE *f;
	int flag=1;
	f=fopen("c:/file.ojs","rb+");
	if(f==0)
		exit(0);
	fflush(stdin);
	system("cls");
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.no,no)==0)
		{	system("cls");
			printf(" Record Found ");
			printf("\n\n Phone no: %s\nName: %s\nPack type: %d\nTalk-time                minutes\nAmount: Rs.%0.2f\n",s.no,s.name,s.type,s.min,s.amount);
			flag=0;
                                   return 1;
			break;
		}
            }
            if(flag==1)
	{	system("cls");
		printf("Phone Number Not found in database");
                        return 0;
	}
	getch();
	fclose(f);
}
void modify1()    //For Admin
{
	FILE *f;
	char no[10];
	long int size=sizeof(s);
	if((f=fopen("c:/file.ojs","rb+"))==NULL)
		exit(0);
	system("cls");
	printf("Enter phone number of the client to modify:");
	scanf("%[^\n]",no);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.no,no)==0)
		{
			system("cls");
			printf("\n Phone number being modified:%d",s.no);
			printf("\n Enter name: ");
			fflush(stdin);
			scanf("%[^\n]",&s.name);
			printf("\n Enter Talk-time minutes: ");
			scanf("%f",&s.min);
			printf(“Enter package type”);
			s.type=selectpack();
			payment();
			fseek(f,-size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	fclose(f);
}

void modify()    //For User
{
	FILE *f;
	char no[10];
	long int size=sizeof(s);
	if((f=fopen("c:/file.ojs","rb+"))==NULL)
		exit(0);
	system("cls");
	printf("Enter your phone number");
	scanf("%[^\n]",no);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.no,no)==0)
		{
			system("cls");
			printf("\n Phone number being modified:%d",s.no);
			printf("\n Enter name: ");
			fflush(stdin);
			scanf("%[^\n]",&s.name);
			printf(“Enter package type”);
			s.type=selectpack();
			payment();
			fseek(f,-size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,f);
			break;
		}
	}
	fclose(f);
}


int pack1(int talktime)
{
int price=0;
if(talktime<=100)                         	price=200;
else if(talktime>100 &&talktime<=200)
{
price=200+(talktime-100)*0.5;
}
else if(talktime>200)
{
price=250+(talktime-200)*0.4;
}
return price;
}
 
int pack2(int talktime)
{
int price=0;
if(talktime<=300)                         	price=250;
else if(talktime>300 &&talktime<=500)
{
price=250+(talktime-300)*0.4;
}
else if(talktime>500)
{
price=320+(talktime-200)*0.3;
}
return price;
}
 
 
 
int pack3(int talktime)
{
int price=0;
if(talktime<=360)                         	price=talktime*0.5;
else if(talktime>360)
{
price=180+(talktime-360)*0.4;
}
return price;
}

int selectpack()
{
printf(“The packs are based on talk time\t\t\tThe packs are as follows”);
printf(“\n Pack 1 \n Rs 200 for first 100 minutes \n Rs 0.5 for each minute for next 100 minutes\n Rs 0.4 for every minute afterwards\n”);
printf(“\n Pack 2 \n Rs 250 for first 300 minutes \n Rs 0.4 for each minute for next 200 minutes\n Rs 0.3 for every minute afterwards\n”);
printf(“\n Pack 3 For first 360 minutes- Rs 0.5 per minute\n Rs 0.4 for every following minute\n”);
printf(“Select 1,2,3 accordingly”);
int ch;  
scanf(“%d”,&ch);
return ch;
} 


void payment()
{
        	FILE *f;
        	char no[10];
        	long int size=sizeof(s);
        	float amount;
        	int i;
        	if((f=fopen("c:/file.ojs","rb+"))==NULL)
        	        	exit(0);
        	system("cls");
        	printf("Enter phone number of the client for payment");
        	scanf("%[^\n]",no);
        	fflush(stdin);
        	while(fread(&s,sizeof(s),1,f)==1)
        	{
        	        	if(strcmp(s.no,no)==0)
        	        	{
        	        	        	system("cls");
        	        	        	printf("\n Phone No.: %s",s.no);
        	        	        	printf("\n Name: %s",s.name);
                                	printf(“\n Package type : %d”,s.type);

                                	
                                	if(s.type==1)
                                	s.amount=pack1(s.min);                               
                                	if(s.type==2)
                                	s.amount=pack2(s.min);
                                	if(s.type==3)
                                	s.amount=pack3(s.min);
                                	printf(“The amount to be paid is : %f”,s.amount”);
        	        	        	printf("\n");    	
        	        	        	fflush(stdin);
        	        	        	fseek(f,-size,SEEK_CUR);
        	        	        	fwrite(&s,sizeof(s),1,f);
        	        	            break;
        	        	}
        	}

        	system("cls");     	
        	getch();
        	fclose(f);
}





