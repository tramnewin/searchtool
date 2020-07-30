#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
//stores the word data from the file
struct position {
     int linenumber;               //line number of the word
     char* word;                   //raw data of the word 
     string finalword;             //the word from the file
};
int main()
{
    ifstream textfile;             //read the text file
    textfile.open("The Road Not Taken.txt");
    int thebottomlinenumber=0;     //count how many lines in the files 
    string buffer;
    string delimeter = " \t\n";
    char buff[16000];                        
    char del[10];
    char* token;                   //tokenize variable
    vector<position> result;                 //stores the info of the tokens in the document 
    position anothertemp;
    int initialnum = 1;                      //the line number counter
    stringstream ss;
    stringstream iss;
    int gap = 0;                             //the number of letters in the last word
    string anotherstring;
    string stringg;
    string stringg2;
    if (!textfile.is_open())                 //if the file is unable to open
      cout << "unable to open the file. Try again\n";
    ss << textfile.rdbuf();                  //read the data into a string stream
    textfile.close();                        //close the fle then open again to store it in another string stream
    textfile.open("The Road Not Taken.txt");
    iss << textfile.rdbuf();
    //get the word lines in a pair
    getline(iss, stringg);
    getline(iss, stringg2);
    while (!(stringg == "" && stringg2 == "")) {       //count the lines that has words
         ++thebottomlinenumber;
         getline(iss, stringg);
         getline(iss, stringg2);
    }
    //double the line count to get the total of written lines
    thebottomlinenumber = thebottomlinenumber * 2;

    buffer.resize(16000);
    buffer = ss.str();
    strcpy(buff, buffer.c_str());                 //copy the cstring into the char array 
    strcpy(del, delimeter.c_str());
    if (buffer.size() <= 0) 
         cout<< "no source";                      //if buffer cannot get the data from text file
    token = strtok(buff, del);                    //stores the word into token
    getline(ss, anotherstring);                   //read the line into anotherstring
    int test = anotherstring.length() - 1;        //get the length of the line
    while (anotherstring[test] != ' ' && test != 0) {
         --test;                                  //get the last word in anotherstring by finding the last word's initial letter's location and the number of letters in that word
         gap++;
    }
    string lastword = anotherstring.substr(test + 1, gap);  //stores last word into lastword
    while (token != NULL) {                                 //tokenize the words from the file until reaching the end of the string stream
         if (token != lastword) {
              anothertemp.word = token;                     //stores data in position data type
              anothertemp.linenumber = initialnum;
              anothertemp.finalword = token;
              result.push_back(anothertemp);                //store tokens into the vector
              token = strtok(NULL, delimeter.c_str());     //get the next token
         }
         else {
              //if the token reaches the last word of that line, store it 
              anothertemp.word = token;
              anothertemp.linenumber = initialnum;
              anothertemp.finalword = token;
              result.push_back(anothertemp);
              // jump to the next line
              getline(ss, anotherstring);
              //if the nextline is empty, read the next line
                   while (anotherstring == "") {
                        getline(ss, anotherstring);
                        initialnum++;
                        //if the line number is equal to the last line of the document, break out of the statement 
                        if (initialnum == thebottomlinenumber) {
                             break;
                        }
                   }
                   //if the line number is equal to the last line of the document, break out of the statement 
                   if (initialnum == thebottomlinenumber) {
                        break;
                   }
                   //get the last word of the line
                   test = anotherstring.length() - 1;
                   gap = 0;
                   while (anotherstring[test] != ' ' && test != 0) {
                        --test;
                        gap++;
                   }
                   lastword = anotherstring.substr(test + 1, gap);
                   token = strtok(NULL, delimeter.c_str());           //tokenize the line
                   initialnum++;
                   
              
         }

    }
    string sample;                                     //stores the word that has non-alphabet character at the end
    for (int j = 0; j < result.size(); j++) {
         sample = result[j].word;

         int theCharLength = strlen(result[j].word);
         for (int z = 0; z < theCharLength; z++) {
              if (sample[z] == '.' || sample[z] == '!' || sample[z] == '?' || sample[z] == ',' || sample[z] == ';' || sample[z] == ':' || sample[z] == '"') {
                   sample.erase(z, 1);                 //remove non-alphabet character and store it the position vector
                   result[j].finalword = sample;

              }
         }
    }
    //result vector now have all the words from the file
    string search;
    cout << "PLease note: this search tool is not case-sensitive\n";
    cout << "Choose the word you want to search for:\t";

    cin >> search;
    string ogsearch = search;
    int i = 0;
    while (search[i]) {
         char c = search[i];
         c = tolower(c);                //search the input in lowercase 
         search[i] = c;
         i++;
    }
    i = 0;
    int count = 0;
    vector<int> pos;
    while (i < result.size()) {
         if (search == result[i].finalword) {
              ++count;                                 //if the word is found in the result vector, store the information into another vector called pos
              pos.push_back(result[i].linenumber);
         }
         i++;
    }
    i = 0;
   char c = search[0];
   c = toupper(c);
   search[0] = c;                                      //find the word in uppercase (only the fisrt letter is in uppercase)
   while (i < result.size()) {
        if (search == result[i].finalword) {
             ++count;
             pos.push_back(result[i].linenumber);     //if found, stores it into the vector
        }
        i++;
   }
   i = 0;
    cout << "there is/are " << count << " " << ogsearch << " in the file\n";              //print out the result
    for (i; i < count; i++) {
         cout << i + 1 << ". at line number " << pos[i] << endl;
    }

}
