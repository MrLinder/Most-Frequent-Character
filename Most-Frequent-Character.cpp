#include <iostream>
#include <cstring>
using namespace std;

class base
{
protected:	
	struct Data{
		unsigned int *calc;
		char *Array;
	};
	struct List{		
		Data *key;	
		List* prev;
		List* next;
		List(){prev = next=NULL;}
	 };
};

class create:public base
{
	unsigned char*SourceArray;
	int NumSourceItems;
	List* Begin;			
	List* Temp;	
	List* End;				
	int one_run;	
public:
	create(char* Arr);    	
	~create();	
	void ShowLoadData();
	void SearchChar(Data* elemt);
	char GetMostFrequentCharacter();
};

create::create (char* Arr) 
{
	// TODO: crach if in array add \0 fix it 
	
	one_run = 0;
	NumSourceItems = strlen(Arr)+1;
		SourceArray = new unsigned char[NumSourceItems];
			for ( int i = 0; i < NumSourceItems; ++i) 
				SourceArray[i] = Arr[i];
			SourceArray[NumSourceItems] = '\0';
	
	Begin = Temp = End = new List();		
	
		Temp->key = new Data[1];
			Temp->key[0].Array = new char();
			Temp->key[0].calc = new unsigned int();
				Temp->key[0].Array[0] =  Arr[0];
				Temp->key[0].calc[0] = 1;
			Temp -> prev = NULL;
		Temp -> next = NULL;
	Begin = Temp;
	End = Temp;
		
	for ( int q = 1; q < NumSourceItems; ++q) 
	{
		Temp -> next = new List();
		
			List* elem = Temp;						
				Temp = Temp->next;						
					Temp->prev = elem;	 
				
						Temp->key = new Data[1];
							Temp->key[0].Array = new char();
							Temp->key[0].calc = new unsigned int();
								Temp->key[0].Array[0] = Arr[q];  
								Temp->key[0].calc[0] = 1;
						Temp->next = NULL;		
					End = Temp->prev;
	}
	Temp = Begin;
}

create::~create() 
{
	delete[]Begin;			
	delete[]Temp;	
	delete[]End;				
} 	

void create::ShowLoadData()
{
	List* pp = Begin;
	do
	{
		if(one_run>0)
			cout << pp -> key[0].Array[0] << "=" << pp -> key[0].calc[0];
		else
			cout << pp -> key[0].Array[0];
		
		pp = pp->next;
		if (pp->next !=NULL)
			cout << ", ";
	}while (pp->next !=NULL);	
	one_run++;
}

void create::SearchChar(Data* elemt)
{
	int calculate = 1;
	if(Temp == NULL) return;				
	List* SearCh = Temp;					

	if(SearCh -> next != NULL)
	{
		List* SearCh_nx = SearCh -> next;
		
		while (SearCh_nx != NULL)
		{ 
			while(SearCh_nx->key[0].Array[0] == elemt->Array[0])
			{
				calculate++;
				SearCh_nx = SearCh_nx->next;
					delete SearCh_nx->prev;
				SearCh_nx->prev = SearCh;
				SearCh->next = SearCh_nx;
			}
			
			if(SearCh_nx->next == NULL)	
				End = SearCh_nx->prev;
	
			SearCh_nx = SearCh_nx-> next;
			SearCh = SearCh->next;	
		}
	}
	elemt->calc[0] = calculate;
	Temp = Temp->next;
}

char create::GetMostFrequentCharacter()
{
	List* SearCh = Begin;
	
	unsigned int n = 0;
	char* returnCh = new char(sizeof(char));
		
	while((SearCh->next!=NULL))
	{
		SearchChar(SearCh->key);
		
		if(SearCh->key[0].calc[0] > n )
		{
			delete[]returnCh;
			n = SearCh->key[0].calc[0];
			returnCh = new char(sizeof(char));
			*returnCh = SearCh->key[0].Array[0];
		}
					
		if(SearCh->next == NULL)
			break;
		
		SearCh = SearCh->next;
	}
	return *returnCh;
	
	//TODO: mostFrequentCharacter(char* str, int size);
}

int main()
{
    char Array[140]={'e','e','e','e','e','q','q','q','q','q','x','x','x','x','x','w','w','w','w','w','f','f','f',
					  'a','s','d','f','g','h','j','h','q','k','x','l','x','c','x','c','z','x','b','n','m','u','a',
					  'm','n','b','v','c','x','z','a','s','l','k','j','h','g','f','d','s','a','p','o','i','u','y',
					  'c','z','x','b','h','q','k','x','a','s','d','f','g','h','q','q','q','q','x','m','n','b','v',
					  'q','a','z','x','s','w','e','d','c','c','v','f','r','t','g','b','n','h','y','u','j','m','j',
					  'e','e','e','e','m','n','b','v','c','x','m','n','b','v','c','x','f','d','s','a','x','x','x'};
	
		
	create *search = new create(Array);
	
	cout << "\nSource Array:" <<endl;
		search->ShowLoadData();
	cout << endl;
	
	cout << "\nMost Frequent Character: " << search->GetMostFrequentCharacter() << endl;
	
	cout << "\nAll result:" <<endl;
		search->ShowLoadData();
	cout << endl;
	
    return 0;
}
 
