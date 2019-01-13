#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
int row[8], a,b,t,counter;

bool place(int r, int c){
	for (int prev = 0; prev < c ; prev++)
	{
		if(row[prev]==r || abs(row[prev]-r)==abs(c-prev)  ){
			return false;
		}
	}
	return true;
}


void backtrack(int c){
	if(c==8 && row[b]==a){
		printf("%2d		%d ",++counter,row[0]+1);
		for (int i = 1; i < 8; i++)
		{
			printf("%d ", row[i]+1);
		}
		printf("\n");
	}
	for (int r = 0; r < 8; r++)
	{
		if (place(r,c))
		{
			row[c]=r;
			backtrack(c+1);
		}
	}
}

int main(){

	scanf("%d" ,&t);
	while(t--){
		scanf("%d %d" ,&a,&b);a--;b--;
		memset(row, 0, sizeof(row));
		printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
		counter = 0;
		backtrack(0);
		if (t) printf("\n");
	}
	return 0;
}