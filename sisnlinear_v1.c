#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 3
#define PI 3.1415

double f1(double x[N]) 
{	return (pow(x[0],2) - 81*pow(x[1] + 0.1, 2) + sin(x[2]) + 1.06)	;	}
	
double f2(double x[N]) 
{	return (exp(x[0]*x[1]) + 20*(x[2]) + (10*PI -3) / 3.0 )	;	}

double f3(double x[N]) 
{	return (-3*x[0] - cos(x[1]*x[2]) - 0.5)	;	}

double df(double f(), double x[N], int x0)
{	int i=1;
	double h=1e-6, xa, dff;
	
		xa=x[x0];
		x[x0]=x[x0]+h/2;
		dff=f(x);
		x[x0]=x[x0]-h;
		dff=(dff-f(x))/h;
		x[x0]=xa;
	return dff;
}

void imprime(double **M)
{	int i, j;
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("%lf\t", M[i][j]);
		}
		printf("\n");
	}
}

void escalonamento(double **M)
{	int i, j, k;
	double pivo;
	
	for(k=0; k<N-1; k++)
	{
		for(i=k+1; i<N; i++)
		{	if(M[k][k]==0)
			{	pivo = 0;	}
			else
			{	pivo = (M[i][k] / M[k][k]);	
				
				for(j=k; j<N+1; j++)
					M[i][j] = M[i][j] - (pivo * M[k][j]);
			}
		}	
	}
	
}


void subs_reversa(double **M)
{   
    double x1, x2, x3;
    
    x3 = ( M[2][4] - (M[2][3]*x4) ) / M[2][2];
    x2 = ( M[1][4] - (M[1][3]*x4) - (M[1][2]*x3) ) / M[1][1];
    x1 = (M[0][4] - (M[0][1]*x2) - (M[0][2]*x3) - (M[0][3]*x4) ) / M[0][0];

    printf("\nA Solução do sistema é: (%.1f,%.1f,%.1f)\n", x1,x2,x3);

} 
	
int main()
{	int cont, i, j; cont;
	double err, norma;
	double x[N], F[N], y[N];
	double (*equacao[N])()={f1, f2, f3};
	double **jacob;
	
	cont=0; err=1e-10;	
	norma = 0;

	//lendo o vetor inicial X[N]
	for(i=0; i<N; i++)
	{
		printf("Informe o valor da posição %d do vetor inicial, Xo(i, j, k):\n", i);
		scanf("%lf", &x[i]);
	}

	//calculando o vetor de equações - F[i]
	for(i=0; i<N; i++)
	{
		F[i]= - equacao[i](x);
	}
	
	jacob = malloc( N*sizeof(double*));
	for (i=0; i<N; i++) 
	{
	 	jacob[i] = malloc((N)*sizeof(double));	
	}

	do
	{
		//calculando o jacobiano
		for(i=0; i<N; i++)
		{
			for(j=0; j<N; j++)
			{
				jacob[i][j] = df(equacao[i], x, j);
			}
		}
	
		printf("A matriz jacobiana é:\n");
		imprime(jacob);
	
		printf("Após o escalonamento a matriz jacobiana é:\n");
		escalonamento(jacob);

		subs_reversa(jacob);
		y[i] = ?;
		for(i=0; i<N; i++)
		{
			x[i]=x[i]+y[i];
		}

		
		cont++;
		if(cont==15)
		{ break; }	//para o loop
	}
	while(norma < err);
}
