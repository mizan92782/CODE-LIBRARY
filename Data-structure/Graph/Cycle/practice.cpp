#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

FILE *fp;
int i,numberArray[10],roll,v;
int a=0,b=0,c=0,d=0,e=0,x;

int main()
{
    system("cls");

    int choice;
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tWelcome to Voting System.\n\n\n\n\t\t\t\t\t\tLets start voting operation\n");
    printf("\t\t\t\t\t\tPress any key to continue...");
    getch();
    system("cls");

    printf("\n\n\n\n\n\t\t\t\t\t\t1. Admin\n");
    printf("\t\t\t\t\t\t2. Voter\n");
    printf("\t\t\t\t\t\t3. Exit Application\n");
    printf("\n\n\n\t\t\t\t\t\tEnter your choice: ");
    fflush(stdin);
    scanf("%d",&choice);

    system("cls");

    switch(choice)
    {
    case 1:
        admin();
        break;
    case 2:

    {
        int n=100;
        for(i=0; i<n; i++)
        {
            int index=check();

            if(index==1)
            {
                system("cls");
                printf("\t\t\t\t\tWelcome to Voting System.\n\n\n\n\n \t\t\t\t\tPress any key to continue...\n\n");
                voter();
                break;
            }
            else
            {
                int test;
                printf("\n\t\t\t\t\t\tNot registered.\n");
                printf("\nEnter Esc to stop voting and go to main menu or \n\nPress any key to continue voting.");
                test=getche();
                if(test==27)
                {
                    system("cls");
                    main();
                }
                else
                {
                    system("cls");
                    continue;
                }
            }
        }
    }

    case 3:
        if(choice == 3)
        {
            return 0;
        }
    default:
        printf("\n\n\n\n\n\t\t\t\t\t\t\t\tInvalid Input\n");
        system("pause");
        main();

    }

}

void admin()
{
    int choice;
    printf("\n\n\n\n\n\t\t\t\t\t\t1. Registration\n");
    printf("\t\t\t\t\t\t2. Result\n");
    printf("\n\n\t\t\t\t\tSELECT YOUR CHOICE AND THEN PRESS ENTER: ");
    scanf("\t\t\t\t\t%d",&choice);

    system("cls");
    switch(choice)

    {
    case 1:
        registration();
        break;
    case 2:
        result();
        break;
    }

}

void registration()
{
    int pin,roll[10];
    while(pin!=2020)
    {

        printf("\n\n\n\n\n\t\t\t\t\tEnter Your Secret Pin Number: ");
        scanf("\t\t%d",&pin);
        if(pin!=2020)
        {
            system("color 04");
            printf("\n\n\n\t\t\t\t\tPLEASE ENTER VALID PASSWORD\n");
            Sleep(1500);
        }
        system("cls");
        system("color 07");
    }
    fp=fopen("Registered list.text","w");
    char test;
    if(fp==NULL)
    {
        printf("Failed to open");
    }
    else
    {
        printf("\n\n\n\t\t\t\t\tEnter the number of voters: ");
        scanf("%d",&v);
        system("cls");

        for(i=0; i<v; i++)
        {
            printf("\n%d.Register the rolls: ",i+1);
            scanf("%d",&roll[i]);
            fprintf(fp,"%d,",roll[i]);
        }
        fflush(stdin);
        system("cls");
        printf("\n\n\n\t\t\t\t\t\tRolls are successfully added.\n");
        fclose(fp);
    }
    printf("\n\n\n\t\t\t\t\t\tPress ESC to exit.\n");

    test=getche();
    if(test==27)


        fp = fopen("Registered list.text", "r");


    if (fp == NULL)
    {
        printf("\n\n\n\t\t\t\t\t\tError Reading File\n");
        exit (0);
    }

    for (i = 0; i < v; i++)
    {
        fscanf(fp, "%d,", &numberArray[i] );
    }
    fclose(fp);
    system("cls");
    main();

}

int check()
{
    int index=0;

    printf("\n\n\n\n\t\t\t\t\t\tEnter your roll: ");
    scanf("%d",&roll);

    for(i=0; i<v; i++)
    {
        if(roll==numberArray[i])
        {


            index=1;


        }
    }
    return index;


}

