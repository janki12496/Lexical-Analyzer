#include<stdio.h>
#include<conio.h>
#include<string.h>
char c;
FILE *f1,*f2;
int i=0;
void object_module(char c)
{
	char str[10],s1[10],*s2,s3[10],s11[10],s33[10];
	int a,b,s,i=0,j=0,s22,c1,c2;
     m:	printf("\n1.Header\n2.Machine Code\n3.Relocation Table\n4.Linking Table\n5.Exit");
	printf("\nEnter number: ");
	scanf("%d",&c1);
	switch(c1)
	{
	case 1: clrscr();
		printf("1.Header: ");
		if(c=='p')
		{
		fscanf(f1,"%[^\n]\n",str);
		fscanf(f1,"\n %s %d",str,&a);
		printf("\nTranslated origin is: %d\nExecution start address is: %d",a,a);
		}

		while(strcmp(str,"END")!=0)
		{
			fscanf(f1,"\n%s",str);
			if(strcmp(str,"END")==0)
			{
				fscanf(f1,"%d",&b);
				s=b-a;
				printf("\nSize of object module: %d\n",s);
			}
		}
		printf("\n\nEnter 1 to go back");
		scanf("%d",&c2);
		clrscr();
		if(c2==1)
			goto m;
		break;

	case 2: clrscr();
		printf("2.Machine code:\n");
		fseek(f1,0,SEEK_SET);
		while((a=getc(f1))!='q')
			printf("%c",a);
		printf("\nEnter 1 to go back");
		scanf("%d",&c2);
		clrscr();
		if(c2==1)
			goto m;
		break;

	case 3: clrscr();
		fseek(f1,0,SEEK_SET);
		printf("\nRELOCTAB:");
		while((a=getc(f1))!=EOF)
		{
			fscanf(f1,"\n%s",str);
			if(strcmp(str,"500")==0)
			{
				i++;
				if(i==1)
				printf("\n	%s",str);
			}
			if(strcmp(str,"538")==0)
			{
				printf("\n	%s",str);
			}
		}
		printf("\n\nEnter 1 to go back");
		scanf("%d",&c2);
		clrscr();
		if(c2==1)
			goto m;
		break;
	case 4: clrscr();
		fseek(f1,0,SEEK_SET);
		printf("\nLINKTAB:\n");
		printf("Symbol   Type    Adress");
			fscanf(f1,"\n%s",str);
		while(strcmp(str,"END")!=0)
		{
			fscanf(f1,"\n%s",str);
			if(j==0)
			{
			if(strcmp(str,"EXTERN")==0)
			{
				strcpy(s3,"EXT");
				fscanf(f1,"%s",s1);
				s2=strtok(s1,",");
				s2=strtok(NULL,",");
			}
			 if(strcmp(str,s1)==0)
			 {
				fscanf(f1,"%d",&a);

			 }
			 if(strcmp(str,s2)==0)
			 {
				fscanf(f1,"%d",&b);

			 }
			 }
			goto h;
		    h:	if(strcmp(str,"ENTRY")==0)
			{
			    strcpy(s33,"PD");
			    fscanf(f1,"%s",s11);
			}
			if(strcmp(str,s11)==0)
			{
			      fscanf(f1,"%s %s %d",str,str,&s22);
			}

		}
		printf("\n%s	 %s	%d",s1,s3,a);
		printf("\n%s	 %s	%d",s2,s3,b);
		printf("\n%s	 %s	%d",s11,s33,s22);
		printf("\n\nEnter 1 to go back");
		scanf("%d",&c2);
		clrscr();
		if(c2==1)
			goto m;
		break;
	case 5: exit(0);
	}
}


void main()
{
	char a;
	clrscr();
	f1=fopen("sp.txt","r");
	printf("	*Program for Object Module*");
	while((c=getc(f1))!=EOF)
	{
		object_module(c);
		fclose(f1);
	}

getch();
}


