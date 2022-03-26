#include <bits/stdc++.h>

using namespace std;

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    int la=0,index=0;
    vector<vector<int>> arr;
    vector<int> result;
    for(int i=0;i<queries.size();i++)
    {
        if(queries[i][0]==1)
        {
            index=((queries[i][1]^la)%n);
            arr[index].push_back(queries[i][2]);
        }
        else {
            index=((queries[i][1]^la)%n);
            la=arr[index][queries[i][2]%arr[index].size()];
            result.push_back(la);
        }
    }
    return(result);
}

int main()
{
    int n,nor;
    cin>>n>>nor;
    vector<vector<int>> queries(n);
    for(int i=0;i<nor;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>queries[i][j];
        }
    }
    vector<int> result;
    result=dynamicArray(n,queries);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<endl;
    }
}



display list of nakshatras,
declaring input of 2 stars in the form of numbers
store only good taras in a dictionary

#include <iostream>
#include<map>
#include<iterator>
#include<vector>

using namespace std;

map<string,string> generateTara(int &input1, vector<string>&n, vector<string>&t)
{
    int mapping=input1-1;
    map<string,string> result;
    for(int i=0;i<n.size();i++)
    {
        
        if(mapping==27)
            mapping=0;
        
        if(mapping>=input1-1){
            if(t[(mapping-(input1-1))%9]=="Sampath"||t[(mapping-(input1-1))%9]=="Kshema"||t[(mapping-(input1-1))%9]=="Sadhana"||t[(mapping-(input1-1))%9]=="Mitra"||t[(mapping-(input1-1))%9]=="Parama Mitra"){
                //cout<<n[mapping]<<":";
                //cout<<t[(mapping-(input1-1))%9]<<endl;
                result[n[mapping]]=t[(mapping-(input1-1))%9];
            }
            mapping++;
        }
        else{
            if(t[(26-input1+1+mapping+1)%9]=="Sampath"||t[(26-input1+1+mapping+1)%9]=="Kshema"||t[(26-input1+1+mapping+1)%9]=="Sadhana"||t[(26-input1+1+mapping+1)%9]=="Mitra"||t[(26-input1+1+mapping+1)%9]=="Parama Mitra"){
                //cout<<n[mapping]<<":";
                //cout<<t[(26-input1+1+mapping+1)%9]<<endl;
                result[n[mapping]]=t[(26-input1+1+mapping+1)%9];
            }
            mapping++;
        }
    }
    return (result);
    
}

int main()
{
    vector<string> n={"Ashwini","Bharani","Krittika","Rohini","Mrigashira","Ardra","Punarvasu","Pushya","Ashlesha","Magha","Purva Phalguni","Uttara Phalguni","Hasta","Chitra","Swati","Vishaka","Anurada","Jyeshta","Mula","Purva Ashadha","Uttara Ashadha","Shravana","Dhanishta","Shatabhishak","Purva Bhadrapada","Uttara Bhadrapada","Revati"};
    vector<string> t={"Janma","Sampath","Vipath","Kshema","Pratyak","Sadhana","Naidhana","Mitra","Parama Mitra"};
    map<string,string> result;
    cout<<"Select one of the nakshatras from the list:"<<endl;
    for(int i=0;i<n.size();i++)
    {
        cout<<i+1<<"."<<n[i]<<endl;
    }
    int input1;
    cin>>input1;
    result=generateTara(input1,n,t);
    map<string,string>::iterator itptr;
    for(itptr=result.begin();itptr!=result.end();itptr++)
    {
        cout<<itptr->first<<":"<<itptr->second<<endl;
    }
    
}

--------------------------------------------------------------------------------------------------------

#include <iostream>
#include<map>
#include<iterator>
#include<vector>

using namespace std;

vector<pair<string,string>> generateTara(int &input1, vector<string>&n, vector<string>&t)
{
    int mapping=input1-1;
    vector<pair<string,string>> result;
    for(int i=0;i<n.size();i++)
    {
        
        if(mapping==27)
            mapping=0;
        
        if(mapping>=input1-1){
            if(t[(mapping-(input1-1))%9]=="Sampath"||t[(mapping-(input1-1))%9]=="Kshema"||t[(mapping-(input1-1))%9]=="Sadhana"||t[(mapping-(input1-1))%9]=="Mitra"||t[(mapping-(input1-1))%9]=="Parama Mitra"){
                //cout<<n[mapping]<<":";
                //cout<<t[(mapping-(input1-1))%9]<<endl;
                result.push_back(make_pair(n[mapping],t[(26-input1+1+mapping+1)%9]));
                //result[n[mapping]]=t[(mapping-(input1-1))%9];
            }
            mapping++;
        }
        else{
            if(t[(26-input1+1+mapping+1)%9]=="Sampath"||t[(26-input1+1+mapping+1)%9]=="Kshema"||t[(26-input1+1+mapping+1)%9]=="Sadhana"||t[(26-input1+1+mapping+1)%9]=="Mitra"||t[(26-input1+1+mapping+1)%9]=="Parama Mitra"){
                //cout<<n[mapping]<<":";
                //cout<<t[(26-input1+1+mapping+1)%9]<<endl;
                result.push_back(make_pair(n[mapping],t[(26-input1+1+mapping+1)%9]));
                //result[n[mapping]]=t[(26-input1+1+mapping+1)%9];
            }
            mapping++;
        }
    }
    return (result);
    
}

int main()
{
    vector<string> n={"Ashwini","Bharani","Krittika","Rohini","Mrigashira","Ardra","Punarvasu","Pushya","Ashlesha","Magha","Purva Phalguni","Uttara Phalguni","Hasta","Chitra","Swati","Vishaka","Anurada","Jyeshta","Mula","Purva Ashadha","Uttara Ashadha","Shravana","Dhanishta","Shatabhishak","Purva Bhadrapada","Uttara Bhadrapada","Revati"};
    vector<string> t={"Janma","Sampath","Vipath","Kshema","Pratyak","Sadhana","Naidhana","Mitra","Parama Mitra"};
    vector<pair<string,string>> result;
    cout<<"Select one of the nakshatras from the list:"<<endl;
    for(int i=0;i<n.size();i++)
    {
        cout<<i+1<<"."<<n[i]<<endl;
    }
    int input1;
    cin>>input1;
    result=generateTara(input1,n,t);
    //map<string,string>::iterator itptr;
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i].first<<":"<<result[i].second<<endl;
    }
    
}
