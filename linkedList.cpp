#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;

struct node
{
	int x;
	node *next;
};
bool isEmpty(node *head)
{
	if(head == NULL)
		return true;
	else
		return false;
}
void add(node *&head, node *&last, int x){
	if(isEmpty(head)){
		node *temp = new node;
		temp->x = x;
		temp->next = NULL;
		head = temp;
		last = temp;
	}
	else{
		node *temp = new node;
		temp->x = x;
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}
int search(struct node *start, int find){
	struct node *p;
	int pos = 1;
	p = start;
	while(p != NULL)
	{
		if(p->x == find)
		{
			return pos;
		}
		p = p->next;
		pos++;
	}
	printf("\n%d not found!\n", find);
	free(p);
	return 500;
}
void print(struct node *cur, int &sum, int &ave){
	int i = 0;
	if(isEmpty(cur))
		cout << "Empty list!\n";
	else
	{
		cout << "\nLinked List:\n";
		while(cur != NULL)
		{
			cout << cur->x << "\n";
			i++;
			sum += cur->x;
			cur = cur->next;
		}
		ave = sum / i;
		printf("\n");
	}
}
void remove(struct node *head, int pos){
	if(pos != 500){
		struct node *temp1 = head;
		if(pos == 1)
		{	
			head = temp1->next;
			free(temp1);
			return;
		}
		for(int i = 0; i < pos - 2; i++)
		{
			temp1 = temp1->next;
		}
		struct node *temp2 = temp1->next;
		temp1->next = temp2->next;
		free(temp2);
	}	
}
int main(){
	int n, choice;
	int sum = 0;
	int average = 0;
	string temp = "";
	node *head = NULL;
	node *last = NULL;
	
	vector<int> intVec;
	cout << "\nHow many integers do you want?  ";
	cin >> choice;
	string stringList;
	cout << "\nInput a list of integers:  ";
	cin.ignore();
	getline(cin, stringList);
	for (int i = 0; stringList[i] != '\0'; i++) {
		if (stringList[i] == ' ') {
			intVec.push_back(stoi(temp));
			temp = "";
		}
		else {
			temp += stringList[i];
		}
	}
	if(stringList[stringList.length() - 1] != ' ')
		intVec.push_back(stoi(temp));
	for (int n = 0; n < intVec.size(); n++){
       		add(head, last, intVec[n]);	
	} 
	print(head, sum, average);
	printf("\nSum = %d\nAverage = %d\n\nEnter a value to delete:  ", sum, average);
	cin >> n;
	remove(head, search(head, n));
	print(head, sum, average);
        return 0;
}

