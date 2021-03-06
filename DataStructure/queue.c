//
//  queue.c
//  DataStructure
//
//  Created by Apple on 2019/5/18.
//  Copyright © 2019 WangAn. All rights reserved.
//

#include <stdlib.h>
#include "queue.h"

/*   -----------------------------   */
// int型队列的操作实现

Queue createQueue(int length){
    Queue queue;
    queue.list = (int*)malloc(sizeof(int)*length);
    queue.front = 0;
    queue.rear = 0;  // 初始条件下，队列为空，front=rear
    queue.size = 0;
    queue.length = length;
    return queue;
}

void enqueue(Queue * queue, int x){
    queue->list[queue->rear] = x;
    queue->rear = (queue->rear+1) % queue->length;
    queue->size++;
}


int dequeue(Queue * queue){
    int result = queue->list[queue->front];
    queue->front = (queue->front+1) % queue->length;
    queue->size--;
    return result;
}


void queue_print(Queue queue){
    printf("this queue cotains: \n");
    for(int i=queue.front;i<queue.front+queue.size;i++)
        printf("%d ",queue.list[i]);
    printf("\n");
}

void queue_test(void){
    Queue queue = createQueue(5);
    enqueue(&queue, 5);
    enqueue(&queue, 4);
    enqueue(&queue, 3);
    enqueue(&queue, 2);
    enqueue(&queue, 1);
    printf("%d",dequeue(&queue));
    printf("%d",dequeue(&queue));
    printf("%d",dequeue(&queue));
    
    printf("front: %d rear: %d\n",queue.front,queue.rear);
    queue_print(queue);
}

/*   -----------------------------   */
// treeNode型队列的操作实现

// 创建空队列
NodeQueue createNodeQueue(int length){
    NodeQueue queue;
    queue.list = (treeNode*)malloc(sizeof(treeNode)*length);
    queue.front = 0;
    queue.rear = 0;  // 初始条件下，队列为空，front=rear
    queue.size = 0;
    queue.length = length;
    return queue;
}

// 入队操作
void enNodeQueue(NodeQueue * queue, treeNode Node){
    queue->list[queue->rear] = Node;
    queue->rear = (queue->rear+1) % queue->length;
    queue->size++;
}

// 出队操作
treeNode deNodeQueue(NodeQueue * queue){
    treeNode result = queue->list[queue->front];
    queue->front = (queue->front+1) % queue->length;
    queue->size--;
    return result;
}

/*   -----------------------------   */

// VertexNode型队列的操作实现

// 创建空队列
VertexQueue createVertexQueue(int length){
    VertexQueue queue;
    queue.list = (Vertex*)malloc(sizeof(Vertex)*length);
    queue.front = 0;
    queue.rear = 0;  // 初始条件下，队列为空，front=rear
    queue.size = 0;
    queue.length = length;
    return queue;
}

// 入队操作
void enVertexQueue(VertexQueue * queue, Vertex Node){
    queue->list[queue->rear] = Node;
    queue->rear = (queue->rear+1) % queue->length;
    queue->size++;
}

// 出队操作
Vertex deVertexQueue(VertexQueue * queue){
    Vertex result = queue->list[queue->front];
    queue->front = (queue->front+1) % queue->length;
    queue->size--;
    return result;
}

/*   -----------------------------   */

