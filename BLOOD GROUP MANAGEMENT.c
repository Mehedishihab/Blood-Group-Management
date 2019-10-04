#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>


void menu();
void login();
void registr();
struct project
{
    int phone,batch;
    char firstname[100];
    char lastname[100];
    char password[30];
    char username[30];
    char name [100];
    char email[100];
    char blood_group[10];


} entry;
int main()
{
    int choise,quite,fd,ch,i,length;
    char search[30],bloodgroup[10];
    FILE *fp,*up,*del;

    printf("\n\n\t\t   ======WELCOME TO BLOOD GROUP MANAGEMENT======\n");
    printf("\n\n\t\t\t*********************************\n\t\t\t*\t\t\t\t*\n\t\t\t*\t     Main Menu      \t*\n\t\t\t*\t\t\t\t*\n\t\t\t*********************************\n\t\t\t*\t\t\t\t*");
    printf("\n\t\t\t*\t  [1]Search\t\t*\n");
    printf("\t\t\t*\t  [2]All List\t\t*\n");
    printf("\t\t\t*\t  [3]About Us\t\t*\n");
    printf("\t\t\t*\t  [4]Login\t\t*\n");
    printf("\t\t\t*\t  [5]Register\t\t*\n");
    printf("\t\t\t*\t  [6]Exit\t\t*\n\t\t\t*\t\t\t\t*\n");
    printf("\t\t\t*********************************\n\n");
    printf("\t\t\t\tChoise Any Number: ");

    scanf("%d",&choise);

    switch(choise)
    {
    case 1:

        system("CLS");
        do
        {
            fd=0;
            printf("\n\t\t\t\tSEARCH\n\t\t===========================================\n");
            fflush(stdin);
            printf("\t\t\tEnter any blood group: ");
            gets(search);
            length=strlen(search);
            fp=fopen("bloodgroup01.txt","r");

            system("CLS");
            printf("\n\t\t\tSEARCH result for %s\n\t\t=====================================",search);
            while(fread(&entry,sizeof(entry),1,fp)==1)
            {
                for(i=0; i<=length; i++)
                {
                    bloodgroup[i]=entry.blood_group[i];
                    bloodgroup[length]='\0';

                }
                if(strcmp(bloodgroup,search)==0)
                {
                    printf("\n\t\t\tName:%s \n\t\t\tBlood group:%s \n\t\t\tBatch:%d\n\t\t\tphone:%d\n\t\t\tEmail:%s\n",entry.name,entry.blood_group,entry.batch,entry.phone,entry.email);
                    printf("\t\t============================================\n");
                    fd++;

                }

            }
            if(fd==0)
            {
                printf("no match\n");
            }
            else
            {
                printf("%d match\n",fd);
            }
            printf("\n\n\n\t\t\t(Press [1]try again or [2]main)");
            printf("\n\n\t\t\tChoise Any Number: ");
            scanf("%d",&ch);
            system("CLS");
            if(ch==2)
            {
                main();
            }


        }
        while(ch==1);
        break;
    case 2:
        system("CLS");
        fflush(stdin);
        printf("\n\n\t\t\t\t All lists\n\t\t===============================================\n");
        fp=fopen("bloodgroup01.txt","r");

        for(i=0; i<100; i++)
        {
            while(fread(&entry,sizeof(entry),1,fp)==1)
            {
                printf("\n\t\t\tName:%s \n\t\t\tBlood group:%s \n\t\t\tBatch:%d\n\t\t\tphone:%d\n\t\t\tEmail:%s\n",entry.name,entry.blood_group,entry.batch,entry.phone,entry.email);
                printf("\t\t============================================\n");
                getch();
            }

        }
        printf("\n\n\t\t\tPress [1] to go back: ");

        scanf("%d",&ch);
        system("CLS");
        if(ch==1)
        {
            main();
        }
        break;

    case 3:
        system("CLS");
        printf("\n\n\t\tINFORMATION ABOUT GROUP 404 NOT FOUND\n\t===========================================================");
        printf("\n\t\tName:Md.Mahedi Hasan\n\t\tID:181-15-10900\n\t\tSECTION:D\n");
        printf("\n\t\tName:Sajib Ahmed\n\t\tID:181-15-10874\n\t\tSECTION:D\n");
        printf("\n\t\tName:Mohd.Mehedi Hasan Joy\n\t\tID:181-15-10632\n\t\tSECTION:D\n");
        printf("\n\t\tName:Akkhar Ulok\n\t\tID:181-15-11207\n\t\tSECTION:D");
        printf("\n\n\t\t\tThis is an c project\n\t===========================================================");
        printf("\n\t\t\tPress any key to continue....");
        getch();
        system("CLS");
        main();
        break;
    case 4:

        login();


        break;

    case 5:

        registr();

        break;
    case 6:
        system("CLS");
        printf("\n\n\n\t\t\t*********************************\n\t\t\t*\t   Are you sure?\t*\n\t\t\t*********************************\n\t\t\t*\t[1]YES   *\t[2]NO   *\n\t\t\t*********************************");
        printf("\n\n\t\t\tChoise Any Number: ");
        scanf("%d",&quite);
        if(quite==1)
        {
            system("CLS");
            printf("\n\n\n\n\n\n\t\t\t*********Thanks For Using*********\n\n\n\n\n\n\n\n\n\n\n");
            break;
        }
        else if(quite==2)
        {

            system("CLS");
            main();       // call menu function
        }
        else
        {
            printf("\n\n\t\t\tInvalid....\n\n ");
            getch();
            system("CLS");
            main();                     //if invalid go to menu


        }
        break;

    }



    return 0;
}

