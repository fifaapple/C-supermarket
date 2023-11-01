#include<iostream>
#include<cstdio>
#include<conio.h>
#include<fstream>
#include<string>
#include<windows.h>
#include<iomanip>

using namespace std;

void Supermarket_Database_Menu();

void Add_new_item();
void Delete_item();
void Edit_item();
void Sort_items();
void Search_for_item();
void Display_items();
void About();

void Fading_output(string, int);
void make_liter_cabital(string &name);

int getint(int);
void Drow();
void Bootup();

void D_Add()
{
cout<<"\n-----------------------------------------You Are In The Supermarket Database--------------------------------------------"<<endl;
	cout<<"                                                << Adding an Item >>\n"<<endl;
}

void D_Delete()
{
	cout<<"\n-----------------------------------------You Are In The Supermarket Database--------------------------------------------"<<endl;
	cout<<"                                               << Deleting an Item >>\n"<<endl;
}

void D_Edit()
{
	cout<<"\n-----------------------------------------You Are In The Supermarket Database--------------------------------------------"<<endl;
	cout<<"                                                << Editing an Item >>\n"<<endl;
}

void D_Sort()
{
	cout<<"\n-----------------------------------------You Are In The Supermarket Database--------------------------------------------"<<endl;
	cout<<"                                                << Sorting Items >>\n"<<endl;
}

void D_Display()
{
	cout<<"\n-----------------------------------------You Are In The Supermarket Database--------------------------------------------"<<endl;
	cout<<"                                              << displaying Items >>\n"<<endl;
}

void D_Search()
{
	cout<<"\n-----------------------------------------You Are In The Supermarket Database--------------------------------------------"<<endl;
	cout<<"                                             << Searching for an Item >>\n"<<endl;
}


struct Items
{
	string  Name;
	int     Quantity;
	double     Price;
};  Items item;



int main(){
Bootup();	

int Choice_number;
bool stop=true;

while(stop)
	{
	system("cls");system("color 0b");
	Drow();
	Supermarket_Database_Menu();

	cout<<"\n   Enter choice number: ";
	Choice_number=getint(Choice_number);
	cin.ignore();


		switch(Choice_number)
		{
			case 1: Add_new_item(); break;
			case 2: Delete_item(); break;
			case 3: Edit_item(); break;
			case 4: Sort_items();break;
			case 5: Display_items(); break;
			case 6: Search_for_item(); break;
			case 7: exit(0);
			case 8: system("cls"); About(); system("pause"); break;
			default: cout<<"\a\n\n\tInvalid choice number! "<<endl;; 
			
			
			Sleep(1700);
		}

	}
		return 0;
}

int getint(int a)//function accept only integers.
{
	while(!(cin>>a))
	{
	cout<<"\a\tPlese enter an integer value:";
	cin.clear();
	cin.ignore(100,'\n');
	}
	return a;
}

double get_double(double a)//function accept only integers.
{
	while(!(cin>>a))
	{
	cout<<"\a\tPlese enter an integer value:";
	cin.clear();
	cin.ignore(100,'\n');
	}
	return a;
}

void Fading_output(string show, int speed=10)
{
	for(int i=0; i<show.length(); i++)
	{
		cout<<show[i];
		Sleep(speed);
	}

}


void make_liter_cabital(string &name)
	{
		int value, length;
	
		length=name.length();
		
		for(int i=0; i<length; i++)
		{
			if(name[i] < 97 && name[i] >= 65 )
			{
				value = static_cast<int>(name[i] + 32);
				name[i] = static_cast<char>(value);
			}
		}
	
	}
	


