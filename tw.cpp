#include<iostream>
#include<list>
using namespace std;

class Hash{
	int MAX;

	list<int>*table;
	
	public:
		Hash(int v);
		
		int Function(int key){
			key=key%MAX;
			return key;
		}
		void Insert(int key){
			int index=Function(key);
			index[table].push_back(key);
		}
		void Delete(int key){
			int index=Function(key);
			list<int>::iterator i;
			for(i=table[index].begin();table[index].end()!=i;i++){
				if(*i==key) {
					table[index].erase(i);
					break;
				}
			}
		}	
		void Display(){
			for(int i=0;i<MAX;i++){
				cout<<i;
				for(list<int>::iterator it=table[i].begin();it!=table[i].end();it++){
					int x=*it;
					cout<<"-->>"<<x;
				}
				cout<<endl;
			}
		}
		void search(int key){
			int index=Function(key);
			list<int>::iterator i;
			for(i=table[index].begin();i!=table[index].end();i++){
					if(*i==key){
				cout<<key<<"found"<<endl;
				break;
				}
				cout<<key<<"not found"<<endl;
			}
		}
};
Hash::Hash(int b){
	this->MAX=b;
	table=new list<int>[MAX];
}
int main(){
	int x;
	int a[5];
	Hash h(7);
			cout<<"*** CHAINING HASHING ***"<<endl;
			cout<<"1. Insert"<<endl;
			cout<<"2. Delete"<<endl;
			cout<<"3. Display"<<endl;
			cout<<"4. search"<<endl;
			cout<<"5. Exit"<<endl;
	while(1){
			cout<<"Enter your choice :";
			cin>>x;			
	switch(x){
	case 1:
		int y;
		cout<<"Enter the Insert number:";
		cin>>y;
		h.Insert(y);
		break;
	case 2:
		int a;
		cout<<"Enter the Delete number:";
		cin>>a;
		 h.Delete(a);
		 break;
	case 3:
		h.Display();
		break;
	case 4:
		int c;
		cout<<"Enter the search number:";
		cin>>c;
		h.search(c);
		break;
	case 5:
		break;	
	default:
		 cout << "Error! Your choice is not correct";

	return 0;
	}
	}
}
