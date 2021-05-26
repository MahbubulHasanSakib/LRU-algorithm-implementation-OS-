#include<bits/stdc++.h>
#define Min 1000000000
using namespace std;
void lru(int str[],int len, int fs)
{
    int frame[fs];
    int f_cnt=0;
    memset(frame,-1,sizeof(frame));       ///initializing all the frame to -1 means empty at fist
    cout<<"Ref String      ";
    for(int i=0;i<fs;i++)
    {
        cout<<"frame-"<<i+1<<"\t\t";
    }
    cout<<"Status"<<endl;
    for(int i=0; i<len; i++)
    {
        int flag=0;
        for(int j=0; j<fs; j++)
        {
            if(frame[j]==str[i])       ///checking if the input character is already exists in the frames
            {
                flag=1;
                break;
            }

        }
        if(flag==1)
        {
            cout<<str[i]<<"\t\t";
            for(int j=0; j<fs; j++)

            {
                cout<<" "<<frame[j]<<"\t\t";     ///printing the remaining frame values
            }
            cout<<"Hit"<<endl;          ///printing page is Hit when the input character is already exists in any one of the frames
            continue;
        }
        if(flag==0)
        {
            for(int j=0; j<fs; j++)
            {
                if(frame[j]==-1)            ///checking if any frame is yet empty
                {
                    frame[j]=str[i];       ///putting the input character into the empty frame
                    flag=1;
                    break;
                }

            }
        }
        if(flag==1)
        {
            cout<<str[i]<<"\t\t";
            for(int j=0; j<fs; j++)

            {
                cout<<" "<<frame[j]<<"\t\t";      ///printing the existing frame values
            }
            cout<<"Fault"<<endl;                  ///page is fault because input value is not matched with any existing frame values
            f_cnt++;                             ///counting it as a page fault
            continue;
        }
        if(flag==0)                ///if input value is unmatched with any frame value and all frames are full,this block will execute
        {
            int minIndex=Min;
            for(int j=0;j<fs;j++)
            {
                for(int k=i-1;k>=0;k--)             ///traversing the previous string indexes for tacking recently used position
                {
                    if(frame[j]==str[k])
                    {
                        minIndex=min(minIndex,k);   ///finding the least recently used frame value index from the string using all of the frame values
                        break;
                    }
                }
            }
            for(int j=0;j<fs;j++)
            {
                if(frame[j]==str[minIndex])       ///finding the frame which contains least recently used character
                {
                    frame[j]=str[i];          ///deleting the least recently used character from the frame and putting the new input character in this frame
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
        {
            cout<<str[i]<<"\t\t";
            for(int j=0; j<fs; j++)

            {
                cout<<" "<<frame[j]<<"\t\t";          ///printing all existing frame values
            }
            cout<<"Fault"<<endl;          ///this is also page fault because input character is not exist in the previous frame values
            f_cnt++;                         ///counting it as a page fault
            continue;
        }
    }
    cout<<endl;
    cout<<"Total number of faults:"<<f_cnt<<endl;    ///printing the total number of page faults
}
int main()
{
    int str[]= {1,3,5,6,3,4,5,6,7,8,9,1,3,5,2,3,3,5,6,7,6,7,8,2,3,4,5,6,7};   ///taking the string as input
    int fs;
    int len=sizeof(str)/sizeof(str[0]);
    cout<<"Enter frame size:";
    cin>>fs;                                       ///taking the frame size
    lru(str,len,fs);
    return 0;
}
