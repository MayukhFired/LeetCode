void heapify(int* heap , int heapSize , int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < heapSize && heap[left] > heap[largest]){
        largest = left;
    }
    if(right < heapSize && heap[right] > heap[largest]){
        largest = right;
    }

    if(largest != i){
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapify(heap , heapSize , largest);
    }
}

int extractMax(int* heap , int* heapSize){
    if(*heapSize <= 0){
        return 0;
    }

    int maxVal = heap[0];
    heap[0] = heap[*heapSize - 1];
    (*heapSize)--;
    heapify(heap , *heapSize , 0);
    return maxVal;
}

void insertHeap(int* heap , int* heapSize , int value){
    heap[*heapSize] = value;
    int i = *heapSize;
    (*heapSize)++;

    while(i != 0 && heap[(i - 1) / 2] < heap[i]){
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int lastStoneWeight(int* stones, int stonesSize) {
    int heapSize = stonesSize;
    
    for(int i = (heapSize / 2) - 1; i >= 0; i--){
        heapify(stones , heapSize , i);
    }

    while(heapSize > 1){
        int s1 = extractMax(stones , &heapSize);
        int s2 = extractMax(stones , &heapSize);

        if(s1 != s2){
            insertHeap(stones , &heapSize , s1 - s2);
        }
    }

    return heapSize == 1 ? stones[0] : 0;
}