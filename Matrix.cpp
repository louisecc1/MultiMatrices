#include<iostream>
using namespace std;
int rec(int a, int b,int m, int **ary){
  if (a==b){
    return 0;
  }
  else{
    ary[a]=new int[m];
    return rec(++a,b,m,ary);
  }
}
int yeso(int **arra,int m, int n,int g,int r){
    if(r==m){
      return 0;
    }
    cin>>*(arra[r]+g);
    if ((g+1)%n==0){
      ++r;
      return yeso(arra,m,n,0,r);
    }
    return yeso(arra,m,n,++g,r);
    }

int imprimir(int **arra, int m, int n,int h,int r){
    if(r==m){
      return 0;
    }
    cout<<*(arra[r]+h);
    if ((h+1)%n==0){
      ++r;
    cout<<"\n";
    return imprimir(arra,m,n,0,r);
    }
  return imprimir(arra,m,n,++h,r);
  }
int multi(int **art,int **sadt,int n,int m, int b,int r,int h,int g,int t){
  g=g+(*(art[r]+h))*(*(sadt[h]+r));
  if(t==n-1){
    return g;
  }
  multi(art,sadt,n,m,b,r,++h,g,++t);
}
int multi1(int **arr,int **sadd,int **cedd,int n,int m, int a, int b,int r,int h){
    if(m!=a){
      cout<<"No se puede realizar la operacion"
      return 0;
    }
    if(r==n){
      return 0;
    }
    *(cedd[r]+h)=multi(arr,sadd,n,m,b,r,0,0,0);
    if((h+1)%b==0){
      multi1(arr,sadd,cedd,n,m,a,b,++r,0);
    }
    return multi1(arr,sadd,cedd,n,m,a,b,++r,++h);
}
int main(){
  int N,M,A,B;
  cout<<"ingrese el tamaño de su matrix1(i*j): "<<"\n";
  cin>>N>>M;
  int **ary = new int *[N];
  rec(0,N,M,ary);
  cout<<"ingrese los datos de su matrix1(i*j): "<<"\n";
  yeso(ary,N,M,0,0);
  imprimir(ary,N,M,0,0);
  cout<<"ingrese el tamaño de su matrix2(i*j): "<<"\n";
  cin>>A>>B;
  int **sada=new int *[A];
  rec(0,A,B,sada);
  cout<<"ingrese los datos de su matrix2(i*j): "<<"\n";
  yeso(sada,A,B,0,0);
  imprimir(sada,A,B,0,0);
  int **ceda=new int*[N];
  rec(0,N,B,ceda);
  multi1(ary,sada,ceda,N,M,A,B,0,0);
  imprimir(ceda,N,B,0,0);
  delete []ary;
  delete []sada;
  delete []ceda;
  return 0;
}
