#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>


unsigned char num_array[] = {
        "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450"
};

int main(void)
{
        int i =0;
        unsigned long long value = 1;
        int temp_array[13] = {0,};
        unsigned long long large_value = 0;


        for(i = 0; i < sizeof(num_array)-13; i++){
                if(i <13){
                        temp_array[i%13] = num_array[i]-'0';
                        value*=temp_array[i%13];
                }
                else{
                        if(temp_array[i%13] != 0){
                                value/=temp_array[i%13];
                        }
                        else{
                                value = temp_array[(i+1)%13] *temp_array[(i+2)%13] *temp_array[(i+3)%13] * temp_array[(i+4)%13]
                                * temp_array[(i+5)%13] *temp_array[(i+6)%13] *temp_array[(i+7)%13] * temp_array[(i+8)%13]
                                * temp_array[(i+9)%13] *temp_array[(i+10)%13]  *temp_array[(i+11)%13] * temp_array[(i+12)%13];
                        }
 
                                //printf("%d,    %d,%d,%d,%d,%d \n",  i, temp_array[0], temp_array[1], temp_array[2], temp_array[3], temp_array[4]);
 
                        temp_array[i%13] = num_array[i]-'0';
                        value*=temp_array[i%13];
                                //printf("Large value %d, value =%d\n", large_value, value);
                        if(large_value < value){
                                large_value = value;
                        }
                }
        }

        printf("Largest value is %llu\n", large_value);


        return 0;
}

