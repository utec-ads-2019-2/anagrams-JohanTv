#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string,int> anagramas;
vector<string> palabras;

string key(string cadena){
    for(int i=0;i<cadena.length();i++){
        cadena[i]=tolower(cadena[i]);
    }
    sort(cadena.begin(),cadena.end());
    return cadena;
}

void impresion(){
    string temp;
    vector<string> save;
    for(auto it= palabras.begin(); it!=palabras.end(); it++){
        if(anagramas[key((*it))]==1){
            save.push_back(*it);
        }
    }
    sort(save.begin(),save.end());
    for(auto it=save.begin();it!=save.end();it++){
        cout<<*it<<endl;
    }
}


int main(){
    string palabra;
    while(cin>>palabra){
        if(palabra=="#") break;
        else{
            palabras.push_back(palabra);
            anagramas[key(palabra)]++;
        }
    }
    impresion();

}
