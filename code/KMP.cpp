void KMP(string text,string pattern){
      int n = text.length(), m = pattern.length(), F[m+2],i,j;
      F[0] = F[1] = 0;
      for(int i = 2;i<=m;i++){
           j = F[i-1];
           while(true){
                if(pattern[j] == pattern[i-1]) { F[i] = j+1; break;}
                else if(j==0) {F[i] = 0; break;}
                else j = F[j];
           }
      }

      i = j = 0;
      while(j<n){
           if(text[j] == pattern[i]){
                i++; j++;
                if(i==m) printf("%d ",j-i+1);
           }
           else if(i>0) i = F[i];
           else j++;
      }
}

int main(){
     string a,b;
     cin>>a>>b;
     KMP(a,b);
    // getch();
}
