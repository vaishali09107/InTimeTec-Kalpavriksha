#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    int id;
    char name[20];
    int age;
}user;
void check_file()
{
    FILE *fp=fopen("users.txt","a");
    if(fp==NULL)
    {
        printf("Error in opening file.\n");
    }
    fseek(fp,0,SEEK_END);
    if(ftell(fp)==0)
    {
        fprintf(fp,"%-10s %-15s %-10s\n","ID","Name","Age");
    }
    fclose(fp);
}
void add_user()
{
    FILE *fp;
    user us;
    check_file();
    fp=fopen("users.txt","a");
    if(fp==NULL)
    {
        printf("Cannot open file.\n");
    }
    printf("Enter the details of the user: \n");
    printf("ID: ");
    scanf("%d",&us.id);
    printf("Name: ");
    scanf(" %[^\n]",us.name);
    printf("Age: ");
    scanf("%d",&us.age);
    fprintf(fp,"%-10d %-15s %-10d\n",us.id,us.name,us.age);
    fclose(fp);
    printf("User record added sucessfully.");
}
void display_user()
{
    FILE *fp;
    char data[256];
    check_file();
    fp=fopen("users.txt","r");
    if(fp==NULL)
    {
        printf("Cannot open file.\n");
        return;
    }
    if(fgetc(fp)==EOF)
    {
        printf("File is empty.\n");
        fclose(fp);
    }
    rewind(fp);
    printf("User record: \n");
    while(fgets(data,sizeof(data),fp))
    {
        printf("%s",data);
    }
    fclose(fp);
}
void update_user()
{
    FILE *fp ,*tfp;
    user us;
    int key;
    int flag=0;
    check_file();
    fp=fopen("users.txt","r");
    tfp=fopen("temp.txt","w");
    if(fp==NULL || tfp==NULL)
    {
        printf("Cannot open file.\n");
        if(fp)
        {
            fclose(fp);
        }
        if(tfp)
        {
            fclose(tfp);
        }
        return;
    }
    printf("Please enter the id of the user you want to update: ");
    scanf("%d",&key);
    char start[256];
    fgets(start,sizeof(start),fp);
    fprintf(tfp,"%s",start);
    while(fscanf(fp,"%d %s %d", &us.id, us.name, &us.age) == 3)
    {
        if(us.id==key)
        {
            printf("Enter new name: ");
            scanf(" %[^\n]", us.name);
            printf("Enter new age: ");
            scanf("%d", &us.age);
            flag=1;
        }
        fprintf(tfp, "%-10d %-15s %-10d\n", us.id, us.name, us.age);
    }
        
    fclose(fp);
    fclose(tfp);
    if(flag)
    {
        remove("users.txt");
        rename("temp.txt", "users.txt");
        printf("Record updated successfully.\n");
    }
    else
    {
        remove("temp.txt");
        printf("Record not found.\n");
    }
    
}
void delete_user()
{
    FILE *fp,*tfp;
    user us;
    int key;
    int flag=0;
    check_file();
    fp=fopen("users.txt","r");
    tfp=fopen("temp.txt","w");
    if(fp==NULL || tfp==NULL)
    {
        printf("Cannot open file.\n");
        if(fp)
        {
            fclose(fp);
        }
        if(tfp)
        {
            fclose(tfp);
        }
    }
    printf("Please enter the id of the user you want to delete: ");
    scanf("%d",&key);
    char start[256];
    fgets(start,sizeof(start),fp);
    fprintf(tfp,"%s",start);
    while(fscanf(fp,"%d %s %d",&us.id,us.name,&us.age)==3)
    {
        if(us.id==key)
        {
            flag=1;

        }
        else
        {
            fprintf(tfp,"%-10d %-15s %-10d\n",us.id,us.name,us.age);
        }
    }
    fclose(fp);
    fclose(tfp);
    if(flag)
    {
        remove("users.txt");
        rename("temp.txt", "users.txt");
        printf("Record deleted successfully.\n");
    }
    else
    {
        remove("temp.txt");
        printf("Record not found.\n");
    } 
}
int main()
{
    int choice;
    do
    {
        printf("\nMenu:");
        printf("\n 1. Create (add new user to the file)");
        printf("\n 2. Read (display all users)");
        printf("\n 3. Update (modify users based on ID)");
        printf("\n 4. Delete (remove user by ID)");
        printf("\n 5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            add_user();
            break;
        case 2:
            display_user();
            break;
        case 3:
            update_user();
            break;
        case 4:
            delete_user();
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice!=5);
    return 0;
}




