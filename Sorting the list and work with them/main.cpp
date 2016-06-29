/*============================================================================
    Name         : Sorting linked list with different types of data.
    Author       : MrLinder.
    Version      : v1.0
    Date         : 16.04.2015/1:41 - 
    License      : Hello shitty World!
    Description  : 	Двусвязный списк 
											Классы
											Наследование классов
											Алгоритмы для работы со списком
											Алгоритмы Сортировки двусвязного списка
											Перегрузка операторов ввода-вывода
											Форматированный ввод-вывод данных
										
										Пространтва имен
										Шаблоные (обобщенные)классы/функции
										Модели компиляции
										Конструкторы копий
										
																				

Создаем Указатель классового типа			
Внутри класса создается список размерностью указанной пользователем
Каждый элемент списка списка должен быть масивом
Поддерживаемые типы данных int, double, char.

Инициализация Автоматическиая, Пользовательская, из массива, из файла

- - - - - - - - - - - - Функции для работы со списком- - - - - - - - - - - - 

//Сохдание списка
List<int> *Object = new List<int>();

//загрузка значений
Object->PushBegin(1);
Object->PushBack(2);

//Удаление элемента 
Object -> DeleteNth(Порядковый_номер_элемента);

//Вставка элемента в порядке возрастания
Object -> InsertSort(6);
Object -> InsertSort();

//Вставка элементов массива по возрастанию (2 способа)
Object -> PushSort(Arr, 6);
InsertSort(&Object, Arr);

//Вставка Значения в указанное место
Object -> InsertIn(Значение, место вставки);

//Вставка Массива в указанное место(2 способа)
Object -> InsertIn(Array, размер, место_вставки);
InsertIn(&Object, Arr2, Место_вставки);

//загрузка массивами 2 способа (int Arr[9] = {1,2,3,4,5,6,7,8,9};)
Object -> PushBack(Arr, 9);
Object -> PushBegin(Arr, 9);
PushBack(&Object, Arr);
PushBegin(&Object, Arr);

//Выталкивание из стека
cout << Object->PopBack() << endl; 
cout << Object->PopBegin() << endl;

//Показать все (2 способа)
Object -> ShowAll();	
cout << *Object << endl;

//Возвращает порядковый номер заданного элемента;
cout << Object -> Search(5) << endl;

//Возвращает значение элемента по указанному порядковому номеру;
cout<<  Object -> GetNth(1) <<endl;

//Полное освобождение памяти
Object -> Free();

delete Object;

//проверка списка элементов по возрастанию
Object -> CheckList();

//Системная информация
Object -> sysinfo();

- - - - - - - - - - - - - - - - ALGORITHMS SORTING - - - - - - - - - - - - - - - - 

Object -> SelectSort();


============================================================================*/
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include "header/SortList.h"
using namespace std;

//Перемешивание массива(не для списка)
template<typename T, int size>
T* MixedArray(T (&arr)[size]) //не список // перемешивание массива
{
	srand(time(NULL));  // что бы был рандом иначе будут одни и теже числа.
		
	for(int i = 0; i < size; i++)
     {
		int rnd = rand() % size;
		T tmp = arr[i];
		arr[i] = arr[rnd];
		arr[rnd] = tmp;
	 }   
	return arr;
}

template<typename T, int size> //Показать массива(не для списка)
void ShowArray(T (&arr)[size])
{
	for ( int i = 0; i < size; ++i) 
		cout <<"["<< arr[i] <<"]";
}

int const N = 100;
int Arr[N];

void Array(){
	for ( int i = 0; i < N; ++i) 
		Arr[i] = i;
}

