//
//  main.cpp
//  Djikstra's Algorithm
//
//  Created by Vivek Tejwani on 03/04/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
using namespace std;
int n;
int adj[100][100];
int q_count;
int queue[100][3];
void djikstra();
void sort_it();
int main (int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    cout<<"Enter the number of vertices\n";
    cin>>n;
    cout<<"We now enter the adjacency matrix, please enter 10000 in case of no direct path\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"The weight of path from "<<i+1<<" to "<<j+1<<" is :";
            cin>>adj[i][j];
            cout<<"\n";
        }
    }
    for(int i=0;i<n;i++)
    {
        queue[i][0]=i+1;
        queue[i][1]=adj[0][i];
        queue[i][2]=0;
    }
    sort_it();
    djikstra();
   
    
    return 0;
}
void sort_it()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(queue[j][1]>queue[j+1][1])
            {
                int temp=queue[j][1];
                queue[j][1]=queue[j+1][1];
                queue[j+1][1]=temp;
                temp=queue[j][2];
                queue[j][2]=queue[j+1][2];
                queue[j+1][2]=temp;
                temp=queue[j][0];
                queue[j][0]=queue[j+1][0];
                queue[j+1][0]=temp;
            }
        }
    }
}

void djikstra()
{
    int arr[4][100];
    arr[1][0]=0;
    for(int i=0;i<n;i++)
    {
        arr[0][i]=i+1;
        if(i!=0)
        {
            arr[1][i]=100000;
        }
        arr[2][i]=0;
        arr[3][i]=0;
    }
    int z=0;
    while(1)
    {
        int u;
        sort_it();
        
        if(z==n)
            break;
        for(z=0;z<n;z++)
        {
            if(queue[z][2]==0)
            {
                u=queue[z][0];
                queue[z][2]=1;
                break;
            }
            
        }
        
        for(int j=0;j<n;j++)
        {
                if((arr[1][u-1]+adj[u-1][j])<arr[1][j])
                {
                    arr[1][j]=arr[1][u-1]+adj[u-1][j];
                    arr[2][j]=u;
                    for(int i=0;i<n;i++)
                    {
                        if(queue[i][0]==j+1)
                        {
                             queue[i][1]=arr[1][j];
                            
                            cout<<j<<"\t";
                            cout<<"Value of "<<queue[i][0]<<" updated to "<<queue[i][1]<<"\n";

                            break;
                        }
                    }
                                   }
            
        }
    }
    cout<<"As a check, lets see the other array\n";
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<" : "<<arr[0][i]<<" "<<arr[1][i]<<" "<<arr[2][i]<<" "<<arr[3][i]<<"\n";
    }
    
    cout<<"The final distances of source from each point are\n";
    for(int i=0;i<n;i++)
    {
        cout<<queue[i][0]<<" : "<<queue[i][1]<<"\n";
    }
}