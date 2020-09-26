// maincode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<fstream>
#include<iostream>
#include<vector>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	long long steval = 0;  //This variable is used for storing ste values per 320 samples
	double freq,prev = 0;  //freq is used for storing current frequency and prev is used for the previous frequency
	int samples = 1;  //Used for determining whether we have captured 320 samples or not

	vector<long long> ste;  //Used for storing the short term energy values per 320 samples
	vector<long long> zcr;  //Used for storing the zero crossing rate values per 320 samples
	long long size = 0;  //This is used for determining the number of segments of 320 samples
	long long count = 0;  //Used for counting the zero crossing rate per 320 samples
	
	ifstream yesno;  //Creating an object for reading the file
	yesno.open("yesno.txt");  //Opening the .txt file in which the voice(yes/no) is stored
	
	ofstream answer;  //Creating an object for writing in to a file
	answer.open("Answer.txt");  //Answer.txt stores the STE and ZCR values per 320 samples
	
	while (yesno>>freq) {  //While loop for extracting each frequency from the file which is given as input
    	if(samples==320){  //Checking ifnumber of samples = 320
			answer<<"STE = "<<steval/320<<"  "<<"ZCR = "<<count<<endl;  //If true then write the values STE and ZCR in the Answer.txt file
			ste.push_back(steval/320);  //Pushback STE values into the vector ste
			zcr.push_back(count);  //Pushback ZCR values into the vector zcr
			size++;  //Incrementing the size variable inorder to know the exact size of vector
			samples = 1;  //Resetting the value of samples to 1
			steval = 0;  //Resetting the value of STE value to 0
			count = 0;  //Resetting the value of count of zcr to 0
		}

		if((freq>0 && prev<0) || (freq<0 && prev>0)){  //Checking if the prev frequency and the current frequency are on opposite side of x-axis
			count++;  //If true then increment the count of zcr
		}
		prev = freq;  //Set the previous frequency as current frequency
		steval += freq*freq;  //Calculating the STE value for the current frequency
		samples++;  //Increment the number of samples
	}

	for(long long i = 0; i<size; i++){  //For iterating over the complete vectors
		if(ste[i] > 200000){  //STE value is compared first. If it is less than 200000 then it must be either silence or noise. Hence STE should be high
			                  //Read readme.txt for better clarification.
			if(zcr[i+15] > 100){  //Compare the ZCR of next 15th sample. If it is more than 100 then the 15th voice must be fricative
				cout<<"Yes"<<endl;  //If it is a fricative then it should be definitely YES
				i= i + 35;  //Once found a word, move forward by 35 samples for next word
				continue;
			}
			else{  //If ZCR is less than 100 that means either it is a silence or a vowel. Therefore it should output No
				cout<<"No"<<endl;  //If there is either silence or vowel then it should be definitely NO
				i= i + 25;  //Once found a word, move forward by 35 samples for next word
				continue;
			}
		}
		else{
			continue;  //If STE is less than 200000 then it should be silence or noise hence increment the value of i by 1
		}
	}

	answer.close();  //Closing the file answer in which STE and ZCR values are stored
	yesno.close();  //Closing the file yesno in which voice(yes/no) is stored

	return 0;
}

