# carWashSalesRecordSystem
 This is a program I wrote for my job at a car wash to keep track of our membership sales. It registers users by storing a username and password in a file, logs in users in if username and password fit an existing file, takes their sales info and presents to them when they need to retrieve it.

In creating this system I learned about 
Functions:
-boolean functions for validating login and existence of data in a file
-void functions for long code for inputting and reading info that repeats itself

File Management:
-ofstream was used to open a file for new user's login information under name username.txt
-ofstream was used to open a file for existing user's sales information
-ifstream was used to read the username and password in the validating login bool function
-ifstream was used to read user's sales information once logged in

string to int conversion-
-used stoi() function to store strings in int variables for calculation of sales percentage