# include <stdio.h>
int max(int x, int y){
  return(x > y)? x : y;
}

unsigned int mochila_0_1_entero(*w,*p,max_w,e){
  //int max_w = c ;//10
  //  int ganancia = (sizeof p/ sizeof p[0]);
  int matriz[e + 1][max_w + 1];
  int i,j;
  for(i = 0; i<=max_w; i++ ){
    matriz[0][i] = 0;
  }
  for(j = 0; j<=e; j++ ){
    matriz[j][0] = 0;
  }

  for(i = 1; i<= e; i++ ){
    for(j = 0; j<= max_w; j++ ){
      if(w[i]<=j){
	 matriz[i][j] = max(matriz[i-1][j], matriz[i-1][j-w[i]] + p[i]);
       }else{
       	matriz[i][j] = matriz[i-1][j];

	  }
    }
  } 
  printf("max  %d\n", max_w);
  return matriz[e][max_w];
}

int main(){
  int w[] = {2,3,4,5};//
  int p[] = {3,4,5,6};//
  int W = 5;//
  int elem = (sizeof p/ sizeof p[0]);
  printf("total : %d\n", mochila_0_1_entero(w,p,W, elem));

  return 0;
}
