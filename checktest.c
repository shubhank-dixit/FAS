#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include "segment.c"
#define ENTER 13 //micro def
#define space 8
int main(void)
{
    int choose;

    printf("enter 1 for register and 2 for login \n");
    scanf("\n%d",&choose);
    switch(choose)
    {
    case 1:
    reg();
    break;
    case 2:
    login();
    break;
    default:
        printf("wrong choice\n");
    }
    return 0;

}
/**************************************************************************************************************************/
reg()
{
    int age,year,i=0,j=0;
    FILE *ftr;
    char name[30], password[15],email[40],conpassword[15],ch,ch1,sapid[10];
    printf("\tHELLO WELCOME TO FAS\n");
    printf("\tKINDLY PROVIDE YOUR INFORMATION\n");
    ftr=fopen("details.txt","a");
    printf("Enter name\n");
    scanf("%s",&name);

    printf("Enter age\n");
    scanf("%d",&age);

    printf("Enter year of admission\n ");
    scanf("%d",&year);

    printf("enter your email id for backup\n");
    scanf("%s",&email);

    printf("enter your sap id and password\n");
    scanf("%s",&sapid);

    while(1) //infi loop
    {
        ch=getch(); //
        if(ch==ENTER)
        {
            password[i]='\0';
            break;

        }
        else if(ch==space)
        {
            i--;
            printf("\b \b");
        }
        else{
            password[i]=ch;
            i++;
            printf("*");
        }

    }
    printf("\nre-enter your password for confirmation\n");
    while(1)
    {

        ch1=getch();
        if(ch1==ENTER)
        {
            conpassword[j]='\0'; //null charater
            break;
        }
        else if(ch1==space)
        {
            j--;
            printf("\b \b");
        }
        else
        {
            conpassword[j]=ch1;
            j++;
            printf("*");

        }
    }

    if(strcmp(conpassword, password)==0)
    {
      fprintf(ftr,"%s %s %d %d %s %s \n",sapid, name, age, year, email, password);
        fclose(ftr);
        printf("\nregistration successful\n ");


    }
    else
    {
        printf("registration not completed\n");
    }

}
/* *************************************************************************************** */
login()
{
  FILE *fp;
  int j=0,i=0,p=0;
  char line[200],searchpass[20],sapid[10],ch1;
  char search[]="ddn";
  char *temp;
  printf("enter id\n");
  scanf("%s",&sapid);
  printf("enter password\n");
  while(1)
  {

      ch1=getch();
      if(ch1==ENTER)
      {
          searchpass[j]='\0';
          break;
      }
      else if(ch1==space)
      {
          j--;
          printf("\b \b");
      }
      else
      {
          searchpass[j]=ch1;
          j++;
          printf("*");

      }
  }
  fp=fopen("details.txt","r");
  while ( fgets ( line, 200, fp ) != NULL )
  {
          if(strstr(line,searchpass))
          i++;
  }
  fclose ( fp );
  if(i>0)
  {
    printf("\nlog in successful\n");
    temp=strstr(sapid,search);
    if(temp!=NULL)
    {
      p++;
    }
   welcome(p);
  }
  else
  {
    printf("\n log in unsuccessful");
  }
  return 0;
}


