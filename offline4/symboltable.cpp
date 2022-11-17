#include<bits/stdc++.h>
using namespace std;

class SymbolInfo
{
private:
    string Name;
    string Type;
public:
    bool global;
    string DataType;
    int num_of_param;
    int isdeclared;
    int isdefined;
    int offset;
    vector<SymbolInfo*> parameter_list;
    SymbolInfo *next;
    SymbolInfo(string name,string type)
    {
        Name=name;
        Type=type;
        DataType=type;
        next=NULL;
        num_of_param=-1;
        isdeclared=0;
        isdefined=0;
        offset=0;
        global=false;
    }
    SymbolInfo(string name,string type,string datatype)
    {
        Name=name;
        Type=type;
        DataType=datatype;
        next=NULL;
        num_of_param=-1;
        isdeclared=0;
        isdefined=0;
        offset=0;
        global=false;
    }
    string getDataType()
    {
        return DataType;
    }
    string setDataType(string datatype)
    {
        DataType=datatype;
    }
    string getName()
    {
        return Name;
    }
    string getType()
    {
        return Type;
    }
    ~SymbolInfo()
    {
        delete next;
        //cout<<"destructor of SymbolInfo called"<<endl;
    }

};
class ScopeTable
{
private:
    SymbolInfo **hashtable;
    int total_buckets;
    string id;
public:
    int deleted_child;
    ScopeTable *parentScope;
    ScopeTable(int n)
    {
        hashtable=new SymbolInfo*[n];
        total_buckets=n;
        for(int i=0; i<n; i++)
            hashtable[i]=NULL;
        deleted_child=0;
        parentScope=NULL;
        id="1";
    }
    string getID()
    {
        return id;
    }
    void setID(string temp)
    {
        id=temp;
    }
    int sdbmhash(string str)
    {
        unsigned long hash = 0;

        for(int i=0; i<str.size(); i++)
            hash =str[i] + (hash << 6) + (hash << 16)-hash;

        return hash%total_buckets;
    }
    bool Insert(string name,string type,string datatype)
    {
        int index=sdbmhash(name);
        SymbolInfo *curr=hashtable[index];
        SymbolInfo *prev;
        int pos=0;
        if (curr==NULL)
        {
            hashtable[index]=new SymbolInfo(name,type,datatype);
            //cout<<"Inserted in ScopeTable# "<<id<<" at position "<<index<<", "<<pos<<endl;
            if (id=="1")
            hashtable[index]->global=true;
            return true;
        }
        while(curr!=NULL)

        {
            if (curr->getName()==name)
            {
                //cout<<"<"<<name<<","<<type<<"> "<<"already exists in current ScopeTable"<<endl;
                return false;
            }
            prev=curr;
            curr=curr->next;
            pos++;
        }
        prev->next=new SymbolInfo(name,type,datatype);
        if (id=="1")
        prev->next->global=true;
        //cout<<"Inserted in ScopeTable# "<<id<<" at position "<<index<<", "<<pos<<endl;
        return true;

    }

    SymbolInfo* Look_up(string name)
    {
        int index=sdbmhash(name);
        SymbolInfo *curr=hashtable[index];
        int pos=0;
        while(curr!=NULL)

        {
            if (curr->getName()==name)
            {
                //cout<<"Found in ScopeTable# "<<id<<" at position "<<index<<", "<<pos<<endl;
                return curr;
            }
            curr=curr->next;
            pos++;
        }
        return curr;

    }