void Add_new_item()
{system("color 0b");
	a:
		
	string Item;
	bool flag=0;
	int Stop_asking_counter=0;
	char choice;
	
	system("cls");
	
	/*opening the items names file in case it is
		exist or making a new one in case it is not*/
	fstream items_names1("items_names.txt", ios::app | ios::out);
	
	
	//Item's name input validation..
	while(1)
	{
		if(Stop_asking_counter != 0)
		{
			system("cls");
			Drow();
			D_Add();
			Fading_output("   <<\a The item's name is already used! >>\n");
			Fading_output("\n\n1) Enter another name for the item: ");
		}
		else 
		{
			Drow();
			D_Add();
			Fading_output("   <<Press \"b\" to get back>>   (or)\n\n\n1) Enter the item's name: ");
		}
		
		getline(cin, item.Name);
		make_liter_cabital(item.Name);
		
	if(item.Name == "b")
	return;
	
	//Make sure that the user does not enter one leter as an item name..
	if(item.Name.length() == 1 || item.Name.length() == 0)
	{
			system("cls");
			Drow();
			D_Add();
			Fading_output("   <<\a The item's name can't be only 1 letter! >>\n");
			Fading_output("\n\n1) Enter another item name: ");
			getline(cin, item.Name);
			make_liter_cabital(item.Name);
			
			if(item.Name.length() == 1 || item.Name.length() == 0)
			{
			Fading_output("\a\n\n   << Sorry, Try again later >>");
			Sleep(1800);
			return;
			}
	}
	
	//opening the file for reading..
	ifstream items_names2("items_names.txt");
	
	//check whether the new item's name is exist in the file
		while(items_names2>>Item)
		{
			if(Item==item.Name)
			{
			flag=1;
			break;
			}
			else flag=0;
		}
	
	/*if the name is not used stop the input validation 
	and keep processing the rest of the function*/
		if(flag==0)
		break;
	
	//Else, limiting the input validation only for two times..
	if(Stop_asking_counter==2)
		{
			Fading_output("\a\n\n   << Sorry, Try again later >>");
			Sleep(1700);
			return;
		}
		
		Stop_asking_counter++;
	}
	
	
	//Adding the item's name to the items names file
	items_names1<<item.Name<<endl;
	items_names1.close();
	
	
	//asking for the price and the quantity
	
	Fading_output("\n   2) Enter the quantity of the item: ");
	item.Quantity = getint(item.Quantity);
	cin.ignore();
	
	Fading_output("\n      3) Enter the price of each item: ");
	item.Price = get_double(item.Price);
	cin.ignore();
	
	
	//preparing the File name for each item..
	string item_nameTXT;
	item_nameTXT = item.Name + ".txt";
	
	//opening a new file for each new item..
	ofstream itemsfile(item_nameTXT.c_str());
	itemsfile<<item.Quantity<<endl;
	itemsfile<<item.Price<<endl;
	itemsfile.close();
	//.....................................
	
	system("cls");
	Drow();
	D_Add();
	Fading_output("\n   << The item was added successfully >>");
	Sleep(1800);
	
	b:
		//Asking user whether they want to add an item again
	system("cls");
	Drow();
	D_Add();
	Fading_output("   Do you want to add another item? (y/n) ");
	choice= getche();
	
	//input validation
	switch(choice)
	{
		case 'Y':
		case 'y': goto a; break;
		case 'N':
		case 'n': break;
		
		default: cout<<"\a\n\n\tInvalid choice! "<<endl;
				 Sleep(1300);
				 goto b;
	}
	
	return;
}







