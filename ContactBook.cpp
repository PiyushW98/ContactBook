//imported all required library
#include<bits/stdc++.h>
#include<conio.h>
#include<fstream>
using namespace std;

class contact{
    private:
        string name, address, email;
        long long mobile_num;
    
    public:
        void createContact(){
            // Take contact detail
            cout<<"Enter the name of contact"<<endl; cin>>name;
            cout<<"Enter the address"<<endl; cin>>address;
            cout<<"Enter the email id"<<endl; cin>>email;
            cout<<"Enter the mobile number"<<endl; cin>>mobile_num;
        }

        void displayContact(){
            // Displaying contact details
            cout<<"Name : "<< name <<endl;
            cout<<"Address : "<< address <<endl;
            cout<<"Email ID : "<< email <<endl;
            cout<<"Mobile number : "<< mobile_num <<endl;
        }

        //Inserting the file 
        void writeFile(){
            char ch;
            ofstream f1;
            //f1.open("diary.txt",ios::app);
            f1.open("CMS.dat",ios::binary | ios::app);

            bool flag = false;
            do{
                string ans;
                createContact();
                f1.write(reinterpret_cast<char *>(this), sizeof(*this));
                cout<<"Do you want to enter another contact"<<endl;
                cout<<"If yes then insert yes, if not then insert no"<<endl;
                cin>>ans;
                
                if(ans == "yes"){
                    flag = true;
                }
                else{
                    flag = false;
                }
            }while(flag);

            cout<<"Contact has been successfully created...."<<endl;
        }

        //reading the file
        void readFile() {
		ifstream f2;
		f2.open("CMS.dat",ios::binary);

		cout<<"\n================================\n";
		cout<<"LIST OF CONTACTS";
		cout<<"\n================================\n";

		while(!f2.eof()) {
			if(f2.read(reinterpret_cast<char*>(this),sizeof(*this)))
			{
				displayContact();
				cout<<"\n================================\n";
			}
		}
		f2.close();
	}
        //searching the file 
        void searchFile(){
            ifstream f3;
            long long phone;
            cout<<"Enter the mobile number"<<endl;
            cin>> phone;

            f3.open("CMS.dat",ios::binary);

            while(!f3.eof()){
                if(f3.read(reinterpret_cast<char *>(this),sizeof(*this))){
                    if(phone == mobile_num){
                        displayContact();
                        return;
                    }
                }
            }
            cout<<"No contact record found"<<endl;
            f3.close();
        }

        void deleteFile(){
            long long phone;
            bool flag = false;
            ofstream f4;
            ifstream f5;

            f5.open("CMS.dat",ios::binary);
            f4.open("temp.dat",ios::binary);

            cout<<"Enter the mobile number to delete"<<endl;
            cin>>phone;

            while(!f5.eof()){
                if(f5.read(reinterpret_cast<char*>(this),sizeof(*this))){
                    if(mobile_num != phone){
                        f4.write(reinterpret_cast<char *>(this),sizeof(*this));
                    }
                    else{
                        flag = true;
                    }
                }
            }
            f4.close();
            f5.close();
            remove("CMS.dat");
            rename("temp.dat", "CMS.dat");

            if(flag)
                cout<<"Contact has been deletes"<<endl;
            else    
                cout<<"Contat not found"<<endl;
        }

        void editContact(){
            long long phone;
            fstream f6;

            cout<<"Edit Contact"<<endl;
            cout<<"Enter the contact to edit"<<endl;
            cin>>phone;

            f6.open("CMS.dat",ios::binary | ios::out | ios::in);

            while(!f6.eof()){
                if(f6.read(reinterpret_cast<char *>(this),sizeof(*this))){
                    if(phone == mobile_num){
                        cout<<"Enter the new record"<<endl;
                        createContact();

                        int pos = -1*sizeof(*this);
                        f6.seekp(pos,ios::cur);
                        f6.write(reinterpret_cast<char*>(this),sizeof(*this));
                        cout<<endl;
                        cout<<"Contact has been successfully updated.."<<endl;
                        return;
                    }
                }
            }

            cout<<"No Record has found"<<endl;
            f6.close();
        }
};

int main(){
    system("cls");
    system("Color 3F"); // Color XY, X == background color, Y == text color
    cout<<endl;
    cout<<"\n\n\n\n\t\t\t\t\t\t------------------------------";
    cout<<"\n\t\t\t\t\t\tYOKOSO WATASHI NO CONTACT BOOK   "<<endl;
    cout<<"\t\t\t\t\t\t------------------------------"<<endl;
    getch();

    while(true){
        contact c1;
        int choice;

        system("cls");
        system("Color 03");

        cout<<"Contact Manual System"<<endl;
        cout<<endl;
        cout<<"1. Add a New Number"<<endl;
        cout<<"2. Display All Numbers"<<endl;
        cout<<"3. Search for a Number"<<endl;
        cout<<"4. Edit a Number"<<endl;
        cout<<"5. Delete a Number"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<endl;
        cout<<"Please enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                system("cls");
                c1.writeFile();
                break;
            
            case 2:
                system("cls");
                c1.readFile();
                break;
            
            case 3:
                system("cls");
                c1.searchFile();
                break;

            case 4:
                system("cls");
                c1.editContact();
                break;

            case 5:
                system("cls");
                c1.deleteFile();
                break;

            case 6:
                system("cls");
                cout<<"Thank you"<<endl;
                exit(6);
                break;

            default:
                cout<<"Enter the valid option"<<endl;
                continue;
        }

        int opt;
        cout<<"Enter the choice"<<endl;
        cout<<"1. Main menu"<<endl;
        cout<<"2. Exit"<<endl;
        cin>> opt;

        switch(opt){
            case 2:
                system("cls");
                cout<<"Thank you"<<endl;
                exit(2);
                break;
            
            default:
                continue;
        }
    }
    return 0;
}