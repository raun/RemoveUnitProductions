#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[])
{
	FILE *f,*out;
	char prod[10][50],ter[10],var[10],source,destin;
	int i,j,k,n=0,flag,l,m;
	f=fopen("gram.txt","r");
	void print_production()
	{	
		int i;
		printf("\nNew Productions:\n");
		for(i=0;i<n;++i)
		puts(prod[i]);
	}
	int isUnitProductionLeft()
	{
		int i,j;
		for(i=0;i<n;++i)
		{
			for(j=1;j<strlen(prod[i]);++j)
			{
				if(((prod[i][j-1]=='>')||(prod[i][j-1]=='|'))&&((prod[i][j]>='A')&&(prod[i][j]<='Z'))&&((prod[i][j+1]=='|')||(prod[i][j+1]=='\0')))
				{
					return 1;
				}
			}
		}
		return 0;
	}	
	if((argc==2)||(argc==3))
	{
		f=fopen(argv[1],"r");
		while(!feof(f))
		{
			fscanf(f,"%s\n",prod[n]);
			n++;
		}
	}
	var[0]='\0';
	ter[0]='\0';
	for(i=0;i<n;++i)
	{
		for(j=0;j<strlen(prod[i]);++j)
		{
			if(prod[i][j]>='a'&&prod[i][j]<='z')
			{
				flag=0;
				for(k=0;k<strlen(ter);++k)
				{
					if(prod[i][j]==ter[k])
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					ter[strlen(ter)+1]='\0';
					ter[strlen(ter)]=prod[i][j];
				}
			}
			if(prod[i][j]>='A'&&prod[i][j]<='Z')
			{
				flag=0;
				for(k=0;k<strlen(var);++k)
				{
					if(prod[i][j]==var[k])
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					var[strlen(var)+1]='\0';
					var[strlen(var)]=prod[i][j];
				}
			}
		}
	}
	while(isUnitProductionLeft())
	{
		for(i=0;i<n;++i)
		{
			flag=0;
			source=prod[i][0];
			for(j=3;j<strlen(prod[i]);++j)
			{
				if(((prod[i][j-1]=='>')||(prod[i][j-1]=='|'))&&((prod[i][j]>='A')&&(prod[i][j]<='Z'))&&((prod[i][j+1]=='|')||(prod[i][j+1]=='\0')))
				{
					destin=prod[i][j];
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				for(k=0;k<n;++k)
				{
					if(k!=i)
					{
						if(destin==prod[k][0])
						{
							for(l=3;l<strlen(prod[k]);++l)
							{
								prod[i][j]=prod[k][l];
								j++;
								if(l!=strlen(prod[k])-1)
									for(m=strlen(prod[i])+1;m>j;--m)
									{
										prod[i][m]=prod[i][m-1];
									}
							}
						}
					}
				}
			}
		}
	}
	printf("\n");
	if(argc==2)
	{
		print_production();
		printf("\n\nDONE....!!!!\n\n");
	}
	else if(argc==3)
	{
		out=fopen(argv[2],"w");
		for(i=0;i<n;++i)
		{
			fprintf(out,"%s\n",prod[i]);
		}
		printf("\n\nDONE....!!!!\n\n");
	}
	return 0;
}