void Delete_item()
{
	a:
	system("color 0b");
	system("cls");
	int counter=1, status, name_counter=0, Stop_asking_counter=0;
	string Item, filename,test, name[1000];
	bool flag;
	char choice;
	
	
	//checking whether there is a content in the file..
	ifstream items_names("items_names.txt");
	if(!(items_names>>test))
	{Drow();
	D_Delete();
		Fading_output("\a\n   << There is no item to delete >>");
		Sleep(1700);
		return;
	}
	items_names.close();
	Drow();
	D_Delete();
	
	//listing the items in case there is a content
	cout<<"\n   	<< The items list >> \n";
	cout<<"   _______________________________\n"<<endl;
	ifstream items_names1("items_names.txt");
	while(items_names1>>Item)
	{
		cout<<"    "<<counter<<". "<<Item<<endl;
		counter++;
	}
	items_names1.close();
	cout<<"   _______________________________\n"<<endl;
	
	
	
	do
	{
		if(Stop_asking_counter != 0)
		{
			system("cls");
			Drow();
			D_Delete();
		
			counter=1;
		
		
			cout<<"\n   	<< The items list >> \n";
	  		cout<<"   _______________________________\n"<<endl;
			ifstream items_names9("items_names.txt");
			while(items_names9>>Item)
			{
				cout<<"    "<<counter<<". "<<Item<<endl;
				counter++;
			}
			items_names1.close();
			cout<<"   _______________________________\n"<<endl;
		
		
			Fading_output("\a\n   << There is no such an item! >>");
			Fading_output("\n   Please enter valid item name: ");
		}
		else Fading_output("\n   <<Press \"b\" to get back>>   (or)\n   Enter the item's name you want to delete: ");
		
		
		getline(cin, item.Name);
		make_liter_cabital(item.Name);
		
		if(item.Name =="b")
		return;
	
	
	//check whether the new item's name is exist in the file
		ifstream items_names2("items_names.txt");
		while(items_names2>>Item)
		{
			if(Item == item.Name)
			{
			flag = 1;
			break;
			}
			else flag = 0;
			
		}
		items_names2.close();
	
	/* if the name is not used stop the input validation 
	and keep processing the rest of the function */
		if(flag == 1)
		break;
	
	//Else, limiting the input validation only for two times..
	if(Stop_asking_counter==2)
		{
			Fading_output("\a\n   << Sorry, Try again later >>");
			Sleep(1700);
			return;
		}
		
		Stop_asking_counter++;
	}
	while(1);
	
	
	filename = item.Name + ".txt";
	
	//Deleting the item's file..
	status = remove(filename.c_str());
	if(status==0)
	{
	system("cls");
	Drow();
	D_Delete();
	Fading_output("\n   << Item was deleted successfully >>\n");
	Sleep(1700);
	}
	else
	{
		Fading_output("\a\n   << Faild to delete the item! >>\n");
		Sleep(1700);
		return;
	}
	
	
	//deleting the item from the items names file..
	ifstream items_names3("items_names.txt");
	while(items_names3>>test)
	{
		if (test!=item.Name)
		{
		name[name_counter]=test;
		name_counter++;
		}
	}
	
	//Deleting the old items names file and create new one..
	ofstream items_names4("items_names.txt");
	
	for(int i=0; i < name_counter; i++)
	{
		items_names4<<name[i]<<endl;
	}
	
	items_names4.close();
	
	ifstream items_names5("items_names.txt");
	
	if(items_names5 >> test)
	{
	b:
	system("cls");
	Drow();
	D_Delete();
	Fading_output("\n   Do you want to delete another item? (y/n) ");
	choice= getche();
	
	//input validation
	switch(choice)
	{
		case 'Y':
		case 'y': goto a; break;
		case 'N':
		case 'n': break;
		
		default: cout<<"\a\n\n\tInvalid choice! "<<endl;
				 Sleep(1300);
				 goto b;
	}
	
	}
	else return;
}






