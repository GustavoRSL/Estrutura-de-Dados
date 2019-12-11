#include <iostream>
using namespace std;

int main()
{	
	int N;
	int M;
	
	cin >> N >> M;
	
	int matriz[N][M];
	
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin >> matriz[i][j];
			
	for(int j=0; j<M; j++)
	{
		for(int i=0; i<N; i++)
		{
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
