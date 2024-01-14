#include<bits/stdc++.h>

using namespace std;

string name[50], number[50];
int k = 0;

void quickSort();
void add_contact();
void display();
void search();
void update();
void delet();
int menu();


int main()
{
    int key;

    while(key != 6)
    {
        system("cls");
        key = menu();

        switch(key)
        {
        case 1:
            system("cls");
            add_contact();
            break;
        case 2:
            system("cls");
            display();
            break;
        case 3:
            system("cls");
            search();
            break;
        case 4:
            system("cls");
            update();
            break;
        case 5:
            system("cls");
            delet();
            break;
        case 6:
            system("cls");
            return 0;
            break;
dafault:
            cout << "Invalid\n";
        }
    }

    return 0;
}


void swap(string* a, string* b)
{
    string t = *a;
    *a = *b;
    *b = t;
}

int partition(string name[], int left, int right)
{
    string pivot = name[right];
    int i = (left - 1);

    for(int j = left; j <= right- 1; j++)
    {

        if(name[j] <= pivot)
        {
            i++;
            swap(&name[i], &name[j]);
        }
    }
    swap(&name[i + 1], &name[right]);
    return (i + 1);
}


void quickSort(string name[], int left, int right)
{
    if (left < right)
    {
        int pi = partition(name, left, right);

        quickSort(name, left, pi - 1);
        quickSort(name, pi + 1, right);
    }
}


int menu()
{
    system("color 5f");

    cout << "\n\n\n";
    cout << "\t\t\t\t\t -----------------------------\n";
    cout << "\t\t\t\t\t |\t  PhoneBook          |\n";
    cout << "\t\t\t\t\t -----------------------------\n";
    cout << "\n";
    cout << "\t\t\t\t\t         1. Add Contact\n";
    cout << "\t\t\t\t\t         2. Display All\n";
    cout << "\t\t\t\t\t         3. Search\n";
    cout << "\t\t\t\t\t         4. Update\n";
    cout << "\t\t\t\t\t         5. Delete\n";
    cout << "\t\t\t\t\t         6. Exit\n";

    int key;
    cout << "\n";
    cout << "\t\t\t\t\t  Enter your choice: ";
    cin >> key;
    return key;
}

void add_contact()
{

    cout << "\n\n\n";
    cout << "\t\t\t\t\t -----------------------------\n";
    cout << "\t\t\t\t\t |\t  Add Contact        |\n";
    cout << "\t\t\t\t\t -----------------------------\n";
    cout << "\n";

    cout << "\t\t\t\t\t  " << "Enter Name: ";
    cin >> name[k];
    cout << "\t\t\t\t\t  " << "Enter Number: ";
    cin >> number[k];
    k++;

    system("cls");

    cout << "\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t  " << "Record Inserted Succesfully\n";

    quickSort(name, 0, k-1);

    cout << "\n\t\t\t\t\t  " << "Press 0 to return. ";

    int a;
    cin >> a;
    if(a == 0) return;
}


void display()
{

    cout << "\n\n\n";
    cout << "\t\t\t\t\t -----------------------------\n";
    cout << "\t\t\t\t\t |\t  Contact List       |\n";
    cout << "\t\t\t\t\t -----------------------------\n";
    cout << "\n";

    for(int i = 0; i<k; i++)
    {
        cout << "\t\t\t\t\t  " << "Name: " << name[i] << endl;
        cout << "\t\t\t\t\t  " << "Number: " << number[i] << endl;
    }

    cout << "\n\t\t\t\t\t  " << "Press 0 to return. ";

    int a;
    cin >> a;
    if(a == 0) return;
}

void search()
{
    string n;
    int j = 0;

    cout << "\n\n\n";
    cout << "\t\t\t\t\t -----------------------------\n";
    cout << "\t\t\t\t\t |\t  Search Contact     |\n";
    cout << "\t\t\t\t\t -----------------------------\n";
    cout << "\n";
    cout << "\t\t\t\t\t  " << "Enter a name you wanna search: ";
    cin >> n;

    int left = 0, mid, right = k-1;

    while(left<=right)
    {
        mid = (left+right)/2;

        if(name[mid] == n)
        {
            cout << "\t\t\t\t\t  " << "Name: " << name[mid] << endl;
            cout << "\t\t\t\t\t  " << "Number: " << number[mid] << endl;
            j++;
        }
        if(name[mid]<n)
        {
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }

    if(j == 0) cout << "\n\t\t\t\t\t  " << "Not matched.\n";

    cout << "\n\t\t\t\t\t  " << "Press 0 to return. ";

    int a;
    cin >> a;
    if(a == 0) return;
}


void update()
{
    string n;
    int j = 0;

    cout << "\n\n\n";
    cout << "\t\t\t\t\t -----------------------------\n";
    cout << "\t\t\t\t\t |\t  Update Contact     |\n";
    cout << "\t\t\t\t\t -----------------------------\n";
    cout << "\n";

    cout << "\t\t\t\t\t  " << "Enter a name you wanna update: ";
    cin >> n;
    for(int i = 0; i<=k; i++)
    {
        if(name[i] == n)
        {
            cout << "\t\t\t\t\t  " << "Enter Name: ";
            cin >> name[i];
            cout << "\t\t\t\t\t  " << "Enter Number: ";
            cin >> number[i];
            j++;

            system("cls");

            cout << "\n\n\n\n\n\n\n\n";
            cout << "\t\t\t\t\t  " << "Record updated succesfully." << endl;
        }
    }

    quickSort(name, 0, k-1);

    if(j == 0)
        cout << "\t\t\t\t\t  " << "Record not found." << endl;

    cout << "\n\t\t\t\t\t  " << "Press 0 to return. ";

    int a;
    cin >> a;

    if(a == 0)
        return;
}


void delet()
{
    string n;
    int j = 0;

    cout << "\n\n\n";
    cout << "\t\t\t\t\t -----------------------------\n";
    cout << "\t\t\t\t\t |\t  Update Delete     |\n";
    cout << "\t\t\t\t\t -----------------------------\n";
    cout << "\n";

    cout << "\t\t\t\t\t  " << "Enter a name you wanna delete: ";
    cin >> n;
    for(int i = 0; i<=k; i++)
    {
        if(name[i] == n)
        {
            for(int l = i; l<k-1; l++)
            {
                name[l] = name[l+1];
                number[l] = number[l+1];
            }
            k--;
            j++;

            system("cls");

            cout << "\n\n\n\n\n\n\n\n";
            cout << "\t\t\t\t\t  " << "Record deleted succesfully." << endl;
        }
    }

    if(j == 0)
        cout << "\n\t\t\t\t\t  " << "Record not found." << endl;

    cout << "\n\t\t\t\t\t  " << "Press 0 to return. ";

    int a;
    cin >> a;
    if(a == 0)
        return;
}
