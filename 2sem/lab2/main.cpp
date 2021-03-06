#include <iostream>
#include <string>
using namespace std;
 
struct Node{                //структура звена списка 
    int value;          //передаваемое значение
    Node *next, *prev;      //указатели на следующий и предыдущий элементы
};
 
struct deque{
    Node *head=nullptr;     //инициализация начала и конца списка, размера дека 
    Node *tail=nullptr;
    int count=0;
    void push_back(int num){
        Node* element=new Node; //выделение памяти под новый элемент структуры
        element->value=num;  //добавляем значение в структуру
        count++;
        if(!head){          //если список пуск
            head=element;       //т.к элемент единственный, 
            tail=head;      //он является и хвостом и головой
        }
        else{
            element->prev=tail; //предыдущий элемент списка относительно добавленного, будет последним(хвостом)
            tail->next=element; //следующий элемент за хвостом это добавляемый элемент списка
            tail=element;       //присваивание элементу статуса хвоста
        }
        
    }
    void push_front(int num){
        Node *element=new Node;
        element->value=num;
        count++;
        if(!head){
            head=element;
            tail=head;
        }
        else{
            element->next=head;      //следующий элемент за добавляемым элементом является хвост
            head->prev=element;      //перед головой находится добавляемый элемент
            head=element;           //присваивание элементу статуса головы
        }
        
    }
    void pop_back(){
        if(count!=0){               //если дек не пустой
            cout<<tail->value<<" ";
            if(count>1){         //если в деке находится больше одного элемента
                Node *element=tail;     //указываем на то, что будет использоваться хвост
                tail=tail->prev; //присваиваем статус хвоста предыдущему элементу
                tail->next=nullptr;     //указываем на то, что за элементом пусто
                delete element;     //удаляем бывший хвост
                count--;        //уменьшаем размер дека
            }
            else{               //если в деке находится всего один элемент
                head=tail=0;        //присваиваем ему значение ноль
                count--;        //уменьшаем размер дека
            }
        }
        else cout<<"error"<<endl;
    }
    void pop_front(){
        if(count!=0){
            cout<<head->value<<" ";
            if(head->next){          //если в деке больше одного элемента 
                Node *element=head; //указываем на то, что будем использовать голову
                head=head->next; //присваиваем статус головы следующему за бывшей головой элементу 
                head->prev=nullptr;  //указываем на то, что перед головой пусто
                delete element;     //удаляем бывшую голову
                count--;        //уменьшаем размер дека
            }
            else if(head==tail){    //если элемент один в деке
                head->next=nullptr;  //указываем, что за головой пусто
                head=nullptr;       //указываем на то, что голова тоже пуста
                delete head;        //удаляем единственный элемент
                count=0;        //присваиваем ноль размеру дека
            }
        }
        else cout<<"error"<<endl;
    }
    void back(){
        if(count!=0)cout<<tail->value<<endl; //выводим значение хвоста
        else cout<<"error"<<endl;
    }
    void front(){
        if(count!=0)cout<<head->value<<endl; //выводим значение головы
        else cout<<"error"<<endl;
    }
    void size(){
        cout<<count<<endl;          //выводим размер дека
    }
    void clear(){
        count=0;               //присваиваем размеру дека ноль
        cout<<"ok"<<endl;
        while(head)             //цикл: пока по адресу головы что-то лежит
     {
         tail=head->next;        //присваиваем статус хвоста следующему элементу, что лежит за головой 
         delete head;           //удаляем первый элемент дека
         head=tail;             //указываем на то, что хвост принимает статус головы
     }
    }
    void exit(){
        cout<<"bye";
    }
};
bool check_polindrom(string word)
{
	int len = word.length();
	for(int i = 0; i < len/2; ++i)
	{
		if(word[i] != word[len-i-1])
		{
			return false;
		}
	}
	return true;
}
int main() {
    deque deq;
    string str;
    string st;
    string k = "123";
    cout<<"Контрольний приклад\nМаємо число 123\nСпочтку перевірка на поліндром"<<endl;
    int len = k.length();
    if(check_polindrom(k))
            {
                cout << "Поліндром!\n";
                int i =0;
                while (k[i]!='\0')
                {
                    deq.push_front(k[i]-48);
                    i++;
                }
                for (size_t i = 0; i < len; i++)
                {
                    deq.pop_front();
                }
            }
            else
            {
                cout << "Не поліндром!\nОтримуємо деку\n";
                int i = 0;
                while (k[i]!='\0')
                {
                    deq.push_front(k[i]-48);
                    i++;
                }
                i = len;
                while (i!=0)
                {
                    i--;
                    deq.push_back(k[i]-48);
                }
                for (size_t i = 0; i < len; i++)
                {
                    deq.pop_front();
                }
                for (size_t i = 0; i < len; i++)
                {
                    deq.pop_back();
                }
            }
            puts("");
            puts("-----------");
    while(1){
        cout<< "1:Додати число до деки\n2:Вихід" <<endl;
        cin>>str;
        if(str=="1")
        {
            cout<<"Введіть число"<< endl;
            cin >> st;
             len = st.length();
            if(check_polindrom(st))
            {
                cout << "Поліндром!\n";
                int i =0;
                while (st[i]!='\0')
                {
                    deq.push_front(st[i]-48);
                    i++;
                }
                for (size_t i = 0; i < len; i++)
                {
                    deq.pop_front();
                }
            }
            else
            {
                cout << "Не поліндром!\n";
                int i = 0;
                while (st[i]!='\0')
                {
                    deq.push_front(st[i]-48);
                    i++;
                }
                i = len;
                while (i!=0)
                {
                    i--;
                    deq.push_back(st[i]-48);
                }
                for (size_t i = 0; i < len; i++)
                {
                    deq.pop_front();
                }
                for (size_t i = 0; i < len; i++)
                {
                    deq.pop_back();
                }
            }
            puts("");
        }
        if(str=="2"){
            deq.exit();
            break;
        }
    }
    return 0;
}