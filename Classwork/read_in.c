#include <stdio.h>

int main()
{
	char fname[100];
	char lname[100];
	int scorel;
	int score2;
	FILE *fp;
	FILE *of;

	fp = fopen("data.txt","r");
	of = fopen("output.txt","w");

	fscanf(fp,"%s %s",fname, lname);
	fprintf(of,"%s %s\n",fname, lname);

	while(fscanf(fp,"%d %d", &score1, &score2) != EOF )
	{
		fprintf(of,"%d %d\n", score1, score2);
	}

	fclose(fp);
	fclose(of);

	//	scanf("%s", buf);
//	printf("%s\n", buf);
//	scanf("%s",buf);
//	printf("%s \n", buf);
}
