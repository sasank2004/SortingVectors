/*
I(Sasank Marthand) rewrote the famous sorting functions for vectors by myself
Hope you like it
I honestly feel great after coding this
*/




#include<iostream>
#include <vector>
using namespace std;

//bubble sort like bubble flow up unless obstructed, 
//the max value floats towards the right
vector<int> bubble(vector<int> a){
    int len=a.size();
    int t;
    for(int k=0;k<len-1;k++){
        //each pass
        for(int i=0;i<len-1-k;i++){
            if(a[i]>=a[i+1]){
                t=a[i+1];
                a[i+1]=a[i];
                a[i]=t;
                //n integers = n-1 comparisions
                //I still have no clue how bubble sort is adaptive
            }
        }
    }
    return a;
};

//Insertion sort happens like we go till we find an unsorted mini array between 0 and n
//then we take the ith element back while exchanging element till we sort it
vector<int> insertion(vector<int> a){
    int len = a.size();
    int t;
    for(int i=0;i<len;i++){
        for(int j=i;j>0;j--){
            if(a[j]<a[j-1]){
                t=a[j-1];
                a[j-1]=a[j];
                a[j]=t;
            }
            else{
                break;
                //this is what makes insertion sort adaptive
            }
        }
    }
    return a;
};

//We find the miniumum as swap with first element in the sub vector
//We then remove the first element from the sub vector and repeat
vector<int> selection(vector<int> a){
    int len = a.size();
    int min,temp,mi=0;;
    for(int i=0;i<len;i++){
        min = a[i];
        for(int j=i;j<len;j++){
            if(a[j]<=min){
                min = a[j];
                mi=j;
            }
        }
        temp = a[mi];
        a[mi]= a[i];
        a[i]=temp;
    }
    return a;
};

//We use recursion of by sub dividing it at index and use fxn for low and that, that and high
//So the recursion is divided until single element is obtained
//Whoever designed quicksort is a genius
vector<int> quick(vector<int> a,int low,int high){
    int pivot = low;
    int i = low+1;
    int j = high;
    int temp,pi;
    if(low<high){
    //until more than 1 element is left
        do{
            while (a[i] <= a[pivot]&&i<high)
            {
                i++;
            }
            while (a[j] >= a[pivot]&&j>low)
            {
                j--;
            }
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }while(i<j);
        
        //switching the pivot itself
        temp = a[pivot];
        a[pivot]=a[j];
        a[j]=temp;
        //all elements on left are less than pivot, all elements on right are more than pivot
        pi=j;
        //breaking at pivot
        if(pi-1>=0){
            a = quick(a,low,pi-1);
            //we use recursion until 1 element is left
        }
        if(pi<=high-1){
            a = quick(a,pi+1,high);
            //we use recursion until 1 element is left
        }
        
    }
    return a;
};

//Came up with sort of my own version for merge sort
//The principle behind is same but I have used a different logic
//We break it at mid until we have two elements, then we sort those two, 
//Then the recursion will take over
//The debugging was hell for this
vector<int> merge(vector<int> a,int low,int high){
        int mid = (low+high)/2;
        vector<int> b=a;
        int i=low,j=mid+1,k=low;
        if(low<high){
            if(high-low>1){
                a = merge(a,low,mid);
                a = merge(a,mid+1,high);
            }
            else{
                if(a[low]>=a[high]){
                    b[high]=a[low];
                    b[low]=a[high];
                }
                else{
                    return a;
                }
            }
            while(i<=mid&&j<=high){
                if(a[i]<=a[j]){
                    b[k]=(a[i]);
                    i++;
                    k++;
                }
                else{
                    b[k]=(a[j]);
                    j++;
                    k++;
                }
            }
            while(i<=mid){
                b[k]=(a[i]);
                i++;
                k++;
            }
            while(j<=high){
                b[k]=(a[j]);
                j++;
                k++;
            }
        }
        else{

        }
        
        return b;
};

//This is quite simple and is like transposing elements to be index
vector<int> count(vector<int> a){
    int max=a[0];
    int len = a.size();
    for(int i =0;i<len;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    //we get the max element
    vector<int> counter,final;
    for(int i=0;i<=max;i++){
        counter.push_back(0);
    }
    //Initialize all elements to 0
    for(int i=0;i<len;i++){
        counter[a[i]]++;
    }
    //increase counter for that value

    for(int i=0;i<=max;i++){
        if(counter[i]>0){
            while(counter[i]>0){
                final.push_back(i);
                counter[i]--;
            }
        }
    }
    return final;
};


int main()
{
    vector<int> a={33,9,1,6,8,11,69,4,39,90,88,4,9,5,7};
    vector<int> b,i,s,q,m,c;
    i = insertion(a);
    b = bubble(a);
    s = selection(a);
    q = quick(a,0,a.size()-1);
    m = merge(a,0,a.size()-1);
    c = count(a);
    //
    cout<<"A : ";
    for(auto x:a){
        cout<<x<<" ";
    }
    cout<<endl;

    cout<<"Bubble sort : ";
    for(auto x:b){
        cout<<x<<" ";
    }
    cout<<endl;

    cout<<"Insertion sort : ";
    for(auto x:i){
        cout<<x<<" ";
    }
    cout<<endl;

    cout<<"Selection sort : ";
    for(auto x:s){
        cout<<x<<" ";
    }
    cout<<endl;
    
    cout<<"Quick Sort : ";
    for(auto x:q){
        cout<<x<<" ";
    }
    cout<<endl;

    cout<<"Merge Sort : ";
    for(auto x:m){
        cout<<x<<" ";
    }
    cout<<endl;

    cout<<"Count Sort : ";
    for(auto x:c){
        cout<<x<<" ";
    }
    cout<<endl;
}