#include <iostream>
using namespace std;

int main()
{
	int m;
	int n;
	bool inter = true;
	
	cin >> m;
	cin >> n;
	
	int vet[m];
	int vet2[n];
	
	for(int i=0; i<m; i++)
		cin >> vet[i];
		
	for(int i=0; i<n; i++)
		cin >> vet2[i];
		
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{	
			if(vet[i]==vet2[j])
			{
				inter = false;
				cout << vet[i] << " ";
				vet2[j] = -1;
			}
		}
	}

	if(inter ==  true)
		cout << -1 << endl;
	else
	cout << endl;
	
	for(int i=0; i<m; i++)
			cout << vet[i] << " ";
			
	for(int i=0; i<n; i++)
		if(vet2[i]!=-1)
			cout << vet2[i] << " ";
			
	return 0;
}
