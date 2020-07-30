*******************************************************
*  Name      : Tram Nguyen         
* Education: : University of Colorado - Denver
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************
This is a search tool that is similar to the one from Microsoft Word. 
How it works: the program opens the file and put it into a string stream variable. Then, it tokenizes the document and put it into a vector.
Then, it recieves the input from the user and goes through the vector to find the words. The program firstly find it in lowercase, then it capitalizes
the first letter of the input word and goes over the vector again. Finally, it prints out the result onto the console
PLEASE NOTE! if you want to use your own document, spare 2 empty lines at the bottom of the file, place it in the same directory as the .cpp file 
and replace the King.txt with your file and it should run smoothly!

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that executes all mentioned process

Name: King.txt
   the sample file

*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on gnu g++ 6.1.x  It was 
   compiled, run, and tested on gcc csegrid server.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the zip file. 
   To uncompress it use the following commands 
       % unzip [searchtool]

   Now you should see a directory named homework with the files:
        main.cpp
        King.txt
	      makefile.txt
        Readme.txt
	

2. Build the program.

    Change to the directory that contains the file by:
    % cd [searchtool] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[searchtool]

4. Delete the obj files, executables, and core dump by
   %./make clean