void Edit_item()
{
	a:
	system("color 0b");
	system("cls");
	string Item, filename, test;
	int counter=1, Stop_asking_counter=0;
	bool flag=0;
	char choice;

	ifstream items_names("items_names.txt");
	if(!(items_names>>test))
	{
		Drow();
		D_Edit();
		Fading_output("\a\n   << There is no item to edit >>");
		Sleep(1700);
		return;
	}
	
	 //opening th file and listing the items...
	  Drow();
	  D_Edit();
	  cout<<"\n   	<< The items list >> \n";
	  cout<<"   _______________________________\n"<<endl;
	  
	ifstream items_names1("items_names.txt");
	while(items_names1>>Item)
	{
		cout<<"    "<<counter<<". "<<Item<<endl;
		counter++;
	}
	items_names1.close();
	cout<<"   _______________________________\n"<<endl;

	
	//User input validation..
	do
	{
		if(Stop_asking_counter!=0)
		{
			system("cls");
			Drow();
			D_Edit();
		
			counter=1;
		
		
			cout<<"\n   	<< The items list >> \n";
	  		cout<<"   _______________________________\n"<<endl;
			ifstream items_names9("items_names.txt");
			while(items_names9>>Item)
			{
				cout<<"    "<<counter<<". "<<Item<<endl;
				counter++;
			}
			items_names1.close();
			cout<<"   _______________________________\n"<<endl;
		
			Fading_output("\n   << Item is not exist! >>\n");
			Fading_output("   Enter another valid item name to edit: ");
		}
		else  Fading_output("\n   <<Press \"b\" to get back>>   (or)\n   Enter the item's name you want to edit: ");
	
	
	getline(cin, item.Name);
	make_liter_cabital(item.Name);
	
	if(item.Name=="b")
	return;
	
	
	
	//opening the file for reading..
	ifstream items_names2("items_names.txt");
	
	//check whether the item's name is exist in the file
	while(items_names2>>Item)
	{
		if(Item==item.Name)
		{
		flag=1;
		break;
		}
	}
	
	if(flag==1)
	break;
	
	//limiting the input validation only for three times..
	Stop_asking_counter++;
	
	if(Stop_asking_counter==3)
	{
		Fading_output("\a\n   << Sorry, Try again later >>");
		Sleep(1700);
		return;
	}

	}
	while(flag==0);
	
	system("cls");
	Drow();
	D_Edit();
		
	cout<<"\n\n   << Item choosed is "<<item.Name<<" >>";
	Fading_output("\n\n1) Enter the item's new quantity: ");
	item.Quantity = getint(item.Quantity);
	cin.ignore();

	Fading_output("\n   2) Enter the new price of each item: ");
	item.Price = get_double(item.Price);
	cin.ignore();
	
	filename = item.Name + ".txt";
	
	//re-opening the file for each new item..
	ofstream itemsfile(filename.c_str());
	itemsfile<<item.Quantity<<endl;
	itemsfile<<item.Price<<endl;
	itemsfile.close();
	
	system("cls");
	Drow();
	D_Edit();
	Fading_output("\n\n   << Item was edited successfully >>");
	Sleep(1700);
	
	
	ifstream items_names5("items_names.txt");
	
	if(items_names5 >> test)
	{
	b:
	system("cls");
	Drow();
	D_Edit();
	Fading_output("\n\n   Do you want to edit another item? (y/n) ");
	choice= getche();
	
	//input validation
	switch(choice)
	{
		case 'Y':
		case 'y': goto a; break;
		case 'N':
		case 'n': break;
		
		default: cout<<"\a\n\n\tInvalid choice! "<<endl;
				 Sleep(1300);
				 goto b;
	}
	
	}
	else return;
}





void Sort_items()
{
	system("color 0b");
	system("cls");
	Drow();
	D_Sort();
	
	int i=0,n=0,j=0;
	string name,test,temp;
	
	
	//checking whether there is a content in the file..
	ifstream items_names("items_names.txt");
	if(!(items_names>>test))
	{
		
		Fading_output("\a\n\n   << There is no item to sort >>");
		Sleep(1700);
		return;
	}
	items_names.close();
	
	ifstream items_names0("items_names.txt");
	while(items_names0 >> name)//Count the Names in the file 
	{
		j++;
	}
	items_names0.close();
	
	string items[j];
	
	ifstream items_names1("items_names.txt");
	while(items_names1 >> name)//Read the Names in the file 
	{
		items[i] = name;
		i++;
	}
	//Sort the items
	n = i;
	for(int i =0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(items[j] > items [j+1]){
				temp = items[j];
				items[j] = items[j+1];
				items[j+1] = temp;
			}
		}
	}
	items_names1.close();
	ofstream items_names2("items_names.txt");//print sorted items to the file..
	for(i=0;i<n;i++){
		items_names2 << items[i]<<endl;
	}
	items_names2.close();
	Fading_output("\n\n   << Items were Sorted successfully >>");
	Sleep(1700);
	return;
}




void Display_items()
{
	system("color 0b");
	system("cls");
	Drow();
	D_Display();
	
	int counter=1, info_counter=0, x=1;
	string Item, info[2]={"Quantity= ", "Price= $"}, filename;
	char press;
	double details;
	
	ifstream items_names("items_names.txt");
	if(!(items_names>>Item))
	{
		Fading_output("\a   << There is no item to display >>");
		Sleep(1700);
		return;
	}
	
	cout<<"\n   		 << The items list >> \n";
	cout<<"   _________________________________________________________________\n"<<endl;
	ifstream items_names1("items_names.txt");
	while(items_names1>>Item)
	{
		info_counter=0;   x=1;
		
		cout<<"    "<<counter<<". "<<left<<setw(30)<<Item;
		counter++;
		
		filename= Item + ".txt";
		
		ifstream item_detail(filename.c_str());
		while(item_detail>>details)
		{
			if(x >= 1)
			{
				cout<<info[info_counter]<<details<<"     ";
				info_counter++;
			}
			x++;	
		}
		cout<<endl;
			
	}
	cout<<"   _________________________________________________________________"<<endl;
	cout<<endl;
	system("pause");
	return;
}




