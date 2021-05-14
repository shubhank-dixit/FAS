appointmentfunc(float p)
{
functions(p);
}
functions(int x)
{
  if(x>0)
  {
    printf("%d\n",x);
create_app();
}
else
{
display_SLL();

book_app();

cancel_app();
}
//sort_app();

return 0;
}
int nodes;
struct appoint
{
 int status;
 char start[10];
 char end[10];
 char max[10];
 char min[10];
 struct appoint *Next;
}*head;

void create_app()
{
    int i ;
    struct appoint *temp, *p;

    head = NULL;

    printf("\n\n How many Appointments");
    scanf("\n%d",&nodes);

    for(i=0; i<nodes; i++)
    {
     printf(" NEW APPOINTMENT ");
       temp =malloc(nodes * sizeof(struct appoint));  //Step 1: Allocate Memory
    temp->status=0;

       printf("\n\t Enter Start Time: ");
       scanf("\n%s",temp->start);
       printf("\n\t Enter End Time: ");
       scanf("\n%s",temp->end);
       printf("\n\t Enter min Time: ");
       scanf("\n%s",temp->min);
       printf("\n\t Enter max Time: ");
       scanf("\n%s",temp->max);

       temp->Next = NULL;

       if(head == NULL)   //Step 3: Attach node in linked List
       {
          head = temp;
          p = head;
       }
       else
       {
          p->Next = temp;
          p = p->Next;
       }

    }
    display_SLL();
    printf("\nAppointement created successfully\n");
    printf("Press any key to continue...");
    getch();
    system ("cls");
    main();

}

void display_SLL()
{
  FILE *ftr;
char c;
  struct appoint *p;

    p = head;
    printf("Status\tStart Time\tEnd Time\tMin Time\tMax Time\n");
    ftr=fopen("appoint.txt","a");
   /*if(ftr== NULL)
    {
      printf("\n cannot open file");
    }
    else
    {
      while(c!=EOF)
      {
        c=fgetc(ftr);
        printf("%c",c);

      }

    }
*/
    while(p != NULL)
    {
    if(p->status==0)
    {
    printf("Free");
  }
    else
    {
     printf("Booked");
 }
fprintf(ftr,"%s \t\t %s \t\t %s \t\t %s \t %s\n",p->status, p->start, p->end, p->min, p->max );
       printf("\t\t %s \t\t %s \t\t %s \t %s\n",p->start, p->end, p->min, p->max);

       p = p->Next;
    }

}
void book_app()
{
  FILE *ftr;
char time[10];
struct appoint *p;
printf("\n\n\tEnter The Time Slot");
scanf("\n%s",&time);
p=head;
 while(p!=NULL)
 {
  if(strcmp(time,p->start) == 0)
  {
    if(p->status == 0)
    {
     p->status=1;
     printf("Your Appointment Is Booked\n\n");
    }
    else
    printf("Appointment slot is Busy\n\n");
    break;
  }
  else
   p=p->Next;
 }

 if(p==NULL)
 printf("\n\n Appointment slot is Not available\n\n");
 display_SLL();

}

void cancel_app()
{
char time[10];
struct appoint *p;
printf("\n\n\tEnter Cancellation Time");
scanf("\n%s",&time);
p=head;
 while(p!=NULL)
 {
  if(strcmp(time,p->start) == 0)
  {
   if(p->status == 1)
    {
     p->status=0;
     printf("Your Appointment Is Cancelled\n\n");
    }
    else
    printf("Appointment slot is Busy\n\n");
    break;
   }
   else
   p=p->Next;
 }

 if(p==NULL)
 printf("\n\n Appointment slot is Not available\n\n");
 display_SLL();


}

/*void sort_app()
{
char str[10];
struct appoint *p;
int i;
for(i=0;i<nodes-1;i++)
 {
  p = head;
  while(p->Next!=NULL)
  {
   if(strcmp(p->start,p->Next->start)>0)
   {
    int tmp=p->status;
    p->status=p->Next->status;
    p->Next->status=tmp;

    strcpy(str,p->start);
    strcpy(p->start,p->Next->start);
    strcpy(p->Next->start,str);

    strcpy(str,p->end);
    strcpy(p->end,p->Next->end);
    strcpy(p->Next->end,str);

    strcpy(str,p->min);
    strcpy(p->min,p->Next->min);
    strcpy(p->Next->min,str);

    strcpy(str,p->max);
    strcpy(p->max,p->Next->max);
    strcpy(p->Next->max,str);
   }
   p=p->Next;
  }
 }
  printf("\n\nSORTED\n");
  display_SLL();
}*/
