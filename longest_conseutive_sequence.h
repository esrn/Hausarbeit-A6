#include <stdio.h>
#include <stdlib.h>
#define arraylength(x) (sizeof(x) / sizeof((x)[0]))
	

void longest_consecutive_sequence(int a[], int arraylength)
{
    if(arraylength==0)
    {
        printf("Array is empty.");
        return;
    }
    int longest_sequence=1;
    int recent_sequence=1;
    int index_longest_sequence=0;
    int index_current_sequence=0;
    int j=0;
    for(int i=0; i<arraylength; i++)
        {
	    if(a[j]+1==(a[j+1]))
	    {
		index_current_sequence=j;
            	while(a[j]+1==(a[j+1]))
            	{
                	recent_sequence++;
                	if(recent_sequence>longest_sequence)
                	{
                    	longest_sequence=recent_sequence;
			index_longest_sequence=index_current_sequence;
                	}
                	j++;
                	//index_longest_sequence=i;
            	}
	    }
	    else
            {
                recent_sequence=1;
		j++;

            }
        }
	/*if(recent_sequence==longest_sequence)
	{
		index_longest_sequence=j;
	}*/
    printf("The longest sequence of consecutive digits starts at index %i, and is %i digits long. \n",index_longest_sequence, longest_sequence);
    }

    int main() {

        int a[5];
        a[0]=0;
        a[1]=1;
        a[2]=3;
        a[3]=4;
        a[4]=5;

        int b = arraylength(a);

        longest_consecutive_sequence(a,b);
        //printf("%li \n",arraylength(a));
        return 0;

    }
