#include<iostream>
#include<fstream>
#include<stdio.h>
#include "Criminal.h"
using namespace std;
bool found = false;
class node
{

public:
    node* next;

    int c_id;
    int c_age;
    string c_name;
    string c_gender;
    string c_penalty;
    string c_offense;
    string c_offenseDate;
};
node *head, *tail;
void FileUpdate()
{
    node* temp = head;
        ofstream ofs("CriminalRecord.txt");
        while(temp != NULL)
        {
        ofs<<temp->c_id<<" "<<temp->c_name<<" "<<temp->c_age<<" "<<temp->c_gender<<" "<<temp->c_offense<<" "<<temp->c_offenseDate<<" "<<temp->c_penalty<<endl;
        temp = temp->next;
        }
        ofs.close();
}
void insertNode(Criminal inp)
{
    node *tl, *ins;

    ins= new node();
    ins->c_id=inp.id;
    ins->c_age=inp.age;
    ins->c_name=inp.name;
    ins->c_gender=inp.gender;
    ins->c_offense=inp.offense;
    ins->c_penalty=inp.penalty;
    ins->c_offenseDate=inp.offenseDate;
    ins->next=NULL;
    if(head==NULL || head->c_id>=inp.id)
    {
        ins->next=head;
        head=ins;

    }
    else
    {
        tl=head;
        while(tl->next!=NULL && tl->next->c_id<inp.id)
            tl=tl->next;
        ins->next=tl->next;
        tl->next=ins;
    }
}

//----------------------------------
bool CheckID(int id)
{
    bool found = false;
    node* temp = head;
    while(temp != NULL)
    {
        if(id == temp->c_id)
        {
            found = true;
            break;
        }
        temp = temp->next;
    }
    return found;
}
//----------------------------------
void ShowData(node* track)
{
    cout<<"Showing Search Result "<<endl;
    cout<<"______________________"<<endl;
    cout<<"ID : ";
    cout<<track->c_id<<"\n";
    cout<<"Name : ";
    cout<<track->c_name<<"\n";
    cout<<"Age : ";
    cout<<track->c_age<<"\n";
    cout<<"Gender : ";
    cout<<track->c_gender<<"\n";
    cout<<"Offense : ";
    cout<<track->c_offense<<"\n";
    cout<<"OffenseDate : ";
    cout<<track->c_offenseDate<<"\n";
    cout<<"Penalty : ";
    cout<<track->c_penalty<<"\n";
    cout<<"______________________"<<endl;
}
//----------------------------------
//Function to insert input at the front of the list

