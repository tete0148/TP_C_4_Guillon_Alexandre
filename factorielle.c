#include<stdio.h>


int factorielle (int num) { 
 if (num == 0) { 
    return 1; 
  } 
  else { 
    return (num * factorielle (num-1)); 
  } 
} 

int main(){
int i=0;
for(i=0;i<10;i++){
printf("%d \n",factorielle(i));
}
return 0;

}
