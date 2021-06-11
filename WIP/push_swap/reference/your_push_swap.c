#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
// Node : 스택에 하나씩 쌓일 데이터를 정의
typedef struct s_node {
    char* data;
    struct s_node* prev;
    struct s_node* next;
} t_node;

// t_stack : 스택 형태의 리스트를 정의
typedef struct s_stack {
    t_node* top; // 리스트의 테일 노드 주소를 가리킬 포인터
    int size; // 리스트의 노드 갯수를 저장할 변수
} t_stack;
// init_stack : 스택 형태의 리스트를 초기화
t_stack* init_stack() {
    t_stack* stack;
    stack = (t_stack*)malloc(sizeof(t_stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

// init_node : 스택에 들어갈 노드를 초기화
t_node* init_node(char* str) {
    // 새로운 노드의 메모리를 힙 영역에 할당
    t_node* newNode = (t_node*)malloc(sizeof(t_node));
    // 노드의 요소(데이터)의 공간을 힙 영역에 할당
    newNode->data = (char*)malloc(strlen(str)+1);
    // 노드의 데이터에 문자열을 복사
    strcpy(newNode->data, str);
    // 노드의 포인터를 지정
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
// push : 리스트(스택)의 Top위에 새로운 노드를 추가
void push(t_stack* list, char* str) {
    // 새로운 노드를 생성
    t_node* newNode = init_node(str);
    // oldTop : 현재의 마지막(가장 위) 노드를 보관할 변수
    t_node* oldTop;

    // 리스트(스택)에 노드가 없는 경우
    if(list->top == NULL) {
        list->top = newNode;
    }
    // 리스트(스택)에 노드가 있는 경우
    else {
        oldTop = list->top;
        oldTop->next = newNode;
        newNode->prev = oldTop;
        list->top = newNode;
    }
    // 리스트의 노드 갯수를 추가
    list->size++;
}
// top : 리스트(스택)의 Top을 반환하는 함수
t_node* top(t_stack* list) {
    return list->top;
}
int main(void) {
    // stack이라는 리스트를 생성
    t_stack* stack;
    // 함수를 통해 리스트 형태의 스택을 생성
    stack = init_stack();
    
    // 1개의 노드를 푸쉬
    printf("Push a node\n");
    push(stack, "AAA");
    // stack 리스트 top의 데이터를 출력
    printf("top : %s\n\n",top(stack)->data);

    return 0;
}