/* ******************************************************************************************  */
 welcome(int x)
{
  int school, depeng,depcs,depbus,dephs,depcsfac, arr[100], num;
  FILE *ftr;
  char c;
  int l=x;
  if(l>0)
  {
  printf("\n\t****Faculty login****");
}
  printf("\n\t WELCOME TO UPES FACULTY APPONTMENT SYSTEM");
  printf("\n\t  School names are as follow:- ");
  printf("\n 1. School of Engineering");
  printf("\n 2. School of Computer Science");
  printf("\n 3. School of Law");
  printf("\n 4. School of Design ");
  printf("\n 5. School of Business");
  printf("\n 6. School of Health Science");
  printf("\n Please enter your school number\n");
  scanf("%d",&school);
  switch (school) {
    case 1:
      printf("\n\t Welcome to School of Engineering");
      printf("\n\t VISION ");
      printf("\n'To be a forerunner in engineering education by delivering excellent engineering graduates fortified with sound knowledge and integrity, by performing cutting-edge research and by innovating new technologies to benefit the nation and the world at large'");
      printf("\n\n\n 1. Department of Aerospace engineering");
      printf("\n 2. Department of applied science");
      printf("\n 3. Department of Applied Science");
      printf("\n 4. Department of Chemical Engineering");
      printf("\n 5. Department of Mechanical Engineering");
      printf("\n 6. Department of Electrical and Electronics Engineering");
      printf("\n 7. Department of petroleum ");
      printf("\n 8. please choose Department number\n");
      scanf("\n%d",&depeng);
      printf("\nSorry no record let the university enter record in it. See you later");
      if(l>0)
      {
       printf("\nHello admin, Please enter no of factulties you want to enter");
       scanf("%d\n",&num);
      // hashing(num);
       }
     switch(depeng)
      {
        }
      break;
      case 2:
      printf("\n\t Welcome to School of Computer Science");
      printf("\n\t VISION ");
      printf("\n To become a multidisciplinary, industry-oriented department of repute, through academic initiatives, creative learning and innovation");
      printf("\n\n\n 1. Department of Systematics");
      printf("\n 2. Department of Informatics");
      printf("\n 3. Department of cybernetics ");
      printf("\n please choose your Department number\n");
      scanf("\n%d",&depcs);
      switch (depcs) {
        case 1:
        printf("\n\t Welcome to Department of Systematics");
        printf("\n\t List of FACULTY :- ");
        printf("\n\n\n 1.  Neeraj Chugh  ");
        printf("\n 2. Bhavna Kasuhik ");
        printf("\n 3. Prashant Rawat ");
        printf("\n 4. Dr. Neelu J. Ahuja ");
        printf("\n 5. Saurabh Jain ");
        printf("\n 6. Deepa Joshi ");
        printf("\n 7. Sumit Kumar " );
        printf("\n 8. Ankit Vishnoi " );
        printf("\n 9. Roohi Sille " );
        printf("\n 10. Varun Sapra " );
        printf("\n 11. S. Christalin Nelson ");
        printf("\n 12. Dr. Mrinal Goswami");
        printf("\n 13. Alok Jhaldiyal ");
        printf("\n choose FACULTY \n");
        scanf("%d",&depcsfac);
        switch (depcsfac) {
          case 1:
          printf("\n mr. Neeraj chugh Schuduele is as follow\n");
          ftr=fopen("time.txt","r");
          if( ftr== NULL)
          {
            printf("\n cannot open file");
          }
          else
          {
            while(c!=EOF)
            {
              printf("%c",c);
              c=fgetc(ftr);
            }
            fclose(ftr);
          }
          appointmentfunc(l);

          break;
        }
        break;
      case 3:
      printf("\n\t Welcome to School of Law");
      break;
      case 4:
      printf("\n\t Welcome to School of Design");
      printf("\n\t VISION0");
      printf("\nTo be internationally recognized School of Design nurturing creative professionals for nation building");
      break;
      case 5:
      printf("\n\t Welcome to School of Business");
      printf("\n\t VISION");
      printf("\n To be a leading global business school known for developing professionals through excellent outcome based learning.");
      printf("\n\n\n 1. Department of Economics and International Business");
      printf("\n 2. Department of Energy Management ");
      printf("\n 3. Department of General Management");
      printf("\n 4. Department of Transportation Management");
      printf("\n Please choose department number");
      scanf("%d",&depbus);
      //switch (/* expression */) {
        //case /* value */:
      //}
      break;
      case 6:
      printf("\n\t Welcome to School of Health Science ");
      printf("\n\t VISION");
      printf("\nLeadership in health sciences education and research through inspirational learning environment for improving health and wellbeing" );
      printf("\n\n\n 1. Department of Allied Health Science");
      printf("\n 2. Department of Pharmaceutical Science");
      printf("\n please choose department number");
      scanf("\n%d",&dephs);
      //switch (/* expression */) {
      //  case /* value */:
      //}


  }
}
}
