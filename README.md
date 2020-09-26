# Yes-No-Speech-Detection-System

Introduction : 
    This is a project which is used to detect whether the user has said Yes or a No. In this the user gives a input file as his voice and the program detects whether the user has said a yes/no and gives the output on the console. This is tuned for both Male and Female voice. This also supports taking multiple yes/no as a input from the user and displaying the respective output in the correct order. In this the word boundary detection is being done by checking the STE values using sliding window approach.
    
Running apparatus :
    Microsoft Visual Studio 2010 Professional, CoolEdit 2000 Software

Tech Stack Used : 
    C++
    
Breif Explanation :
     In this project I created a .txt file from a .wav file and extracted the frequencies at 16000 samples per section. Then I calculated the short term energy and zero crossing rate for disjoint samples of 320 each. Now, after obtaining all this data, I used simple logic that for a segment if STE is high then it may be a vowel or a fricative and if the ZCR is higher than say 100 then it must be a fricative. This helped me identify whether the next alphabet after the vowel is a fricative or just some random noise.
     
 For detailed explanation of the logic used in the code please read the Readme.txt file inside the Code folder.
