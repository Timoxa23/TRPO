#include <stdio.h> // Подключаем необходимые библиотеки.
#include <string.h>
#include <stdlib.h>
struct Patients // Задаем структуру.
{
    char LastName[20];
    char Name[20];
    char Patronymic[20];
    int DateofBirthday;
    char Pol[10];
    char Sity[10];
    int Number;
    char Diagnos[15];
                                                                                                                                                          
};
struct users
{
    char login[30];
    char password[30];
    int role;
};
void array_nulling(char *array, int *size) // Все значения массива приравниваем к нулю.
{
    for (int i=0; i<*size; i++)
    {
        *(array+i)=0;
    }
}
void patients(int *k, struct users *a1, int *size)
{
    int n, stop, MaxLetters=30;
    char login[MaxLetters], password[MaxLetters];
    while (*k==0)
    {
        array_nulling(login, &MaxLetters);
        array_nulling(password, &MaxLetters);
        stop=0;
        printf("Login: ");
        scanf("%s", &login);
        printf("Password: ");
        scanf("%s", &password);
        for (int i=0; i<*size; i++)
        {
            if (memcmp((a1+i)->login, login, MaxLetters)==0 && memcmp((a1+i)->password, password, MaxLetters)==0) // Сравниваем данные из массива с заданными пользователем.
            {
                if ((a1+i)->role==1)
                {
                    *k=2;
                    printf("Enter succesful!\nYou have entered as Admin\n");
                    break;
                }
                else *k=3;
                printf("Enter succesful!\nYou have entered as User\n");
                break;
            }
        }
        if (*k==0) printf("\nYou have entered an incorrect login or password\n");
        while ((*k==0) && stop!=1)
        {
            printf("1 - Try logging in again\n2 - Exit\n");
            scanf("%d", &n);
            switch(n)
            {
                case 1:
                    stop=1;
                    break;
                case 2:
                    *k=-1;
                    break;
                default:
                    printf("\nYou have entered an incorrect number, please try again\n");
            }
        }
    }
    system("pause");
}
void outputInformationAboutPatients(struct Patients *a, int *size) // Функция для ввода информации.
{
    for (int i=0; i<*size; i++)
    {
        printf("%d.|FIO: %2s %2s %2s | DateofBirthday: %d | Pol: %2s | Sity: %2s | Number: %d | Diagnos : %2s |\n", i+1, (a+i)->LastName, (a+i)->Name, (a+i)->Patronymic, (a+i)->DateofBirthday, (a+i)->Pol, (a+i)->Sity, (a+i)->Number, (a+i)->Diagnos);
    }
}
void editInformationAboutPatients(struct Patients *a, int *size) // Функция для возможности  редактирвоания информации.
{
    int n, m=0, n1=0, m1=0;
    while (m==0)
   {
      printf("Enter the patient number(0-Exit): ");
      scanf("%d", &n1);
      m1=0;
      if ((n1<0) || (n1>*size))
      {
        printf("\nYou have entered an incorrect number, please try again");
      }
     else if (n1==0)
      {
        m=1;
      }
      else while (m1==0)
        {
            printf("\n1 - Edit lastname\n2 - Edit name\n3 - Edit patronymic\n4 - Edit DateofBirthday");
            printf("\n5 - Edit Pol\n6 - Edit Sity\n7 - Edit Number\n8 - Edit Diagnos\n0 - Exit\n");
                scanf("%d", &n);
                switch (n)
                {
                    case 1:
                        printf("\nEnter new LastName: ");
                        scanf("%s", &(a+n1-1)->LastName);
                        break;
                    case 2:
                        printf("\nEnter new Name: ");
                        scanf("%s", &(a+n1-1)->Name);
                        break;
                    case 3:
                        printf("\nEnter new Patronymic: ");
                        scanf("%s", &(a+n1-1)->Patronymic);
                        break;
                    case 4:
                        printf("\nEnter new DateofBirthday: ");
                        scanf("%d", &(a+n1-1)->DateofBirthday);
                        break;
                    case 5:
                        printf("\nEnter new Pol: ");
                        scanf("%s", &(a+n1-1)->Pol);
                        break;
                    case 6:
                        printf("\nEnter new Sity: ");
                        scanf("%s", &(a+n1-1)->Sity);
                        break;
                    case 7:
                        printf("\nEnter new Number: ");
                        scanf("%d", &(a+n1-1)->Number);
                        break;
                        case 8:
                        printf("\nEnter new Diagnos: ");
                        scanf("%s", &(a+n1-1)->Diagnos);
                        break;
                    case 0:
                        m1=1;
                        break;
                    default:
                        printf("\nYou have entered an incorrect number, please try again\n");
                        break;
                }
            }
        
    }
}
void addNewUser(struct users *a1, int *size)
{
    printf("\nEnter Login: ");
    scanf("%s", &((a1+*size)->login));
    printf("\nEnter Password: ");
    scanf("%s", &((a1+*size)->password));
    printf("\nEnter Role(0 or 1): ");
    scanf("%d", &((a1+*size)->role));
    printf("\nNew user was added\n");
    system("pause");
}
void outputUsers(struct users *a1, int *size)
{
    for (int i=0; i<*size; i++)
    {
        printf("%d.Login: %s  Password: %s  Role: %d\n", i+1, (a1+i)->login, (a1+i)->password, (a1+i)->role);
    }
    system("pause");
}
void addNewPatients(struct Patients *a, int *size)
{
    printf("Enter FIO: ");
    scanf("%s %s %s", &(a+*size)->LastName, &(a+*size)->Name, &(a+*size)->Patronymic);
    printf("Enter DateofBirthday: ");
    scanf("%d", &((a+*size)->DateofBirthday));
    printf("Enter Pol: ");
    scanf("%s", &((a+*size)->Pol));
    printf("Enter Sity: ");
    scanf("%s", &((a+*size)->Sity));
    printf("Enter Number: ");
    scanf("%d", &((a+*size)->Number));
     printf("Enter Diagnos: ");
    scanf("%s", &((a+*size)->Diagnos));
    printf("New patients was added\n");
    system("pause");
}
void individualTask(struct Patients *a, int *sizePatients)
{
    int age, stop=0, n, i, maxNum=15;
    char diagnos[maxNum];
    array_nulling(diagnos, &maxNum);
    printf("Enter the age above which you want to withdraw patients: ");
    scanf("%d", &age);
    printf("Enter a diagnosis: ");
    scanf("%s", &diagnos);
    for (i=0; i<*sizePatients; i++)
    {
        if (strcmp((a+i)->Diagnos, diagnos)==0 && (age<2022-(((a+i)->DateofBirthday)%10000) && strcmp((a+i)->Sity, "Gomel")!=0))
        {
            printf("%d.|FIO: %2s %2s %2s|\n", i+1, (a+i)->LastName, (a+i)->Name, (a+i)->Patronymic);
        }
    }
    system("pause");
}
int main()
{
    int k=0, size1=2, n, size2=1, m=0;
    struct users a1[5]={"admin", "admin", 1, "user", "user", 0};
    struct Patients a[5]={"Timofeev", "Alexander", "Sergeevich", 23052004, "Men", "Gomel", 445892839,"perelom"};
    patients(&k, a1, &size1);
    if (k==3)
    {
        m=0;
        while (m==0)
        {
            printf("1 - Display information about Patients \n2 - Exit\n");
            scanf("%d", &n);
            switch(n)
            {
                case 1:
                    outputInformationAboutPatients(a, &size2);
                    system("pause");
                    break;
                case 2:
                    m=-1;
                    break;
                default:
                    printf("\nYou have entered an incorrect number, please try again\n");
                    break;
            }
        }
    }
    if (k==2)
    {
        m=0;
        while (m==0)
        {
           printf("1 - Display information about Patients \n2 - Edit information Patients\n3 - Add new user\n4 - Display all users\n5 - Add new Patients\n6 - Exit\n7 - Task\n");
            scanf("%d", &n);
            switch(n) // Выводим на экран возможные действия с программой.
             {
                case 1:
                    outputInformationAboutPatients(a, &size2);
                    system("pause");
                    break;
            
                case 2:
                    outputInformationAboutPatients(a, &size2);
                    editInformationAboutPatients(a, &size2);
                    break;
                case 3:
                    addNewUser(a1, &size1);
                    size1++;
                    break;
                case 4:
                    outputUsers(a1, &size1);
                    break;
                case 5:
                     addNewPatients(a, &size2);
                    size2++;
                    break;
                case 6:
                    m=1;
                    break;
                case 7:
                    individualTask(a, &size2);
                    break;
                default:
                    printf("\nYou have entered an incorrect number, please try again\n");
                    break;
            }
        }
    }
    system("pause");
    return 0;
}