void voter()
{
    int n=100,choice;

        getche();
        system("cls");
        printf("\n\n\t\t\t\t\t*****WELCOME TO CASTING VOTE*****\n");
        printf("\n\t\t\t\t\t\t1. List of candidates.\n");
        printf("\t\t\t\t\t\t2. Candidates information.\n");
        printf("\t\t\t\t\t\t3. Contribution.\n");
        printf("\t\t\t\t\t\t4. Cast vote.\n");
        printf("\n\t\t\t\t\t*********************************\n");
        printf("\t\t\t\t\t\t\t\tEnter your choice:\n");
        scanf("%d",&choice);


        system("cls");
        switch(choice)

        {
        case 1:
            printf("\n\n\t\t\t\t\t\tCandidates Name:\n");
            printf("\nt\t\t\t\t\t1. Rakib Hasan \n");
            printf("\t\t\t\t\t\t2. Samit Haque \n");
            printf("\t\t\t\t\t\t3. Makam Chowdhury \n");
            printf("\t\t\t\t\t\t4. Kabir Hossain \n");

            printf("\n\n\n\n\n\t\t\t\t\t\t\tPRESS ANY KEY TO GO TO MAIN MENU.....");
            voter();
            break;
        case 2:

            printf("\n\t\t\t\t\t\tCandidates information: \n");

            printf("\t\t\t\t1. Rakib Hasan: \n");
            printf("\n\tRakib Hasan is an Architect. He has a clear vision about this city. \n\tHe wants to rebuild this city new a good way.\n");

            printf("\n\t\t\t\t2. Samit Haque: \n");
            printf("\n\tSamit Haque is a Business man. He is a very honest man. \n\tEverybody knows him for his good behavior.\n");

            printf("\n\t\t\t\t3. Makam Chowdhury: \n");
            printf("\n\tMakam Chowdhury is an Engineer. He has great concern for the environment.\n\tSo, he wants to emphasis on that. \n");

            printf("\n\t\t\t\t4. Kabir Hossain: \n");
            printf("\n\tKabir Hossain is Doctor. He loves to help people. Everybody is same for him.\n\tSo, He wants to work for everyone in equal measure.\n");

            printf("\n\n\t\t\t\t\tPRESS ANY KEY TO GO TO MAIN MENU.....");
            voter();
            break;

        case 3:
            printf("\nCandidates Contribution: \n");

            printf("\n\n\n1. Rakib Hasan is a social worker. Co-founder of volunteer organization like NFCO, SNO, VUI. \n   Re-constructed the road system. \n");

            printf("\n\n\n2. Samit Haque serves for people. Has contributed establish a few educational institutes. \n   Has created a fair job market for IT sector.\n");

            printf("\n\n\n3. Makam Chowdhury contributes a lot for society. Worked a lot for the water logging issues of \n   the locality. Played a significant in economical development. \n");

            printf("\n\n\n4. Kabir Hossain works for welfare of the society. was elected two times before. \n   At present, he is a role model of young generation. \n");

            printf("\n\n\n\n\n\t\t\t\t\t\tPRESS ANY KEY TO GO TO MAIN MENU.....");

            voter();

            break;

        case 4:

        {

            system("cls");

            printf("\n\n\n\n\n\t\t\t\t\tCandidates Name:\n");
            printf("\n\t\t\t\t\t1. Rakib Hasan. \n");
            printf("\t\t\t\t\t2. Samit Haque. \n");
            printf("\t\t\t\t\t3. Makam Chowdhury. \n ");
            printf("\t\t\t\t\t4. Kabir Hossain. \n");


            printf("\n\n\n\t\t\t\t\t\tPlease enter the serial no of your favourite candidate: ");
            scanf("%d",&x);


            if(x==1)
            {
                a++;
            }
            else if(x==2)
            {
                b++;
            }
            else if(x==3)
            {
                c++;
            }
            else if(x==4)
            {
                d++;
            }

            printf("\n\n\n\n\n\t\t\t\t\tPRESS ANY KEY TO GO TO MAIN MENU.....");
            getche();
            system("cls");
            main();

            break;
        }

        }

    }

    void result()
    {
        int pin;
        while(pin!=1520)
        {

            printf("\n\n\n\n\n\t\t\t\t\tEnter Your Secret Pin Number: ");
            scanf("%d",&pin);
            if(pin!=1520)
            {
                system("color 04");
                printf("\n\n\n\n\n\t\t\t\t\tPLEASE ENTER VALID PASSWORD \n");
                Sleep(1500);
            }
            system("cls");
            system("color 07");
        }
        system("cls");
        printf("\n\n\n\n\n\n\t\t\t\t\t*****RESULT OF THE ELECTION*****\n");

        printf("\n\n\n\n\t\t\t\t\tTHE RESULT IS:\n\n");
        printf("\t\t\t\t\tVote for Rakib= %d\n",a);
        printf("\t\t\t\t\tVote for Samit= %d\n",b);
        printf("\t\t\t\t\tVote for Makam= %d\n",c);
        printf("\t\t\t\t\tVote for Kabir= %d\n",d);
        printf("\t\t\t\t\tNo one= %d\n",e);

        if(a>b&&a>d&&a>c)
        {
            printf("\t\t\t\t\tRakib Won the election\n\n\n");
        }
        else if (b>a&&b>c&&b>d)
        {
            printf("\t\t\t\t\tSamit Won the election\n\n\n");
        }
        else if(c>a&&c>b&&c>d)
        {
            printf("\t\t\t\t\tMakam Won the election\n\n\n");
        }
        else if (d>a&&d>b&&d>c)
        {
            printf("\t\t\t\t\tKabir Won the election\n\n\n");
        }
        else
        {
            printf("\n\t\t\t\t\tThe power goes to the authority\n\n\n");
        }
        printf("\t\t\t\t\tEnter Esc to exit.\n");
        printf("\n\t\t\t\t\tThank You");
        getche();
        exit(0);
    }


