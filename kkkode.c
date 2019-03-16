#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
//char password[10];
//char userid[10];
int t[5]={20,10,30,40,23};
void Dequeue();
void Enqueue(int x,long time);

struct node1
 {   int id,phno;
     char pass[10];
     char name[20];
     char address[50];
     char report[100];
     struct node1* link;
 };
 struct node1 *ptr1,*header1,*new1;

 struct node2
{
 int hid;
 char hname[20];
 struct node2* link;
 };
 struct node2 *ptr2,*header2,*new2;

struct patient
 {
   char name[20];
   int id;
  char address[20];
   int phno;
   //char doctor[20];
   char report[100];
}p[5];
struct node3
{
  int dId;
  char docname[20];
  int hosid;
  char spec[20];
  int avgt;
struct node3* link;
};
struct node3 *header3,*ptr3,*new3;
struct Node {
    int data;
    long time;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;



/*
 void getdata_patient(struct patient *p,int id)
  {
   int a,i;
   printf("enter the information of patient:\n");
   for(i=0;i<5;i++)
   {
   printf("enter name");
    scanf("%s",p[i].name);
    printf("enter the address");
    scanf("%s",p[i].address);
     printf("enter the phone number");
    scanf("%d",&p[i].phno);
    printf("enter the doctor name");
    scanf("%s",p[i].doctor);
     printf("\n");
   }
   }*/

//*********************************
void printdata(int id)
 {
  int c=0,i;
//  printf("Enter the id no");
 // scanf("%d",&id);
ptr1=header1->link;
  while(ptr1!=NULL)
  {
   if(ptr1->id==id)
    {
     
      printf("Name = %s",ptr1->name);
      printf("Address = %s",ptr1->address);
      printf("Phone number = %d",ptr1->phno);
    }
     else
       printf("invalid id");
  }
 }

//************************************
int insert_patient()
 {
   int id,phno;
 char pass1[20];
   char name1[20];
   char add[50];
  new1=(struct node1*)malloc(sizeof(struct node1));
   printf("\nEnter the user id");
   scanf("%d",&id);
  printf("\nEnter the password");
  scanf("%s",pass1);
  printf("\nEnter the name");
  scanf("%s",name1);
  printf("\nEnter the address : ");
  scanf("%s",add);
  printf("\nEnter the phno : ");
  scanf("%d",&phno);
  new1->id=id;
 strcpy(new1->pass,pass1);
  strcpy(new1->name,name1);
  strcpy(new1->address,add);
  new1->phno=phno;
  if(header1==NULL)
   {
   header1=new1;
  }
  else
  {
    ptr1=header1;
    while(ptr1!=NULL)
    {
      ptr1=ptr1->link;

    }
    ptr1=new1;
    ptr1->link=NULL;
  }
  return id;
}

//*****************************
void doc_entry()
{
  int d_id,t;
  char dname[20];
  char spec[20];
  new3=(struct node3*)malloc(sizeof(struct node3));
  printf("\nEnter the doctor id : ");
  scanf("%d",&d_id);
  printf("\nEnter the doctor nmae : ");
  scanf("%s",dname);
  printf("\nEnter the doctor specialisation : ");
  scanf("%s",spec);
  printf("Enter the average consultation time : ");
  scanf("%d",&t);
  new3->dId=d_id;
 strcpy( new3->docname,dname);
 strcpy( new3->spec,spec);
  new3->avgt=t;
  if(header3->link==NULL)
  {
    header3->link=new3;
    new3->link=NULL;
  }
  else
  {
    ptr3=header3;
    while(ptr3->link!=NULL)
    {
      ptr3=ptr3->link;
    }
    ptr3->link=new3;
    new3->link=NULL;
  }
  
}

//*****************************

void doc_platform(int id)
{char report1[100];
  header1=ptr1;
  
  while(ptr1!=NULL)
  {
    if(ptr1->id==id)
    {
      strcpy(report1,ptr1->report);
    }
  }
}
//*****************************

void alert(int time)
{
    if(time<10)
        printf("please arrive at time %d",time+10);
    else if(time<20)
        printf("next token will be you,Be ready");
    else
        printf("wait");

}



//****************************
int booktickets(int id)
{
  int d_id,i,temp,sec,less;
  int time;
  //printf("\nEnter the id  ");
 // scanf("%d",&id);
 printf("Enter the doctor id you wish to consult : ");
scanf("%d",&d_id);
 printf("\nEnter the time you wish to consult ");
  scanf("%d",&time);
  Enqueue(id,time);
alert(time);

 /* for(i=0;i<5;i++)
  {
    if(t[i]<t[q])
    {
      temp=t[i];
      t[i]=t[q];
      t[q]=temp;
    }
  }
  printf("next patient is %d",t[0]);
  time_t mytime,ct;
  mytime=time(NULL);
  ct=(ctime(&mytime));*/
}
//*****************************
 int recipt (int d_id , long time) {
int i=0;

   ptr3=header3->link;
   while(ptr3->link!=NULL)
   {
     if(ptr3->dId==d_id)
     i=i+1;
     printf("\nDoctor Name : %s",ptr3->docname);
     printf("\nTocken no : %d ",i);
     //printf("\nCunsultation time = ")
     Dequeue();
   }
return 0;
 }

//*****************************
void hos_signup()
{
  char hname[20];
  int id;
char ch;
 header2->link=ptr2;
 new2=(struct node2*)malloc(sizeof(struct node2));
 printf("\nEnter the hospital name : ");
 scanf("%s",hname);
 printf("\nEnter the hospital id : ");
 scanf("%d",&id);
 new2->hid=id;
 strcpy(new2->hname,hname);
 if(ptr2==NULL)
 {
   ptr2=new2;
   ptr2->link=NULL;
 }
 else
 {
   while(ptr2->link!=NULL)
   {
     ptr2=ptr2->link;
   }
   ptr2=new2;
 }
 do
 {
 printf("\nEnter the doctor details one by one");
 doc_entry();
 printf("Do you want to continue y/n");
 scanf("%c",&ch);
}while(ch=='y');
}
//***************************
 void signin(int userid,char password[20])
{
	int flag=0;
	
  ptr1=header1->link;
if(header1==NULL)
{
	printf("Account not found");
 }
else
{
  while(ptr1!= NULL)
   {
    if(((ptr1->id)==userid) && ((ptr1->pass)==password))
    {
	flag=1;
	printf("%d",flag);
      // booktickets(userid);
    }
     ptr1=ptr1->link;
  }
}
}
 //*****************************

