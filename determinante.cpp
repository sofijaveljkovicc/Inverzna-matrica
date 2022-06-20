#include <stdio.h>

float det2(float m[2][2])
{
	return m[0][0]*m[1][1]-m[1][0]*m[0][1];
}

float det3(float m[3][3])
{
	float pom1[2][2]={{m[1][1],m[1][2]},{m[2][1],m[2][2]}}, pom2[2][2]={{m[1][0],m[1][2]},{m[2][0],m[2][2]}}, pom3[2][2]={{m[1][0],m[1][1]},{m[2][0],m[2][1]}};
	return m[0][0]*det2(pom1)-m[0][1]*det2(pom2)+m[0][2]*det2(pom3);
}

void inv(float m[3][3])
{
	float pom00[2][2]={{m[1][1],m[1][2]},{m[2][1],m[2][2]}}, pom01[2][2]={{m[1][0],m[1][2]},{m[2][0],m[2][2]}}, pom02[2][2]={{m[1][0],m[1][1]},{m[2][0],m[2][1]}},
		  pom10[2][2]={{m[0][1],m[0][2]},{m[2][1],m[2][2]}}, pom11[2][2]={{m[0][0],m[0][2]},{m[2][0],m[2][2]}}, pom12[2][2]={{m[0][0],m[0][1]},{m[2][0],m[2][1]}},
		  pom20[2][2]={{m[0][1],m[0][2]},{m[1][1],m[1][2]}}, pom21[2][2]={{m[0][0],m[0][2]},{m[1][0],m[1][2]}}, pom22[2][2]={{m[0][0],m[0][1]},{m[1][0],m[1][1]}}, inverzna[3][3], d;
	int i,j;
	d=det3(m);
	inverzna[0][0]=1.0/d*det2(pom00);
	inverzna[0][1]=-1.0/d*det2(pom10);
	inverzna[0][2]=1.0/d*det2(pom20);
	inverzna[1][0]=-1.0/d*det2(pom01);
	inverzna[1][1]=1.0/d*det2(pom11);
	inverzna[1][2]=-1.0/d*det2(pom21);
	inverzna[2][0]=1.0/d*det2(pom02);
	inverzna[2][1]=-1.0/d*det2(pom12);
	inverzna[2][2]=1.0/d*det2(pom22);
	printf("\nInverzna matrica je: \n");
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			printf("%f\t",inverzna[i][j]);
		}
	}
	
}

int main()
{
	float m[3][3];
	int i,j;
	char c[20];
	printf("\nUnesi elemente matrice: \n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("m[%d][%d]=",i,j);
			scanf("%f",&m[i][j]);
		}
	}
	printf("\nDeterminanta je %f\n",det3(m));
	if(det3(m)==0)
	{
		printf("Nema inverzne matrice.");
	}
	else
	{
		inv(m);
	}
	printf("\nUnesi bilo sta za zavrsetak.\n");
	scanf("%s",&c);
	return 0;
}
