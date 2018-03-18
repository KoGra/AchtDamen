#include <stdio.h>



// solves the problem of 8 queens
//

struct achtdamen
{
	int sp[8];
	int z;
};

int check_allowed(struct achtdamen a)
{
	int i,j;
	for (i = 0; i < a.z; i++)
	{
		for (j = i + 1; j <= a.z; j++)
		{
			if (a.sp[i] == a.sp[j])
			{
				return 0;
			}
			if (a.sp[i] + (j - i) == a.sp[j] || a.sp[i] + (i - j) == a.sp[j])
			{
				return 0;
			}
		}
	}
	return 1;
}

int nexttry(struct achtdamen *a)
{
	int i, j, k;
	int allowed;


	if (a->sp[a->z] == 8)
	{
		a->sp[a->z] = 0;
		a->z--;
		a->sp[a->z]++;
		return 1;
	}
	a->z++;
	if (a->z == 8)
		return 0;

	for (i = a->sp[a->z]; i < 8; i++)
	{
		a->sp[a->z] = i;
		if (check_allowed(*a))
			return 1;
	}
	a->sp[a->z] = 0;
	a->z--;
	a->sp[a->z]++;

	return 1;

}

void print_damen(struct achtdamen a)
{
	int i, j;
	for (i = 0; i< a.z; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (a.sp[i] == j)
				printf("D ");
			else
				printf("_ ");

		}
		printf("\n");
	}
	printf("\n");

}
void main()
{
	struct achtdamen a = { { 0 }, 0 };
	int count=0;

	while (a.sp[0] < 7)
	{
		while (nexttry(&a))
		{
			count++;
		}
		printf("%d\n", count);
		print_damen(a);
		a.sp[7]++;
	}


}