int main() 
{
	Array();		//Заполним массив
		
	cout << "Ogiginal Array" <<endl;
	ShowArray(Arr);
		
	cout << "\nMixed Array"<<endl;
	MixedArray(Arr);
	ShowArray(Arr);

		List<int>* Select_Sort = new List<int>();  
			PushBack(&Select_Sort, Arr);		// Загружаем в список Массивж
			Select_Sort -> SelectSort();

		List<int>* Bubble_Sort = new List<int>();  
			PushBack(&Bubble_Sort, Arr);		// Загружаем в список Массивж
			Bubble_Sort -> BubbleSort();
	
		List<int>* Sub_Bubble_Sort = new List<int>();  
			PushBack(&Sub_Bubble_Sort, Arr);		// Загружаем в список Массивж
			Sub_Bubble_Sort -> SubBubbleSort();
	
		List<int>* Shaker_Sort = new List<int>();  
			PushBack(&Shaker_Sort, Arr);		// Загружаем в список Массивж
			Shaker_Sort -> ShakerSort();
	
		List<int>* Insert_Sort = new List<int>();  
			PushBack(&Insert_Sort, Arr);		// Загружаем в список Массивж
			Insert_Sort -> InsertSort();
	
		List<int>* Shell_Sort = new List<int>();  
			PushBack(&Shell_Sort, Arr);		// Загружаем в список Массивж
			Shell_Sort -> ShellSort();	
		
		List<int>* Heap_Sort = new List<int>();  
			PushBack(&Heap_Sort, Arr);		// Загружаем в список Массивж
			Heap_Sort -> HeapSort();	

	cout << "\nInsert Sort\n" << 	 *Select_Sort;
	cout << "\nBubble_Sort\n" <<      *Bubble_Sort;
	cout << "\nSub BubbleS Sort\n"<<  *Sub_Bubble_Sort;
	cout << "\nShaker_Sort\n"	<< 		 *Shaker_Sort;
	cout << "\nSelect Sort\n" <<		 *Insert_Sort;	
	cout << "\nShell Sort\n" <<		 *Shell_Sort;	
	cout << "\nHeap Sort\n" <<		 *Heap_Sort;

	Select_Sort -> sysinfo();
	Bubble_Sort -> sysinfo();
	Sub_Bubble_Sort -> sysinfo();	
	Shaker_Sort -> sysinfo();
	Insert_Sort -> sysinfo();
	Shell_Sort -> sysinfo();
	Heap_Sort -> sysinfo();

	Select_Sort -> Free();
	Bubble_Sort -> Free();
	Sub_Bubble_Sort -> Free();
	Shaker_Sort -> Free();
	Insert_Sort -> Free();
	Shell_Sort -> Free();
	Heap_Sort -> Free();
	
	
	
	
	system("PAUSE");
	return 0;
}


 //system("PAUSE");

/*
Select_Sort -> ShowAll(FromEnd);

	cout<<"\n*Object: "<<sizeof(*Select_Sort) <<endl;
*/





















