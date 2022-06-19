#include <iostream>
#include <fstream>
#include <string>

class contact{
private:
  std::string name;
  std::string address;
  std::string gender;
  long int number;
  int x;
public:
  void append();
  void deletec();
  void deleteall();
  void search();
};

void contact::deletec(){
  std::string find;
  std::string line;
  std::cin.ignore();
    std::cout<<"Please enter the name u wanna delete\n";
  std::getline(std::cin, find);
  std::ifstream file;
  file.open("contacts.dat");

  std::ofstream temp;
  temp.open("temp.dat");
  while(file>>name>>gender>>number>>address){
    if(name == find){
  while(getline(file, line)){
    if (line != name)
      temp<< line << std::endl;
  }
    }
      }
  file.close();
  temp.close();
  remove("contacts.dat");
  rename("temp.dat", "contacts.dat");
}

void contact::append(){
    std::cin.ignore();
    std::ofstream cnt;
    cnt.open("contacts.dat", std::ofstream::app);
    /* making a ofstream object called cnt
       and making a file from object called contacts.dat 
       and oppening it on append mode*/
    std::cout<<"Writing to the file\n";
    std::cout<<"Please enter the name\n";
    std::getline(std::cin, name);
    cnt <<name << std::endl;
    
    bool flag=true;
      while (flag){
    std::cout<<"Plase enter the gender\n";
    std::cout<<"1 ---- Male\n"<<"2 ---- female\n";
    std::cin>>x;
    if(std::cin.good()){
      if(x == 1){
	gender = "Male";
	cnt<<gender<<std::endl;
	  flag=false;
	  break;
      }
      else if(x == 2){
	gender = "Female";
	  cnt<<gender<<std::endl;
	  flag=false;
	  break;
      }
      else{
	std::cout<<"Unvalid entry\n\a";
      }
    }
    else{
    std::cout<<"unvalid entry, please enter an integer\a"<<std::endl;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
    }
      }

    flag=true;
    while(flag){
    std::cout<< "Enter the number:\n";
    std::cin >> number;
    if(std::cin.good()){
    try{
      if(number == 0){
	throw number;
      }
      else{
	cnt <<  number <<"\n";
	flag=false;
	break;
        /* since my country's calling code 
           is 98, I used this. you can change 
           it to your country's calling code */
      }
    }
    catch (...){
      std::cout<<"Unvalid entry\n\a";
    }
    }
    else{
      std::cout<<"unvalid entry, please enter an integer\a"<<std::endl;
      std::cin.clear();
      std::cin.ignore(10000, '\n');
    }
    }
    std::cin.ignore();
    std::cout<<"Enter the address\n";
    std::getline(std::cin, address);
    cnt<<address<<"\n\n";
    std::cout<<"Added Successfully";
      cnt.close();
}


void contact::deleteall(){
  std::ifstream myfile;
	  myfile.open("contacts.dat");
	    if(myfile){
	      std::remove("contacts.dat");
	      std::cout<<"cleared successfully";
		}
	      else{
		std::cout<<"\ncontacts is empty\n\a";
	      }
 }
void contact::search(){
  std::cin.ignore();
  std::ifstream sr;
  sr.open("contacts.dat");
  std::string search_name;
  bool found = false;
  gender='\0';
  std::cout<<"Enter a name for finding its phone number\n";
  std::getline(std::cin, search_name);
  while(sr){
  while(sr>>name){
    if(name == search_name){
      sr>>gender;
      std::cout<<"Name: "<<name<<std::endl;
      std::cout<<"Gender: "<<gender<<std::endl;
      sr>>number;
      std::cout<<"Number: "<<number<<std::endl;
      sr>>address;
      std::cout<<"Address: "<<address<<std::endl;
      found=true;
      break;
    }
  }
  }
  if (found==false){
    std::cout<<search_name<<" not found";
  }
  sr.close();
}
int main(){
  contact cont;
  int choice;
     while (1) {
       std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~WELCOME~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~\n\n" ;
	std::cout << "Enter Your Choice\n";
	std::cout << "\t1. Add contact \n";
	std::cout << "\t2. Display Contacts \n";
	std::cout << "\t3. Delete a Contact\n";
	std::cout << "\t4. Find contacts\n";
	std::cout << "\t5. Modify contact\n";
	std::cout << "\t6. Clear contacts\n";
	std::cout << "\t0. exit\n";
	std::cin >> choice;

	switch(choice){
	case 1:
	  cont.append();
	  break;
	case 2:{
	  std::ifstream f;
	  f.open("contacts.dat");
	  if (f){
	    std::cout << f.rdbuf();
	  }
	  else{
	    std::cout<<"contacts is empty\n\a";
	  }
	  break;
	}
	case 3:{
	  cont.deletec();
	  break;
	}
	case 4:{
	  cont.search();
	  break;
	}
	case 6:{
	  cont.deleteall();
	  break;
	}
	case 0:{
	  exit(1);
	  break;
	}
	default:
	  std::cout<<"\ninvalid Choice\n\a";
	}
     }
}
