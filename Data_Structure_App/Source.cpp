#include<iostream>
#include<string>
using namespace std;
class arrr
{
private:
	int *arr, size;
public:
	void crate_arr(int x)
	{
		arr = new int(x);
		for (int i = 0; i < x; i++)
		{
			cout << "enter number\n";
			cin >> arr[i];
		}
		size = x;
	}
	void insert(int position, int value)
	{
		if (position < size)
		{
			for (int i = size - 1; i >= position; i--)
			{
				arr[i + 1] = arr[i];
			}
			arr[position] = value;
			size++;
		}
		else
			cout << "out of space\n";
	}
	void erase(int position)
	{
		if (position < size)
		{
			for (int i = position; i < size - 1; i++)
				arr[i] = arr[i + 1];
			size--;
		}
		else
			cout << "out of space\n";
	}
	int searsh(int element)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == element)
			{
				return i;
			}
		}
		return -1;
	}
	void sort()
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (arr[j] < arr[i])
				{
					int t = arr[i];
					arr[i] = arr[j];
					arr[j] = t;
				}
			}
		}
	}
	void merge(arrr b)
	{
		int *c;
		c = new int(b.size + size);
		int i = 0;
		for (i = 0; i <size; i++)
			c[i] = arr[i];
		int j = 0;
		for (; i < size + b.size; i++, j++)
			c[i] = b.arr[j];

		for (i = 0; i < size + b.size; i++)
			cout << c[i] << " ";
		if (i != 0)
			cout << "\n";
	}
	void reverse()
	{
		int e = size - 1;
		for (int i = 0; i < size / 2; i++)
		{
			int t = arr[e];
			arr[e] = arr[i];
			arr[i] = t;
			e--;
		}
	}
	void display()
	{
		int i = 0;
		for (i = 0; i < size; i++)
			cout << arr[i] << " ";
		if (i != 0)
			cout << "\n";
	}
};
class Stack
{
private:
	int *arr;
	int size;
	int top;
public:
	Stack(int x)
	{


		size = x;
		top = -1;
		arr = new int[x];

	}
	bool is_empty()
	{
		if (top == -1)
			return true;
		return false;
	}
	bool is_full()
	{
		if (top == size - 1)
			return true;
		return false;
	}
	void bottom_insert(int x)
	{
		if (top < 0)
			push(x);
		else
		{
			int temp = arr[top];
			pop();
			bottom_insert(x);
			push(temp);
		}
	}
	void reverse_recursive()
	{
		if (top > 0)
		{
			int temp = arr[top];
			pop();
			reverse_recursive();
			bottom_insert(temp);
		}
	}
	void push(int x)
	{
		if (!is_full())
		{
			top++;
			arr[top] = x;
		}
		else
			cout << "IS Full\n";
	}
	int pop()
	{
		if (!is_empty())
		{
			int data = arr[top];
			arr[top] = NULL;
			top--;
			return data;
		}
		else
			cout << "Is Empty\n";
	}
	void display()
	{
		Stack s1(top + 1);
		int i;
		int ss = top;
		for (i = 0; i <= ss; i++)
		{
			int d = pop();
			cout << d << " ";
			s1.push(d);
		}
		if (i != 0)
			cout << "\n";
		for (int i = 0; i <= ss; i++)
			push(s1.pop());
	}
	void erase_items()
	{
		while (size)
		{
			pop();
			size--;
		}
	}
	int find(int x)
	{
		for (int i = 0; i < size; i++)
			if (arr[i] == x)
				return i;

		return -1;
	}
};
class infix
{
private:
	int top, size;
	char arr[100];
public:
	void infex_to_postifix()
	{
		char post[100], infex[100], ch;
		cout << "Enter infix string\n";
		cin >> infex;
		int len = strlen(infex);
		infex[len++] = ')';
		push('(');
		int j, i;
		for (i = 0, j = 0; i <len; i++)
		{
			switch (priorty(infex[i]))
			{
			case 1:
				push(infex[i]);
				break;
			case 2:
				ch = pop();
				while (ch != '(')
				{
					post[j++] = ch;
					ch = pop();
				}
				break;
			case 3:
				ch = pop();
				while (priorty(ch) >= 3)
				{
					post[j++] = ch;
					ch = pop();
				}
				push(ch);
				push(infex[i]);
				break;
			case 4:
				ch = pop();
				while (priorty(ch) >= 4)
				{
					post[j++] = ch;
					ch = pop();
				}
				push(ch);
				push(infex[i]);
				break;
			case 5:
				push(infex[i]);
				break;
			default:
				post[j++] = infex[i];
				break;
			}
		}
		for (int i = 0; i < j; i++)
			cout << post[i] << " ";
		cout << "\n";
	}
	infix()
	{
		top = -1;
		size = 100;
	}
	void push(char x)
	{
		if (top == size - 1)
			cout << "overflow\n";
		else
		{
			top++;
			arr[top] = x;
		}
	}
	char pop()
	{
		if (top != -1)
		{
			char d = arr[top];
			top--;
			return d;
		}
		else
			cout << "underflow\n";

	}
	void display()
	{
		for (int i = 0; i <= top; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}
	int priorty(char a)
	{
		switch (a)
		{
		case '(':
			return 1;
		case ')':
			return 2;
		case '+':
		case '-':
			return 3;
		case '*':
		case'/':
			return 4;
		case '^':
			return 5;
		default:
			return 0;
			break;
		}
	}
	void infex_to_prefix()
	{
		char post[100], infex[100], inf[100], ch;
		cout << "Enter infix string\n";
		cin >> inf;
		int len = strlen(inf);
		infex[0] = '(';
		for (int l = 1; l <= len + 1; l++)
		{
			char a = inf[l - 1];
			infex[l] = inf[l - 1];

		}
		push(')');
		int j, i;
		for (i = len, j = 0; i >= 0; i--)
		{
			switch (priorty(infex[i]))
			{
			case 2:
				push(infex[i]);
				break;
			case 1:
				ch = pop();
				while (ch != ')')
				{
					post[j++] = ch;
					ch = pop();
				}
				break;
			case 3:
				ch = pop();
				while (priorty(ch) >= 3)
				{
					post[j++] = ch;
					ch = pop();
				}
				push(ch);
				push(infex[i]);
				break;
			case 4:
				ch = pop();
				while (priorty(ch) >= 4)
				{
					post[j++] = ch;
					ch = pop();
				}
				push(ch);
				push(infex[i]);
				break;
			case 5:
				push(infex[i]);
				break;
			default:
				post[j++] = infex[i];
				break;
			}
		}
		for (int i = j - 1; i >= 0; i--)
			cout << post[i] << " ";
		cout << "\n";
	}

};
class postifix_to_inf_or_pre
{
private:
	int top, size;
	string arr[100];
public:
	postifix_to_inf_or_pre()
	{
		top = -1;
		size = 100;
	}
	void push(string x)
	{
		if (top == size - 1)
			cout << "overflow\n";
		else
		{
			top++;
			arr[top] = x;
		}
	}
	string pop()
	{
		if (top != -1)
		{
			string d = arr[top];
			top--;
			return d;
		}
		else
			cout << "underflow\n";

	}
	void display()
	{
		for (int i = 0; i <= top; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}
	void post_to_inf()
	{
		char post[100];
		cout << "Enter postifex string\n";
		cin >> post;
		string s;
		int le = strlen(post);
		for (int i = 0; i < le; i++)
		{
			if (post[i] == '+' || post[i] == '*' || post[i] == '/' || post[i] == '^' || post[i] == '-')
			{
				string a, b;
				b = pop();
				a = pop();
				string c = '(' + a + post[i] + b + ')';
				push(c);
			}
			else if (post[i] == ' ')
				continue;
			else
			{
				s += post[i];
				push(s);
				s = "";
			}
		}
		cout << pop() << "\n";
	}
	void prefix_to_inf()
	{
		char post[100];
		cout << "Enter prefix string\n";
		cin >> post;
		string s;
		int le = strlen(post);
		for (int i = le - 1; i >= 0; i--)
		{
			if (post[i] == '+' || post[i] == '*' || post[i] == '/' || post[i] == '^' || post[i] == '-')
			{
				string a, b;
				a = pop();
				b = pop();
				string c = '(' + a + post[i] + b + ')';
				push(c);
			}
			else if (post[i] == ' ')
				continue;
			else
			{
				s += post[i];
				push(s);
				s = "";
			}
		}
		string f = pop();
		cout << f << "\n";
	}
	void post_to_prefix()
	{
		char post[100];
		cout << "Enter postifex string\n";
		cin >> post;
		string s;
		int le = strlen(post);
		for (int i = 0; i < le; i++)
		{
			if (post[i] == '+' || post[i] == '*' || post[i] == '/' || post[i] == '^' || post[i] == '-')
			{
				string a, b;
				b = pop();
				a = pop();
				string c = post[i] + a + b;
				push(c);
			}
			else if (post[i] == ' ')
				continue;
			else
			{
				s += post[i];
				push(s);
				s = "";
			}
		}
		cout << pop() << "\n";
	}
};
template<class T>
class queue
{
private:
	int fro;
	int rear;
	int siz;
	T *arr;
public:
	queue()
	{
		siz = 1;
		arr = new T[1];
		fro = -1;
		rear = -1;
	}
	queue(int x)
	{
		siz = x;
		arr = new T[x];
		fro = -1;
		rear = -1;
	}
	void show()
	{
		for (int i = fro; i <= rear; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}
	void push(T x)
	{
		if (fro == -1 && rear == -1)
			fro = 0, rear = 0;
		if (rear >= siz - 1)
		{
			T *temp;
			temp = new T[siz];
			for (int i = 0; i <= rear; i++)
				temp[i] = arr[i];
			delete[]arr;
			arr = new T[siz * 2];
			siz *= 2;
			for (int i = 0; i <= rear; i++)
				arr[i] = temp[i];
			delete[]temp;
			rear++;
		}
		arr[rear] = x;
	}
	T pop()
	{
		T data = arr[0];
		for (int i = 0; i < rear; i++)
			arr[i] = arr[i + 1];
		rear--;
		return data;
	}
	int size()
	{
		return rear + 1;
	}
	int capacity()
	{
		return siz;
	}
	T front()
	{
		return arr[0];
	}
};
template<class T>
class D_queue
{
private:
	int size, rear, front;
	T *arr;
public:
	D_queue(int si)
	{
		size = si;
		arr = new T[si];
		front = -1;
		rear = -1;
	}
	bool is_full()
	{
		if ((front == 0 && rear == size - 1) || front == rear + 1)
			return true;
		return false;
	}
	bool is_empty()
	{
		if (front == -1 && rear == -1)
			return true;
		return false;
	}
	void push_back(T x)
	{
		if (is_full())
		{
			cout << "Full\n";
		}
		else
		{
			if (front == -1 && rear == -1)
				front = 0, rear = 0;
			else
				rear = (rear + 1) % size;
			arr[rear] = x;
		}
	}
	void push_front(T x)
	{
		if (is_full())
		{
			cout << "Full\n";
		}
		else
		{
			if (front == -1 && rear == -1)
				front = 0, rear = 0;
			else
			{
				front--;
				if (front == -1)
					front = size - 1;
			}
			arr[front] = x;
		}
	}
	T pop_back()
	{
		T data = -999999;
		if (!is_empty())
		{
			data = arr[rear];
			if (rear == front)
			{
				rear = -1; front = -1;
			}
			else
			{
				rear--;
				if (rear == -1)
					rear = size - 1;
			}
		}
		else
		{
			cout << "is empty\n";
		}
		return data;
	}
	T pop_front()
	{
		T data = -999999;
		if (!is_empty())
		{
			data = arr[front];
			if (rear == front)
			{
				rear = -1; front = -1;
			}
			else
				front = (front + 1) % size;
		}
		else
		{
			cout << "Empty\n";
		}
		return data;
	}
	void show()
	{
		if (!is_empty())
		{
			int x = abs(front - rear);
			int f = front;
			while (f<rear || f>rear)
			{
				cout << arr[f] << " ";
				f++;
				if (f == size)
					f = 0;
				x--;
			}
			cout << arr[f] << "\n";
		}
	}
	void input()
	{
		char n;
		int x;
		do
		{
			system("cls");
			cout << "\t\t\t\t********************************************\n";
			cout << "\t\t\t\t1-inset in rear\t\t\t2-delete from rear\n\t\t\t\t3-delete from front\t\t4-show\n";
			cout << "\t\t\t\t********************************************\n";
			cin >> x;
			switch (x)
			{
			case 1:
				cout << "enter number to insert\n";
				cin >> x;
				push_back(x);
				break;
			case 2:
				pop_back();
				show();
				break;
			case 3:
				pop_front();
				show();
				break;
			case 4:
				show();
				break;
			default:
				break;
			}
			cout << "Enter y to continue\n";
			cin >> n;
		} while (n == 'y' || n == 'Y');
	}
	void output()
	{
		char n;
		int x;
		do
		{
			system("cls");
			cout << "\t\t\t\t********************************************\n";
			cout << "\t\t\t\t1-inset in rear\t\t\t2-insert in front\n\t\t\t\t3-delete from front\t\t4-show\n";
			cout << "\t\t\t\t********************************************\n";
			cin >> x;
			switch (x)
			{
			case 1:
				cout << "enter number to insert\n";
				cin >> x;
				push_back(x);
				break;
			case 2:
				cout << "enter number to insert\n";
				cin >> x;
				push_front(x);
				break;
			case 3:
				pop_front();
				show();
				break;
			case 4:
				show();
				break;
			default:
				break;
			}
			cout << "Enter y to continue\n";
			cin >> n;
		} while (n == 'y' || n == 'Y');
	}
};
template<class T>
class c_queu
{
private:
	int size, rear, front;
	T *arr;
public:
	c_queu(int si)
	{
		size = si;
		arr = new T[si];
		front = -1;
		rear = -1;
	}
	bool is_full()
	{
		if ((front == 0 && rear == size - 1) || front == rear + 1)
			return true;
		return false;
	}
	bool is_empty()
	{
		if (front == -1 && rear == -1)
			return true;
		return false;
	}
	void enqueu(T x)
	{
		if (is_full())
		{
			cout << "Full\n";
		}
		else
		{
			if (front == -1 && rear == -1)
				front = 0, rear = 0;
			else
				rear = (rear + 1) % size;
			arr[rear] = x;
		}
	}
	T dequeu()
	{
		T data=-999;
		if (!is_empty())
		{
			data = arr[front];
			if (front == rear)
			{
				front = -1;
				rear = -1;
			}
			else
			{
				front = (front + 1) % size;
			}
		}
		else
		{
			cout << "Empty\n";
		}
		return data;
	}
	void show()
	{
		if (front == -1)
		{
			cout << "empty\n";
			return;
		}
		int i;
		for (i = front; i < rear||rear<front; i = (i + 1) % size)
			cout << arr[i] << " ";
		cout << arr[i];
		cout << "\n";
	}
};
struct node
{
	int data;
	node* next;
};
//node* head;
class linked_l
{
public:
	node* head;
	void push_back(int x)
	{
		node* n = new node;
		n->data = x;
		n->next = NULL;
		if (head == NULL)
			head = n;
		else
		{
			node* temp = head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = n;
		}
	}
	void push_front(int x)
	{
		node* n = new node;
		n->data = x;
		if (head == NULL)
		{
			n->next = NULL;
			head = n;
		}
		else
		{
			n->next = head;
			head = n;
		}
	}
	void push_in(int d, int po)
	{
		if (po == 0)
		{
			push_front(d);
			return;
		}
		int c = 1;
		node* n = new node;
		n->data = d;
		node* temp = head;

		while (c < po)
		{
			if (temp->next == NULL)
			{
				cout << "indix is greater than size of linkef=d list\n";
				return;
			}
			temp = temp->next;
			c++;
		}
		n->next = temp->next;
		temp->next = n;
	}
	void push_after_data(int val, int dat)
	{
		node* n = new node;
		n->data = val;
		node* temp = head;
		while (temp != NULL)
		{
			if (temp->data == dat)
			{
				n->next = temp->next;
				temp->next = n;
			}
			temp = temp->next;
		}
	}
	void show()
	{
		node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "\n";
	}
	void pop_by_data(int d)
	{
		bool t = false;
		node* temp1 = head;
		node* temp2 = head;
		while (temp1 != NULL)
		{
			if (temp1->data == d)
			{
				t = true;
				break;
			}
			temp2 = temp1;
			temp1 = temp1->next;
		}
		if (t == false)
		{
			return;
		}
		if (temp1->data == d&&temp1->next == NULL)
			pop_back();

		else if (temp1 == temp2)
		{
			node* temp = head;
			head = head->next;
			free(temp);
		}
		else
		{
			node* dd = temp1;
			temp2->next = temp1->next;
			free(dd);
		}
	}
	void pop_front()
	{
		if (link_size() == 1)
		{
			free(head);
			head = NULL;
			return;
		}
		if (link_size()>0)
		{
			node* temp = head;
			head = head->next;
			free(temp);
		}
		else
			cout << "Empty\n";
	}
	void pop_back()
	{
		if (link_size() == 1)
		{
			free(head);
			head = NULL;
			return;
		}
		if (link_size()>0)
		{
			node* temp = head;
			while (temp->next->next != NULL)
				temp = temp->next;
			node* t = temp->next;
			temp->next = NULL;
			free(t);
		}
		else
			cout << "Empty\n";
	}
	void pop_by_position(int po)
	{
		if (link_size() == 0)
		{
			return;
		}
		if (po == 0)
		{
			pop_front();
			return;
		}
		node* temp = head;
		int c = 0;
		while (c<po - 1)
		{
			if (temp->next == NULL)
			{
				cout << "number of element less than insidx\n";
				return;
			}
			temp = temp->next;
			c++;
		}
		node* dd = temp->next;
		temp->next = dd->next;
		free(dd);
	}
	int link_size()
	{
		int c = 0;
		node* temp = head;
		while (temp != NULL)
		{
			temp = temp->next;
			c++;
		}
		return c;

	}
	void reverse()
	{
		node *c, *n, *p;
		c = head;
		p = NULL;
		if (link_size() == 1 || link_size() == 0)
			return;
		while (c->next != NULL)
		{
			n = c->next;
			c->next = p;
			p = c;
			c = n;
		}
		c->next = p;
		p = c;
		head = c;
	}
	void concat(linked_l second)
	{
		node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = second.head;
	}
	void searsh(int x)
	{
		bool f = false;
		node* temp = head;
		int c = 0;
		while (temp!= NULL)
		{

			if (temp->data == x)
			{
				cout << "found int "<<c<<"\n";
				f = true;
			}
			temp = temp->next;
			c++;
		}
		if (f == false)
			cout << "not found\n";
	}
};
class queu_linked
{
private:
	node* front;
	node* rear;
public:
	queu_linked()
	{
		front = NULL;
		rear = NULL;
	}
	void push(int x)
	{
		node* newnode = new node();
		newnode->data = x;
		newnode->next = NULL;
		if (front == NULL&&rear == NULL)
			front = newnode;
		else
			rear->next = newnode;
		rear = newnode;
	}
	int pop()
	{
		int g = NULL;
		if (front == NULL)
		{
			cout << "empty\n";
			return NULL;
		}
		if (front == rear)
		{
			rear = NULL;
			front = NULL;
		}
		else
		{
			node* temp = front;
			g = temp->data;
			front = front->next;
			free(temp);
		}
		return g;
	}
	void show()
	{
		node* temp = front;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "\n";
	}
};
class nodee
{
public:
	nodee* lpoint;
	int data;
	nodee* rpoint;
	nodee()
	{
		lpoint = NULL; rpoint = NULL;

	}
};
class Double_Linked
{
private:
	nodee* head;
public:
	Double_Linked()
	{
		head = NULL;
	}
	void push_back(int x)
	{
		nodee* newnode = new nodee();
		newnode->data = x;
		newnode->lpoint = NULL;
		newnode->rpoint = NULL;
		if (head == NULL)
			head = newnode;
		else
		{
			nodee* temp = head;
			while (temp->rpoint != NULL)
			{
				temp = temp->rpoint;
			}
			temp->rpoint = newnode;
			newnode->lpoint = temp;
		}
	}
	void push_front(int x)
	{
		nodee* newnode = new nodee();
		newnode->data = x;
		newnode->lpoint = NULL;
		newnode->rpoint = NULL;
		if (head == NULL)
			head = newnode;
		else
		{

			head->lpoint = newnode;
			newnode->rpoint = head;
			head = newnode;
		}
	}
	void push(int x, int pos)
	{
		nodee* temp = head;
		int i = 1;
		if (pos == 0)
		{
			push_front(x);
			return;
		}
		while (i < pos&& temp != NULL)
		{
			if (temp->rpoint == NULL)
			{
				cout << "position is greater than size\n";
				return;
			}
			temp = temp->rpoint;
			i++;
		}
		nodee* add = new nodee();
		add->data = x;
		add->lpoint = temp;
		add->rpoint = temp->rpoint;
		(temp->rpoint)->lpoint = add;
		temp->rpoint = add;
	}
	void diplay()
	{
		nodee* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->rpoint;
		}
		cout << "\n";
	}
	void pop_front()
	{
		if (head == NULL)
		{
			cout << "empty\n";
			return;
		}
		if (head->rpoint == NULL&&head->lpoint == NULL)
		{
			free(head);
			head = NULL;
			return;
		}
		nodee* temp = head;
		temp->rpoint->lpoint = NULL;
		head = temp->rpoint;
		free(temp);
	}
	void pop_back()
	{
		if (head == NULL)
		{
			cout << "empty\n";
			return;
		}
		if (head->rpoint == NULL&&head->lpoint == NULL)
		{
			free(head);
			head = NULL;
			return;
		}
		nodee* temp = head;
		while (temp->rpoint != NULL)
			temp = temp->rpoint;
		temp->lpoint->rpoint = NULL;
		free(temp);
	}
	void pop_by_data(int x)
	{
		nodee* temp = head;
		if (head->data == x)
		{
			pop_front();
			return;
		}
		while (temp != NULL)
		{
			if (temp->rpoint == NULL&&temp->data == x)
			{
				pop_back();
				return;
			}
			if (temp->data == x)
			{
				temp->lpoint->rpoint = temp->rpoint;
				temp->rpoint->lpoint = temp->lpoint;
				free(temp);
				break;
			}
			temp = temp->rpoint;
		}
	}
	int link_size()
	{
		int c = 0;
		nodee* temp = head;
		while (temp != NULL)
		{
			temp = temp->rpoint;
			c++;
		}
		return c;
	}
	void pop_by_pos(int x)
	{
		if (x == 0)
			pop_front();
		else if (x == link_size() - 1)
			pop_back();
		else if (x >= link_size())
			cout << "position out of size\n";
		else
		{
			nodee* temp = head;
			int c = 0;
			while (c < x)
			{
				temp = temp->rpoint;
				c++;
			}
			temp->lpoint->rpoint = temp->rpoint;
			temp->rpoint->lpoint = temp->lpoint;
			free(temp);
		}
	}
	void search(int x)
	{
		int c = 0;
		nodee* temp = head;
		while (temp != NULL)
		{
			c++;
			if (temp->data == x)
			{
				cout << "found in " << c-1 << "\n";
				return;
			}
			temp = temp->rpoint;
		}
		cout << "not found\n";
	}
	void reverse()
	{
		nodee* temp = head;
		while (temp != NULL)
		{
			if (temp->rpoint == NULL)
				head = temp;
			nodee* tt = temp;
			temp = temp->rpoint;
			nodee* h = tt->lpoint;
			tt->lpoint = tt->rpoint;
			tt->rpoint = h;
		}
	}
	void display_reverse()
	{
		nodee* temp = head;
		if (temp == NULL)
			return;
		while (temp->rpoint != NULL)
			temp = temp->rpoint;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->lpoint;
		}
		cout << "\n";
	}
};
class Nodee
{
public:
	Nodee* next;
	int data;
	Nodee()
	{
		next = NULL;
	}
};
class c_queue_linked
{
private:
	Nodee* last;
public:
	c_queue_linked()
	{
		last = NULL;
	}
	void push_to_empty(int x)
	{
		if (last != NULL)
			return;
		Nodee* add = new Nodee();
		add->data = x;
		add->next = add;
		last = add;
		last->next = add;
	}
	void push_front(int x)
	{
		if (last == NULL)
		{
			push_to_empty(x);
			return;
		}
		Nodee* add = new Nodee();
		add->data = x;
		add->next = last->next;
		last->next = add;
	}
	void push_back(int x)
	{
		if (last == NULL)
		{
			push_to_empty(x);
			return;
		}
		Nodee* add = new Nodee();
		add->data = x;
		add->next = last->next;
		last->next = add;
		last = add;
	}
	void show()
	{
		if (last == NULL)
		{
			cout << "empty\n";
			return;
		}
		Nodee* temp = new Nodee();
		Nodee* p = new Nodee();
		temp = last->next;
		p = last;
		while (temp != p&&temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << temp->data << "\n";

	}
	void after_data(int x, int item)
	{
		if (last == NULL)
			return;
		Nodee* add = new Nodee();
		add->data = item;
		Nodee* temp = new Nodee();
		temp = last->next;
		Nodee* p = new Nodee();
		p = last;
		while (temp != p)
		{
			if (temp->data == item)
			{
				Nodee* tt = new Nodee();
				tt->data = x;
				tt->next = temp->next;
				temp->next = tt;
				return;
			}
			temp = temp->next;
		}
		if (temp->data == item)
		{
			Nodee* tt = new Nodee();
			tt->data = x;
			tt->next = temp->next;
			temp->next = tt;
			return;
		}
	}
	void pop()
	{
		if (last == NULL)
			return;
		if (last == last->next)
		{
			free(last);
			last = NULL;
			return;
		}
		Nodee* temp = new Nodee();
		temp = last->next;
		last->next = temp->next;
		free(temp);
	}
};
struct Node
{
	int data;
	struct Node *next;
};
Node* head;
class sorting
{
public:
	void add_node(int x)
	{
		Node* temp = new Node();
		temp->data = x;
		if (head == NULL)
		{
			temp->next = NULL;
			head = temp;
		}
		else
		{
			temp->next = head;
			head = temp;
		}
	}
	void buble_sort(int arr[], int size)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - 1 - i; j++)
			{
				if (arr[j]<arr[j + 1])
				{
					int t = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = t;
				}
			}
		}
	}
	void show_nodes()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "\n";
	}
	void insertion_sort(int arr[], int size)
	{
		for (int i = 1; i < size; i++)
		{
			int k = arr[i];
			int c = i - 1;
			while (c >= 0 && arr[c]>k)
			{
				int t = arr[c];
				arr[c] = k;
				arr[c + 1] = t;
				c--;
			}
		}
	}
	void selection_sotr(int arr[], int size)
	{
		for (int i = 0; i < size - 1; i++)
		{
			int min = i;
			for (int j = i + 1; j < size; j++)
			{
				if (arr[j] < arr[min])
					min = j;
			}
			if (min != i)
			{
				int t = arr[min];
				arr[min] = arr[i];
				arr[i] = t;
			}
		}

	}
	void bubble_sort_linked_list(Node* head)
	{
		Node* i;
		Node* j;
		int temp;
		for (i = head; i != NULL; i = i->next)
		{
			for (j = i->next; j != NULL; j = j->next)
			{
				if (i->data > j->data)
				{
					temp = i->data;
					i->data = j->data;
					j->data = temp;
				}
			}
		}
	}
	void selection_sort_linked_list(Node *head)
	{
		Node *i, *j, *min;
		for (i = head; i->next != NULL; i = i->next)
		{
			min = i;
			for (j = i->next; j->next != NULL; j = j->next)
			{
				if (j->data < min->data)
					min = j;
			}
			if (j->data < min->data)
				min = j;
			if (i != min)
			{
				int t = i->data;
				i->data = min->data;
				min->data = t;
			}
		}
	}
	//merge sort
	void merge(int arr[], int low, int mid, int high)
	{
		int arr2[100];
		int i = low, j = mid + 1, k = low;
		while (i <= mid&&j <= high)
		{
			if (arr[j] > arr[i])
			{
				arr2[k] = arr[i];
				i++; k++;
			}
			else
			{
				arr2[k] = arr[j];
				j++; k++;
			}
		}
		while (i <= mid)
		{
			arr2[k] = arr[i];
			i++; k++;
		}
		while (j <= high)
		{
			arr2[k] = arr[j];
			j++; k++;
		}
		for (int i = low; i < k; i++)
			arr[i] = arr2[i];
	}
	void merge_sort(int arr[], int low, int high)
	{
		if (low < high)
		{
			int mid = (low + high) / 2;
			merge_sort(arr, low, mid);
			merge_sort(arr, mid + 1, high);
			merge(arr, low, mid, high);
		}
	}
	// quick sort
	int partition(int arr[], int left, int right)
	{
		int i = left + 1;
		int j = right;
		int p = arr[left];
		while (i < j)
		{
			while (arr[i] < p)
				i++;
			while (arr[j]>p)
				j--;
			if (i <= j)
			{
				int t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
				i++;
				j--;
			}
		}
		int t = arr[left];
		arr[left] = arr[j];
		arr[j] = t;
		return j;
	}
	void quick_sort(int arr[], int left, int right)
	{
		if (left < right)
		{
			int pivot = partition(arr, left, right);
			quick_sort(arr, left, pivot - 1);
			quick_sort(arr, pivot + 1, right);
		}
	}
	// merge sort by linked list
	void partition(Node* head, Node **front, Node **back)
	{
		Node* fast = NULL;
		Node* slow = NULL;
		if (head == NULL || head->next == NULL)
		{
			*front = head;
			*back = NULL;
		}
		else
		{
			slow = head;
			fast = slow->next;
		}
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				fast = fast->next;
				slow = slow->next;
			}
		}
		*front = head;
		*back = slow->next;
		slow->next = NULL;
		//show_nodes();
	}
	Node* mergelist(Node* a, Node* b)
	{
		Node* merg = NULL;
		if (a == NULL)
			return b;
		else if (b == NULL)
			return a;
		if (a->data <= b->data)
		{
			merg = a;
			merg->next = mergelist(a->next, b);
		}
		else
		{
			merg = b;
			merg->next = mergelist(a, b->next);
		}
		return merg;
	}
	void merge_sort_linked(Node **head)
	{
		Node* a = NULL;
		Node* b = NULL;
		Node* source = *head;
		if (source == NULL || source->next == NULL)
			return;
		partition(source, &a, &b);
		merge_sort_linked(&a);
		merge_sort_linked(&b);
		*head = mergelist(a, b);
	}
};

