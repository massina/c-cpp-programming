/*
tok(): is use to generate a unique key.
shmget(): int shmget(key_t,size_tsize,intshmflg); upon successful completion, shmget() 
returns an identifier for the shared memory segment.

shmat(): Before you can use a shared memory segment, you have to attach yourself
to it using shmat(). void *shmat(int shmid ,void *shmaddr ,int shmflg);
shmid is shared memory id. shmaddr specifies specific address to use but we should set
it to zero and OS will automatically choose the address.

shmdt(): When you’re done with the shared memory segment, your program should
detach itself from it using shmdt(). int shmdt(void *shmaddr);

shmctl(): when you detach from shared memory,it is not destroyed. So, to destroy
shmctl() is used. shmctl(int shmid,IPC_RMID,NULL);
*/


// #include <iostream> 
// #include <sys/ipc.h> 
// #include <sys/shm.h> 
// #include <stdio.h> 
// using namespace std; 
  
// int main() 
// { 
//     // ftok to generate unique key 
//     key_t key = ftok("shmfile",65); 
  
//     // shmget returns an identifier in shmid 
//     int shmid = shmget(key,1024,0666|IPC_CREAT); 
  
//     // shmat to attach to shared memory 
//     char *str = (char*) shmat(shmid,(void*)0,0); 
  
//     cout<<"Write Data : "; 
//     gets(str); 
  
//     printf("Data written in memory: %s\n",str); 
      
//     //detach from shared memory  
//     shmdt(str); 
  
//     return 0; 
// } 