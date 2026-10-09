int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int counts[2] = {0 , 0};
    for(int i = 0; i < studentsSize; i++){
        counts[students[i]]++;
    }

    for(int i = 0; i < sandwichesSize; i++){
        int s = sandwiches[i];
        if(counts[s] == 0){
            break;
        }

        counts[s]--;
    }
    return counts[0] + counts[1];
}