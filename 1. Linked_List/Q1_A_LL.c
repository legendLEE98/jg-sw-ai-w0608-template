//////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 Data Structures
Lab Test: Section A - Linked List Questions
Purpose: Implementing the required functions for Question 1 */

//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////

// 리스트노드 타입 - ListNode 타입
typedef struct _listnode{
	// ListNode.item = int형
	int item;
	
	// 본인 지정 / ListNode와 연결된 다음 값의 주소
	// 포인터로 지정된 애라, 에스터리스크를 써야 볼 수 있음
	struct _listnode *next;
} ListNode;			// You should not change the definition of ListNode

// 링크드리스트 타입 - LinkedList 타입
typedef struct _linkedlist{
	// 변수의 사이즈를 담는 영역
	int size;

	// ListNode의 가장 첫 위치의 주소
	ListNode *head;
} LinkedList;			// You should not change the definition of LinkedList


///////////////////////// function prototypes ////////////////////////////////////

//You should not change the prototype of this function
int insertSortedLL(LinkedList *ll, int item);

void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode *findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);


//////////////////////////// main() //////////////////////////////////////////////

int main()
{
	// LinkedList 타입 ll
	LinkedList ll;
	// c , i , j 를 int형으로 선언
	int c, i, j;
	// c는 1의 값 추가
	c = 1;

	//Initialize the linked list 1 as an empty linked list
	// c언어는 null타입이 가능한듯? 일단 헤드에 NULL값 선언
	ll.head = NULL;
	// 링크드리스트 타입 ll에, 값을 0으로 넣음.
	ll.size = 0;

	// 선택지
	printf("1: 정렬된 연결 리스트에 정수를 삽입:\n");
	printf("2: 가장 최근에 입력된 값의 인덱스를 출력:\n");
	printf("3: 정렬된 연결 리스트를 출력:\n");
	printf("0: 종료:");

	while (c != 0)
	{
		printf("\n선택지를 골라주세요. (1/2/3/0): ");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			printf("연결 리스트에 추가할 정수를 입력: ");
			scanf("%d", &i);
			// 여기에서 i값 받고, 현재 링크드리스트랑, 입력값 넘겨줌.
			j = insertSortedLL(&ll, i);
			printf("결과로 생성된 연결 리스트는 다음과 같습니다: \n");
			printList(&ll);
			break;
		case 2:
			printf("값 %d가 인덱스 %d에 추가되었습니다. \n", i, j);
			break;
		case 3:
			printf("정렬된 연결 리스트의 결과는 다음과 같습니다: ");
			printList(&ll);
			removeAllItems(&ll);
			break;
		case 0:
			removeAllItems(&ll);
			break;
		default:
			printf("선택지가 이상해요.\n");
			break;
		}


	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////

// 입력한 링크드 리스트 정렬
int insertSortedLL(LinkedList *ll, int item)
{
	// 이거 걍 순회정렬하면 최대 O(n)이라서 그냥 순회정렬 하면 됨.
	// *ll은 링크드리스트의 0번째 인덱스
	ListNode *ln = malloc(sizeof(ListNode));
	ln->item = item;

	// ll의 헤드값 찾기
	ListNode *headNode = ll->head;
	// 링크드리스트 배열이 한 개 이상 존재할 경우
	if (ll->size != 0) {
		// 우선 현재 값과 ll.head랑 비교
		// 아래는 입력값보다 헤드가 더 클 때
		if (headNode->item > ln->item) {
			// 현재값의 next를 현재 헤드 노드로 잡고,
			ln->next = ll->head;
			// 해당 링크드리스트의 헤드를 현재값의 주소값 할당
			ll->head = ln;
			// 마지막으로 size 키우기
			ll->size += 1;

			return 0;
		} else if (headNode->item == ln->item) {
			free(ln);
			return -1;
		} else { // 그 외의 경우
			// 반복 시행. 현재값의 next랑 입력받은 값을 비교
			for (int i = 1; i <= ll->size; i++) {
				// next값이 없을 경우
				if (headNode->next == NULL) {
					headNode->next = ln;
					ll->size += 1;

					return ll->size;
				} else if (headNode->next->item < ln->item) { // 현재 값이 head값의 next보다 큰 경우
					// 헤드노드의 다음 값을 현재 헤드노드로 임시적으로 넣음
					headNode = headNode->next;
				} else if (headNode->next->item > ln->item) { // 현재 값이 head값 보단 크지만, next값 보다 작은 경우
					// ln의 넥스트 값을 head의 next로 넣고,
					ln->next = headNode->next;
					// headNode의 넥스트값을 ln으로 넣는다.
					headNode->next = ln;

					return i;
				} else if (headNode->next->item == ln->item) {
					// 다음 값이 현재값과 동일할 경우.
					free(ln);
					return -1;
				}
			}
		}
	} else { // ll 사이즈가 0 일 때
		ll->head = ln;
		ll->size += 1;
		return 0;
	}
}

///////////////////////////////////////////////////////////////////////////////////

void printList(LinkedList *ll){

	ListNode *cur;
	if (ll == NULL)
		return;
	cur = ll->head;

	if (cur == NULL)
		printf("비었어용");
	while (cur != NULL)
	{
		printf("%d ", cur->item);
		cur = cur->next;
	}
	printf("\n");
}


void removeAllItems(LinkedList *ll)
{
	ListNode *cur = ll->head;
	ListNode *tmp;

	while (cur != NULL){
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	ll->head = NULL;
	ll->size = 0;
}


ListNode *findNode(LinkedList *ll, int index){

	ListNode *temp;

	if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;

	temp = ll->head;

	if (temp == NULL || index < 0)
		return NULL;

	while (index > 0){
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
}

int insertNode(LinkedList *ll, int index, int value){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	// If empty list or inserting first node, need to update head pointer
	if (ll->head == NULL || index == 0){
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}


	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	return -1;
}


int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){

		if (pre->next == NULL)
			return -1;

		cur = pre->next;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 0;
	}

	return -1;
}