void UpdateData(node* address)
{
    node* track = address;


    int choice;
    cin>>choice;
    if(choice != 0)
    {
        switch(choice)
        {
        case 1:
        {
            int id;
            cout<<"Update ID : ";
            cin>>id;
            track->c_id = id;
            cout<<"Id Updated"<<endl;
            UpdateData(track);
            break;
        }
        case 2:
        {
            string name;
            cout<<"Update Name : ";
            cin>>name;
            track->c_name = name;
            cout<<"Name Updated"<<endl;
            UpdateData(track);
            break;
        }
        case 3:
        {
            int age;
            cout<<"Update age : ";
            cin>>age;
            track->c_age = age;
            cout<<"Age Updated"<<endl;
            UpdateData(track);
            break;
        }
        case 4:
        {
            string gender;
            cout<<"Update Gender : ";
            cin>>gender;
            track->c_gender = gender;
            cout<<"Gender Updated"<<endl;
            UpdateData(track);
            break;
        }
        case 5:
        {
            string offense;
            cout<<"Update Offense : ";
            cin>>offense;
            track->c_offense = offense;
            cout<<"Offense Updated"<<endl;
            UpdateData(track);
            break;
        }
        case 6:
        {
            string offenseDate;
            cout<<"Update Offense : ";
            cin>>offenseDate;
            track->c_offenseDate = offenseDate;
            cout<<"OffenseDate Updated"<<endl;
            UpdateData(track);
            break;
        }
        case 7:
        {
            string penalty;
            cout<<"Update penalty : ";
            cin>>penalty;
            track->c_penalty = penalty;
            cout<<"Penalty Updated"<<endl;
            UpdateData(track);
            break;
        }
        }
    }
    else
    {
        FileUpdate();

    }
}
//----------------------------------
void Insert( Criminal s)
{

    ofstream myfil("CriminalRecord.txt",ios :: app);
    if(!myfil)
    {
        cout<<"File coudn't be opened"<<endl;
    }
    else
    {
        myfil<<s.id<<" "<<s.name<<" "<<s.age<<" "<<s.gender<<" "<<s.offense<<" "<<s.offenseDate<<" "<<s.penalty<<endl;
    }
    myfil.close();

    insertNode(s);
}
//----------------------------------
node* SearchByID(int id)
{
    int choice;
    node* temp = head;
    node* temp2;
    while(temp != NULL)
    {
        if(id == temp->c_id)
        {
            temp2 = temp;
            cout<<"Id found."<<endl;
            cout<<"Press 1 to see the search result."<<endl;
            cin>>choice;
            if(choice == 1)
            {
                ShowData(temp);
            }
            break;
        }
        temp = temp->next;
    }
    return temp2;
}
//----------------------------------
node* SearchByName(string name)
{
    node* temp = head;
    node* temp2;
    while(temp != NULL)
    {
        if(name == temp->c_name)
        {
            temp2 = temp;
            cout<<"name found."<<endl;
            cout<<"Press 1 to see the search result."<<endl;
            int choice;
            cin>>choice;
            if(choice == 1)
            {
                ShowData(temp);
            }
        }
        temp = temp->next;

    }
    return temp2;
}
//----------------------------------
node* SearchByOffense(string offense)
{
    node* temp = head;
    node* temp2;
    while(temp != NULL)
    {
        if(offense == temp->c_offense)
        {
            temp2 = temp;
            cout<<"offense found."<<endl;
            cout<<"Press 1 to see the search result."<<endl;
            int choice;
            cin>>choice;
            if(choice == 1)
            {
                ShowData(temp);
            }
        }
        temp = temp->next;
    }
    return temp2;
}

//----------------------------------
bool CheckData(int id)
{
    bool found;
    node* temp = head;
    while(temp != NULL)
    {
        if(id == temp->c_id)
        {
            found = true;
            break;
        }
        temp = temp->next;
    }
    return found;
}
//----------------------------------
//Show the output
void Print()
{
    node* temp = head;
    cout<<"___________________________________"<<endl;
    cout<<"\tShowing Output"<<endl;
    cout<<"___________________________________"<<endl;


    while(temp!=NULL)
    {
        cout <<"Id : "<<temp->c_id<<endl;
        cout<< "Name : " << temp->c_name <<endl;
        cout<< "Age : " << temp->c_age <<endl;
         cout<<"Gender : "<< temp->c_gender <<endl;
         cout<<"Offense : " << temp->c_offense << endl;
         cout<<"OffenseDate : " << temp->c_offenseDate << endl;
         cout<<"Penalty : " << temp->c_penalty << endl;
         cout<<"___________________________________"<<endl;

        temp = temp->next;
    }

}
//----------------------------------
void DeleteAtFirst()
{
    node* temp = head;
    if(head != NULL)
    {
        head = head->next;
    }
    delete temp;
}
//----------------------------------


