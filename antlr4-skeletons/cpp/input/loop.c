int main(){
    int a,b,c, d, i,J,p;
    b=0;
	c=0;
    for(i=0;i<4;i++){
        a=3;
        while(a--){
            for(p=0;p<5;p++){
                c++;
                println(c);
            }
            b++;
        }
    }
    // for ( i = 0; i < 3; i++)
    // {
    //     for (J = 0; J < 4; J++)
    //     {
    //         for ( p = 0; p < 5; p++)
    //         {
    //             c++;
    //             println(c);
    //         }
            
    //     }
        
    // }
    
    println(a);
    println(b);
    println(c);
}
