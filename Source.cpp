#define _CRT_SECURE_NO_WARNINGS
#include <ctime> // ���������� �������
#include <cmath>
#include <locale.h>
#include <iostream> // ���������� �����,������
#include <conio.h>
#include < queue >
#include <time.h>

int** matrix;
using namespace std;
struct bfsQ {

	int data;

	bfsQ *next, *prev;
	
};

bfsQ *head, *tail;

typedef bfsQ *PbfsQ;

bfsQ* tmp;
bfsQ* n_tmp;
void push(int versh)
{
	
	n_tmp = new bfsQ;
	
	n_tmp->data=versh;
	n_tmp->next = NULL;
	n_tmp->prev = NULL;
	if (tail == NULL)
	{
		tmp = n_tmp;
		head= tmp;
		tail = tmp;
	}
	else
	{
		n_tmp->next = tmp;
		tmp->prev = n_tmp;
		tmp = n_tmp;
		tail = tmp;
	}
	
}

void pop()
{
	bfsQ* m_tmp;
	if ((head) != NULL)
	{
		n_tmp = head;
		if ((n_tmp->prev) !=NULL)
		{
		m_tmp = n_tmp->prev;
		free(n_tmp);
		m_tmp->next = NULL;
		head = m_tmp;
		}
		else
		{
		free(n_tmp);
		head = NULL;
		tail = NULL;
		}
		
	}
	
}
int front()
{
	if ((head) != NULL)
	{
		return (head->data);
	}
}
bool empty_1()
{
	if ((head) == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
struct spisok_smzh {

	int versh;
	spisok_smzh* next;

};

struct spiski_smzh {

	spisok_smzh* spisok;
	spiski_smzh* next;
};

spiski_smzh* p_spiski = NULL;
spiski_smzh* n_spiski = NULL;
spiski_smzh* p_spiski_start = NULL;
spisok_smzh* p_spisok = NULL;
spisok_smzh* p_spisok_start = NULL;
spisok_smzh* n_spisok = NULL;


void bfs2(int v, int n)
{
	clock_t time;
	time = clock();
	int p = 0, i = 0, u = 0;
	char* NUM;
	NUM = new char[n];
	for (u = 0; u < n; u++)
	{
		NUM[u] = 0;
	}
	cout << v;
	//i = s;
	queue <int> plan; // ���� ��������� � ���� �������
	p_spiski = p_spiski_start;
	spisok_smzh* p_spisok_loc = NULL;
	plan.push(v); // �� �������� � 0, � �� � 1
	NUM[v] = 1; // ��������, ��� ��� ������� ��� ���������� � ����
	//int counter = 1; // ��������� ��� ���������

	while (!plan.empty()) {
		v = plan.front(); // �������� ��������� �� ����� �������
		plan.pop(); // ������� �� �� ����� ���������
		for (int i = 0; i < v; i++)
			p_spiski = p_spiski->next;
		p_spisok_loc = p_spiski->spisok;
		p_spiski = p_spiski_start;
		//cout � v;
		while (p_spisok_loc != NULL) { // ���������� �������� � ���
			if (!NUM[p_spisok_loc->versh]) { // ���� �����, ��
				plan.push(p_spisok_loc->versh); // ��������� �� � ����
				cout << p_spisok_loc->versh;
				NUM[p_spisok_loc->versh] = 1; // ��������, ��� ��� �� �����

			}
			p_spisok_loc = p_spisok_loc->next;
		}
	}
	time = clock() - time;
	cout << endl;
	printf("%.30f", (double)time / CLOCKS_PER_SEC);
}

void bfs(int v, int n)
{
	clock_t time;
	time = clock();
	bfsQ* head = NULL;
	bfsQ* tail = NULL;
	int p = 0, i = 0, u = 0;
	char* NUM;
	NUM = new char[n];
	for (u = 0; u < n; u++)
	{
		NUM[u] = 0;
	}
	cout << v;
	//i = s;
	//queue <int> plan; // ���� ��������� � ���� �������
	p_spiski = p_spiski_start;
	spisok_smzh* p_spisok_loc = NULL;
	push(v); // �� �������� � 0, � �� � 1
	NUM[v] = 1; // ��������, ��� ��� ������� ��� ���������� � ����
	//int counter = 1; // ��������� ��� ���������

	while (!empty_1()) {
		v = front(); // �������� ��������� �� ����� �������
		pop(); // ������� �� �� ����� ���������
		for (int i = 0; i < v; i++)
			p_spiski = p_spiski->next;
		p_spisok_loc = p_spiski->spisok;
		p_spiski = p_spiski_start;
		//cout � v;
		while (p_spisok_loc != NULL) { // ���������� �������� � ���
			if (!NUM[p_spisok_loc->versh]) { // ���� �����, ��
				push(p_spisok_loc->versh); // ��������� �� � ����
				cout << p_spisok_loc->versh;
				NUM[p_spisok_loc->versh] = 1; // ��������, ��� ��� �� �����
				
			}
			p_spisok_loc = p_spisok_loc->next;
		}
	}
	time = clock() - time;
	cout << endl;
	printf("%.30f", (double)time / CLOCKS_PER_SEC);
}


int main()
{
	
	int p = 0, i = 0, n,j;
	int v = 0;
	//int s;
	setlocale(LC_ALL, "Russian"); // ����������� ��������
	//srand(time(NULL)); // ����� ������ �������

	cout << "n="; // ������� ������
	cin >> n; // �������� ������
	matrix = new int* [n];
	//cout � "n=";
	//cin � n;
	cout << "�������: \n";
	int z;
	for (i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}



	for (i = 0; i < n; i++)
	{
		for (p = 0; p < n; p++)
		{
			matrix[i][p] = rand() % 2;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (p = 0; p < n; p++)
		{
			
			if (p == i)
			{
				matrix[i][p] = 0;
			}
			else
			{
				matrix[i][p] = matrix[p][i];
			}
			cout << matrix[i][p]<<"  ";
			
		}

	}
	for (int i = 0; i < n; i++)
	{
		n_spiski = (spiski_smzh*)malloc(sizeof(spiski_smzh));
		p_spisok = NULL;
		p_spisok_start = NULL;
		for (j = 0; j < n; j++)
		{
			if (matrix[i][j] == 1)
			{
				n_spisok = (spisok_smzh*)malloc(sizeof(spisok_smzh));
				n_spisok->versh = j;
				if (p_spisok == NULL)
				{
					p_spisok = n_spisok;
					p_spisok_start = p_spisok;
				}
				else
				{
					p_spisok->next = n_spisok;
					p_spisok = n_spisok;
				}
				n_spisok->next = NULL;
			}
		}
		n_spiski->spisok = p_spisok_start;
		if (p_spiski == NULL)
		{
			p_spiski = n_spiski;
			p_spiski_start = p_spiski;
		}
		else
		{
			p_spiski->next = n_spiski;
			p_spiski = n_spiski;
		}
	}

	p_spiski = p_spiski_start;

	for (int i = 0; i < n; i++)
	{
		p_spisok = p_spiski->spisok;
		p_spisok_start = p_spisok;

		cout << "\n";
		cout << "{";
		while (p_spisok != NULL)
		{
			cout << p_spisok->versh << " ";
			p_spisok = p_spisok->next;
		}
		cout << "}" << "   �������" << i;
		p_spisok = p_spisok_start;
		p_spiski = p_spiski->next;
	}
	cout << "\n";

	p_spiski = p_spiski_start;

	

	cout << "\n";
	cout << "\n";
	for (i = 0; i < n; i++)
	{
		// used[i] = false;
		for (p = 0; p < n; p++)
			cout << matrix[i][p] << " "; // ������� �������
		cout << endl;
	}

	cout << "��������� ������� � ";
	//cin � s;
	cin >> v;
	//bool* vis = new bool[n];
	cout << "������� ������: ";
	//time = clock();
	bfs(v, n);
	//time = clock() - time;
	cout << endl;
	//printf("%.30f", (double)time / CLOCKS_PER_SEC);
	cout << endl;
	cout << "������� ������: ";
	//time = clock();
	bfs2(v, n);
	//time = clock() - time;
	cout << endl;
	//printf("%.30f", (double)time / CLOCKS_PER_SEC);
	//delete[] used;
	_getch();
}

