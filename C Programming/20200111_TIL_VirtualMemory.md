## 가상 메모리와 메모리의 동적 할당
1. 가상 메모리란 무엇인가?  
2. malloc, calloc, free, memset, memcpy

### 가상 메모리란 무엇인가?

![Virtual Memory](/Images/VirtualMemory.png)

   
### malloc, free, calloc
개발자가 Heap 영역에 동적으로 메모리를 할당할 수 있다.  
지역변수의 경우 함수를 빠져나가면 메모리가 해제되고,  
전역변수의 경우 프로그램 종료 시까지 메모리가 유지되지만 동일한 주소 공간에 값이 덮어써지게 된다.  
이런 지역, 전역이 해결하지 못하는 **지역변수가 같이 매번 할당이 되지만, 소멸되지 않고 덮어쓰고 싶지않을때** 사용할 수 있는 것이 동적 할당이다.

간단한 코드로 보자면, UseName() 함수에서 name이라는 변수를 Heap 영역에 동적으로 할당해준다.
함수 내에서는 메모리를 해제시키지 않는다. 개발자가 원할때 해제가 가능하다는 소리다.
main() 함수가 끝나기전 free(name1), free(name2) 를 이용해 name으로 생성된 메모리 공간 영역을 해제해준다.  

- **malloc / calloc** 의 차이
1. void * malloc(size_t size) 매개변수로 할당할 크기만 알려준다.
2. void * calloc(size_t elt_count, size_t elt_size) 매개변수로 자료형의 개수, 자료형의 사이즈를 따로 알려준다.
매개변수가 1개이냐 2개이냐 외에도 malloc 과 calloc은 초기화 값에 차이가 있다.
malloc 은 초기화를 따로 안해주므로 메모리 값에 cd 값이 들어가게 된다. 만약 0으로 초기화하고자 한다면 memset을 시켜줘야 한다.
calloc 메모리 할당과 동시에 0으로 초기화를 시켜준다.
- **메모리의 복사 memcpy / 메모리 비교 memcmpc**
1. memcpy(대상주소, 복사할주소, 복사할크기)
2. memcmp(대상주소, 복사할주소, 비교할크기)


```(.C)
char* UseName()
{
	char* name = (char*)malloc(sizeof(char) * 30);
  // 메모리 할당 시에 malloc 함수 내에 할당할 크기를 알려준다.
  // 하지만 +sizeof(int) 나 sizeof(char) * 4+ 나 크기가 동일하므로 메모리 할당 시에 char 혈을 원하는지 int 형을 원하는지 알 수가 없다. 
  // 따라서 malloc 함수를 할당하기에 앞서 어떤 자료형으로 할당할 것인지 알려줘야 한다.
 

	printf("이름 입력 : ");
	gets(name);

	return name;
}
void main()
{
	char* name1;
	char* name2;

	name1 = UseName();
	printf("%s\n", name1);

	name2 = UseName();
	printf("%s\n", name2);

	printf("%s %s", name1, name2);

	free(name1);
	free(name2);
}
```
