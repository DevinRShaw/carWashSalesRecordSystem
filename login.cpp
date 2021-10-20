//carwash employee sales rate registration and login system
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//username and password validation
string username, password, storedUsername, storedPassword;

//how we will deal with our files
ofstream file;

//user info stored in files
string salesAttempted, salesMade, month;

//user choice for register vs log in + info validation
int selection;
bool valid;

//user choice for input vs output + existing data check
int action;
bool occupied;

//replacing inputs 
int newAttempted;
int newSales;
int oldAttempted;
int oldMade;
int totalAttempted;
int totalMade;

//Confirms if login is correct
bool login () {
  cout << "Input username: ";
  cin >> username;
  cout << "Input password: ";
  cin >> password;

  //checks for matching info in stored file 
  ifstream read ("extra/" + username + ".txt");
  getline (read, storedUsername);
  getline (read, storedPassword);

  if (username == storedUsername && password == storedPassword){
    return true;
  }
  else {
    return false;
  }
}

//check if there is existing data to add on to
bool dataExists (){
  ifstream read("extra/" + username + ".info" + ".txt");
  getline (read, month);
  getline (read, salesAttempted);
  getline (read, salesMade);
  if (month.size() != 0 || salesAttempted.size() != 0 || salesMade.size() != 0){
    return true;
  }
  else {
    return false;
  }
}

//takes in sales information
void takeInfo(){
  cout << "Enter month: ";
  cin >> month;
  cout << "Enter sales attempted: ";
  cin >> salesAttempted;
  cout << "Enter sales made: ";
  cin >> salesMade;
  file.open("extra/" + username + ".info" + ".txt");
  file << month << endl << salesAttempted << endl << salesMade;
  file.close();
}

//presents info present in salesperson file
void readInfo(){
  ifstream read("extra/" + username + ".info" + ".txt");
  getline (read, month);
  getline (read, salesAttempted);
  getline (read, salesMade);
          
  //stores strings as variables
  int made = stoi(salesMade);
  int attempt = stoi(salesAttempted);
  cout << setprecision(4);
  cout << "Month: " << month << endl << "Attempted Sales: " << salesAttempted << endl << "Sales Made: " << salesMade << endl << "Sales percentage: " << ((static_cast<double>(made))/attempt) * 100 << "%";
  cout << endl << endl;
}

//gives percentage of sales feedback
void percentage(){
  int made = stoi(salesMade);
  int attempt = stoi(salesAttempted);
  cout << setprecision(4);
  cout << "Sales percentage: " << ((static_cast<double>(made))/attempt) * 100 << "%";
  cout << endl << endl;
}

//register or log in -- input or read -- if input and data exists overwrite
int main(){
  //main menu
  cout << "1. Register Employee" << endl << "2. Log In" << endl << "Selection: ";
  cin >> selection;
  cout << endl;
  
  switch (selection){
    case 1:
      cout << "Enter username: ";
      cin >> username;
      cout << "Enter password: ";
      cin >> password;

      //stores username and password in new username file
      file.open("extra/" + username + ".txt");
      file << username << endl << password;
      file.close();
      cout << username << " is registered" << endl << endl;
    break;
    
    case 2:
      valid = login();
      if (valid){
        cout << "Log in successful" << endl << endl;

        //functional part of program for input and information on sales 
        cout << "1. Input" << endl << "2. Read" << endl << "Selection: ";
        cin >> action;
        cout << endl;

        if (action == 1){
          //checks if data already exists, if not asks for data, if occupied adds additonal data somehow
          occupied = dataExists();
          if (!occupied){
            takeInfo();
            percentage();
          }
          //adds new info to file 
          else {
            cout << "Sales information is already present" << endl << endl;
            readInfo();
            cout << endl;
            cout << "Add new info to values to overwrite or exit program" << endl << endl;
            takeInfo();
            percentage();
          }
        }
        else {
          readInfo();
        }
      }
      else {
       cout << "Log in failed" << endl;
      }
    break;

    

    default:
      cout << "Invalid input";
    break;

  }
  main();
  return 0;
}