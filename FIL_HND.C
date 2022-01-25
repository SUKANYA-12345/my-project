#include<stdio.h>
#include<conio.h>
struct student
{
	int roll;
	char nm[10];
}s;
void main()
{
	int ch,sz;
	char rep;
	FILE*f;
	a:
	clrscr();
	printf("main menu:");
	printf("\n1. store record");
	printf("\n2. display record");
	printf("\n3. file info");
	printf("\n4. exit");
	printf("\n enter choice:");
	scanf("%d",&ch);
	fflush(stdin);
	switch(ch)
	{
		case 1:
		f=fopen("sukanya.txt","a");
		if(f==NULL)
		{
			printf("\n error accessing the file");
		}
		else
		{
			do
			{
				printf("\n enter roll:");
				scanf("%d",&s.roll);
				fflush(stdin);
				printf("enter name:");
				scanf("%s",&s.nm);
				fflush(stdin);
				fwrite((char*)&s,sizeof (s),1,f);
				printf("continue?:");
				scanf("%c",&rep);
				fflush(stdin);
			}while(rep=='y'||rep=='Y');
			fclose(f);
		}
		getch();
		goto a;
		case 2:
		f=fopen("sukanya.txt","r");
		if(f==NULL)
		{
			printf("\n error reading the file");
		}
		else
		{
			fread((char*)&s,sizeof(s),1,f);
			while(!feof(f))
			{
				printf("\nroll:%d name:%s",s.roll,s.nm);
				fread((char*)&s,sizeof(s),1,f);
			}
			fclose(f);
		}
		getch();
		goto a;
		case 3:
		f=fopen("sukanya.txt","r");
		if(f==NULL)
		{
			printf("\n error reading the file");
		}
		else
		{
			fseek(f,0,SEEK_END);
			sz=ftell(f);
			printf("\nsize of file is:%fd",sz);
			printf("\ntotal records:%d",sz/sizeof(s));
			fclose(f);
			getch();
			goto a;
		}
		case 4:
			break;
	}
}
