#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;

int new_word();
void all_words();
void search_word();
int menu();

int main()
{
	
	int ch=menu(); // the nuber which is returned by the function menu is returned and stored in the variable ch
					// which is furtherr paassed in swith statement.
	
	char t;
	switch(ch)
	{
		case 1: search_word();
				break;

		case 2: new_word();
			    break;
		case 3: all_words();
				break;
		case 9:	exit(1);
				break;	
		default: cout<<"invalid choise !!!";
		
	}

}
	
int menu()
{
	int ch;
	printf("===================================================================================================================================================================================================================\n");
	cout<<endl<<"                                                                                    WELCOME TO THE GPS DICTIONARY"<<endl<<endl<<endl;
	
	printf("===================================================================================================================================================================================================================\n");
	cout<<"Press 1 to search a word"<<endl;
	cout<<"Press 2 to add a new word and its meaning"<<endl;
	cout<<"Press 3 to view all the words"<<endl;
	cout<<"Press 9 to exit the dictionary"<<endl<<endl;
	printf("===================================================================================================================================================================================================================\n");
	cout<<"Please enter your choise"<<endl;
	
	cin>>ch;
	system("cls");
	
	return ch;
}	
int new_word()
	{
	int k;	
	string meaning;
	char word[26];
	ofstream thefile("dicto.txt",ios::app);
	printf("===================================================================================================================================================================================================================\n");
	cout<< "enter a word"<<endl;
	cin>>word;
	cin.ignore();    // cin.ignore() function is used when getline is used after the cin as if it is not used then the getline will not take the input from the user and it just skipps that part
	cout<<"enter the meaning"<<endl<<endl;
	getline(cin,meaning);
	cout<<"the new word and its meaning entered to the dictionary is:"<<endl;
	cout<<word<<" : "<< meaning<<endl<<endl;
	thefile<< word <<' '<<meaning<<endl;
	printf("===================================================================================================================================================================================================================\n");
	
	cout<<"Press 1 to enter another word and its meaning"<<endl;
	cout<<"Press 2 to go back to main menu"<<endl;
	cout<<"press 0 to exit"<<endl;
	cin>>k;
	system("cls");
	if(k==1)
	new_word();
	if(k==2)
	menu();
	thefile.close();
	}
	
	void all_words()
	{
	int k,no=1;	
	char word2[26];
	string meaning2;
	ifstream thefile1("dicto.txt");   // we need a different object for this class as it is a different class.
									  // if we use the same object then it will give the error.
	printf("===================================================================================================================================================================================================================\n");
	
	cout<<endl<<"                                                                                    ALL WORDS AND THEIR MEANINGS:"<<endl<<endl;
	printf("===================================================================================================================================================================================================================\n\n");
	
	

	while(!thefile1.eof())
	{
	
	thefile1>> word2;
	getline(thefile1,meaning2);  // getline is used to read the string from the file as the normal method was not reading the 
	                             //whole string but it was reaading only upto the space.
	                             // as getline is used to take input from the user so in this case the getline is
	                             // used t get the input from the file(which is basically called the reading)
	cout<<no<<".  "<<word2<<":"<<meaning2<<endl;
	fflush(stdout);printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	no++;

	}
	
	printf("===================================================================================================================================================================================================================\n");
	
	
	cout<<endl<<"Press 1 to go back to main menu"<<endl;
	
	cout<<"press 0 to exit"<<endl;
	cin>>k;
	system("cls");
	if(k==1)
	menu();
	thefile1.close();
	}

void search_word()
{
	int n,pp;
	char sword[30],word[30];
	string meaning;
	cout<<"enter the word you want to search"<<endl;
	cin>>sword;
	system("cls");
	// this comment should be ignored as i have change the settings  // here i have added the ':' this sign colon to the word as in the text file it was like this
						// if i dont use this colon with the word then it shows the message not found as the user will not
						// type the colon along with the word but in the text file they are with the colon.
	cin.ignore();  //ignor is used because the program was not stoping for the next input. 
	ifstream sthefile;
	sthefile.open("dicto.txt");
	while(!sthefile.eof())
	{
		sthefile>> word;  // for taking the word from the file.
		getline(sthefile,meaning); // for taking the meaning from the file.
		pp=stricmp(sword,word);
		if(pp==0)
		{
			printf("===================================================================================================================================================================================================================\n\n");
	
			cout<<"The meaning of the word you searched for:"<<endl<<endl;
			printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	
			cout<<endl<<word <<":"<<meaning<<endl<<endl;
			printf("===================================================================================================================================================================================================================\n\n");
	
			break;
		}
	}
	if(sword!=word)
	{
		cout<<"Entered word not found"<<endl;
	}
	cout<<"Press 1 Search another word"<<endl;
	cout<<"Press 2 to go back to menu"<<endl;
	cout<<"Press 0 for exit"<<endl;
	cin>>n;
	system("cls");
	if(n==1)
	search_word();
	if(n==2)
	menu();
}
