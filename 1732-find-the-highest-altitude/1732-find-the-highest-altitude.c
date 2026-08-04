#define max(a , b) ((a) > (b) ? (a) : (b))
int largestAltitude(int* gain, int gainSize) {
    int curr_alt = 0;
    int max_alt = 0;
    for(int i = 0 ; i < gainSize; i++){
        curr_alt += gain[i];
        if(max_alt < curr_alt){
            max_alt = curr_alt;
        }
    }
    return max_alt;
}