int main()
{
	char ch = 'y';
	do
	{
		system("cls");
		cout << "                        *****************************************************\n\t\t\t1-chapter 1\t\t\t2-chapter 2\n\t\t\t3-chapter 3\t\t\t4-chapter 4\n\t\t\t5-chapter 5\t\t\t6-chapter 6\n                       *******************************************************\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			//array operations 
			char c = 'y';
			int x, y, aa, b;
			cout << "enter size of array\n";
			cin >> y;
			arrr a;
			a.crate_arr(y);
			do
			{
				system("cls");
				cout << "\t\t\t\t********************************************\n";
				cout << "\t\t\t\t1-insert\t\t\t2-erase\n\t\t\t\t3-reverse\t\t\t4searsh\n\t\t\t\t5-display\t\t\t6-merge\n\t\t\t\t7-sort\n";
				cout << "\t\t\t\t********************************************\n";

				cin >> x;
				switch (x)
				{
				case 1:
					cout << "enter position\n";
					cin >> aa;
					cout << "enter value\n";
					cin >> b;
					a.insert(aa, b);
					break;
				case 2:
					cout << "enter position\n";
					cin >> aa;
					a.erase(aa);
					break;
				case 3:
					a.reverse();
					break;
				case 4:
					cout << "enter number to searsh\n";
					cin >> aa;
					if (a.searsh(aa) == -1)
						cout << "not found\n";
					else
						cout << "indix is " << a.searsh(aa) << "\n";
					break;
				case 5:
					a.display();
					break;
				case 6:
					arrr b;
					cout << "enter size \n";
					int x;
					cin >> x;
					b.crate_arr(x);
					a.merge(b);
					break;
				case 7:
					a.sort();
				default:
					break;
				}
				cout << "Enter y or Y in chapter 1 to continue and N to stop\n";
				cin >> c;
			} while (c == 'y' || c == 'Y');
			break;
		}
		case 2:
		{
			system("cls");

			cout << "\t\t\t\t********************************************\n";
			cout << "\t\t\t\t1-stack operations\t\t\t2-infix operations\n\n";
			cout << "\t\t\t\t********************************************\n";
			int uu;
			cin >> uu;
			//stack operations
			if (uu == 1)
			{
				char n;
				int t, x, z;
				cout << "Enter Size Of Stack\n";
				cin >> z;
				Stack s(z);
				for (int i = 0; i < z; i++)
				{
					cout << "enter number " << i + 1 << "\n";
					int c;
					cin >> c;
					s.push(c);
				}
				do
				{
					system("cls");
					cout << "\t\t\t\t********************************************\n";
					cout << "\t\t\t\t1-push\t\t\t2-pop\n\t\t\t\t3-display\t\t4-find_item\n\t\t\t\t5-reverse using recurgan\n";
					cout << "\t\t\t\t********************************************\n";
					cin >> t;
					switch (t)
					{
					case 1:
						cout << "Enter Number\n";
						cin >> x;
						s.push(x);
						s.display();
						break;
					case 2:
						s.pop();
						s.display();
						break;
					case 3:
						s.display();
						break;
					case 4:
						cout << "Enter Number To searsh\n";
						cin >> x;
						cout << s.find(x) << "\n";
						break;
					case 5:
						s.reverse_recursive();
					default:
						break;
					}

					cout << "Enter y to continue\n";
					cin >> n;

				} while (n == 'y' || n == 'Y');
			}
			else
			{
				char n='y';
				do
				{
					infix in;
					postifix_to_inf_or_pre p;
					int t;
					system("cls");
					cout << "\t\t\t\t********************************************\n";
					cout << "\t\t\t\t1-infix to postifix\t\t2-infix to prefix\n\t\t\t\t3-postifix to infix\t\t4-postifix to prefix\n\t\t\t\t5-prefix to infix\n";
					cout << "\t\t\t\t********************************************\n";
					cin >> t;
					switch (t)
					{
					case 1:
						in.infex_to_postifix();
						break;
					case 2:
						in.infex_to_prefix();
						break;
					case 3:
						p.post_to_inf();
						break;
					case 4:
						p.post_to_prefix();
						break;
					case 5:
						p.prefix_to_inf();
					default:
						break;
					}
					cout << "Enter y to continue\n";
					cin >> n;
				} while (n == 'y' || n == 'Y');
			}
			break;
		}
		case 3:
		{
			int t;
			system("cls");
			cout << "\t\t\t\t********************************************\n";
			cout << "\t\t\t\t1-queue\t\t\t\t2-circular queue\n\t\t\t\t3-double queue\t\t\t\n\n\n";
			cout << "\t\t\t\t********************************************\n";
			cin >> t;
			switch (t)
			{
			case 1:
			{
				cout << "enter size of queue\n";
				int s;
				cin >> s;
				char n = 'y';
				queue<int>cc(s);
				do
				{
					system("cls");

					cout << "\t\t\t\t********************************************\n";
					cout << "\t\t\t\t1-push\t\t\t\t2-pop\n\t\t\t\t3-show\t\t\t\t4-top\n\t\t\t\t5-size\n";
					cout << "\t\t\t\t********************************************\n";			
					int x;
					cin >> x;
					switch (x)
					{
					case 1:
						cout << "enter number to insert\n";
						cin >> x;
						cc.push(x);
						break;
					case 2:
						cc.pop();
						break;
					case 3:
						cc.show();
						break;
					case 4:
						cc.front();
						break;
					case 5:
						cout<<cc.size()<<"\n";
						break;
					default:
						break;
					}
					cout << "Enter y to continue\n";
					cin >> n;
				} while (n == 'y' || n == 'Y');
				break;
			}
			case 2:
			{
				cout << "enter size of circular queue\n";
				int x;
				char n;
				cin >> x;
				c_queu<int>cc(x);
				do
				{
					system("cls");
					cout << "\t\t\t\t*******************circular queue*************************\n";
					cout << "\t\t\t\t1-push\t\t\t\t2-pop\n\t\t\t\t3-show\n";
					cout << "\t\t\t\t*******************circular queue*************************\n";	
					cin >> x;
					switch (x)
					{
					case 1:
						cout << "enter number to insert\n";
						cin >> x;
						cc.enqueu(x);
						break;
					case 2:
						cc.dequeu();
						break;
					case 3:
						cc.show();
						break;
						
					default:
						break;
					}
					cout << "Enter y to continue\n";
					cin >> n;
				} while (n == 'y' || n == 'Y');
				break;
			}
			case 3:
			{
				int x;
				cout << "enter size of double queue\n";
				cin >> x;
				D_queue<int>c(x);
				cout << "1-Input restricted de-queue\t\t2-Output restricted de-queue\n";
				cin >> x;
				if (x == 1)
					c.input();
				else
					c.output();
				break;
			}
			default:
				break;
			}
			break;
		}
		case 4:
		{
			linked_l link, ll;
			link.head = NULL;
			ll.head = NULL;
			char c = 'y';
			do
			{
				system("cls");
				cout << "\t\t\t\t*******************\tLinked List\t*************************\n\n\n";
				cout << "\t\t\t\t1-Add_back\t\t\t2-Add_front\n\t\t\t\t3-push in postion\t\t4push after data\n\t\t\t\t5-show\t\t\t\t6-delete by data\n\t\t\t\t7-delete front\t\t\t8-delete back\n\t\t\t\t9-pop by position\t\t10-reverse\n\t\t\t\t11-search\t\t\t12-queue linked list\n\t\t\t\t13-Double linked list\t\t14-circular linked list\n\n";
				cout << "\t\t\t\t*******************\tLinked List\t*************************\n";
				int x;
				cin >> x;
				int aa, b;
				switch (x)
				{
				case 1:
					cout << "enter number\n";
					cin >> aa;
					link.push_back(aa);
					break;
				case 2:
					cout << "enter number\n";
					cin >> aa;
					link.push_front(aa);
					break;
				case 3:
					cout << "enter position\n";
					cin >> b;
					cout << "enter data\n";
					cin >> aa;
					link.push_in(aa, b);
					break;
				case 4:
					cout << "enter number to add after it\n";
					cin >> b;
					cout << "enter data\n";
					cin >> aa;
					link.push_after_data(aa, b);
					break;
				case 5:
					link.show();
					break;
				case 6:
					int yy;
					cout << "enter number to delete\n";
					cin >> yy;
					link.pop_by_data(yy);
					break;
				case 7:
					link.pop_front();
					break;
				case 8:
					link.pop_back();
					break;
				case 9:
					int h;
					cout << "enter position to delete\n";
					cin >> h;
					link.pop_by_position(h);
					break;
				case 10:
					link.reverse();
					break;
				case 11:
					int j;
					cout << "enter number to search\n";
					cin >> j;
					link.searsh(j);
					break;
				case 12:
				{
						   char n;
						   queu_linked q;
						   do
						   {
							   system("cls");
							   cout << "\n\n\n";
							   cout << "\t\t\t\t****************\tqueue linked list****************************\n\n\n";
							   cout << "\t\t\t\t1-push\t\t\t\t2-pop\n\t\t\t\t3-show\t\t\t\n";
							   cout << "\t\t\t\t****************\tqueue linked list****************************\n";
							   cin >> x;
							   switch (x)
							   {
							   case 1:
								   cout << "enter number to insert\n";
								   cin >> x;
								   q.push(x);
								   break;
							   case 2:
								   q.pop();
								   q.show();
								   break;
							   case 3:
								   q.show();
								   break;
							   default:
								   break;
							   }
							   cout << "Enter y to continue\n";
							   cin >> n;
						   } while (n == 'y' || n == 'Y');
						   break;
				}
				case 13:
				{
						   char n;
						   Double_Linked q;
						   do
						   {
							   system("cls");
							   cout << "\n\n\n";
							   cout << "\t\t\t\t*******************\tDouble Linked List\t*************************\n\n\n";
							   cout << "\t\t\t\t1-Add_back\t\t\t2-Add_front\n\t\t\t\t3-push in postion\t\t4-display\n\t\t\t\t5-pop front\t\t\t6-pop back\n\t\t\t\t7-pop by data\t\t\t8-size of linked\n\t\t\t\t9-pop by position\t\t10-search\n\t\t\t\t11-reverse\t\t\t12-display reverse\n\n";
							   cout << "\t\t\t\t*******************\tDouble Linked List\t*************************\n";
							   cin >> x;
							   switch (x)
							   {
							   case 1:
								   cout << "enter number to push back\n";
								   cin >> x;
								   q.push_back(x);
								   break;
							   case 2:
								   cout << "enter number to push front\n";
								   cin >> x;
								   q.push_back(x);
								   break;
							   case 3:
								   cout << "enter number to push in position\n";
								   cin >> x;
								   cout << "enter position\n";
								   int j;
								   cin >> j;
								   q.push(x,j);
								   break;
							   case 4:
								   q.diplay();
								   break;
							   case 5:
								   q.pop_front();
								   q.diplay();
								   break;
							   case 6:
								   q.pop_back();
								   q.diplay();
								   break;
							   case 7:
								   cout << "enter number to delete it\n";
								   int c;
								   cin >> c;
								   q.pop_by_data(c);
								   q.diplay();
								   break;
							   case 8:
							   {
										 int ct = q.link_size();
										 cout << "size is " << ct << "\n";
										 break;
							   }
							   case 9:
								   cout << "enter position to delete it\n";
								   int jt;
								   cin >> jt;
								   q.pop_by_pos(jt);
								   q.diplay();
								   break;
							   case 10:
								   cout << "enter number to search\n";
								   int h;
								   cin >> h;
								   q.search(h);
								   break;
							   case 11:
								   q.reverse();
								   q.diplay();
								   break;
							   case 12:
								   q.display_reverse();
								   break;
							   default:
								   break;
							   }
							   cout << "Enter y to continue\n";
							   cin >> n;
						   } while (n == 'y' || n == 'Y');
						   break;
				}
				case 14:
				{
						   char n;
						   c_queue_linked q;
						   do
						   {
							   system("cls");
							   cout << "\n\n\n";
							   cout << "\t\t\t\t****************\tcircular linked list****************************\n\n\n";
							   cout << "\t\t\t\t1-push_front\t\t\t\t2-push_back\n\t\t\t\t3-push after datat\t\t\t4-pop\n\t\t\t\t5-show\n\n\n";
							   cout << "\t\t\t\t****************\tcircular linked list****************************\n";
							   cin >> x;
							   switch (x)
							   {
							   case 1:
								   cout << "enter number to push\n";
								   cin >> x;
								   q.push_front(x);
								   break;
							   case 2:
								   cout << "enter number to push\n";
								   cin >> x;
								   q.push_back(x);
								   break;
							   case 3:
								   cout << "enter number to add it\n";
								   cin >> x;
								   int hh;
								   cout << "enter item you want to add after it\n";
								   cin >> hh;
								   q.after_data(x,hh);
								   break;
							   case 4:
								   q.pop();
								   break;
							   case 5:
								   q.show();
								   break;
							   default:
								   break;
							   }
							   cout << "Enter y to continue\n";
							   cin >> n;
						   } while (n == 'y' || n == 'Y');
						   break;
				}

				default:
					break;
				}
				cout << "Enter y in chapter to continue and N to stop\n";
				cin >> c;
			} while (c == 'y' || c == 'Y');
			break;
		   }
			break;
			case 5:
			{
						char n='y';
						int t;
						system("cls");
						cout << "\t\t\t\t******************\tsotring techniques\t**************************\n";
						cout << "\t\t\t\t1-Array\t\t\t\t2-linked list\n\n";
						cout << "\t\t\t\t******************\tsotring techniques\t**************************\n";
						cin >> t;
						sorting sss;
						switch (t)
						{
						case 1:
						{
								system("cls");
								cout << "enter size of array\n";
								int vvv;
								cin >> vvv;
								int arr[100];
								for (int i = 0; i < vvv; i++)
								{
									cout << "enter numner\n";
									cin >> arr[i];
								}
								char n = 'y';
								while (n == 'y' || n == 'Y')
								{
									system("cls");
									cout << "\t\t\t\t******************\tsotring techniques\t**************************\n\n\n";
									cout << "\t\t\t1-insertion sort\t\t\t2-lselection sort\n\t\t\t3-Bubble sort\t\t\t\t4-Quich sort\n\t\t\t5-Merge sort\t\t\t6-show\n\n\n";
									cout << "\t\t\t\t******************\tsotring techniques\t**************************\n";
									int s;
									cin >> s;
									switch (s)
									{
									case 1:
										sss.insertion_sort(arr,vvv);
										break;
									case 2:
										sss.selection_sotr(arr,vvv);
										break;
									case 3:
										sss.buble_sort(arr, vvv);
										break;
									case 4:
										sss.quick_sort(arr, 0, vvv - 1);
										break;
									case 5:
										sss.merge_sort(arr,0,vvv-1);
										break;
									case 6:
									{
												for (int i = 0; i < vvv; i++)
													cout << arr[i] << " ";
												cout << "\n";
												break;
									}
									default:
										break;
									}
									cout << "Enter y to continue\n";
									cin >> n;
								} 
								break;
							  }
						case 2:
						{
								  system("cls");
								  cout << "enter size of linked list\n";
								  int vvv;
								  cin >> vvv;
								  int arr[100];
								  int m;
								  for (int i = 0; i < vvv; i++)
								  {
									  cin >> m;
									  sss.add_node(m);
								  }
								  char n = 'y';
								  while (n == 'y' || n == 'Y')
								  {
									  system("cls");
									  cout << "\t\t\t\t******************\tsotring techniques\t**************************\n\n\n";
									  cout << "\t\t\t1-Bubble sort\t\t\t2-selection sort\n\t\t\t3-Merge sort\t\t\t4-show\n\n\n";
									  cout << "\t\t\t\t******************\tsotring techniques\t**************************\n";
									  int s;
									  cin >> s;
									  switch (s)
									  {
									  case 1:
										  sss.bubble_sort_linked_list(head);
										  break;
									  case 2:
										  sss.selection_sort_linked_list(head);
										  break;
									  case 3:
										  sss.merge_sort_linked(&head);
										  break;
									  case 4:
										  sss.show_nodes();
										  break;
									  default:
										  break;
									  }
									  cout << "Enter y to continue\n";
									  cin >> n;
								  }
								  break;
						}
							  default:
								  break;
							  }
					}
					case 6:
						cout << "in all function above\n";
						break;
		default:
			break;
		}
		cout << "enter y to select another chapter\n";
		cin >> ch;
	} while (ch == 'y');
}





         