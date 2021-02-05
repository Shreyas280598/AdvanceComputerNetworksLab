#include<stdio.h>
#include<stdlib.h>

void main()  {
    int incoming, outgoing, buck_size,n;
    int remain, storage = 0;
    printf("Enter the bucket size, outgoing rate and number of inputs/n");
    scanf("%d %d %d", &buck_size, &outgoing, &n);
    
    while(n != 0){
        printf("Enter incoming packet size\n");
        scanf("%d", &incoming);
        printf("Incoming packet size %d\n", incoming);
        remain = buck_size - storage;
        if(incoming <= remain){
            store += incoming;
            printf("bucket buffer size %d out of %d\n", storage, buck_size);
        }
        else {
            printf("dropped %d packets", incoming - remain);
            printf("Bucker buffer size %d out of %d", remain, buck_size);
            storage = buck_size;
        }
        storage = storage - outgoing;
        printf("After outgoing %d packet left out of %d in buffer\n", storage, buck_size);
        n--;
    }
}
