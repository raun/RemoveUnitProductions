#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[])
{
	FILE *f,*out;
	char prod[10][50],source,destin;
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