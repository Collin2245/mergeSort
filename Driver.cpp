#include <iostream>
using namespace std;

void printArray(int * ar, int begin, int end)
{
    for(int i =begin; i <=end; i ++)
    {
        cout << ar[i]<< " ";
    }
    cout << "\n";
}

void miniSort(int* ar, int begin, int end)
{
    for(int i =begin; i <= end; i ++)
    {
        if(ar[i]>ar[i+1])
        {
            int temp = ar[i+1];
            ar[i+1]=ar[i];
            ar[i]=temp;
        }
    }
}

void mergeSort(int* ar, int begin, int end)
{
    cout << "Merge Sorting: ";
    printArray(ar, begin, end);
    //if it is not a 1 list (not trivially sorted)
    if(begin != end)
    {
        int begin1 = begin;
        int end1 = (end + begin)/2;
        int begin2 = end1 +1;
        int end2 = end;

        mergeSort(ar, begin1, end1);

        //call mergeSort on the second half, this will not fire until the entire first half is dealt with
        mergeSort(ar,begin2,end2);

        cout << "now we have to merge: \n";
        cout<<"arrayOne: "; 
        printArray(ar,begin1,end1);
        cout<<"arrayTwo: "; 
        printArray(ar,begin2,end2);
        cout <<"\n";

        miniSort(ar,begin1,end1);
        miniSort(ar,begin2,end2);


        for(int i = begin; i<=end;i++)
        {
            for(int k =begin; k<=end;k++)
            {
                if(ar[i]<ar[k])
                {
                    int temp = ar[k];
                    ar[k]=ar[i];
                    ar[i]=temp;
                }
            }
        }

        cout<<"sort Done: "; 
        printArray(ar,begin,end);
   
    }
    else
    {
        cout << "One list, do nothing.\n";
    }
    
}


int main()
{
    int ar[10] = {7,2,1,4,3,9,9,0,3,4};
    mergeSort(ar, 0,9);
    printArray(ar,0,9);
    return 0;
}   