 void Enqueue(int x,long time) {
    struct Node* temp =
        (struct Node*)malloc(sizeof(struct Node));
    temp->data =x;
    temp->time=time;
    temp->next = NULL;
    if(front == NULL && rear == NULL){
        front = rear = temp;
    }
    else
    {
    rear->next = temp;
    rear = temp;
    }
}
//*******************************
void Dequeue() {
    struct Node* temp = front;
    if(front == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    if(front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->next;
    }
    printf("patien is %d",temp->data);
    free(temp);
}

int Front() {
    if(front == NULL) {
        printf("Queue is empty\n");
        return 0;
    }
    return front->data;
}
//******************************

int main()
  {
  int id,a,m,c,luid;
  char lpw[20];
  header1=(struct node1*)malloc(sizeof(struct node1));
  header1=NULL;
  header2=(struct node2*)malloc(sizeof(struct node2));
  header2=NULL;
  header3=(struct node3*)malloc(sizeof(struct node3));
  header3=NULL;
do{ 
 printf("\n Choose from the menu");
  printf("1. sign in\n2. sign up\n3. get details \n4.booking\n5.sign out");
  printf("enter the choice");
   scanf("%d",&a);
  
 switch(a)
 {
    case 1:printf("\nEnter userid :");
            scanf("%d",&id);
            printf("\nEnter password :");
            scanf("%s",lpw);
            signin(id,lpw);
          break;
    case 2: printf("\nEnter 1 for patient signup or 2 for patient signup");
          scanf("%d",&c);
          switch(c)
          {
            case 1:insert_patient();
            break;
            case 2:hos_signup();
            break;
          }
          break;
    case 3:printf("enter your id");
        scanf("%d",&id);
		printdata(id);
          break;
    case 4:printf("enter your id");
        scanf("%d",&id);
	booktickets(id);
          break;
	case 5:
		exit(0);
    default :
		printf("Wrong Entry\n");
 }
}while(1);
 }
