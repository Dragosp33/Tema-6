#include<iostream>
using namespace std;
class Node {
public:
int key; // cheia/pozitia nodului
int data; // valoarea inregistrata in nod
Node * next; // pointer spre urmatorul nod in lista
Node()
{
key = 0;
data = 0;
next = NULL;
}
Node(int key1, int data1)
{
key = key1;
data = data1;
}
};
class CircularLinkedList {
public:
Node * h; // varf
CircularLinkedList()
{
h = NULL;
}
Node * NodeExists(int k) // verificare existenta nod
{
Node * tmp = NULL;
Node * pointer = h;
if (pointer == NULL)
{
return tmp;
}
else {
      do
        {
          if (pointer -> key == k)
          {
          tmp = pointer;
          }
          pointer = pointer -> next;
        } while (pointer != h);
      return tmp;
     }
}
void AppendNode(Node * newnode) // adaugare nod in lista
{
    if (NodeExists(newnode -> key) != NULL)
    {
      cout<<"Nodul " <<newnode -> key;
      cout<<" nu poate fi lipit intrucat deja exista."<<endl;
    }
    else
    {
      if (h == NULL)
      {
        h = newnode;
        newnode -> next = h;
        cout << "Nod lipit, devenit varf" << endl;
      }
      else
      {
        Node * pointer = h;
        while (pointer -> next != h)
        {
          pointer = pointer -> next;
        }
        pointer -> next = newnode;
        newnode -> next = h;
        cout << "Nod lipit" << endl;
      }
    }
}
void PrependNode(Node * newnode) //alipire la inceputul listei (schimbare varf)
{
    if (NodeExists(newnode -> key) != NULL)
    {
      cout<<"Nodul " <<newnode -> key;
      cout<<" nu poate fi adaugat intrucat deja exista."<<endl;
    }
    else
    {
      if (h == NULL)
       {
        h = newnode;
        newnode -> next = h;
        cout << "Nod varf" << endl;
       }
      else
       {
        Node * pointer = h;
        while (pointer -> next != h)
        {
          pointer = pointer -> next;
        }
        pointer -> next = newnode;
        newnode -> next = h;
        h = newnode;
        cout << "Nod alipit." << endl;
       }
    }
}
void InsertNode(int k, Node * newnode)  //inserare nod
{
    Node * pointer = NodeExists(k);
    if (pointer == NULL)
    {
      cout << "Nod cu cheia:" << k <<" Nu exista"<< endl;
    }
    else
    {
     if (NodeExists(newnode -> key) != NULL)
     {
        cout<<"Intrucat nodul cu valoarea: " <<newnode -> key;
        cout<<"exista, acesta nu mai poate fi inserat"<<endl;
     }
     else
     {
        if (pointer -> next == h)
        {
          newnode -> next = h;
          pointer -> next = newnode;
          cout << "Nod inserat la sfarsitul listei." << endl;
        }
        else
        {
          newnode -> next = pointer -> next;
          pointer -> next = newnode;
          cout << "Nod inserat in lista." << endl;
        }
      }
    }
}
void DeleteNode(int k) // stergere nod
{
    Node * pointer = NodeExists(k);
    if (pointer == NULL)

    {
      cout << "Nu exista nod pe pozitia : " << k <<endl;

    }
    else
    {
     if (pointer == h)
     {
        if (h -> next == h)
        {
          h = NULL;
          cout << "Varful a fost sters iar lista este acum goala."<<endl;
        }
        else
        {
          Node * pointer1 = h;
          while (pointer1 -> next != h)
          {
            pointer1 = pointer1 -> next;
          }
          pointer1 -> next = h -> next;
          h = h -> next;
          cout << "Nod sters de pe pozitia : " << k << endl;
        }
     }
     else
     {
        Node * tmp = NULL;
        Node * prevpointer = h;
        Node * currentpointer = h -> next;
        while (currentpointer != NULL)
        {
          if (currentpointer -> key == k)
          {
            tmp = currentpointer;
            currentpointer = NULL;
          }
          else
          {for (int i=0; i<k; i++){
            prevpointer = prevpointer -> next;
            currentpointer = currentpointer -> next;}
          }
        }
        prevpointer -> next = tmp -> next;
        cout << "Nod sters de pe pozitia : " << k << endl;
     }
   }
}
void DeleteK(int k){     //Stergere nod din k in k pozitii
int count=0;
if(h==NULL)
{
cout << "Numarul de noduri= "<<count<<endl;
}
else
{
Node * tmp =h;
do
{
count++;
tmp = tmp -> next;
} while (tmp != h);}
for (int i=k; i<=count; i+=k){
    DeleteNode(i);
}
}

void UpdateNode(int k, int newdata)  //actualizare nod
{
 Node * pointer = NodeExists(k);
 if (pointer != NULL)
  {
      pointer -> data = newdata;
      cout << "Node actualizat." << endl;
  }
 else
  {
   cout << "Nu exista nodul pe pozitia  " << k << endl;
  }
}
void DisplayList()
{
    if (h == NULL)
    {
      cout << "Lista circulara goala."<<endl;
    }
    else
    {
      cout <<"Varf: [" << h -> key << "," << h -> data << "," << h -> next << "]" << endl;
      cout << "Valorile din lista circulara: " << endl;
      Node * tmp = h;
      do
      {
        cout << "[" << tmp -> key << "," << tmp -> data << "," << tmp -> next << "] ----> ";
        tmp = tmp -> next;
      } while (tmp != h);
    }
}
void CountList()
{
int count=0;
if(h==NULL)
{
cout << "Node Count= "<<count<<endl;
}
else
{
Node * tmp =h;
do
{
count++;
tmp = tmp -> next;
} while (tmp != h);
cout<<"Node Count= "<<count<<endl;
}
}
};
int main() //functie principala
{
CircularLinkedList c;
int op;
int keyvalue, kvalue, datavalue;
do
{
    cout<< "\n Selecteaza optiunea dorita pe Lista Circulara."<< endl;
    cout<< "1. Lipeste " << endl;
    cout<< "2. Adauga (Creare/Schimbare varf) " << endl;
    cout<< "3. Inserare " << endl;
    cout<< "4. Sterge " << endl;
    cout<< "5. Sterge pozitiile k"<<endl;
    cout<< "6. Update " << endl;
    cout<< "7. Afiseaza " << endl;
    cout<< "8. Numarul de noduri " << endl;
    cout<< " Introdu 0 pentru iesire " << endl;
    cin >> op;
    Node * node1 = new Node();
    switch (op) {
    case 0:
      break;
    case 1:
      cout << "Introduceti pozitia (valoarea cheie)." << endl;
      cin >> keyvalue;
      cout << "Introduceti valoarea propriu-zisa" << endl;
      cin >> datavalue;
      node1 -> key = keyvalue;
      node1 -> data = datavalue;
      c.AppendNode(node1);
      break;
    case 2:
      cout << "Introduceti pozitia (valoarea cheie)." << endl;
      cin >> keyvalue;
      cout << "Introduceti valoarea propriu-zisa" << endl;
      cin >> datavalue;
      node1 -> key = keyvalue;
      node1 -> data = datavalue;
      c.PrependNode(node1);
      break;
    case 3:
      cout << "Introduceti pozitia (valoarea cheie) dupa care sa fie introdus nodul. " << endl;
      cin >> kvalue;
      cout << "Introduceti pozitia (valoarea cheie) a nodului care urmeaza sa fie introdus." << endl;
      cin >> keyvalue;
      cout << "Introduceti valoarea propriu-zisa a nodului" << endl;
      cin >> datavalue;
      node1 -> key = keyvalue;
      node1 -> data = datavalue;
      c.InsertNode(kvalue,node1);
      break;
    case 4:
      cout << "Introduceti pozitia (valoarea cheie) a nodului care trebuie sters " << endl;
      cin >> kvalue;
      c.DeleteNode(kvalue);
      break;
    case 5:
      cout << "Introduceti valoarea ( k ) pentru a sterge elementele din k in k pozitii"<<endl;
      cin >> kvalue;
      c.DeleteK(kvalue);
      break;
    case 6:
      cout << "Introduceti pozitia (valoarea cheie) care trebuie actualizata" << endl;
      cin >> keyvalue;
      cout << "Introduceti valoarea actualizata" << endl;
      cin >> datavalue;
      c.UpdateNode(keyvalue, datavalue);
      break;
    case 7:
      c.DisplayList();
      break;
    case 8:
      c.CountList();
      break;
    default:
      cout << "Optiune invalida!" << endl;
    }
  } while (op!=0);
 return 0;
}