    bool Delete(string name)
    {
        int index=sdbmhash(name);
        SymbolInfo *curr=hashtable[index];
        SymbolInfo *prev;
        int pos=0;
        if (curr!=NULL && curr->getName()==name)
        {
            hashtable[index]=curr->next;
            //cout<<"Found in ScopeTable# "<<id<<" at position "<<index<<", "<<pos<<endl;
            curr->next=NULL;
            delete curr;
            //cout<<"Deleted Entry "<<index<<", "<<pos<<" from current ScopeTable"<<endl;
            return true;
        }
        while(curr!=NULL)

        {
            if (curr->getName()==name)
            {
                prev->next=curr->next;
                //cout<<"Found in ScopeTable# "<<id<<" at position "<<index<<", "<<pos<<endl;
                curr->next=NULL;
                delete curr;
                //cout<<"Deleted Entry "<<index<<", "<<pos<<" from current ScopeTable"<<endl;
                return true;

            }
            prev=curr;
            curr=curr->next;
            pos++;
        }
        //cout<<"Not found"<<endl;
        //cout<<name<<" not found"<<endl;
        return false;

    }
    string Print()
    {
        string temp;
        temp+=("ScopeTable # "+id+"\n");
        for(int i=0; i<total_buckets; i++)
        {
            string str;
            stringstream ss;
            ss<<i;
            ss>>str;
            SymbolInfo *curr=hashtable[i];
            if (curr==NULL)
                continue;
            temp+=str+" --> ";
            while(curr!=NULL)
            {
                temp+=("<"+curr->getName()+":"+curr->getType()+"> ");
                //cout<<"<"<<curr->getName()<<":"<<curr->getType()<<"> ";
                curr=curr->next;
            }
            temp+="\n";
            //cout<<endl;
        }
        return temp;
    }
    ~ScopeTable()
    {
        //cout<<"Destructor of ScopeTable called"<<endl;
        delete parentScope;
        for(int i=0; i<total_buckets; i++)
            delete hashtable[i];
        delete[] hashtable;
    }
};
class SymbolTable
{
private:
    ScopeTable *current;
    int total_buckets;
public:
    SymbolTable(int n)
    {
        current=new ScopeTable(n);
        current->parentScope=NULL;
        total_buckets=n;
    }
    void Enter_Scope()
    {
        ScopeTable *prev=current;
        current=new ScopeTable(total_buckets);
        current->parentScope=prev;
        if (current->parentScope!=NULL)
        {
            string str;
            stringstream ss;
            ss<<current->parentScope->deleted_child+1;
            ss>>str;
            current->setID(current->parentScope->getID()+"."+str);
        }
        //cout<<"New ScopeTable with id "<<current->getID()<<" created"<<endl;
    }
    void Exit_Scope()
    {
        ScopeTable *curr=current;
        if (current!=NULL)
        {
            current=current->parentScope;
            //cout<<"ScopeTable with id "<<curr->getID()<<" removed"<<endl;
            curr->parentScope=NULL;
            delete curr;
            if (current!=NULL)
                current->deleted_child+=1;
        }
        else
        {

        }
        // cout<<"No Current Scope"<<endl;
    }
    bool Insert(string name,string type,string datatype)
    {
        if (current!=NULL)
        {
            return current->Insert(name,type,datatype);
        }
        Enter_Scope();
        return current->Insert(name,type,datatype);
        //return false;
    }
    bool Remove(string name)
    {
        if (current!=NULL)
            return current->Delete(name);

        return false;
    }
    SymbolInfo* Look_up(string name)
    {
        ScopeTable *curr=current;
        SymbolInfo *obj=NULL;
        while(curr!=NULL)
        {
            obj=curr->Look_up(name);
            if (obj==NULL)
                curr=curr->parentScope;
            else
                break;
        }
        if (obj==NULL)
        {
            //cout<<"Not found"<<endl;
        }
        return obj;

    }
    string Print_Current_ScopeTable()
    {
        string temp="";
        if(current!=NULL)
            temp+=current->Print();
        else
        {
            temp+="No Current Scope\n";
        }
        return temp;

    }
    string Print_All_ScopeTable()
    {
        ScopeTable *curr=current;
        string temp="";
        while(curr!=NULL)
        {
            temp+=curr->Print();
            curr=curr->parentScope;
        }
        return temp;
    }
    ~SymbolTable()
    {
        //cout<<"Destructor of SymbolTable Called"<<endl;
        delete current;
    }
};
class complex_obj
{  public:
    string return_type;
    string DataType;
    int offset;
    vector<SymbolInfo*>*vec;
    complex_obj()
    {
        vec=new vector<SymbolInfo*>();
        return_type="void";
        DataType="void";
        offset=0;

    }
    string getDataType()
    {
        return DataType;
    }
};

/*int main()
{
    fstream file("1805009_input.txt");
    int n;
    file>>n;
    SymbolTable st(n);
    while(file)
    {
        string t;
        getline(file,t);
        stringstream ss(t);
        ss>>t;
        if (t=="I")
        {
            string name,type;
            ss>>name>>type;
            st.Insert(name,type);
        }
        else if (t=="L")
        {
            string name;
            ss>>name;
            st.Look_up(name);
        }
        else if (t=="D")
        {
            string name;
            ss>>name;
            st.Remove(name);
        }
        else if (t=="P")
        {
            string f;
            ss>>f;
            if (f=="C")
                st.Print_Current_ScopeTable();
            else if(f=="A")
                st.Print_All_ScopeTable();
        }
        else if (t=="S")
        {
            st.Enter_Scope();
        }
        else if (t=="E")
        {
            st.Exit_Scope();
        }
    }


}
*/



