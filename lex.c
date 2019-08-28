#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
	FILE *f1;
	char str[10],c[50],*p,di[5],d;
	int i,j;
	clrscr();
	f1=fopen("cd3.txt","r");	
	printf("Lexical Analyzer:\n\n");
	while((d=getc(f1))!=EOF)
	{
		printf("%c",d);
	}
	fclose(f1);
	f1=fopen("cd3.txt","r");
	printf("\nTokens are:\n ");
	while((fgets(str,10,f1))!=NULL){
		p=strtok(str," ");
		while(p!=NULL){

			strcpy(c,p);
			p=strtok(NULL," ");
			if(strcmp(c,"int")==0||strcmp(c,"float")==0||strcmp(c,"char")==0||strcmp(c,"long")==0||strcmp(c,"double")==0)
			{
				printf("%s is keyword\n",c);
			}
			else
			{
				for(i=0;i<strlen(c);i++)
				{
					if(c[i]>=97 && c[i]<=122)
					{
						printf("%c is identifier\n",c[i]);
					}
					if(c[i]==','||c[i]=='@'||c[i]==';')
					{
						printf("%c is special character\n",c[i]);
					}
					if(c[i]=='+'||c[i]=='-'||c[i]=='%'||c[i]=='*'||c[i]=='/'||c[i]=='=')
					{
						printf("%c is operator\n",c[i]);
					}
					if(c[i]>=48 && c[i]<=57){
						printf("%c",c[i]);
						if(!(c[i+1]>=48 && c[i+1]<=57)){
							printf(" is constant\n");

						}
					}
				}
			}
		}
	}
getch();
}
