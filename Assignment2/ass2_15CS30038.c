#define BUFF 50
#define BYTES 100
#define ERR 1
#define OK 0

int intToStr(int x, char str[], int d);    //FUNCTION FOR SELF USE
int power(int x, unsigned int y);          //FUNCTION FOR SELF USE


int printStr(char *x){
    char buff[BUFF];
    int i,bytes=0;
    for(i = 0; x[i] != '\0'; ++i)
    {
        buff[i] = x[i];
        bytes++;
    }

    buff[i] = '\n';
    bytes=bytes+1;

    __asm__ __volatile__ (
        "movl $1,%%eax\n\t"
        "movq $1,%%rdi\n\t"
        "syscall \n\t"
        :
        :"S"(buff),"d"(bytes)
        );
    return bytes-1;
}

int readInt(int* n){
    char buff[BUFF];
    int bytes=BYTES;
    int error_x;

    __asm__ __volatile__ (
        "movl $0,%%eax\n\t"
        "movq $0,%%rdi\n\t"
        "syscall \n\t"
        :"=a"(error_x)
        :"S"(buff),"d"(bytes)
        );

    int res = 0;  // Initialize result
    int sign = 1;  // Initialize sign as positive
    int i=0;  // Initialize index of first digit
    // If number is negative, then update sign
    if (buff[0] == '-')
    {
        sign=-1;
        i++;  // Also update index of first digit
    }
    for (; (buff[i]=='0'|| buff[i]=='1'||buff[i]=='2'||buff[i]=='3'||buff[i]=='4'||buff[i]=='5'||buff[i]=='6'||buff[i]=='7'||buff[i]=='8'|| buff[i]=='9'); ++i)
        {res = res*10 + buff[i]-'0';}
    int k=sign*res;
    *n=k;

    if(error_x<0){
    return ERR;
   }else return OK;

}

int printInt(int n){
    char buff[BUFF],zero='0';
    int i=0,j,k,bytes,error_x;
    if(n==0) buff[i++]=zero;
    else{

        if(n<0){
            buff[i++]='-';
            n=-n;
        }

        while(n){
            int dig=n%10;
            buff[i++]=(char)(zero+dig);
            n/=10;
        }

        if(buff[0]=='-')j=1;
        else j=0;
        k=i-1;
        while(j<k){
            char temp=buff[j];
            buff[j++]=buff[k];
            buff[k--]=temp; 
        }
    }
    buff[i]='\n';
    bytes=i+1;

    __asm__ __volatile__ (
        "movl $1,%%eax\n\t"
        "movq $1,%%rdi\n\t"
        "syscall \n\t"
        :"=a"(error_x)
        :"S"(buff),"d"(bytes)
        );
    if(error_x<0){
    return ERR;
   }else return bytes-1;
}


int readFlt(float *f){
     char buff[BUFF];
     int bytes=BYTES,ps;
     float ans,rx=0,ft=1;
     int i=0,error_x;

    __asm__ __volatile__ (
        "movl $0,%%eax\n\t"
        "movq $0,%%rdi\n\t"
        "syscall \n\t"
        :"=a"(error_x)
        :"S"(buff),"d"(bytes)
        );

  if (buff[0]=='-'){
     i++;
    ft = -1;
  };

  for (ps = 0; buff[i]!='\0';++i){
    if (buff[i] == '.'){
      ps = 1; 
      continue;
    };

    int dr = buff[i]-'0';
    if (dr >= 0 && dr <= 9){
      if (ps) ft /= 10.0f;
      rx=rx*10.0f+(float)dr;
    };
  };
  ans= rx * ft;
  *f=ans;

  if(error_x<0){
    return ERR;
  }else return OK;

}


int printFlt(float n){
	char buff[BUFF];
	int bytes,x=0;
	int afterpoint=4;  //number of points after decimal

	int ipart,error_x;
    float fpart;
    
    if(n>0){   //Seperate integer and float parts
    ipart = (int)n;
    fpart = n - (float)ipart;
    }else{
        ipart = (int)n;
        fpart = (float)ipart - n;
    } 
    
    int i = intToStr(ipart, buff , 0);
    if (afterpoint != 0)
    {
        buff[i] = '.';  // add dot
        fpart = fpart * power(10, afterpoint);
        x = intToStr((int)fpart, buff + i + 1, afterpoint);
    }
    	buff[x+i+1]='\n';
    	bytes=x+i+2;

	__asm__ __volatile__ (
		"movl $1,%%eax\n\t"
		"movq $1,%%rdi\n\t"
		"syscall \n\t"
		:"=a"(error_x)
		:"S"(buff),"d"(bytes)
		);

    if(error_x<0){
    return ERR;
   }else return bytes-1;
}





//FUNCTIONS FOR SELF USE
int power(int x, unsigned int y) //POW FUNCTION 
{
    if (y == 0)
        return 1;
    else if (y%2 == 0)
        return power(x, y/2)*power(x, y/2);
    else
        return x*power(x, y/2)*power(x, y/2);
}
 
int intToStr(int x, char str[], int d) //FUNCTION TO CONVERT THE INTEGER TO STRING
{   char zero= '0';
    int i=0,j,k;
    if(x==0) str[i++]=zero;
    else{

        if(x<0){
            str[i++]='-';
            x=-x;
        }

        while(x){
            int dig=x%10;
            str[i++]=(char)(zero+dig);
            x/=10;
        }

        if(str[0]=='-')j=1;
        else j=0;
        k=i-1;
        while(j<k){
            char temp=str[j];
            str[j++]=str[k];
            str[k--]=temp; 
        }
    }
    str[i]='\0';
    return i;

}