void registr()
{
    system("CLS");
    FILE *fp;
    fp=fopen("anotherproject.txt","w");
    printf("\n\t\t\t\tREGISTRATION\n\t\t==============================================\n");
    printf("\n\t\t\tFrist Name:");
    fflush(stdin);
    gets(entry.firstname);
    printf("\n\t\t\tLast Name:");
    gets(entry.lastname);
    printf("\n\t\t\tUser Name:");
    gets(entry.username);
    printf("\n\t\t\tPassword:");
    gets(entry.password);
    fwrite(&entry,sizeof(entry),1,fp);
    fclose(fp);
    printf("\n\t\tRegistration Successfully.....\n");
    printf("\n\t\tPlease press any key to continue.....");
    getch();
    system("CLS");
    login();


}
void login()
{
    system("CLS");
    int choise,i;

    char password[30];
    char username[30],ch;
    fflush(stdin);
    FILE *fp;
    fp=fopen("anotherproject.txt","r");
    printf("\n\t\t\tENTER YOUR USERNAME AND PASSWORD\n\t    ==========================================================\n");

    printf("\n\t\t\tUser Name: ");
    gets(username);

    printf("\n\t\t\tPassword: ");
    gets(password);

    while(fread(&entry,sizeof(entry),1,fp))
    {

        if(strcmp(username,entry.username)==0 && strcmp(password,entry.password)==0)
        {
            system("CLS");
            printf("\n\n\n\t\t\tSuccesful login....\n");
            printf("\n\t\t\tPress any key to continue....");
            getch();
            system("CLS");
            menu();

        }

        else
        {
            printf("\n\t\tYour Username Or Password Is Incorrect\n\t\tPlease Enter correct Username and Password\n\n\n\n");


            printf("\n\n\n\t\t\t(Press [1]try again or [2]menu)");
            printf("\n\n\t\t\tChoise Any Number: ");
            scanf("%d",&choise);
            if(choise==1)
            {
                login();
            }
            else if(choise==2)
            {
                system("CLS");
                main();
            }
        }
    }

    fclose(fp);

}
void menu()
{
    char search[30],bloodgroup[10],name[100];
    int i,c,choise,quite,length,ch,fd;
    FILE *fp,*del,*up;

    printf("\n\n\t\t   ======WELCOME TO BLOOD GROUP MANAGEMENT======\n");
    printf("\n\n\t\t\t*********************************\n\t\t\t*\t\t\t\t*\n\t\t\t*\t     Main Menu      \t*\n\t\t\t*\t\t\t\t*\n\t\t\t*********************************\n\t\t\t*\t\t\t\t*");
    printf("\n\t\t\t*\t  [1]Data Entry\t\t*\n");
    printf("\t\t\t*\t  [2]All List\t\t*\n");
    printf("\t\t\t*\t  [3]Search\t\t*\n");
    printf("\t\t\t*\t  [4]Update\t\t*\n");
    printf("\t\t\t*\t  [5]Delete\t\t*\n");
    printf("\t\t\t*\t  [6]About Us\t\t*\n");
    printf("\t\t\t*\t  [0]Exit\t\t*\n\t\t\t*\t\t\t\t*\n");
    printf("\t\t\t*********************************\n\n");
    printf("\t\t\t\tChoise Any Number: ");

    scanf("%d",&choise);

    switch(choise)
    {

    case 0:
        system("CLS");
        printf("\n\n\n\t\t\t*********************************\n\t\t\t*\t   Are you sure?\t*\n\t\t\t*********************************\n\t\t\t*\t[1]YES   *\t[2]NO   *\n\t\t\t*********************************");
        printf("\n\n\t\t\tChoise Any Number: ");
        scanf("%d",&quite);
        if(quite==1)
        {
            system("CLS");
            printf("\n\n\n\n\n\n\t\t\t*********Thanks For Using*********\n\n\n\n\n\n\n\n\n\n\n");
            break;
        }
        else if(quite==2)
        {

            system("CLS");
            menu();       // call menu function
        }
        else
        {
            printf("\n\n\t\t\tInvalid....\n\n ");
            getch();
            system("CLS");
            menu();                     //if invalid go to menu


        }
        break;
    case 1:
        system("CLS");
        fp=fopen("bloodgroup01.txt","a");                //open a text file name bloodgroup.txt
        printf("\n\n\t\t\t ENTRY YOUR USEFUL DATA\n\t===========================================================");

        while(1)
        {
            fflush(stdin);                               //fflush(stdin) using for clear buffer memory
            printf("\n\t\t(to exit enter a blank space in name option)");
            printf("\n\n\t\t\tName:");
            gets(entry.name);
            if( strcmp(entry.name," ")==0)
            {
                break;
            }
            fflush(stdin);
            printf("\t\t\tBlood Group:");
            gets(entry.blood_group);
            fflush(stdin);
            printf("\t\t\tBatch:");
            scanf("%d",&entry.batch);
            fflush(stdin);
            printf("\t\t\tPhone:");
            scanf("%d",&entry.phone);
            fflush(stdin);
            printf("\t\t\tEmail:");
            gets(entry.email);
            fflush(stdin);
            fwrite(&entry,sizeof(entry),1,fp);             //fwrite for written all entry in file
            system("CLS");
            printf("\n\n\t\t\t ENTRY YOUR USEFUL DATA\n\t===========================================================");
        }
        fclose(fp);
        printf("\n\n\n\t\t\t(Press [1]exit or [2]menu)");
        printf("\n\n\t\t\tChoise Any Number: ");
        scanf("%d",&quite);
        if(quite==1)
        {
            system("CLS");
            printf("\n\n\n\n\n\n\t\t\t*********Thanks For Using*********\n\n\n\n\n\n\n\n\n\n\n");
            break;
        }
        else if(quite==2)
        {

            system("CLS");
            menu();       // call menu function
        }
        else
        {
            printf("\n\n\t\t\tPlease Enter Valid Option....\n\n ");
            getch();
            system("CLS");
            menu();
        }

        //closing file
        break;
    case 2:
        system("CLS");
        fflush(stdin);
        printf("\n\n\t\t\t\t All lists\n\t\t===============================================\n");
        fp=fopen("bloodgroup01.txt","r");

        for(i=0; i<100; i++)
        {
            while(fread(&entry,sizeof(entry),1,fp)==1)
            {
                printf("\n\t\t\tName:%s \n\t\t\tBlood group:%s \n\t\t\tBatch:%d\n\t\t\tphone:%d\n\t\t\tEmail:%s\n",entry.name,entry.blood_group,entry.batch,entry.phone,entry.email);
                printf("\t\t============================================\n");
                getch();
            }

        }
        printf("\n\n\t\t\tPress [1] to go back: ");

        scanf("%d",&ch);
        system("CLS");
        if(ch==1)
        {
            menu();
        }
        break;
    case 3:
        system("CLS");
        do
        {
            fd=0;
            printf("\n\t\t\t\tSEARCH\n\t\t===========================================\n");
            fflush(stdin);
            printf("\t\t\tEnter any blood group: ");
            gets(search);
            length=strlen(search);
            fp=fopen("bloodgroup01.txt","r");

            system("CLS");
            printf("\n\t\t\tSEARCH result for %s\n\t\t=====================================\n",search);
            while(fread(&entry,sizeof(entry),1,fp)==1)
            {
                for(i=0; i<=length; i++)
                {
                    bloodgroup[i]=entry.blood_group[i];
                    bloodgroup[length]='\0';

                }
                if(strcmp(bloodgroup,search)==0)
                {
                    printf("\n\t\t\tName:%s \n\t\t\tBlood group:%s \n\t\t\tBatch:%d\n\t\t\tphone:%d\n\t\t\tEmail:%s\n",entry.name,entry.blood_group,entry.batch,entry.phone,entry.email);
                    printf("\t\t============================================\n");
                    fd++;

                }

            }
            if(fd==0)
            {
                printf("\t\t\tno match\n");
            }
            else
            {
                printf("\t\t\t%d match\n",fd);
            }
            printf("\n\n\n\t\t\t(Press [1]try again or [2]menu)");
            printf("\n\n\t\t\tChoise Any Number: ");
            scanf("%d",&ch);
            system("CLS");
            if(ch==2)
            {
                menu();
            }


        }
        while(ch==1);
        break;
    case 4:
        system("CLS");



        fp=fopen("bloodgroup01.txt","r");
        up=fopen("update.txt","w");
        fflush(stdin);
        printf("\n\t\t\t\t\tUPDATE\n\t\t====================================================\n");
        printf("\t\tEnter the name to change: ");
        gets(name);
        while(fread(&entry,sizeof(entry),1,fp)==1)
        {
            if(strcmp(name,entry.name)!=0)
            {
                fwrite(&entry,sizeof(entry),1,up);
            }
        }
        fflush(stdin);
        printf("\n\n\t\t\tName:");
        gets(entry.name);
        fflush(stdin);
        printf("\t\t\tBlood Group:");
        gets(entry.blood_group);
        fflush(stdin);
        printf("\t\t\tBatch:");
        scanf("%d",&entry.batch);
        fflush(stdin);
        printf("\t\t\tPhone:");
        scanf("%d",&entry.phone);
        fflush(stdin);
        printf("\t\t\tEmail:");
        gets(entry.email);
        fflush(stdin);
        fwrite(&entry,sizeof(entry),1,up);
        fclose(fp);
        fclose(up);
        remove("bloodgroup01.txt");
        rename("update.txt","bloodgroup01.txt");
        printf("\n\n\n\t\t\t(Press [1]try again or [2]menu)");
        printf("\n\n\t\t\tChoise Any Number: ");
        scanf("%d",&ch);
        system("CLS");
        if(ch==2)
        {
            menu();
        }

        break;


    case 5:
        system("CLS");
        fflush(stdin);
        printf("\n\t\t\t\tDELETE\n\t\t=======================================\n");
        printf("\t\tEnter the name to delete: ");
        gets(name);
        fp=fopen("bloodgroup01.txt","r");
        del=fopen("update.txt","w");
        while(fread(&entry,sizeof(entry),1,fp)!=0)
        {
            if(strcmp(name,entry.name)!=0)
            {
                fwrite(&entry,sizeof(entry),1,del);
            }
        }
        fclose(fp);
        fclose(del);
        remove("bloodgroup01.txt");
        rename("update.txt","bloodgroup01.txt");
        printf("\n\n\n\t\t\t(Press [1]try again or [2]menu)");
        printf("\n\n\t\t\tChoise Any Number: ");
        scanf("%d",&ch);
        system("CLS");
        if(ch==2)
        {
            menu();
        }

        break;


    case 6:
        system("CLS");
        printf("\n\n\t\tINFORMATION ABOUT GROUP 404 NOT FOUND\n\t===========================================================");
        printf("\n\t\tName:Md.Mahedi Hasan\n\t\tID:181-15-10900\n\t\tSECTION:D\n");
        printf("\n\t\tName:Sajib Ahmed\n\t\tID:181-15-10874\n\t\tSECTION:D\n");
        printf("\n\t\tName:Mohd.Mehedi Hasan Joy\n\t\tID:181-15-10632\n\t\tSECTION:D\n");
        printf("\n\t\tName:Akkhar Ulok\n\t\tID:181-15-11207\n\t\tSECTION:D");
        printf("\n\n\t\t\tThis is an c project\n\t===========================================================");
        printf("\n\t\t\tPress any key to continue....");
        getch();
        system("CLS");
        menu();
        break;




    default:

        printf("\n\t\t\tPlease Enter Valid Option....");
        printf("\n\t\t\tPress any key to continue....");
        getch();
        system("CLS");
        menu();
        break;
    }



}








