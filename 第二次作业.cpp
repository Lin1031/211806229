#include<stdio.h>
#include<string.h>

struct Data
{
	char senderName[10];
	char receiverName[10];
	int data;
}sender[20000];

struct Hacker
{
	char hackerName[10];
}hacker[100];

int main() {

	FILE* read, * write;
	read = fopen("test.txt", "r");
	if (read == NULL)
	{
		printf("ERROR");
		return -1;
	}
	int num = 0;
	while (!feof(read))
	{
		fscanf(read, "%s %s %d\n", sender[num].senderName, sender[num].receiverName, &sender[num].data);
		num++;
	}
	fclose(read);
	int i, j, count = 0;
	int flag = 1;
	for (i = 0;i < num;i++)
	{
		if (sender[i].data >= 100)
		{
			flag =1;
			for (j = 0;j < count;j++)
			{

				if (strcmp(sender[i].senderName, hacker[j].hackerName) == 0) 
					flag = 0;
			}
			if (flag) 
			{
				strcpy(hacker[count].hackerName, sender[i].senderName);
				count++;
			}
		}
	}
	printf("%d\n", count);
	for (i = 0;i < count;i++)
	{
		printf("%s\n", hacker[i].hackerName);
	}

	return 0;

}
