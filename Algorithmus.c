#include <stdio.h>
#include <stdlib.h>
#define arraylength(x) (sizeof(x) / sizeof((x)[0]))

void longest_consecutive_sequence(int a[], int arraylen)
{
	if(arraylen==0)
	{
		printf("Array is empty.");
		return;
	}
	int longest_sequence=1;
	int recent_sequence=1;
	int index_longest_sequence=0;	
	for(int i=0;i<arraylen;i++)
	{
		while(a[i]+1==(a[i+1]))
		{
			index_longest_sequence=i;
			recent_sequence++;
			if(recent_sequence>longest_sequence)
			{
				longest_sequence=recent_sequence;
			}
			i++;
			index_longest_sequence--;
		
		}
		if(a[i]+1!=(a[i+1]))
		{
			recent_sequence=0;
		}
	}
	printf("The longest sequence of consecutive digits starts at index %i, and is %i digits long. \n",index_longest_sequence, longest_sequence);
}

int main(){

	int a[5];
	a[0]=1;
	a[1]=2;
	a[2]=3;
	a[3]=5;
	a[4]=6;

	int b = arraylength(a);
	
	longest_consecutive_sequence(a,b);
	printf("%li \n",arraylength(a));
	return 0;

}