void DeleteData(int id)
{
    node* temp = head;
    if(id == head->c_id)
    {
        DeleteAtFirst();
    }
    else
    {
        while(temp->next->c_id != id)
        {
            temp = temp->next;
        }
        node* temp2 = temp->next;
        temp->next = temp2->next;

        delete temp2;

    }
    FileUpdate();

}
//----------------------------------
//Main Menu
void Menu(int choice)
{

    if(choice != 0)
    {
        switch(choice)
        {
        case 1 :
        {
                Criminal s;

                cout<<"ID : ";
                cin>>s.id;
                cout<<"Name : ";
                cin>>s.name;
                cout<<"Age : ";
                cin>>s.age;
                cout<<"Gender : ";
                cin>>s.gender;
                cout<<"Offense : ";
                cin>>s.offense;
                cout<<"OffenseDate : ";
                cin>>s.offenseDate;
                cout<<"Penalty : ";
                cin>>s.penalty;
                Insert(s);

                cout<<"Select option(1-5) :\n";
                cin>>choice;
                Menu(choice);
                break;
        }
        case 2:
        {
            cout<<"Search By :"<<endl;
            cout<<"\t"<<"1.Name"<<endl;
            cout<<"\t"<<"2.ID"<<endl;
            cout<<"\t"<<"3.Offense"<<endl;
            cout<<"Enter option : ";
            int choice2;
            cin>>choice2;
            switch(choice2)
            {
            case 1:
            {
                cout<<"Enter Name : ";
                string name;
                cin>>name;
                SearchByName(name);
                cout<<"Select option(1-5) :\n";
                cin>>choice;
                Menu(choice);
                break;
            }
            case 2:
            {
                cout<<"Enter Id : ";
                int id;
                cin>>id;
                SearchByID(id);
                cout<<"Select option(1-5) :\n";
                cin>>choice;
                Menu(choice);
                break;
            }
            case 3:
            {
                cout<<"Enter Offense : ";
                string offense;
                cin>>offense;
                SearchByOffense(offense);
                cout<<"Select option(1-5) :\n";
                cin>>choice;
                Menu(choice);
                break;
            }

            }
            break;
        }
        case 3:
        {
            cout<<"Enter ID you want to delete"<<endl;
            cout<<"ID : ";
            int id;
            cin>>id;
            if(CheckData(id))
            {
                DeleteData(id);
                cout<<"Deleted"<<endl;
            }
            else
                cout<<"not found"<<endl;
            cout<<"Select option(1-5) :\n";
            cin>>choice;
            Menu(choice);
            break;
        }

        case 4:
        {
            cout<<"Search ID you want to Update : "<<endl;
            int id;
            cin>>id;
            if(CheckID(id))
            {

                node* x = SearchByID(id);
                cout<<"Press 0 to go back to main menu"<<endl;
                cout<<"Or->"<<endl;
                cout<<"1.Update Id"<<endl;
                cout<<"2.Update Name"<<endl;
                cout<<"3.Update Age"<<endl;
                cout<<"4.Update Gender"<<endl;
                cout<<"5.Update Offense"<<endl;
                cout<<"6.Update OffenseDate"<<endl;
                cout<<"7.Update Penalty"<<endl;
                UpdateData(x);
            }
            else
                cout<<"Id not found"<<endl;
            cout<<"Select option(1-5) :\n";
            cin>>choice;
            Menu(choice);
            break;
        }

        case 5:
        {
            Print();
            cout<<"Select option(1-5) :\n";
            cin>>choice;
            Menu(choice);
            break;
        }
        }
    }
    else
    {
        cout<<"Exited";
    }
}



void inputFromFile()
{
    Criminal s;
    ifstream temp("CriminalRecord.txt");
    while(temp>>s.id>>s.name>>s.age>>s.gender>>s.offense>>s.offenseDate>>s.penalty)
    {
        insertNode(s);
    }
    temp.close();
}


//----------------------------------
int main()
{
    head = NULL;
    inputFromFile();
    cout<<"___________________________________"<<endl;

    cout<<"---MENU---"<<endl;
    cout<<"___________________________________"<<endl<<endl;

    cout<<"Select option(1-5) :\n";
    cout<<"1.INSERT\n";
    cout<<"2.SEARCH\n";
    cout<<"3.DELETE\n";
    cout<<"4.UPDATE\n";
    cout<<"5.SHOW\n";
    cout<<"Or press 0 to exit"<<endl;
    cout<<"___________________________________"<<endl;
    int choice;
    cin>>choice;



    Menu(choice);



    return 0;
}
//----------------------------------