void Search_for_item()
{
	system("color 0b");
	int Stop_asking_counter=0, info_counter=0, x=1;
	string  info[2]={"Quantity= ", "|   Price= $"}, filename, Item;
	double details;
	bool flag;
	char press;
	
	system("cls");
	Drow();
	D_Search();
	
	ifstream items_names("items_names.txt");
	if(!(items_names>>Item))
	{
		Fading_output("\a   << There is no item to search for >>");
		Sleep(1700);
		return;
	}
	
	
	do
	{
		if(Stop_asking_counter != 0)
		{
			system("cls");
			Drow();
			D_Search();
			
			Fading_output("\a\n\n   << There is no such an item! >>");
			Fading_output("\n\n     Please enter valid item name: ");
		}
		else Fading_output("\n\n   <<Press \"b\" to get back>>   (or)\n   Enter the item's name: ");
		
		getline(cin, item.Name);
		if(item.Name=="b")
		return;
		cout<<endl;
	
	//check whether the new item's name is exist in the file
		ifstream items_names2("items_names.txt");
		while(items_names2>>Item)
		{
			if(Item == item.Name)
			{
			flag = 1;
			break;
			}
			else flag = 0;
			
		}
		items_names2.close();
	
	/* if the name is not used stop the input validation 
	and keep processing the rest of the function */
		if(flag == 1)
		break;
	
	//Else, limiting theq input validation only for two times..
	if(Stop_asking_counter==2)
		{
			Fading_output("\a\n   << Sorry, Try again later >>");
			Sleep(1700);
			return;
		}
		
		Stop_asking_counter++;
	}
	while(1);
	
		
		filename= item.Name + ".txt";
		cout<<"   << ";
		ifstream item_detail(filename.c_str());
		while(item_detail>>details)
		{
				cout<<info[info_counter]<<details;
				if(info_counter!=1)
				cout<<"   ";
				info_counter++;	
		}
		cout<<" >>";
		cout<<endl<<endl<<endl;
		
	cout<<"\n\n   ";
	system("pause");
	return;
			
	}
	
void Supermarket_Database_Menu()
{
		cout<<"\n-----------------------------------------You Are In The Supermarket Database--------------------------------------------\n"
		<<"\t\t             __________________________________________________________\n"
	    <<"\t\t            |                                                          |\n"
	    <<"\t\t         _  |   1.{New item}    2.{Delete item}    3.{Edit item}       |  _   \n"
	    <<"\t\t      _ / ) |                                                          | ( \\ _     \n"
	    <<"\t\t  _  / / /  |   4.{Sort item}   5.{Display items}  6.{Search for item} |  \\ \\ \\  _\n"
	    <<"\t\t | )/ / / __|                                                          |__ \\ \\ \\( |\n"
	    <<"\t\t | / / / / _| _ 7.{Exit}        8.{About Us}                         _ |_ \\ \\ \\ \\ |\n"
	    <<"\t\t | | | `'  )|/(|____________________________________________________|)\\|(  '' | | |\n"
	    <<"\t\t |         \\ \\  \\                                                  /  / /         |\n"
	    <<"\t\t \\          \\|  |                                                  |  |/          /\n"
	    <<"\t\t  \\             |                                                  |             /\n"
	    <<"\t\t   \\           /                                                    \\           /\n"
	    <<"\t\t    \\         /                                                      \\         /\n"
	    <<"\t\t    )        /                                                        \\        (\n"
	    <<"\t\t   /        /                                                          \\        \\\n"
	    <<"\t\t  /________/                                                            \\________\\\n";
}
	
