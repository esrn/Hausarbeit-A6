#include <stdio.h>
#include <stdlib.h>

void longest_consecutive_sequence(FILE *input_stream)
{
    int length=0;
    char character;
    while(!feof(input_stream)) {
        character=fgetc(input_stream);
        if(character=='\n') {
            length++;
        }
    }
    char line[length];
    int contentarray[length];
    rewind(input_stream);
    if(length!=0)
    {
        for(int i=0; i<length; i++)
        {
            contentarray[i]=atoi(fgets(line,length,input_stream));
        }
    } else
    {
        printf("File is empty \n");
        return;
    }
    int longest_sequence=1;
    int recent_sequence=1;
    int index_longest_sequence=0;
    int index_current_sequence=0;
    int j=0;
    for(int i=0; i<length; i++)
    {
        if(contentarray[j]+1==(contentarray[j+1]))
        {
            index_current_sequence=j;
            while(contentarray[j]+1==(contentarray[j+1]))
            {
                recent_sequence++;
                if(recent_sequence>longest_sequence)
                {
                    longest_sequence=recent_sequence;
                    index_longest_sequence=index_current_sequence;
                }
                j++;
            }
        }
        else
        {
            recent_sequence=1;
            j++;

        }
    }
    printf("The longest sequence of consecutive digits starts at line %i, and is %i digits long. \n",index_longest_sequence+1, longest_sequence);
}
