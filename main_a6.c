#include<stdio.h>
#include<getopt.h>
#include"longest_consecutive_sequence.h"

void help()
{
	printf("Dieses Programm gibt Ihnen die den Index und die Länge der längesten Reihe aufeinanderfolgender Ziffern an. Die Ziffern sollen hierzu in einem Textdokument (.txt-Datei) jeweils mit einem Zeilenumbruch getrennt übergeben werden. Der Index wird mit der 1 beginnend durchnummeriert, also: erste Ziffer -> Index 1.")
	printf("Bitte nutzen Sie folgende Argumente: \n");
	printf("-h: Hilfe \n");
	printf("-p: Angabe des Dateipfads \n");
}

int main(int argc, char* argv[])
{
	int opt;
	char *file;

	while((opt=getopt(argc,argv,"hp:"))!=-1)
	{
		switch (opt){
			case 'h':
				help();
				return 0;
				break;
			case 'p';
				file = optarg;
				break;
		}
	}

	FILE *input_stream;
	input_stream=fopen(file,"r");

	if(input_stream==NULL)
	{
		printf("Datei nicht vorhanden. \n");
		return 0;
	}
	longest_consecutive_sequence(input_stream);
	fclose(inputstream);
	return 0;
}
