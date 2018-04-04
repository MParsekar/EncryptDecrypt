#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
void decrpt(char orig[], char  decrpt_file_name[], char encrpt_file[], char  txt[]){
	FILE *source, *destination;
	char cha;
	int i;	
	for(i=0;i<=strlen(txt)-1;i++){
		encrpt_file[i]=orig[i];
	}
	if(strcmp(encrpt_file, txt)==0)
		{
	
			printf("Decrypting %s: to %s \nContent: ",orig, decrpt_file_name);
			
			destination=fopen(decrpt_file_name, "w+");
			if(destination==NULL)
				perror("Error Destination:");
			source=fopen(orig, "r");
			if(source==NULL)
				perror("Error source:");
		
		
			cha=getc(source);
			while(cha!=EOF){
				printf("%c", cha-8);	
				fprintf(destination, "%c", cha-8);
				cha=getc(source);
			}
			close(source);
			close(destination);
		}else
		{
			printf("\nThe file is not Encrpted");
			
		}
}
int main(int argc, char *argv[])
{


int i, j=0;
char decrpt_file_name[50]="DecryptFile_";
char encrpt_file[strlen(argv[1])];



if(argc<2 || argc>=3){
	printf("Error: Wrong use of the arguement\nUsage: encrypt filename_to_encrpt");
	return 1;
}
else
	{	
		

	for(i=12;i<strlen(argv[1])+16;i++){
			decrpt_file_name[i]= argv[1][i];
	}
	
	
	decrpt(argv[1], decrpt_file_name,encrpt_file,  "EncryptFile" );
	return 0;
	}
}

