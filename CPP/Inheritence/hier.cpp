#include<bits/stdc++.h>

using namespace std;

class employee{
	string name,ID,dob;
	int salary;
	public:
		employee(string n,string i,string d,int s)
		{
			name=n;
			ID=i;
			dob=d;
			salary=s;
		}
		int get_salary(){return salary;}
		string get_ID(){return ID;}
		string get_name(){return name;}
		string get_dob(){return dob;}
};


class manager:public employee{
	string name;
	list<employee*> e;
	typedef map<string,manager*> vmap;
	vmap work;
	public:
		manager(string n)
		{
			name=n;
		}
		void set_employee_list();
		void show_emp_list();
		void add_manager();
};

void manager::add_manager(string n,employee* e)
{
	vmap::iterator it=work.begin();
	it=work.find(n);
	if(it==work.end()){
		work[n]=new manager(n);
		work[n]->set_employee_list(e);
	}else{
		it->second->set_employee_list(e);
	}
		
}

void manager::set_employee_list(employee* el)
{
	e.push_back(el);
}

void manager::show_emp_list()
{
	cout<<"MANAGER   EMP_NAME      SALARY      DOB        ID"<<endl;
	for(vmap::iterator it=work.begin();it!=work.end();it++){
		cout<<it->second->name<<"\t";
		for(list<employee*>::iterator iter=it->second->e.begin();iter!=it->second->e.end();iter++)
			cout<<iter->name<<"\t"<<iter->salary<<"\t"<<iter->dob<<"\t"<<iter->ID<<endl;
	}
}

int main()
{
	ifstream fin;
	fin.open("employee.txt");
	manager m;
	while(!fin.eof()){
		string nam,sal,db,man;
		int id;
		fin >>nam>>sal>>db>>id>>man;
		employee* emp=new employee(nam,id,db,sal);
		m.add_manager(man,emp);
	}
	m.show_emp_list();
	return 0;
}