void Drow()
{	cout<<"\t\t\t    __ _   _ _ __   ___ _ __ _ __ ___   __ _ _ __ _        _"<<endl
		<<"\t\t\t  / __| | | | '_ \\ / _ \\ '__| '_ ` _ \\ / _` | '__| |      | |\n"
	    <<"\t\t\t  \\__ \\ |_| | |_) |  __/ |  | | | | | | (_| | |  | | _____| |_\n"
		<<"\t\t\t  |___/\\__,_| .__/ \\___|_|  |_| |_| |_|\\__,_|_|  | |/ / _ \\ __|\n"
		<<"\t\t\t            | |                                  |   <  __/ |_\n"
		<<"\t\t\t            |_|                                  |_|\\_\\___|\\__|\n";
}

void Bootup()
{
	system("color 0b");
Sleep(2000);
cout<<"\n\n\n\n\n\n\n\n";
cout<<"\t.d8888b 888  888  88888b.   .d88b.  888d888 88888b.d88b.  ,adPPYYba, 888d888 888               888\n"
	     <<"\t88K     888  888  888 \"88b d8P  Y8b 888P\"   888 \"888 \"88b \"\"     'Y8 888P\"   888               888\n"
	     <<"\t\"Y8888b 888  888  888  888 88888888 888     888  888  888 ,adPPPPP88 888     888  888  .d88b.  888888\n"
	     <<"\t    X88 Y88b 888  888 d88P Y8b.     888     888  888  888 88,    ,88 888     888 .88P d8P  Y8b 888  \n"
	     <<"\t 88888P'\"Y888888| 88888P\"  \"Y8888   888     888  888  888 '\"8bbdP\"Y8 888     888888K 888888888 888\n"
	     <<"\t		  888					   		     888 \"88b Y8b.    Y88b.\n"
	     <<"\t		  888						             888  888 \"Y8888   \"Y888\n"
	     <<"\t		  888\n";
cout<<"\n\n\n\n\t\t       Loading ";Sleep(800);
	for(int i;i<30;i++){
		cout<<"� ";Sleep(10);}
Sleep(1500);
system("cls");
Sleep(100);
}

void About(){
	system("color 0b");
	
	cout<<"\t\t\t   ____________________________________________________\n"
	    <<"\t\t\t   :   ____________________________________________   :\n"
	    <<"\t\t\t   `.  `.                                        .'  .'\n"
	    <<"\t\t\t    :   :   Akram Al-Hamdani       ID:23160049   :   :\n"
	    <<"\t\t\t    `.  `.                                      .'  .'\n"
	    <<"\t\t\t     :   :   Osama Al-Safwani     ID:23160068   :   :\n"
	    <<"\t\t\t     `.  `.                                    .'  .'\n"
	    <<"\t\t\t      :   :    Zeiad Shadi       ID:23160100   :   :\n"
	    <<"\t\t\t      `.  `.                                  .'  .'\n"
	    <<"\t\t\t       :   :__________________________________:   :\n"
	    <<"\t\t\t       `.                 IT1.AM                 '\n"
	    <<"\t\t\t        '-------------|  |-----|  |--------------'\n"
	    <<"\t\t\t       .\"\"\"\"\"\"\"\"\"\"\"\"\"\"|  |\"\"\"\"\"|  |\"\"\"\"\"\"\"\"\"\"\"\"\"\".\n"
	    <<"\t\t\t       |  ()          '-----------'      o   ()  |\n"
	    <<"\t\t\t       |   ___________________________________   |\n"
	    <<"\t\t\t       |  :__|__|__|__|__|__|__|__|__|__|__|__:  |\n"
	    <<"\t\t\t       |  |___|__|__|__|__|__|__|__|__|__|__|_|  |\n"
	    <<"\t\t\t       |  :__|_|__|__|__|__|__|__|__|__|__|___:  |\n"
	    <<"\t\t\t       |  |___|__|___________________|__|__|__|  |\n"
	    <<"\t\t\t       |             .-------------.             |\n"
	    <<"\t\t\t       |             |             |             |\n"
	    <<"\t\t\t       |             |______ ______|             |\n"
	    <<"\t\t\t       |             '._____|_____.'             |\n"
	    <<"\t\t\t       '-----------------------------------------'\n";
}
	
