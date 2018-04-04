#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{
	FILE *source, *destination;
	char cha;
	char encrpt_file_name[70];
	int i, j=0;
	char txt[4]=".txt";
	
	
	strcpy(encrpt_file_name,"../Files_Encription/EncryptFile_");
	if(argc<2 || argc>=3){
		printf("Error: Wrong use of the arguement\nUsage: encrypt filename_to_encrpt");
		return 1;
	}
	else{
		
		for(i=0;i<strlen(argv[1])+4;i++)
		{
				encrpt_file_name[i+32]=argv[1][i];
		}
		printf("Encrypt File name: %s\nContent : ", encrpt_file_name);
		destination=fopen(encrpt_file_name, "w+");
		if(destination==NULL)
			perror("Error Destination:");
		source=fopen(argv[1], "r");
		if(source==NULL)
			perror("Error source:");
		
		
	cha=getc(source);
	while(cha!=EOF){
		printf("%c", cha+8);	
		fprintf(destination, "%c", cha+8);
		cha=getc(source);
		}
	close(source);
	close(destination);
	return 0;
	}
}