#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define EMAIL_ADDR_SIZE 100

int main()
{
	char num[100];
	char c;
	int num_fields = 0;
	int num_lines = 0;
	char path[100];
	char new_path[100] = "uniqueemails.txt";
	FILE *fptr;
	int backup_flag = 1;

	/* Input source file path path */
	printf("Enter path(or filename if its same dir) of the file with email address: \n");
	scanf("%s", path);

	/* Update Backup flag from user */
	printf("Select Below Option \n"
			"1. Create New file : %s\n"
			"2. Update the original file %s\n"
			"default (1): ",new_path, path);
	scanf("%d", &backup_flag);
	if(backup_flag !=2)
	{
		backup_flag = 1;
	}

	if ((fptr = fopen(path,"r")) == NULL){
		printf("Error! opening file");
		exit(1);
	}

	// Find number of lines and number of Email Address
	for (c = getc(fptr); c != EOF; c = getc(fptr)) 
	{
		if (c == '\n') 
		{
			num_lines++; 
			num_fields++;
		}
		if(c == ',')
		{
			num_fields++;
		}
	}
	printf("num_fields=%d  num_lines = %d\n", num_fields, num_lines);
	fseek(fptr, 0, SEEK_SET);

	// copy total number of email address from file
	char email_addrs[num_fields][EMAIL_ADDR_SIZE];
	int list_offset = 0;
	int addr_offset = 0;
	for (c = getc(fptr); c != EOF; c = getc(fptr)) 
	{
		if (c == '\n' || c==',') // Increment count if this character is newline 
		{
			email_addrs[list_offset][addr_offset] = '\0';
			printf("list_offset=%d  email = %s\n", list_offset + 1, email_addrs[list_offset]);
			list_offset++;
			addr_offset = 0;
		}
		else
		{
			email_addrs[list_offset][addr_offset++] = c;
		}
	}
	fclose(fptr); 

	//create a unique list from the existing list
	char unique_eaddrs[list_offset][EMAIL_ADDR_SIZE];
	int unique_max = 0;
	int unique = 0;
	for(int main_offset = 0; main_offset < list_offset; main_offset++)
	{
		for(int unique_offset = 0; unique_offset < unique_max; unique_offset++)
		{
			if(strcmp(email_addrs[main_offset], unique_eaddrs[unique_offset]) == 0)
			{
				unique = 0;
			}
		}
		if(unique)
		{
			strcpy(unique_eaddrs[unique_max++],email_addrs[main_offset]);
		}
		else
		{
			unique = 1;
		}
	}

	//Print Unique List
	for(int unique_offset = 0; unique_offset < unique_max; unique_offset++)
	{
		printf("unique list_offset=%d  email = %s\n", unique_offset, unique_eaddrs[unique_offset]);
	}

	//Depending on backup_flag create new file
	if(backup_flag == 2)
	{
		if ((fptr = fopen(path,"w")) == NULL){
			printf("Error! opening file");
			exit(1);
		}

	}
	else
	{
		if ((fptr = fopen(new_path,"w")) == NULL){
			printf("Error! opening file");
			exit(1);
		}	
	}

	//Fill unique list and close the file
	for(int unique_offset = 0; unique_offset < unique_max; unique_offset++)
	{
		fputs(unique_eaddrs[unique_offset], fptr);
		fputc(',', fptr);

	}
	fclose(fptr); 
	return 0;
}
