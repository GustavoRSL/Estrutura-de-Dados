#include <iostream>
using namespace std;

void quick(int vet[], int esq, int dir){
    int pivo = esq, i,ch,j;         
    for(i=esq+1;i<=dir;i++){        
        j = i;                      
        if(vet[j] < vet[pivo]){     
            ch = vet[j];               
            while(j > pivo){           
                vet[j] = vet[j-1];      
                j--;                    
            }
            vet[j] = ch;               
            pivo++;                    
        }
    }
    if(pivo-1 >= esq){              
        quick(vet,esq,pivo-1);      
    }
    if(pivo+1 <= dir){              
        quick(vet,pivo+1,dir);      
    }
 }

int main()
{
	int vet1[5];
	int vet2[5];
	int vetresultante[10];
	
	for(int i=0; i<5; i++)
		cin >> vet1[i];
	
	for(int i=0; i<5; i++)
		cin >> vet2[i];
	
	for(int i=0; i<10; i++)
	{
		if(i<5)
		vetresultante[i] = vet1[i];
		else
		{
			vetresultante[i] = vet2[i-5];
		}
	}
	
	quick(vetresultante,0,9);
	
	for(int i=0; i<10; i++)
	cout << vetresultante[i] << " ";
	
	
	return 0;
}