/*
int main ()
{
	List<int> *Object = new List<int>();
	
	int Arr[6] = {1,3,5,7,9,11};
	//int Arr2[6] = {100,300,500,700,900,110};
	
	Object -> PushBack(Arr, 6);
	Object -> PushBegin(Arr, 6);
	                      
	
	Object -> PushBack(1);
	Object -> PushBack(2);
	//Object -> PushBack(3);
	//Object -> PushBack(4);
	//Object -> PushBack(5);
	//Object -> PushBack(6);
	//Object -> PushBack(7);
	//Object -> PushBack(8);
	
	//for ( int i = 0; i > -5; --i) 
	//	Object->PushBegin(i);
	
	//for ( int i = 8; i < 15; ++i) 
	//	Object->PushBack(i);
	
	for ( int i = 0; i < 100; ++i) 
		Object->PushBegin(i);
	
	for ( int i = 0; i < 100; ++i) 
		Object->PushBack(i);
	
	
	for ( int i = 0; i < 50; ++i) 
		cout << Object->PopBegin() <<endl;
	
	for ( int i = 0; i < 50; ++i) 
		cout << Object->PopBack() <<endl;
			
	for ( int i = 0; i < 50; ++i) 
		cout << Object->PopBegin() <<endl;
		
	for ( int i = 0; i < 50; ++i) 
		cout << Object->PopBack() <<endl;	
	
		
	//Object -> InsertSort(18);
	//Object -> InsertSort(6);
	//Object -> InsertSort();
	
	//Object -> InsertSort(Arr, 6);
	//InsertSort(&Object, Arr);
	
	
	
	
	//PushBack(&Object, Arr);
	//PushBegin(&Object, Arr);

	
	//Object -> ShowAll();
	
							
	cout << Object->PopBegin() << endl;
		
		cout << Object->PopBegin() << endl;
		cout << Object->PopBegin() << endl;
cout << Object->PopBegin() << endl;
			cout << Object->PopBegin() << endl;
	cout << Object->PopBegin() << endl;
	cout << Object->PopBegin() << endl;
		cout << Object->PopBegin() << endl;
cout << Object->PopBegin() << endl;	
	
	

															
	cout << Object->PopBack() << endl;
	cout << Object->PopBack() << endl;
	cout << Object->PopBack() << endl;
	cout << Object->PopBack() << endl;
	cout << Object->PopBack() << endl;
	cout << Object->PopBack() << endl;
		cout << Object->PopBack() << endl;
cout << Object->PopBack() << endl;
	cout << Object->PopBack() << endl;
	cout << Object->PopBack() << endl;
	cout << Object->PopBack() << endl;
		cout << Object->PopBack() << endl;
cout << Object->PopBack() << endl;
	cout << Object->PopBack() << endl;
	cout << Object->PopBack() << endl;
	cout << Object->PopBack() << endl;
		cout << Object->PopBack() << endl;
cout << Object->PopBack() << endl;
	cout << Object->PopBack() << endl;
	
	cout << Object->PopBegin() << endl;
	cout << Object->PopBegin() << endl;
	
	//Object -> ShowAll();
	
	//cout << *Object << endl;
	Object -> ShowAll(FromBegin);
	Object -> ShowAll(FromEnd);

	
	
	
	
	//double Arr2[3] = {1.1,2.2,3.2};
	
	
	//cout << Object << endl;
	
	//Object -> InsertSort();
	
	//cout<< "Search "<< Object -> Search(10) << endl;
	//cout<< "Get "<< Object -> GetNth(Object -> Search(10)) << endl;
	
	//Object -> InsertIn(100, Object -> Search(2));
	
	//Object -> InsertIn(200, 55);
		
	//Object -> InsertIn(Arr2, 6, 5);
	
	//InsertIn(&Object, Arr2, 123);
	
	//cout <<"del  "  << Object -> DeleteNth(39) <<endl;

	
	//cout<< "Get :: "<< Object -> GetNth(38) << endl;
	
	//Object -> DeleteVal(500);
	//Object -> DeleteVal(900);
	Object -> DeleteVal(1);
	Object -> DeleteVal(2);
	
	
	
	Object -> ShowAll(FromBegin);
	Object -> ShowAll(FromEnd);
	
	
	Object -> sysinfo();
	
	Object -> Free();
	
	cout << *Object << endl;
	
	delete Object;
	
	
	
	system("PAUSE");
   return 0;
}


	//  ТЕСТ
	
	//---------------------------
	List<int> obi;
	obi.Add(10);
	obi.showAll();
	//--------------------------	
	
	
	List<double> *Object = new List<double>();
	
	Object->PushBegin('c');
	Object->PushBegin('b');
	Object->PushBegin('a');
	
	Object->PushBack('d');	
	Object->PushBack('e');
	Object->PushBack('f');
	
		cout << Object->PopBack() << endl;
		cout << Object->PopBack() << endl;
		cout << Object->PopBack() << endl;
		cout << Object->PopBack() << endl; 
	
		cout << Object->PopBegin() << endl;
		cout << Object->PopBegin() << endl;
		cout << Object->PopBegin() << endl;
		cout << Object->PopBegin() << endl; 
	
	
	for ( int i = 0; i < 100; ++i) 
		Object->PushBegin(i);
		
	for ( int i = 0; i < 100; ++i) 
		Object->PushBack(i*2);
		
	for ( int i = 0; i < 1000; ++i) 
		Object->PushBack(i*2);
		
	for ( int i = 0; i < 1000; ++i) 
		Object->PushBegin(i);
		
	for ( int i = 0; i < 100; ++i) 
		Object->PushBegin(i);
		
	for ( int i = 0; i < 1000; ++i) 
		Object->PushBack(i*2);
		
	for ( int i = 0; i < 100; ++i) 
		Object->PushBack(i*2);
		
	for ( int i = 0; i < 1000; ++i) 
		Object->PushBegin(i);
		
	for ( int i = 0; i < 2100; ++i) 
		Object->PopBegin();
		
	for ( int i = 0; i < 2200; ++i) 
		Object->PopBack();
		
	for ( int i = 0; i < 50; ++i) 
		cout << Object->PopBegin() <<endl;;
		
	for ( int i = 0; i < 50; ++i) 
		cout << Object->PopBack() <<endl;;
		
	*/







