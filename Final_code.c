#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int occ[280]; 								//	Global array indicating whether a parking slot is available(1) or not(0)
int allotment()
{
	int i;
	for(i = 1; i <= 280; i++)					//	For loop to check the least available slot to allot
	{
		if(occ[i] == 0)
		{
			occ[i] = 1;					//	Allotment done!
			if((i >= 1) && (i <= 56))			//	Checking range to convert the input into appropriate array indexes
			i = i + 100;
			else if((i >= 57) && (i <= 112))
			i = i + 144;
			else if((i >= 113) && (i <= 168))
			i = i + 188;
			else if((i >= 169) && (i <= 224))
			i = i + 232;
			else if((i >= 225) && (i <= 280))
			i = i + 276;
			else
			{
				printf("Invalid number\n");				
			}
			return i;					//	Returns the appropriate alloted parking slot!
		}
	}
	return -1;							//	Returns -1 if all slots are occupied
}
int main()
{
	int i, j, allot, allot2, e, avail[10];	//loop variables(i,j), allot-to obtain the available allotment, allot2-to obtain the allotment if the car stand is available in the
	char in[10], op[10], ex[10];		//	parking slot, e,ex[]-reqd for exit, avail[],op[]-to get input from the user if the car stand is available, in[]-input choice by user
	for(i = 1; i <= 280; i++)		//	For loop to initialize all slots in the beginning to 0 
	{
		occ[i] = 0;
	}
	printf("100. Entry\n010. Exit\n001. Stop\n");
	while(1)
	{
		printf("\nEnter your choice:");
		scanf("%s",in);
		if(strcmp("100",in) == 0)						//	If choice is entry
		{
			allot = allotment();						// 	Allots the least slot available 
			if(allot == -1)
			{
				printf("Parking full!\n");
				exit(0);
			}
			else
			{
				printf("Available Parking slot is %d\n",allot);		//	Prints the least slot available
				printf("Car stand available at %d ? ",allot);		
				scanf("%s",op);						//	Input to check whether slot is available(1) or not(0)
				for(j = 0; j < 10; j++)					//	For loop to convert the input string into integer array
				{
					avail[j] = (int)op[j] - 48;
				}
				if((avail[0] == 0) && ((avail[1] == (-48))))		//	If the input is 0 and the second value of input(if present) is -48(indicating no value)
				printf("Alloted parking slot is %d\n",allot);		//	Print the Available parking slot as the Alloted parking slot(if car stand is not available)
				else if((avail[0] == 1) && ((avail[1] == (-48))))	//	If the input is 1 and the second value of input(if present) is -48(indicating no value)
				{
					allot2 = allotment();				//	Call the allotment() function again to determine the next minimum allotment
					if(allot2 == -1)
					{
						printf("Parking full!\n");
						exit(0);
					}
					else
					printf("Alloted parking slot is %d\n",allot2);	//	Print the next least slot available as the Alloted parking slot
				}
				else
				{
					printf("Invalid option entered!\n");		//	If the option entered is not 0 or 1, then print "invalid"
					if((allot >= 101) && (allot <= 156))		//	Irrespective of the car stand being available, the occ[i] becomes 1 due to the fn call-line47
					{						//	So,checking the range of allot that is already allotted & changing it to 0.
						if((occ[allot-100]) == 1)
						{
							occ[allot-100] = 0;
						}
					}
					else if((allot >= 201) && (allot <= 256))
					{
						if((occ[allot-144]) == 1)
						{
							occ[allot-144] = 0;
						}
					}
					else if((allot >= 301) && (allot <= 356))
					{
						if((occ[allot-188]) == 1)
						{
							occ[allot-188] = 0;
						}
					}
					else if((allot >= 401) && (allot <= 456))
					{
						if((occ[allot-232]) == 1)
						{
							occ[allot-232] = 0;
						}
					}
					else if((allot >= 501) && (allot <= 556))
					{
						if((occ[allot-276]) == 1)
						{
							occ[allot-276] = 0;
						}
					}
				}	
			}
		}
		else if(strcmp("010",in) == 0)						//	If choice is exit
		{
			printf("Enter the parking slot to exit:");
			scanf("%s",ex);
			e = atoi(ex);							//	Converting the input of parking slot to exit to integer
			if((e >= 101) && (e <= 156))					//	Checking range to exit the appropriate car slot
			{
				if((occ[e-100]) == 1)
				{
					occ[e-100] = 0;
					printf("Car exited!\n");
				}
				else
				printf("No car in the slot entered!\n");			
			}
			else if((e >= 201) && (e <= 256))
			{
				if((occ[e-144]) == 1)
				{
					occ[e-144] = 0;
					printf("Car exited!\n");
				}
				else
				printf("No car in the slot entered!\n");
			}
			else if((e >= 301) && (e <= 356))
			{
				if((occ[e-188]) == 1)
				{
					occ[e-188] = 0;
					printf("Car exited!\n");
				}
				else
				printf("No car in the slot entered!\n");
			}
			else if((e >= 401) && (e <= 456))
			{
				if((occ[e-232]) == 1)
				{
					occ[e-232] = 0;
					printf("Car exited!\n");
				}
				else
				printf("No car in the slot entered!\n");
			}
			else if((e >= 501) && (e <= 556))
			{
				if((occ[e-276]) == 1)
				{
					occ[e-276] = 0;
					printf("Car exited!\n");
				}
				else
				printf("No car in the slot entered!\n");
			}
			else
			printf("Invalid Parking slot entered!\n");
		}
		else if(strcmp("001",in) == 0)						//	If option is exit the program
		exit(0);
		else
		printf("Invalid choice\n");
	}
	return 0;
}
