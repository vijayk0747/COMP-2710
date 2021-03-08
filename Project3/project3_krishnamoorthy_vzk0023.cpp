/**

* Vijay Krishnamoorthy (vzk0023)
* project3_krishnamoorthy_vzk0023.cpp

* compile using g++ -o proj3 project3_krishnamoorthy_vzk0023.cpp
* run using ./proj3

* Learned how to read and write to files using Dr.Li's guide, c++ forum, and stackoverflow.
* Learned how to use sort from Dr.Li and the c++ forum.
* Learned how to merge arrays from geeksforgeeks.

*/

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 100;

//DECLARING USER DEFINED METHODS

//This method is used to read an input file, append its data into an array, and return the length of that array.
int readFile(int iArray[], ifstream& instream);


//This method is used to create the ofstream, and then append the data to the user created txt file.
void writeFile(int outputArray[], int outputArray_size, char* outputname);


//This method is used to first merge the data from the two arrays, sort the output array, and then return the length of that array.
int mergeSort(int iArray1[], int iArray1_size, int iArray2[], int iArray2_size, int outputArray[]);

//Main
int main()
{

    //Initialize Variables for the Files
    char file1[50];
    char file2[50];

    //Initialize the Array's that will store the values
    int iArray1[MAX_SIZE];
    int iArray2[MAX_SIZE];

    //Initialize the Array that we will output
    int outputArray[2*MAX_SIZE];

    cout<<"*** Welcome to Vijay's sorting program ***"
        <<"\nEnter the first input file name: ";
    cin>>file1;

    //Open the file
    ifstream currFile;
    currFile.open(file1);

    //Error message for when file is not opened
    if(currFile.fail())
    {
    cout << "Input file opening failed!" << endl;
    exit(1);
    }

    //We read the file and then close it.
    int input1_size = readFile(iArray1,currFile);
    currFile.close();

    cout<<"The list of "<<input1_size<<" numbers in file "<<file1<<" is: \n"; //Give the number on characters in file and display them.

    for(int i=0;i<input1_size;i++)
    {
        cout<<iArray1[i]<<endl;
    }

    //Repeat the process for file2
    cout<<"\nEnter the second input file name: ";
    cin>>file2;

    currFile.open(file2);

    //Check for error again.
    if(currFile.fail())
    {
    cout << "Input file opening failed!" << endl;
    exit(1);
    }

    int input2_size = readFile(iArray2,currFile);
    currFile.close();

    cout<<"The list of "<<input2_size<<" numbers in file "<<file2<<" is: \n"; //Give the number on characters in file and display them.

    for(int i=0;i<input2_size;i++)
    {
        cout<<iArray2[i]<<endl;
    }

    //After finishing getting the two inputs and getting them into arrays, we prepare the output array.

    int output_size = mergeSort(iArray1, input1_size, iArray2, input2_size, outputArray);

    cout<<"\nThe sorted list of 11 numbers is: ";

    for(int i=0;i<output_size;i++)
    {
        cout<<outputArray[i]<<" ";
    }
    cout<<std::endl;

    //After displaying the output array, we move to the output file.

    cout<<"Enter the output file name: ";

    char outputname[50]; //Declare output
    cin>> outputname;
    writeFile(outputArray,output_size,outputname);
    cout<<"*** Please check the new file - "<<outputname<<" ***"
        <<"\n*** Goodbye. ***";

}
//End of Main.

/**
* The readfile method is taken mostly from Dr.Li's hint page.
* I found that I could implement this using !eof so that I wouldn't have to find an index.
*/
int readFile(int iArray[], ifstream& instream)
{
    int i = 0;
    instream >> iArray[i];
    while(!instream.eof())
    {
        i++;
        instream >> iArray[i];
    }
    return i;
}

/**
* The write file method was taken mostly from Dr.Li's hint page.
* I got a very small amount of assistance from irl0006 who just helped me understand how the function works (He gave me no help in writing the code itself).
*/
void writeFile(int outputArray[], int outputArray_size, char* outputname)
{
    std::ofstream ofs(outputname);

    //Check if output file is opened
    if(ofs.fail())
    {
        cout<< "Failed to open file for writing" <<endl;
        exit(1);
    }

    //Write to output file
    for(int i=0; i<outputArray_size; i++)
    {
        ofs << outputArray[i] << std::endl;
    }
}

/**
* I decided to implement a function that would allow me to merge and sort the arrays simaltaneously.
* I tried to use the merge function but it didn't work so I merged the arrays manually using while loops.
* I learned how to use the sort function in c++ through the c++ forum/documentation.
*/

int mergeSort(int iArray1[], int iArray1_size, int iArray2[], int iArray2_size, int outputArray[])
{
    int i=0;
    int j=0;
    int k=0;

    //Filling Array with Input1
    while(i<iArray1_size)
    {
        outputArray[k] = iArray1[i];
        i += 1;
        k += 1;
    }

    //Filling Array with Input2
    while(j<iArray2_size)
    {
        outputArray[k] = iArray2[j];
        j += 1;
        k += 1;
    }

    //Sorting and Returning Length
    sort(outputArray, outputArray + iArray1_size + iArray2_size);
    return iArray1_size + iArray2_size;
}

