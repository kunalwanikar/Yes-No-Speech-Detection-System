This is a program which detects Yes/No when an input voice(in .txt) format is given as input.
In this program I used 2 vectors namely "ste" for stroring short term energies and "zcr" for storing zero crossing rate.


My logic for finding the values of STE and ZCR is as follows
I have read the input frequency from the file and calculated the STE value using the formula STE = 1/N  * (Summation from 1 to N )(frequency*frequency)
And the ZCR value by checking if the previous frequency and the current frequency are on the opposite side of x-axis.

Now the logic of the program is as follows
I check for every STE if it is greater than 200000 because for fricatives and vowel the STE is generally above 200000.
If the STE is less than 200000, then I declare it as silence or noise and check for the next STE.
Now when a vowel is called the STE is more than 200000.
Now we know that Yes contains a vowel "e" and also No contains a vowel "o". Also we know that ZCR for fricatives is very high as compared to vowels.
So my logic was if after the vowel there exists a ZCR value which is more than 100 that means a fricative exists just after the vowel and therefore the voice should be a "YES".
If the ZCR is less than 100 this means that either the vowel is the last alphabet or there is silence. By this we can conclude that the voice is a "NO".

So here when STE is greater than 200000, I check for the ZCR value which is 15 samples ahead of the current STE value.
If it is more than say 100 then fricative exists, hence it will be a YES.
Else it will be a NO.

Now when we detect a YES/NO, then we need to increment the counter of the for loop by atleast 25 samples so that it does not collide with the current word spoken.
This is how I have detected which is the next word is spoken.