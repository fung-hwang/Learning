//生产者消费者问题
//2个生产者+2个消费者+5个缓冲池
//使用条件变量+互斥锁
//编译的时候需要连接lpthread或pthread
//算是第一个多线程程序？


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

int maxbuff=5;
int buff=0;

struct msg
{
        pid_t id;
        time_t mytime;
        struct msg* next;
};
struct msg *head;

pthread_cond_t product_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t product_empty = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* producer(void *p)
{
        struct msg *mp;
        int i;
        for(i=0;i<10;i++)
        {
        mp=malloc(sizeof(struct msg));
        mp->id=pthread_self();
        time(&(mp->mytime));
        buff++;
        pthread_mutex_lock(&lock);
        while(buff==maxbuff)
        {
         pthread_cond_wait(&product_full,&lock);
        }
        mp->next=head;
        head=mp;
        pthread_mutex_unlock(&lock);

        printf("生产者%d 第%d次生产:id=%u,time=%s\n",p,i+1,(unsigned)(mp->id),ctime(&(mp->mytime)));

        pthread_cond_signal(&product_empty);
        sleep(rand()%5);
        }
}

void* consumer(void *p)
{
        struct msg *mp;
        int i;
        for(i=0;i<10;i++)
        {
        pthread_mutex_lock(&lock);
        while(head==NULL){
                pthread_cond_wait(&product_empty,&lock);
        }
        mp=head;
        head=mp->next;
        buff--;
        printf("消费者%d 第%d次消费:id=%u,time=%s\n",p,i+1,(unsigned)(mp->id),ctime(&(mp->mytime)));

        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&product_full);
        free(mp);
        sleep(rand() % 5);
        }
}

int main()
{
pthread_t pid1,pid2,cid1,cid2;
srand(time(NULL));
pthread_create(&pid1,NULL,producer,1);
pthread_create(&pid2,NULL,producer,2);
pthread_create(&cid1,NULL,consumer,1);
pthread_create(&cid2,NULL,consumer,2);

pthread_join(pid1,NULL);
pthread_join(pid2,NULL);
pthread_join(cid1,NULL);
pthread_join(cid2,NULL);

return 0;
}
