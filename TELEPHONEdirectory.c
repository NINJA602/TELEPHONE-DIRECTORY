#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<conio.h>
struct T     //structure for storing each person's info
{
    char name[120];
    int number;
    char address[150];
};
void Display(struct T p)  //function which prints details of a struc. variable
{
    if(strlen(p.name)<8)
    {
    printf("\n\t%s\t\t\t%d\t\t\t%s",p.name,p.number,p.address);
    }
    else
    {
    printf("\n\t%s\t\t%d\t\t\t%s",p.name,p.number,p.address);
    }
}
void main()
{   system("COLOR 1F");
    char password[]="tele",enp[50],lqa[50],adminp[]="phone",adpp[50],adpr[50];
    struct T p,q;
    printf("\n\n\n\n\n");
    printf("\n\t\t\t\t\t\t\t\t\t...........WELCOME TO SHRABAN's TELEPHONE DIRECTORY...........");
    printf("\n\t\t\t\t\t\t\t\t\t                            (V 1.0)                             ");
    printf("\n\t\t\t\t\t\t\t\t\t--------------------------------------------------------------");
    printf("\n\t\t\t\t\t\t\t\t\t--------------------------------------------------------------");
    printf("\n                                                      ");
    printf("\n                                                      ");
    printf("\n                                                      ");
    printf("\n                                                      ");
    printf("\n\n\n");
    printf("\n\t\t\t\t\t\t\t\t\tEnter password : ");
    int uil=0;
    for(uil=0;uil<50;uil++)
    {
        enp[uil]=getch();
        if(enp[uil]=='\r')
        {
            break;
        }
        else
        {
            printf("*");
        }
    }
    uil=0;
    for(uil=0;uil<50;uil++)
    {
        if(enp[uil]!='\r')
        {
            lqa[uil]=enp[uil];
        }
        else
        {
            break;
        }
    }
    FILE *fp;
    fp=fopen("TD.DAT","ab+");
    int ck,c=0,gg,v=0,i;char ch='y',cn[100],cm[100],cq[100];
    int qa,qb;char py[1];int jjj=0,mkf=0,jz=0,mhx=0;
    if(strcmp(lqa,password)==0)
    {system("CLS");
    if(fp!=NULL)
    {
    while(1)
    {   system("COLOR 1F");
        printf("\n");
        printf("\n ____________________________________________________________");
        printf("\n|                                                            |");
        printf("\n|ACTIONS :                                                   |");
        printf("\n|-------                                                     |");
        printf("\n|1. Add info to the directory.                     (Enter 1) |");
        printf("\n|2. Print all the existing records.                (Enter 2) |");
        printf("\n|3. Delete info from the directory.                (Enter 3) |");
        printf("\n|4. Modify an existing record from the directory.  (Enter 4) |");
        printf("\n|5. View a record by searching with name.          (Enter 5) |");
        printf("\n|6. View a record by searching with number.        (Enter 6) |");
        printf("\n|7. View names starting with a specific letter.    (Enter 7) |");
        printf("\n|8. Exit.                                          (Enter 8) |");
        printf("\n|9. Information about developer.                   (Enter 9) |");
        printf("\n|____________________________________________________________|");
        printf("\n\n");
        printf("\nEnter your choice : ");
        scanf("%d",&ck);
        switch(ck)
        {
            case 1: system("COLOR A0");
                    system("CLS");
                    printf("\n\nSince this is an admin function, enter password : ");
                    for(mhx=0;mhx<50;mhx++)
                    {
                        adpp[mhx]=getch();
                        if(adpp[mhx]=='\r')
                        {
                            break;
                        }
                        else
                        {
                            printf("*");
                        }
                    }
                    mhx=0;
                    for(mhx=0;mhx<50;mhx++)
                    {
                        if(adpp[mhx]!='\r')
                        {
                            adpr[mhx]=adpp[mhx];
                        }
                        else
                        {
                            break;
                        }
                    }
                    if(strcmp(adpr,adminp)==0)
                    {system("CLS");                     //for entering info
                     printf("Enter the name : ");
                     scanf("%s",&p.name);
                     printf("\nEnter the number : ");
                     scanf("%d",&p.number);
                     printf("\nEnter the address : ");
                     scanf("%s",&p.address);
                     fwrite(&p,sizeof(p),1,fp);
                     system("CLS");
                    }
                    else
                    {
                        printf("\n\nAccess Denied.");
                    }
                    printf("\n\nPress ENTER to go to the main menu.......");
                    getch();
                    system("CLS");
                     break;
            case 2:rewind(fp);                          //for displaying info
                    system("CLS");
                    printf("\nThe records are : \n");
                    printf("\n");
                    printf("\n\tName\t\t\tPh. Number\t\t\tAddress");
                    printf("\n\t----\t\t\t----------\t\t\t-------");
                    for(i=65;i<=90;i++)
                    {
                        while(fread(&p,sizeof(p),1,fp)==1)
                        {   if(((int)(p.name[0])==i)||((int)(p.name[0])==i+32))
                            {
                                Display(p);
                            }
                        }
                        rewind(fp);
                    }
                     printf("\n\n\nPress ENTER to go to main menu........");
                     getch();
                     system("CLS");
                     break;
            case 3:system("COLOR 50");
                    system("CLS");
                    printf("\n\nSince this is an admin function, enter password : ");
                    for(mhx=0;mhx<50;mhx++)
                    {
                        adpp[mhx]=getch();
                        if(adpp[mhx]=='\r')
                        {
                            break;
                        }
                        else
                        {
                            printf("*");
                        }
                    }
                    mhx=0;
                    for(mhx=0;mhx<50;mhx++)
                    {
                        if(adpp[mhx]!='\r')
                        {
                            adpr[mhx]=adpp[mhx];
                        }
                        else
                        {
                            break;
                        }
                    }
                    if(strcmp(adpr,adminp)==0)
                    {system("CLS");                       //for deleting info
                         rewind(fp);
                         FILE *ft;
                         ft=fopen("AP.DAT","wb");
                         printf("Enter the name of the person whose record is to be deleted : ");
                         scanf("%s",&cn);
                         while(fread(&p,sizeof(p),1,fp)==1)
                         {
                             if(strcmpi(p.name,cn)!=0)
                             {
                                 fwrite(&p,sizeof(p),1,ft);
                             }
                             else
                             {
                                 mkf=mkf+1;
                             }
                        }
                         fclose(ft);
                         fclose(fp);
                         remove("TD.DAT");
                         rename("AP.DAT","TD.DAT");
                         fp=fopen("TD.DAT","ab+");
                         if(mkf==0)
                         {
                             printf("\nRecord with the given name not found for deletion.");
                         }
                         else
                         {
                             printf("\nRecord deleted.");
                         }
                         mkf=0;
                    }
                    else
                    {
                        printf("\n\nAccess Denied.");
                    }
                    printf("\n\nPress ENTER to go to the main menu......");
                    getch();
                    system("CLS");
                        break;
             case 4:system("COLOR B0");
                    system("CLS");
                    printf("\n\nSince this is an admin function, enter password : ");
                    for(mhx=0;mhx<50;mhx++)
                    {
                        adpp[mhx]=getch();
                        if(adpp[mhx]=='\r')
                        {
                            break;
                        }
                        else
                        {
                            printf("*");
                        }
                    }
                    mhx=0;
                    for(mhx=0;mhx<50;mhx++)
                    {
                        if(adpp[mhx]!='\r')
                        {
                            adpr[mhx]=adpp[mhx];
                        }
                        else
                        {
                            break;
                        }
                    }
                    if(strcmp(adpr,adminp)==0)
                    {
                    system("CLS");                  //for modifying records
                    rewind(fp);
                    FILE *sa;
                    sa=fopen("RPS.DAT","wb");
                    printf("Enter the name of the person whose record is to be modified : ");
                    scanf("%s",&cm);
                    while(fread(&p,sizeof(p),1,fp)==1)
                    {
                        if(strcmpi(p.name,cm)==0)
                        {
                            printf("\nModification : ");
                            printf("\nEnter the name : ");
                            scanf("%s",&q.name);
                            printf("\nEnter the number : ");
                            scanf("%d",&q.number);
                            printf("\nEnter the address : ");
                            scanf("%s",&q.address);
                            fwrite(&q,sizeof(q),1,sa);
                            jz=jz+1;
                        }
                        else
                        {
                            fwrite(&p,sizeof(p),1,sa);
                        }
                    }
                    fclose(sa);
                    fclose(fp);
                    remove("TD.DAT");
                    rename("RPS.DAT","TD.DAT");
                    fp=fopen("TD.DAT","ab+");
                    if(jz==0)
                    {
                        printf("\nRecord not found to be modified.");
                    }
                    else
                    {
                        printf("\nRecord modified.");
                    }
                    jz=0;
                    }
                    else
                    {
                        printf("\n\nAccess Denied.");
                    }
                    printf("\n\nPress ENTER to go to the main menu......");
                    getch();
                    system("CLS");
                    break;
             case 5:system("COLOR C1");
                    system("CLS");          //to search by name
                    rewind(fp);
                    printf("\nEnter the name to be searched for : ");
                    scanf("%s",&cq);
                    system("CLS");
                    printf("\n\tName\t\t\tPh. Number\t\t\tAddress");
                    printf("\n\t----\t\t\t----------\t\t\t-------");
                    while(fread(&p,sizeof(p),1,fp)==1)
                    {
                        if(strcmpi(p.name,cq)==0)
                        {
                            Display(p);
                            c=c+1;
                        }
                    }
                    if(c==0)
                    {   printf("\n\t----\t\t\t----------\t\t\t-------");
                        printf("\n\nRecord with the mentioned name does not exist.");
                    }
                    c=0;
                    printf("\n\nPress ENTER to go to main menu......");
                    getch();
                    system("CLS");
                    break;
             case 6:system("COLOR C2");
                    system("CLS");               //to search by number
                    rewind(fp);
                    printf("\nEnter the number to be searched for : ");
                    scanf("%d",&gg);
                    system("CLS");
                    printf("\n\tName\t\t\tPh. Number\t\t\tAddress");
                    printf("\n\t----\t\t\t----------\t\t\t-------");
                    while(fread(&p,sizeof(p),1,fp)==1)
                    {
                        if(p.number==gg)
                        {
                            Display(p);
                            v=v+1;
                        }
                    }
                    if(v==0)
                    {   printf("\n\t----\t\t\t----------\t\t\t-------");
                        printf("\n\nRecord with the mentioned number does not exist.");
                    }
                    v=0;
                    printf("\n\nPress ENTER to go to the main menu.......");
                    getch();
                    system("CLS");
                    break;
             case 7:system("COLOR DF");
                    system("CLS");    //view names starting with a specific character
                    rewind(fp);
                    printf("\nEnter the character with which the names start : ");
                    scanf("%s",&py);
                    system("CLS");
                    printf("\n\tName\t\t\tPh. Number\t\t\tAddress");
                    printf("\n\t----\t\t\t----------\t\t\t-------");
                    while(fread(&p,sizeof(p),1,fp)==1)
                    {   qa=(int)py[0];
                        qb=(int)p.name[0];
                        if((qa==qb)||(qa+32==qb)||(qa-32==qb))
                        {
                            Display(p);
                            jjj=jjj+1;
                        }
                    }
                    if(jjj==0)
                    {   printf("\n\t----\t\t\t----------\t\t\t-------");
                        printf("\n\nNo names start with this character.");
                    }
                    jjj=0;
                    printf("\n\nPress ENTER to go to the main menu.........");
                    getch();
                    system("CLS");
                    break;
             case 8:system("COLOR 07");
                    exit(0);                            //to exit
                    break;
             case 9:system("CLS");                      //info about developer
                    printf("\n");
                    printf("\n");
                    printf("\nNAME : SHRABAN SAHA");
                    printf("\nCONTACT NO. : +91 9038838852");
                    printf("\nOFFICE LOCATION: KOLKATA,WEST BENGAL,INDIA");
                    printf("\n\nPress ENTER to go to the main menu.......");
                    getch();
                    system("CLS");
                    break;
             default:printf("\nWrong choice.");
                    break;
        }
    }
    fclose(fp);
}
else
{
    printf("\nFile does not exist.");
}
}
else
{
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\tWRONG PASSWORD.\n\n\n\n\n\n\n");
    exit(0);
}
}
