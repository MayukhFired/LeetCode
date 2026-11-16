// 1-----------------------------------------------------1
// bool binary_search(int s , int e , int n){
//     if(s > e){
//         return false;
//     }
//     long long mid = s + (e - s) / 2;
//     if(mid * mid == n){
//         return true;
//     }
//     if(mid * mid > n){
//         return binary_search(s , mid - 1 , n);
//     }
//     return binary_search(mid + 1 , e , n);
// }
// 1----------------------------------------------------1

bool judgeSquareSum(int c) {
// 1-------------------------------------------------1
    // for(long long a = 0; a * a <= c; a++){
    //     int b = c - (int)(a * a);
    //     if(binary_search(0 , b , b)){
    //         return true;
    //     }
    // }
    // return false;
// 1--------------------------------------------------1
    long long a = 0;
    long long b = sqrt(c);
    while(a <= b){
        long long d = (a * a) + (b * b);
        if(d == c){
            return true;
        }else if(d > c){
            b--;
        }else{
            a++;
        }
    }
    return false;
}