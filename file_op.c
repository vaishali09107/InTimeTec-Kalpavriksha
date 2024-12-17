#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    int id;
    char *name;
    int age;
}user;
void check_file()
{
    FILE *file_pointer=fopen("users.txt","a");
    if(file_pointer==NULL)
    {
        printf("Error in opening file.\n");
    }
    fseek(file_pointer,0,SEEK_END);
    if(ftell(file_pointer)==0)
    {
        fprintf(file_pointer,"%-10s %-15s %-10s\n","ID","Name","Age");
    }
    fclose(file_pointer);
}
void add_user()
{
    FILE *file_pointer;
    user us;
    check_file();
    file_pointer=fopen("users.txt","a");
    if(file_pointer==NULL)
    {
        printf("Cannot open file.\n");
    }
    us.name=(char *)malloc(20 * sizeof(char));
    if(us.name==NULL)
    {
        printf("Error in memory allocation for name.\n");
        return;
    }
    printf("Enter the details of the user: \n");
    printf("ID: ");
    scanf("%d",&us.id);
    printf("Name: ");
    getchar();
    int size = 0, capacity = 20;
    char character;
    while(scanf("%c", &character)==1 && character!='\n')
    {
        if(size>=capacity)
        {
            capacity*=2;
            us.name=(char *)realloc(us.name, capacity * sizeof(char));
            if(us.name==NULL)
            {
                printf("Memory Re-Allocation Failed.\n");
                return;
            }
        }
        us.name[size++]=character;
    }
    us.name[size] = '\0';
    printf("Age: ");
    scanf("%d",&us.age);
    fprintf(file_pointer,"%-10d %-15s %-10d\n",us.id,us.name,us.age);
    fclose(file_pointer);
    printf("User record added sucessfully.");
    free(us.name);
}
void display_user()
{
    FILE *file_pointer;
    char data[256];
    check_file();
    file_pointer=fopen("users.txt","r");
    if(file_pointer==NULL)
    {
        printf("Cannot open file.\n");
        return;
    }
    if(fgetc(file_pointer)==EOF)
    {
        printf("File is empty.\n");
        fclose(file_pointer);
    }
    rewind(file_pointer);
    printf("User record: \n");
    while(fgets(data,sizeof(data),file_pointer))
    {
        printf("%s",data);
    }
    fclose(file_pointer);
}
void update_user()
{
    FILE *file_pointer ,*temp_file_pointer;
    user us;
    int key;
    int flag=0;
    check_file();
    file_pointer=fopen("users.txt","r");
    temp_file_pointer=fopen("temp.txt","w");
    if(file_pointer==NULL || temp_file_pointer==NULL)
    {
        printf("Cannot open file.\n");
        if(file_pointer)
        {
            fclose(file_pointer);
        }
        if(temp_file_pointer)
        {
            fclose(temp_file_pointer);
        }
        return;
    }
    us.name=(char *)malloc(20 * sizeof(char));
    if(us.name==NULL)
    {
        printf("Error in memory allocation for name.\n");
        return;
    }
    printf("Please enter the id of the user you want to update: ");
    scanf("%d",&key);
    char start[256];
    fgets(start,sizeof(start),file_pointer);
    fprintf(temp_file_pointer,"%s",start);
    while(fscanf(file_pointer,"%d %s %d", &us.id, us.name, &us.age) == 3)
    {
        if(us.id==key)
        {
            printf("Enter new name: ");
            getchar();
            int size = 0, capacity = 20;
            char character;
            while(scanf("%c", &character)==1 && character!='\n')
            {
                if(size>=capacity)
                {
                    capacity*=2;
                    us.name=(char *)realloc(us.name, capacity * sizeof(char));
                    if(us.name==NULL)
                    {
                        printf("Memory Re-Allocation Failed.\n");
                        return;
                    }
                }
                us.name[size++]=character;
            }
            us.name[size] = '\0';
            printf("Enter new age: ");
            scanf("%d", &us.age);
            flag=1;
        }
        fprintf(temp_file_pointer, "%-10d %-15s %-10d\n", us.id, us.name, us.age);
    }
        
    fclose(file_pointer);
    fclose(temp_file_pointer);
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
    free(us.name);
    
}
void delete_user()
{
    FILE *file_pointer,*temp_file_pointer;
    user us;
    int key;
    int flag=0;
    check_file();
    file_pointer=fopen("users.txt","r");
    temp_file_pointer=fopen("temp.txt","w");
    if(file_pointer==NULL || temp_file_pointer==NULL)
    {
        printf("Cannot open file.\n");
        if(file_pointer)
        {
            fclose(file_pointer);
        }
        if(temp_file_pointer)
        {
            fclose(temp_file_pointer);
        }
    }
    us.name=(char *)malloc(20 * sizeof(char));
    if(us.name==NULL)
    {
        printf("Error in memory allocation for name.\n");
        return;
    }
    printf("Please enter the id of the user you want to delete: ");
    scanf("%d",&key);
    char start[256];
    fgets(start,sizeof(start),file_pointer);
    fprintf(temp_file_pointer,"%s",start);
    while(fscanf(file_pointer,"%d %s %d",&us.id,us.name,&us.age)==3)
    {
        if(us.id==key)
        {
            flag=1;

        }
        else
        {
            fprintf(temp_file_pointer,"%-10d %-15s %-10d\n",us.id,us.name,us.age);
        }
    }
    fclose(file_pointer);
    fclose(temp_file_pointer);
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
    free(us.name);
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
