#include <iostream>

using namespace std;

void Merge(int A[], int low, int mid, int high)
{
	//size of left array
	int i,j,k;
	int l=mid-low+1;
	int L[l];
	
	//size of right array
	int r=high-mid;
	int R[r];
	
	//input left and right arrays
	for(i=0; i<l; i++)
	{
		L[i]=A[low+i];
	}
	for(j=0; j<r; j++)
	{
		R[j]=A[mid+1+j];
	}
	
	i=0; j=0; k=1;
	for(k=low; i<l && j<r; k++)
	{
		if(L[i]<R[j])
		{
			A[k]=L[i];
			i++;
		}
		else
		{
			A[k]=R[j];
			j++;
		}
	}
    while(i<l)
    {
       A[k++]=L[i++];	
	}
    	
    while(j<r)
    {
       A[k++]=R[j++];	
	}
    	
    	
	
	
}


//Dividing list, sorting and merging list
void MSort(int A[], int low, int high)
{
	if(low<high)
	{
		int mid=(low + high)/2;  
		
		MSort(A,low,mid);
		
		MSort(A,mid+1,high);
		
		Merge(A,low,mid,high);
	}
}


int main()
{
	//take number of list in total
	int n;
	cout<<" Enter total elements number "<<endl;
	cin>>n;
	cout<<" number of items in list:"<<n<<endl;
	int A[n];
	
	//take list items
    cout << " key in list" << endl;
    for(int i=0; i<n; i++)
    {
    	cin>>A[i];
    	cout<<" List item:"<<A[i]<<endl;
	}
	
	// Merge sort applied
	MSort(A,0,n-1);
	for(int i=0; i<n; i++)
	{
		cout<<A[i]<<" "<<endl;
	}
	
	
return 0;
}
