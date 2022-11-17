%{
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include "symboltable.cpp"
#include "optimize.cpp"

    using namespace std;

    int yyparse(void);
    int yylex(void);
    extern FILE *yyin;
    FILE *fout,*errorout,*assemblyout;
    SymbolInfo temp("","");
    string temps;
    int flag=0;
    int ismain=0;
    int ismainreturn=0;
    extern int line_count;
    extern int err;
    extern int yylineno;

    SymbolTable st(30);
    vector<string>args_type;
    stack<string>labels;
    int offset;
    int label_no=0;
    void yyerror(char *s)
    {
        fprintf(fout,"Error at line %d: %s\n",line_count,s);
        fprintf(errorout,"Error at line %d: %s\n",line_count,s);
        err++;
        //write your code
    }
    string newLabel()
    {
        label_no++;
        stringstream ss;
        ss<<"L"<<label_no;
        return ss.str();
    }


%}

%union
{
    SymbolInfo* symbolinfo;
    complex_obj *obj;
}

%token<symbolinfo> PRINTLN ADDOP MULOP DECOP INCOP RELOP ASSIGNOP LOGICOP NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON IF FOR DO INT FLOAT VOID SWITCH DEFAULT ELSE WHILE BREAK CHAR DOUBLE RETURN CASE CONTINUE CONST_INT CONST_FLOAT CONST_CHAR ID STRING
%type<symbolinfo>type_specifier
%type<obj> statements program unit start declaration_list parameter_list var_declaration variable expression logic_expression rel_expression simple_expression term unary_expression factor argument_list arguments expression_statement statement compound_statement func_declaration func_definition
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%

start :
{
    fprintf(assemblyout,".model small\n.stack 100h\n.data\ncr equ 0Dh\nlf equ 0Ah\nnumber db \"00000$\"\n");
}
program
{
    fprintf(fout,"Line %d: start : program\n",line_count);
    fprintf(fout,"%s\n",st.Print_All_ScopeTable().c_str());
    fprintf(fout,"Total lines: %d\n",yylineno);
    fprintf(fout,"Total errors: %d\n",err);
    fprintf(fout,"\n");

    fprintf(assemblyout,"new_line proc\n\
    push ax\n\
    push dx\n\
    mov ah,2\n\
    mov dl,cr\n\
    int 21h\n\
    mov ah,2\n\
    mov dl,lf\n\
    int 21h\n\
    pop dx\n\
    pop ax\n\
    ret\n\
    new_line endp\n");
    fprintf(assemblyout,"print_output proc  ;print what is in ax\n\
    push ax\n\
    push bx\n\
    push cx\n\
    push dx\n\
    push si\n\
    lea si,number\n\
    mov bx,10\n\
    add si,4\n\
    cmp ax,0\n\
    jnge negate\n\
    print:\n\
    xor dx,dx\n\
    div bx\n\
    mov [si],dl\n\
    add [si],'0'\n\
    dec si\n\
    cmp ax,0\n\
    jne print\n\
    inc si\n\
    lea dx,si\n\
    mov ah,9\n\
    int 21h\n\
    pop si\n\
    pop dx\n\
    pop cx\n\
    pop bx\n\
    pop ax\n\
    ret\n\
    negate:\n\
    push ax\n\
    mov ah,2\n\
    mov dl,'-'\n\
    int 21h\n\
    pop ax\n\
    neg ax\n\
    jmp print\n\
    print_output endp\n");
    fprintf(assemblyout,"end main\n");

}
;

program :
program unit
{
    fprintf(fout,"Line %d: program : program unit\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
    }

    $$->vec->push_back(new SymbolInfo("\n","NEWLINE","NEWLINE"));
    fprintf(fout,"\n");
    for(int i=0; i<$2->vec->size(); i++)
    {
        $$->vec->push_back($2->vec->at(i));
        fprintf(fout,"%s",$2->vec->at(i)->getName().c_str());
    }


    fprintf(fout,"\n");

}
| unit
{
    fprintf(fout,"Line %d: program : unit\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
    }
    
    fprintf(fout,"\n");

}
;

unit :
var_declaration
{
    fprintf(fout,"Line %d: unit : var_declaration\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
    }


    fprintf(fout,"\n");


}
|func_declaration
{
    fprintf(fout,"Line %d: unit : func_declaration\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
    }


    fprintf(fout,"\n");
}
|func_definition
{
    fprintf(fout,"Line %d: unit : func_definition\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
    }


    fprintf(fout,"\n");


}
;
func_declaration :
type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
{
    if (!st.Insert($2->getName(),"ID",$1->getName()))
    {
        fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,$2->getName().c_str());
        fprintf(errorout,"Error at line %d: Multiple declaration of %s\n",line_count,$2->getName().c_str());
        err++;
    }
    SymbolInfo* obj=st.Look_up($2->getName());
    obj->num_of_param=0;
    obj->isdeclared=1;
    for(int i=0; i<$4->vec->size(); i++)
    {
        if ($4->vec->at(i)->getName()=="int" || $4->vec->at(i)->getName()=="float")
        {
            obj->parameter_list.push_back(new SymbolInfo($4->vec->at(i)->getName(),$4->vec->at(i)->getType(),$4->vec->at(i)->getName()));
            obj->num_of_param++;
        }

    }
    fprintf(fout,"Line %d: func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n",line_count);
    
    $$=new complex_obj();
    $$->vec->push_back($1);
    fprintf(fout,"%s",$1->getName().c_str());
    
    $$->vec->push_back(new SymbolInfo(" ","SPACE","SPACE"));
    fprintf(fout," ");
    
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());
    
    $$->vec->push_back($3);
    fprintf(fout,"%s",$3->getName().c_str());
   
    for(int i=0; i<$4->vec->size(); i++)
    {
        $$->vec->push_back($4->vec->at(i));
        fprintf(fout,"%s",$4->vec->at(i)->getName().c_str());
    }
    $$->vec->push_back($5);
    fprintf(fout,"%s",$5->getName().c_str());
    
    $$->vec->push_back($6);
    fprintf(fout,"%s",$6->getName().c_str());
    fprintf(fout,"\n");
    
    st.Enter_Scope();
    st.Exit_Scope();
    temp.parameter_list.clear();
}
| type_specifier ID LPAREN RPAREN SEMICOLON
{
    if (!st.Insert($2->getName(),"ID",$1->getName()))
    {
        fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,$2->getName().c_str());
        fprintf(errorout,"Error at line %d: Multiple declaration of %s\n",line_count,$2->getName().c_str());
        err++;
    }
    SymbolInfo* obj=st.Look_up($2->getName());
    obj->num_of_param=0;
    obj->isdeclared=1;
    $2->setDataType($1->getName());
    fprintf(fout,"Line %d: func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n",line_count);
    $$=new complex_obj();
    $$->vec->push_back($1);
    fprintf(fout,"%s",$1->getName().c_str());
    $$->vec->push_back(new SymbolInfo(" ","SPACE","SPACE"));
    fprintf(fout," ");
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());

    $$->vec->push_back($3);
    fprintf(fout,"%s",$3->getName().c_str());
    $$->vec->push_back($4);
    fprintf(fout,"%s",$4->getName().c_str());
    $$->vec->push_back($5);
    fprintf(fout,"%s",$5->getName().c_str());

    fprintf(fout,"\n");


    st.Enter_Scope();
    st.Exit_Scope();
}

;
func_definition :
type_specifier ID LPAREN parameter_list RPAREN
{   
	if (!st.Insert($2->getName(),"ID",$1->getName()))
    {
        SymbolInfo* obj=st.Look_up($2->getName());
        if (!obj->isdeclared || obj->isdefined)
        {
            fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,$2->getName().c_str());
            fprintf(errorout,"Error at line %d: Multiple declaration of %s\n",line_count,$2->getName().c_str());
            err++;
        }
    }

    SymbolInfo* obj=st.Look_up($2->getName());
    obj->isdefined=1;
    if (obj->isdeclared)
    {
        if (obj->getDataType()!=$1->getName())
        {
            fprintf(fout,"Error at line %d: Return type mismatch with function declaration in function %s\n",line_count,$2->getName().c_str());
            fprintf(errorout,"Error at line %d: Return type mismatch with function declaration in function %s\n",line_count,$2->getName().c_str());
            //err++;
        }

        int k=0;
        for(int i=0; i<$4->vec->size(); i++)
        {
            if ($4->vec->at(i)->getType()=="ID")
            {
                if (k>=obj->parameter_list.size())
                {
                    fprintf(fout,"Error at line %d: Total number of arguments mismatch with declaration in function %s\n",line_count,$2->getName().c_str());
                    fprintf(errorout,"Error at line %d: Total number of arguments mismatch with declaration in function %s\n",line_count,$2->getName().c_str());
                    err++;
                    break;
                }
                else if ($4->vec->at(i-2)->getName()!=obj->parameter_list[k]->getName())
                {
                    fprintf(fout,"Error at line %d: Type Mismatch\n",line_count);
                    fprintf(errorout,"Error at line %d: Type Mismatch\n",line_count);
                    err++;
                }
                k++;
            }

        }
        if (k<obj->parameter_list.size())
        {
            fprintf(fout,"Error at line %d: Total number of arguments mismatch with declaration in function %s\n",line_count,$2->getName().c_str());
            fprintf(errorout,"Error at line %d: Total number of arguments mismatch with declaration in function %s\n",line_count,$2->getName().c_str());
            err++;
        }
    }
    else
    {
        obj->num_of_param=0;
        obj->isdeclared=1;
        obj->isdefined=1;
        for(int i=0; i<$4->vec->size(); i++)
        {
            if ($4->vec->at(i)->getType()=="ID")
            {
                obj->parameter_list.push_back(new SymbolInfo($4->vec->at(i)->getName(),$4->vec->at(i)->getType(),$4->vec->at(i-2)->getName()));
                obj->num_of_param++;

            }

        }
    }
    fprintf(assemblyout,";");  //print statement
    fprintf(assemblyout,"%s",$1->getName().c_str());  //print statement
    fprintf(assemblyout," ");  //print statement
    fprintf(assemblyout,"%s",$2->getName().c_str());  //print statement
     fprintf(assemblyout,"%s",$3->getName().c_str());  //print statement
     for(int i=0; i<$4->vec->size(); i++)
    {
        fprintf(assemblyout,"%s",$4->vec->at(i)->getName().c_str());  //print statement
    }
    fprintf(assemblyout,"%s",$5->getName().c_str());  //print statement
    fprintf(assemblyout,"\n");  //print statement
    if (flag==0) {flag=1;fprintf(assemblyout,".code\n");}
    fprintf(assemblyout,"%s proc\npush bp\nmov bp,sp\n",$2->getName().c_str());
    int temp_int=(obj->num_of_param+1)*2;
    for(int i=2;temp_int>2;i+=2)
    {
        fprintf(assemblyout,"mov bx,[bp+%d]\n",temp_int);
        fprintf(assemblyout,"mov [bp-%d],bx\n",i);
        temp_int-=2;
    }
offset=0;

} compound_statement
{
    SymbolInfo* obj=st.Look_up($2->getName());
    if (obj->getDataType()!=$7->return_type)
    {
        fprintf(fout,"Error at line %d: Return type mismatch with function declaration\n",line_count);
        fprintf(errorout,"Error at line %d: Return type mismatch with function declaration\n",line_count);
        //err++;
    }
    fprintf(fout,"Line %d: func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n",line_count);
    $$=new complex_obj();
    $$->vec->push_back($1);

    fprintf(fout,"%s",$1->getName().c_str());
    $$->vec->push_back(new SymbolInfo(" ","SPACE","SPACE"));
    fprintf(fout," ");
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());


    $$->vec->push_back($3);
    fprintf(fout,"%s",$3->getName().c_str());
    for(int i=0; i<$4->vec->size(); i++)
    {
        $$->vec->push_back($4->vec->at(i));
        fprintf(fout,"%s",$4->vec->at(i)->getName().c_str());

    }
    $$->vec->push_back($5);
    fprintf(fout,"%s",$5->getName().c_str());
    for(int i=0; i<$7->vec->size(); i++)
    {
        $$->vec->push_back($7->vec->at(i));
        fprintf(fout,"%s",$7->vec->at(i)->getName().c_str());
    }

    fprintf(fout,"\n");
    if ($1->getName()=="void")
    {for(int i=0;i<offset;i+=2)
    {
        fprintf(assemblyout,"add sp,2\n");
    }
    fprintf(assemblyout,"pop bp\nret\n%s endp\n",$2->getName().c_str());}
     else
    {
        fprintf(assemblyout,"%s endp\n",$2->getName().c_str());
    }


}
| type_specifier ID LPAREN RPAREN
{
    if (!st.Insert($2->getName(),"ID",$1->getName()))
    {
        SymbolInfo* obj=st.Look_up($2->getName());
        if (!obj->isdeclared || obj->isdefined)
            {fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,$2->getName().c_str());
            fprintf(errorout,"Error at line %d: Multiple declaration of %s\n",line_count,$2->getName().c_str());
            }
    }

    SymbolInfo* obj=st.Look_up($2->getName());
    if (obj->isdeclared)
    {
        if (obj->getDataType()!=$1->getName() && $2->getName()!="main")
        {
            fprintf(fout,"Error at line %d: Return type mismatch with function declaration in function %s\n",line_count,$2->getName().c_str());
            fprintf(errorout,"Error at line %d: Return type mismatch with function declaration in function %s\n",line_count,$2->getName().c_str());
            //err++;
        }
        if (obj->parameter_list.size()>0)
        {
            fprintf(fout,"Error at line %d: Total number of arguments mismatch with declaration in function %s\n",line_count,$2->getName().c_str());
            fprintf(errorout,"Error at line %d: Total number of arguments mismatch with declaration in function %s\n",line_count,$2->getName().c_str());
            err++;
        }
    }

    obj->isdefined=1;
    obj->isdeclared=1;
    obj->num_of_param=0;
    fprintf(assemblyout,";"); //print statement
    fprintf(assemblyout,"%s ",$1->getName().c_str());  //print statement
    fprintf(assemblyout,"%s",$2->getName().c_str());  //print statement
    fprintf(assemblyout,"%s",$3->getName().c_str());  //print statement
    fprintf(assemblyout,"%s",$4->getName().c_str());  //print statement
    fprintf(assemblyout,"\n");  //print statement
    if (flag==0) {flag=1;fprintf(assemblyout,".code\n");}
    if ($2->getName()=="main")
    {
        fprintf(assemblyout,"main proc\nmov ax,@data\nmov ds,ax\nmov bp,sp\n");
        ismain=1;
    }
    else
    {
        fprintf(assemblyout,"%s proc\npush bp\nmov bp,sp\n",$2->getName().c_str());
    }
    int temp_int=(obj->num_of_param+1)*2;
    for(int i=2;temp_int>2;i+=2)
    {
        fprintf(assemblyout,"mov bx,[bp+%d]\n",temp_int);
        fprintf(assemblyout,"mov [bp-%d],bx\n",i);
        temp_int-=2;
    }
offset=0;

} compound_statement
{
    SymbolInfo* obj=st.Look_up($2->getName());
    if (obj->getDataType()!=$6->return_type && $2->getName()!="main")
    {
        fprintf(fout,"Error at line %d: Return type mismatch with function declaration\n",line_count);
        fprintf(errorout,"Error at line %d: Return type mismatch with function declaration\n",line_count);
        //err++;
    }
    fprintf(fout,"Line %d: func_definition : type_specifier ID LPAREN RPAREN compound_statement\n",line_count);
    $$=new complex_obj();
    $$->vec->push_back($1);
    fprintf(fout,"%s",$1->getName().c_str());

    $$->vec->push_back(new SymbolInfo(" ","SPACE","SPACE"));
    fprintf(fout," ");
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());


    $$->vec->push_back($3);
    fprintf(fout,"%s",$3->getName().c_str());
    $$->vec->push_back($4);
    fprintf(fout,"%s",$4->getName().c_str());
    for(int i=0; i<$6->vec->size(); i++)
    {
        $$->vec->push_back($6->vec->at(i));
        fprintf(fout,"%s",$6->vec->at(i)->getName().c_str());
    }

    fprintf(fout,"\n");
    
  
    
            if ($1->getName()=="void")
    {for(int i=0;i<offset;i+=2)
    {
        fprintf(assemblyout,"add sp,2\n");
    }
    fprintf(assemblyout,"pop bp\nret\n%s endp\n",$2->getName().c_str());}
    else if ($2->getName()!="main")
    {
        fprintf(assemblyout,"%s endp\n",$2->getName().c_str());
    }
    else if ($2->getName()=="main" && ismainreturn==0)
    {
        fprintf(assemblyout,"mov ah,4Ch\nint 21h\nmain endp\n");
    }
    



}


;


parameter_list  :
parameter_list COMMA type_specifier ID
{
    for(int i=0; i<temp.parameter_list.size(); i++)
    {
        if (temp.parameter_list[i]->getName()==$4->getName())
        {
            fprintf(fout,"Error at line %d: Multiple declaration of %s in parameter\n",line_count,$4->getName().c_str());
            fprintf(errorout,"Error at line %d: Multiple declaration of %s in parameter\n",line_count,$4->getName().c_str());
            err++;
        }

    }
    temp.parameter_list.push_back($3);
    temp.parameter_list.push_back($4);
    if ($3->getName()=="void")
    {
        fprintf(fout,"Error at line %d: Variable type cannot be void\n",line_count);
        fprintf(errorout,"Error at line %d: Variable type cannot be void\n",line_count);
        err++;
    }
    fprintf(fout,"Line %d: parameter_list  : parameter_list COMMA type_specifier ID\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
    }
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());
    $$->vec->push_back($3);
    fprintf(fout,"%s ",$3->getName().c_str());
    $$->vec->push_back(new SymbolInfo(" ","SPACE","SPACE"));

    $$->vec->push_back($4);
    fprintf(fout,"%s",$4->getName().c_str());


    fprintf(fout,"\n");
    


}
| parameter_list COMMA type_specifier
{
    if ($3->getName()=="void")
    {
        fprintf(fout,"Error at line %d: Variable type cannot be void\n",line_count);
        fprintf(errorout,"Error at line %d: Variable type cannot be void\n",line_count);
        err++;
    }
    fprintf(fout,"Line %d: parameter_list  : parameter_list COMMA type_specifier\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
    }
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());
    $$->vec->push_back($3);
    fprintf(fout,"%s",$3->getName().c_str());

    fprintf(fout,"\n");
}
| type_specifier ID
{
    for(int i=0; i<temp.parameter_list.size(); i++)
    {
        if (temp.parameter_list[i]->getName()==$2->getName())
        {
            fprintf(fout,"Error at line %d: Multiple declaration of %s in parameter\n",line_count,$2->getName().c_str());
            fprintf(errorout,"Error at line %d: Multiple declaration of %s in parameter\n",line_count,$2->getName().c_str());
            err++;
        }

    }
    if ($1->getName()=="void")
    {
        fprintf(fout,"Error at line %d: Variable type cannot be void\n",line_count);
        fprintf(errorout,"Error at line %d: Variable type cannot be void\n",line_count);
        err++;
    }
    fprintf(fout,"Line %d: parameter_list  : type_specifier ID\n",line_count);
    $$=new complex_obj();
    $$->vec->push_back($1);
    fprintf(fout,"%s ",$1->getName().c_str());
    $$->vec->push_back(new SymbolInfo(" ","SPACE","SPACE"));
    temp.parameter_list.push_back($1);
    temp.parameter_list.push_back($2);
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());

    fprintf(fout,"\n");


}
| type_specifier
{
    if ($1->getName()=="void")
    {
        fprintf(fout,"Error at line %d: Variable type cannot be void\n",line_count);
        fprintf(errorout,"Error at line %d: Variable type cannot be void\n",line_count);
        err++;
    }
    fprintf(fout,"Line %d: parameter_list  : type_specifier\n",line_count);
    $$=new complex_obj();
    $$->vec->push_back($1);
    fprintf(fout,"%s",$1->getName().c_str());

    fprintf(fout,"\n");

}
| parameter_list error
{

}
;


compound_statement :
LCURL
{

    st.Enter_Scope();
    for(int i=0; i<temp.parameter_list.size(); i++)
    {
        if (temp.parameter_list[i]->getType()=="ID" && temp.parameter_list[i-1]->getName()!="void")
        {
            st.Insert(temp.parameter_list[i]->getName(),"ID",temp.parameter_list[i-1]->getName());
            SymbolInfo* element=st.Look_up(temp.parameter_list[i]->getName());
            offset+=2;
            fprintf(assemblyout,"sub sp,2\n");
            element->offset=offset;
            //fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,temp.parameter_list[i]->getName().c_str());

        }
    }
	temp.parameter_list.clear();

} statements RCURL
{
    fprintf(fout,"Line %d: compound_statement : LCURL statements RCURL\n",line_count);
    $$=new complex_obj();
    $$->vec->push_back($1);
    fprintf(fout,"%s ",$1->getName().c_str());
    $$->vec->push_back(new SymbolInfo("\n","NEWLINE"));
    fprintf(fout,"\n");

    for(int i=0; i<$3->vec->size(); i++)
    {
        $$->vec->push_back($3->vec->at(i));
        fprintf(fout,"%s",$3->vec->at(i)->getName().c_str());

    }
    $$->vec->push_back(new SymbolInfo("\n","NEWLINE"));
    fprintf(fout,"\n");
    $$->vec->push_back($4);
    fprintf(fout,"%s",$4->getName().c_str());

    fprintf(fout,"\n");
    fprintf(fout,"%s\n",st.Print_All_ScopeTable().c_str());
    st.Exit_Scope();


    $$->return_type=$3->return_type;
  
}
| LCURL RCURL
{
	fprintf(fout,"Line %d: compound_statement : LCURL RCURL\n",line_count);
    st.Enter_Scope();
    for(int i=0; i<temp.parameter_list.size(); i++)
    {
        if (temp.parameter_list[i]->getType()=="ID" && temp.parameter_list[i-1]->getName()!="void")
        {
            st.Insert(temp.parameter_list[i]->getName(),"ID",temp.parameter_list[i-1]->getName());
            //fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,temp.parameter_list[i]->getName().c_str());
        }
    }
    $$=new complex_obj();
    $$->vec->push_back($1);
    fprintf(fout,"%s ",$1->getName().c_str());
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());
    fprintf(fout,"\n");
    temp.parameter_list.clear();
    fprintf(fout,"%s\n",st.Print_All_ScopeTable().c_str());
    st.Exit_Scope();

}
;

var_declaration :
type_specifier declaration_list SEMICOLON
{

    fprintf(fout,"Line %d: var_declaration : type_specifier declaration_list SEMICOLON\n",line_count);
    fprintf(assemblyout,";"); //print statement
    if ($1->getDataType()=="void")
    {
        fprintf(fout,"Error at line %d: Variable type cannot be void\n",line_count);
        fprintf(errorout,"Error at line %d: Variable type cannot be void\n",line_count);
        err++;
    }
    $$=new complex_obj();
    $$->vec->push_back($1);
    fprintf(fout,"%s ",$1->getName().c_str());
    fprintf(assemblyout,"%s ",$1->getName().c_str()); //print statement

    $$->vec->push_back(new SymbolInfo(" ","SPACE","SPACE"));
    for(int i=0; i<$2->vec->size(); i++)
    {
        $$->vec->push_back($2->vec->at(i));
        fprintf(fout,"%s",$2->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",$2->vec->at(i)->getName().c_str()); //print statement

        if ($2->vec->at(i)->getType()=="ID")
        {
            //st.Insert($2->vec->at(i)->getName(),"ID",$1->getName());
            SymbolInfo* element=st.Look_up($2->vec->at(i)->getName());
            if ($1->getDataType()=="void")
                st.Remove($2->vec->at(i)->getName());
            if (element!=NULL && element->getDataType()=="array")
            {
                element->setDataType($1->getName()+"_array");
            }
            else if (element!=NULL && element->getDataType()=="ID")
                element->setDataType($1->getName());
        }

    }
    $$->vec->push_back($3);
    fprintf(fout,"%s",$3->getName().c_str());
    fprintf(assemblyout,"%s",$3->getName().c_str()); //print statement
    
    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement


}

;

type_specifier	:
INT
{
    fprintf(fout,"Line %d: type_specifier : INT\n",line_count);
    fprintf(fout,"%s \n",$1->getName().c_str());
}
| FLOAT
{
    fprintf(fout,"Line %d: type_specifier : FLOAT\n",line_count);
    fprintf(fout,"%s \n",$1->getName().c_str());
}
| VOID
{
    fprintf(fout,"Line %d: type_specifier : VOID\n",line_count);
    fprintf(fout,"%s \n",$1->getName().c_str());
}
;

declaration_list :
declaration_list COMMA ID
{
    fprintf(fout,"Line %d: declaration_list : declaration_list COMMA ID\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
    }

    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());
    if (!st.Insert($3->getName(),"ID","ID"))
    {
        fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,$3->getName().c_str());
        fprintf(errorout,"Error at line %d: Multiple declaration of %s\n",line_count,$3->getName().c_str());
        err++;
    }
    
    $$->vec->push_back($3);
    offset+=2;
    SymbolInfo* element=st.Look_up($3->getName());
    element->offset=offset;
    fprintf(fout,"%s",$3->getName().c_str());

    fprintf(fout,"\n");
    if (element->global==true)
    fprintf(assemblyout,"%s dw ?\n",element->getName().c_str());
    else
    fprintf(assemblyout,"sub sp,2\n");


}

| declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
{
    if (!st.Insert($3->getName(),"ID","array"))
    {
        fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,$3->getName().c_str());
        fprintf(errorout,"Error at line %d: Multiple declaration of %s\n",line_count,$3->getName().c_str());
        err++;
    }
    fprintf(fout,"Line %d: declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",($1->vec->at(i)->getName()).c_str());
    }

    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());


    $$->vec->push_back($3);
    fprintf(fout,"%s",$3->getName().c_str());

    $$->vec->push_back($4);
    fprintf(fout,"%s",$4->getName().c_str());
    $$->vec->push_back($5);
    fprintf(fout,"%s",$5->getName().c_str());
    $$->vec->push_back($6);
    fprintf(fout,"%s",$6->getName().c_str());
    fprintf(fout,"\n");
    SymbolInfo* element=st.Look_up($3->getName());
    offset+=2;
    element->offset=offset;
    if (element->global==true)
    fprintf(assemblyout,"%s dw %s dup (?)\n",$3->getName().c_str(),$5->getName().c_str());
    else
    fprintf(assemblyout,"push ax\nmov ax,2\nmov bx,%s\nmul bx\nsub sp,ax\npop ax\n",$5->getName().c_str());
    stringstream ss;
    int temp_int;
    ss<<$5->getName();
    ss>>temp_int;
    offset+=(2*temp_int-2);
}
| ID
{
    if (!st.Insert($1->getName(),"ID","ID"))
    {
        fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,$1->getName().c_str());
        fprintf(errorout,"Error at line %d: Multiple declaration of %s\n",line_count,$1->getName().c_str());
        err++;
    }
    fprintf(fout,"Line %d: declaration_list: ID\n",line_count);
    $$=new complex_obj();
    $$->vec->push_back($1);
    fprintf(fout,"%s",$1->getName().c_str());
    fprintf(fout,"\n");
    SymbolInfo* element=st.Look_up($1->getName());
    offset+=2;
    element->offset=offset;
    if (element->global==true)
    fprintf(assemblyout,"%s dw ?\n",element->getName().c_str());
    else
    fprintf(assemblyout,"sub sp,2\n");
}

| ID LTHIRD CONST_INT RTHIRD
{
    if (!st.Insert($1->getName(),"ID","array"))
    {
        fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,$1->getName().c_str());
        fprintf(errorout,"Error at line %d: Multiple declaration of %s\n",line_count,$1->getName().c_str());
        err++;
    }

    fprintf(fout,"Line %d: declaration_list: ID LTHIRD CONST_INT RTHIRD\n",line_count);
    $$=new complex_obj();
    $$->vec->push_back($1);
    fprintf(fout,"%s",$1->getName().c_str());
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());
    $$->vec->push_back($3);
    fprintf(fout,"%s",$3->getName().c_str());
    $$->vec->push_back($4);
    fprintf(fout,"%s",$4->getName().c_str());
    fprintf(fout,"\n");
    SymbolInfo* element=st.Look_up($1->getName());
    offset+=2;
    element->offset=offset;
    if (element->global==true)
    fprintf(assemblyout,"%s dw %s dup (?)\n",$1->getName().c_str(),$3->getName().c_str());
    else
    fprintf(assemblyout,"push ax\nmov ax,2\nmov bx,%s\nmul bx\nsub sp,ax\npop ax\n",$3->getName().c_str());
    stringstream ss;
    int temp_int;
    ss<<$3->getName();
    ss>>temp_int;
    offset+=(2*temp_int-2);
}
| declaration_list COMMA ID LTHIRD error RTHIRD
{   if (!st.Insert($3->getName(),"ID","ID"))
    {
        fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,$3->getName().c_str());
        fprintf(errorout,"Error at line %d: Multiple declaration of %s\n",line_count,$3->getName().c_str());
        err++;
    }
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",($1->vec->at(i)->getName()).c_str());
    }

    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());


    $$->vec->push_back($3);
    fprintf(fout,"%s",$3->getName().c_str());
    fprintf(fout,"\n");

}
| ID LTHIRD error RTHIRD
{
    if (!st.Insert($1->getName(),"ID","ID"))
    {
        fprintf(fout,"Error at line %d: Multiple declaration of %s\n",line_count,$1->getName().c_str());
        fprintf(errorout,"Error at line %d: Multiple declaration of %s\n",line_count,$1->getName().c_str());
        err++;
    }
    $$=new complex_obj();
    $$->vec->push_back($1);
    fprintf(fout,"%s",$1->getName().c_str());
    fprintf(fout,"\n");
}
|declaration_list error
{

}
;

statements :
statement
{
    fprintf(fout,"Line %d: statements : statement\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",($1->vec->at(i)->getName()).c_str());
    }

    fprintf(fout,"\n");
    $$->return_type=$1->return_type;
}
| statements statement
{
    fprintf(fout,"Line %d: statements : statements statement\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",($1->vec->at(i)->getName()).c_str());
    }
    $$->vec->push_back(new SymbolInfo("\n","NEWLINE","NEWLINE"));
    fprintf(fout,"\n");
    for(int i=0; i<$2->vec->size(); i++)
    {
        $$->vec->push_back($2->vec->at(i));
        fprintf(fout,"%s",($2->vec->at(i)->getName()).c_str());
    }
    $$->return_type=$2->return_type;

    fprintf(fout,"\n");
}
|statements error
{

}
;
statement :
var_declaration
{
    fprintf(fout,"Line %d: statement : var_declaration\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");

}
| expression_statement
{
    fprintf(fout,"Line %d: statement : expression_statement\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");
    $$->return_type=$1->return_type;

}
| compound_statement
{
    fprintf(fout,"Line %d: statement : compound_statement\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");
    $$->return_type=$1->return_type;

}
| FOR LPAREN expression_statement {labels.push(newLabel()); fprintf(assemblyout,"%s:\n",labels.top().c_str());} expression_statement 
{fprintf(assemblyout,"cmp bx,0\nje end_%s\n",labels.top().c_str());
labels.push(newLabel());fprintf(assemblyout,"jmp end_%s\n%s:\n",labels.top().c_str(),labels.top().c_str());
} expression  RPAREN {temps=labels.top(); labels.pop(); fprintf(assemblyout,"jmp %s\nend_%s:\n",labels.top().c_str(),temps.c_str()); labels.push(temps);} statement
{
    fprintf(fout,"Line %d: statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n",line_count);
    fprintf(assemblyout,";"); //print statement
    $$=new complex_obj();
    $$->vec->push_back($1);
    fprintf(fout,"%s",$1->getName().c_str());
    fprintf(assemblyout,"%s",$1->getName().c_str()); //print statement
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());
     fprintf(assemblyout,"%s",$2->getName().c_str()); //print statement

    for(int i=0; i<$3->vec->size(); i++)
    {
        $$->vec->push_back($3->vec->at(i));
        fprintf(fout,"%s",$3->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",$3->vec->at(i)->getName().c_str()); //print statement
    }

    for(int i=0; i<$5->vec->size(); i++)
    {
        $$->vec->push_back($5->vec->at(i));
        fprintf(fout,"%s",$5->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",$5->vec->at(i)->getName().c_str()); //print statement
    }

    for(int i=0; i<$7->vec->size(); i++)
    {
        $$->vec->push_back($7->vec->at(i));
        fprintf(fout,"%s",$7->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",$7->vec->at(i)->getName().c_str()); //print statement
    }

    $$->vec->push_back($8);
    fprintf(fout,"%s",$8->getName().c_str());
    fprintf(assemblyout,"%s",$8->getName().c_str()); //print statement

    for(int i=0; i<$10->vec->size(); i++)
    {
        $$->vec->push_back($10->vec->at(i));
        fprintf(fout,"%s",$10->vec->at(i)->getName().c_str());
    }

    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    
    fprintf(assemblyout,"jmp %s\n",labels.top().c_str());
    labels.pop();
    fprintf(assemblyout,"end_%s:\n",labels.top().c_str());
    labels.pop();

}
|IF LPAREN expression RPAREN X statement %prec LOWER_THAN_ELSE
{
    fprintf(fout,"Line %d: statement : IF LPAREN expression RPAREN statement\n",line_count);
    fprintf(assemblyout,";"); //print statement
    $$=new complex_obj();
    $$->vec->push_back($1);
    fprintf(fout,"%s",$1->getName().c_str());
    fprintf(assemblyout,"%s",$1->getName().c_str()); //print statement
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());
    fprintf(assemblyout,"%s",$2->getName().c_str()); //print statement
    for(int i=0; i<$3->vec->size(); i++)
    {
        $$->vec->push_back($3->vec->at(i));
        fprintf(fout,"%s",$3->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",$3->vec->at(i)->getName().c_str()); //print statement
    }


    $$->vec->push_back($4);
    fprintf(fout,"%s",$4->getName().c_str());
    fprintf(assemblyout,"%s",$4->getName().c_str()); //print statement

    for(int i=0; i<$6->vec->size(); i++)
    {
        $$->vec->push_back($6->vec->at(i));
        fprintf(fout,"%s",$6->vec->at(i)->getName().c_str());
    }

    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement

    fprintf(assemblyout,"%s:\n",labels.top().c_str());
    labels.pop();


}
| IF LPAREN expression RPAREN X statement ELSE {
    fprintf(assemblyout,"jmp end_%s\n%s:\n",labels.top().c_str(),labels.top().c_str());
    fprintf(assemblyout,";"); //print statement
    fprintf(assemblyout,"%s",$1->getName().c_str()); //print statement
    fprintf(assemblyout,"%s",$2->getName().c_str()); //print statement
    for(int i=0; i<$3->vec->size(); i++)
    {
        fprintf(assemblyout,"%s",$3->vec->at(i)->getName().c_str()); //print statement
    }
    fprintf(assemblyout,"%s",$4->getName().c_str()); //print statement
    fprintf(assemblyout,"\n");

    } statement
{
    fprintf(fout,"Line %d: statement : IF LPAREN expression RPAREN statement ELSE statement\n",line_count);
    fprintf(assemblyout,";"); //print statement
    $$=new complex_obj();
    $$->vec->push_back($1);
    fprintf(fout,"%s",$1->getName().c_str());
    fprintf(assemblyout,"%s",$1->getName().c_str()); //print statement
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());
    fprintf(assemblyout,"%s",$2->getName().c_str()); //print statement
    for(int i=0; i<$3->vec->size(); i++)
    {
        $$->vec->push_back($3->vec->at(i));
        fprintf(fout,"%s",$3->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",$3->vec->at(i)->getName().c_str()); //print statement
    }


    $$->vec->push_back($4);
    fprintf(fout,"%s",$4->getName().c_str());
    fprintf(assemblyout,"%s",$4->getName().c_str()); //print statement

    for(int i=0; i<$6->vec->size(); i++)
    {
        $$->vec->push_back($6->vec->at(i));
        fprintf(fout,"%s",$6->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");
    $$->vec->push_back(new SymbolInfo("\n","NEWLINE","NEWLINE"));
    $$->vec->push_back($7);
    fprintf(fout,"%s",$7->getName().c_str());
    fprintf(assemblyout,"%s",$7->getName().c_str()); //print statement
    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    $$->vec->push_back(new SymbolInfo("\n","NEWLINE","NEWLINE"));
    for(int i=0; i<$9->vec->size(); i++)
    {
        $$->vec->push_back($9->vec->at(i));
        fprintf(fout,"%s",$9->vec->at(i)->getName().c_str());
    }

    fprintf(fout,"\n");
    fprintf(assemblyout,"end_%s:\n",labels.top().c_str());
    labels.pop();
    

}
| WHILE LPAREN {labels.push(newLabel()); fprintf(assemblyout,"%s:\n",labels.top().c_str());} expression 
{fprintf(assemblyout,"cmp bx,0\nje end_%s\n",labels.top().c_str());
fprintf(assemblyout,";"); //print statement
fprintf(assemblyout,"%s",$1->getName().c_str()); //print statement
fprintf(assemblyout,"%s",$2->getName().c_str()); //print statement
for(int i=0; i<$4->vec->size(); i++)
    {
        fprintf(assemblyout,"%s",$4->vec->at(i)->getName().c_str());
    }
    fprintf(assemblyout,")\n"); //print statement
} RPAREN statement
{
    fprintf(fout,"Line %d: statement : WHILE LPAREN expression RPAREN statement\n",line_count);
    $$=new complex_obj();
    $$->vec->push_back($1);
    fprintf(fout,"%s",$1->getName().c_str());
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());

    for(int i=0; i<$4->vec->size(); i++)
    {
        $$->vec->push_back($4->vec->at(i));
        fprintf(fout,"%s",$4->vec->at(i)->getName().c_str());
    }


    $$->vec->push_back($6);
    fprintf(fout,"%s",$6->getName().c_str());

    for(int i=0; i<$7->vec->size(); i++)
    {
        $$->vec->push_back($7->vec->at(i));
        fprintf(fout,"%s",$7->vec->at(i)->getName().c_str());
    }

    fprintf(fout,"\n");

    fprintf(assemblyout,"jmp %s\nend_%s:\n",labels.top().c_str(),labels.top().c_str());
    labels.pop();


}
| PRINTLN LPAREN ID RPAREN SEMICOLON
{
    fprintf(fout,"Line %d: statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n",line_count);
    fprintf(assemblyout,";"); //print statement;
    SymbolInfo* obj=st.Look_up($3->getName());
    if (obj==NULL)
    {
        fprintf(fout,"Error at line %d: Undeclared variable %s\n",line_count,$3->getName().c_str());
        fprintf(errorout,"Error at line %d: Undeclared variable %s\n",line_count,$3->getName().c_str());
        err++;
    }
    else if(obj->getDataType().find("array")!=string::npos)
    {
        fprintf(fout,"Error at line %d: Type Mismatch,  %s is an array\n",line_count,$3->getName().c_str());
        fprintf(errorout,"Error at line %d: Type Mismatch,  %s is an array\n",line_count,$3->getName().c_str());
        err++;
    }
    $$=new complex_obj();
    $$->vec->push_back($1);
    fprintf(fout,"%s",$1->getName().c_str());
    fprintf(assemblyout,"%s",$1->getName().c_str()); //print statement;
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());
    fprintf(assemblyout,"%s",$2->getName().c_str()); //print statement;

    $$->vec->push_back($3);
    fprintf(fout,"%s",$3->getName().c_str());
    fprintf(assemblyout,"%s",$3->getName().c_str()); //print statement;

    $$->vec->push_back($4);
    fprintf(fout,"%s",$4->getName().c_str());
    fprintf(assemblyout,"%s",$4->getName().c_str()); //print statement;
    $$->vec->push_back($5);
    fprintf(fout,"%s",$5->getName().c_str());
    fprintf(assemblyout,"%s",$5->getName().c_str()); //print statement;
    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement;
    if (obj->global==true)
    fprintf(assemblyout,"mov ax,%s\ncall print_output\ncall new_line\n",obj->getName().c_str());
    else

    fprintf(assemblyout,"mov ax,[bp-%d]\ncall print_output\ncall new_line\n",obj->offset);


}
| RETURN expression SEMICOLON
{
    fprintf(fout,"Line %d: statement : RETURN expression SEMICOLON\n",line_count);
    fprintf(assemblyout,";"); //print statement
    $$=new complex_obj();
    $$->vec->push_back($1);
    fprintf(fout,"%s",$1->getName().c_str());
    fprintf(assemblyout,"%s",$1->getName().c_str()); //print statement
    $$->vec->push_back(new SymbolInfo(" ","SPACE","SPACE"));
    fprintf(fout," ");
    fprintf(assemblyout," "); //print statement
    for(int i=0; i<$2->vec->size(); i++)
    {
        $$->vec->push_back($2->vec->at(i));
        fprintf(fout,"%s",$2->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",$2->vec->at(i)->getName().c_str()); //print statement
    }


    $$->vec->push_back($3);
    fprintf(fout,"%s",$3->getName().c_str());
    fprintf(assemblyout,"%s",$3->getName().c_str()); //print statement


    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    $$->return_type=$2->return_type;
    if (ismain==0)
   {for(int i=0;i<offset;i+=2)
    {
        fprintf(assemblyout,"add sp,2\n");
    }
    fprintf(assemblyout,"pop bp\nret\n");}
    else
    {   
    
        fprintf(assemblyout,"mov ah,4Ch\nint 21h\nmain endp\n");
        ismainreturn=1;
    

    }
}

| RETURN error
{
	$$=new complex_obj();
}
;
X :
{labels.push(newLabel());
    fprintf(assemblyout,"cmp bx,0\nje %s\n",labels.top().c_str());

}

expression_statement :
SEMICOLON
{
    fprintf(fout,"Line %d: expression_statement : SEMICOLON\n",line_count);
    $$=new complex_obj();
    $$->vec->push_back($1);
    fprintf(fout,"%s",$1->getName().c_str());
    fprintf(fout,"\n");

}
| expression SEMICOLON
{
    fprintf(fout,"Line %d: expression_statement : expression SEMICOLON\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
    }
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());
    fprintf(fout,"\n");
}


;

variable :
ID
{
    fprintf(fout,"Line %d: variable : ID\n",line_count);
    $$=new complex_obj();
    SymbolInfo* element=st.Look_up($1->getName());
    if (element==NULL)
    {
        fprintf(fout,"Error at line %d: Undeclared variable %s\n",line_count,$1->getName().c_str());
        fprintf(errorout,"Error at line %d: Undeclared variable %s\n",line_count,$1->getName().c_str());
        err++;
        $$->return_type="int";
    }
    else
    {
        if(element->getDataType().size()>=6 && element->getDataType().substr(element->getDataType().size()-6,element->getDataType().size())=="_array")
        {
            fprintf(fout,"Error at line %d: Type Mismatch,  %s is an array\n",line_count,$1->getName().c_str());
            fprintf(errorout,"Error at line %d: Type Mismatch,  %s is an array\n",line_count,$1->getName().c_str());
            err++;
            $$->return_type=element->getDataType();
            $$->offset=element->offset;
        }
        else
            {$$->return_type=element->getDataType();
            $$->offset=element->offset;
            }
    }
   $1->global=element->global;
    $$->vec->push_back($1);
    fprintf(fout,"%s",$1->getName().c_str());
    fprintf(fout,"\n");
    


}
| ID LTHIRD expression RTHIRD
{
    fprintf(fout,"Line %d: variable : ID LTHIRD expression RTHIRD\n",line_count);
    $$=new complex_obj();
    SymbolInfo* element=st.Look_up($1->getName());
    if (element==NULL)
    {
        fprintf(fout,"Error at line %d: Undeclared variable %s\n",line_count,$1->getName().c_str());
        fprintf(errorout,"Error at line %d: Undeclared variable %s\n",line_count,$1->getName().c_str());
        $$->return_type="int";
        err++;
    }
    else
    {
        if (element->getDataType().find("array")==string::npos)
        {
            fprintf(fout,"Error at line %d:  %s is not an array\n",line_count,$1->getName().c_str());
            fprintf(errorout,"Error at line %d:  %s is not an array\n",line_count,$1->getName().c_str());
            err++;
            $$->return_type=element->getDataType();
            $$->offset=element->offset;
        }
        else
        {
            $$->return_type=element->getDataType().substr(0,element->getDataType().size()-6);
            $$->DataType=element->getDataType();
            $$->offset=element->offset;
        }
    }

    if ($3->return_type!="int")
    {
        fprintf(fout,"Error at line %d: Expression inside third brackets not an integer\n",line_count);
        fprintf(errorout,"Error at line %d: Expression inside third brackets not an integer\n",line_count);
        err++;
    }
    

    $$->vec->push_back($1);
    fprintf(fout,"%s",$1->getName().c_str());
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());
    for(int i=0; i<$3->vec->size(); i++)
    {
        $$->vec->push_back($3->vec->at(i));
        fprintf(fout,"%s",$3->vec->at(i)->getName().c_str());
    }
    $$->vec->push_back($4);
    fprintf(fout,"%s",$4->getName().c_str());
    fprintf(fout,"\n");
    $1->global=element->global;
    if (element->global==true)
    fprintf(assemblyout,"push ax\nmov ax,2\nmul bx\n");
    else
    fprintf(assemblyout,"push ax\nmov ax,2\nmul bx\nadd ax,%d\n",element->offset);
    
    



}
| ID LTHIRD error RTHIRD
{
	$$=new complex_obj();
	$$->vec->push_back($1);
} 
;

expression :
logic_expression
{
    fprintf(fout,"Line %d: expression : logic_expression\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");
    $$->return_type=$1->return_type;


}
| variable ASSIGNOP logic_expression
{
    fprintf(fout,"Line %d: expression : variable ASSIGNOP logic_expression\n",line_count);
    fprintf(assemblyout,";"); //print statement
    $$=new complex_obj();
    if ($1->return_type!=$3->return_type)
    {
        if ($1->return_type=="float" && $3->return_type=="int") ;
        else if ($3->return_type=="void")
        {
            fprintf(fout,"Error at line %d: Void function used in expression\n",line_count);
            fprintf(errorout,"Error at line %d: Void function used in expression\n",line_count);
            err++;
        }
        else if($1->return_type.find("array")==string::npos && $3->return_type.find("array")==string::npos)
        {
            fprintf(fout,"Error at line %d: Type Mismatch\n",line_count);
            fprintf(errorout,"Error at line %d: Type Mismatch\n",line_count);
            err++;
        }

    }
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",$1->vec->at(i)->getName().c_str()); //print statement
    }
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());
    fprintf(assemblyout,"%s",$2->getName().c_str()); //print statement
    for(int i=0; i<$3->vec->size(); i++)
    {
        $$->vec->push_back($3->vec->at(i));
        fprintf(fout,"%s",$3->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",$3->vec->at(i)->getName().c_str()); //print statement
    }
    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    $$->return_type=$1->return_type;
    if ($1->getDataType().find("array")==string::npos)
    {
        if ($1->vec->at(0)->global==true)
    {fprintf(assemblyout,"mov %s,bx\n",$1->vec->at(0)->getName().c_str());
    
    }
    else
    fprintf(assemblyout,"mov [bp-%d],bx\n",$1->offset);}
    else
    {
        if ($1->vec->at(0)->global==true)
        fprintf(assemblyout,"push si\nmov si,ax\nmov [%s+si],bx\npop si\npop ax\n",$1->vec->at(0)->getName().c_str());
        else
fprintf(assemblyout,"sub bp,ax\nmov [bp],bx\nadd bp,ax\npop ax\n");
    }
}
;

logic_expression :
rel_expression
{
    fprintf(fout,"Line %d: logic_expression : rel_expression\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");
    $$->return_type=$1->return_type;

}
| rel_expression  LOGICOP {
if ($2->getName()=="||")
{labels.push(newLabel());
fprintf(assemblyout,"cmp bx,0\njne end_%s\n%s:\n",labels.top().c_str(),labels.top().c_str());
}
else if ($2->getName()=="&&")
{labels.push(newLabel());
fprintf(assemblyout,"cmp bx,0\nje end_%s\n%s:\n",labels.top().c_str(),labels.top().c_str());
}
} rel_expression
{
    fprintf(fout,"Line %d: logic_expression : rel_expression LOGICOP rel_expression\n",line_count);
    fprintf(assemblyout,";"); //print statement
    if ($1->return_type=="void" || $4->return_type=="void")
    {
        fprintf(fout,"Error at line %d: Void function used in expression\n",line_count);
        fprintf(errorout,"Error at line %d: Void function used in expression\n",line_count);
        err++;
    }
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",$1->vec->at(i)->getName().c_str()); //print statement
    }
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());
    fprintf(assemblyout,"%s",$2->getName().c_str()); //print statement
    for(int i=0; i<$4->vec->size(); i++)
    {
        $$->vec->push_back($4->vec->at(i));
        fprintf(fout,"%s",$4->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",$4->vec->at(i)->getName().c_str()); //print statement
    }

    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    $$->return_type="int";

    fprintf(assemblyout,"end_%s:\n",labels.top().c_str());
    labels.pop();

}
;

rel_expression	:
simple_expression
{
    fprintf(fout,"Line %d: rel_expression	: simple_expression\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
    }

    fprintf(fout,"\n");
    $$->return_type=$1->return_type;

}
| simple_expression RELOP {fprintf(assemblyout,"push ax\nmov ax,bx\n");} simple_expression
{
    fprintf(fout,"Line %d: rel_expression	: simple_expression RELOP simple_expression\n",line_count);
    fprintf(assemblyout,";"); //print statement
    if ($1->return_type=="void" || $4->return_type=="void")
    {
        fprintf(fout,"Error at line %d: Void function used in expression\n",line_count);
        fprintf(errorout,"Error at line %d: Void function used in expression\n",line_count);
        err++;
    }
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",$1->vec->at(i)->getName().c_str()); //print statement
    }
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());
    fprintf(assemblyout,"%s",$2->getName().c_str()); //print statement
    for(int i=0; i<$4->vec->size(); i++)
    {
        $$->vec->push_back($4->vec->at(i));
        fprintf(fout,"%s",$4->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",$4->vec->at(i)->getName().c_str()); //print statement
    }

    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    $$->return_type="int";
    if ($2->getName()==">=")
    {string temp=newLabel();
        fprintf(assemblyout,"cmp ax,bx\njnge %s\nmov bx,1\njmp end_%s\n%s:\nmov bx,0\nend_%s:\npop ax\n",temp.c_str(),temp.c_str(),temp.c_str(),temp.c_str());

    }
    else if ($2->getName()=="<=")
    {string temp=newLabel();
        fprintf(assemblyout,"cmp ax,bx\njnle %s\nmov bx,1\njmp end_%s\n%s:\nmov bx,0\nend_%s:\npop ax\n",temp.c_str(),temp.c_str(),temp.c_str(),temp.c_str());

    }
    else if ($2->getName()==">")
    {string temp=newLabel();
        fprintf(assemblyout,"cmp ax,bx\njng %s\nmov bx,1\njmp end_%s\n%s:\nmov bx,0\nend_%s:\npop ax\n",temp.c_str(),temp.c_str(),temp.c_str(),temp.c_str());

    }
    else if ($2->getName()=="<")
    {string temp=newLabel();
        fprintf(assemblyout,"cmp ax,bx\njnl %s\nmov bx,1\njmp end_%s\n%s:\nmov bx,0\nend_%s:\npop ax\n",temp.c_str(),temp.c_str(),temp.c_str(),temp.c_str());

    }
    else if ($2->getName()=="==")
    {string temp=newLabel();
        fprintf(assemblyout,"cmp ax,bx\njne %s\nmov bx,1\njmp end_%s\n%s:\nmov bx,0\nend_%s:\npop ax\n",temp.c_str(),temp.c_str(),temp.c_str(),temp.c_str());

    }
    else if ($2->getName()=="!=")
    {string temp=newLabel();
        fprintf(assemblyout,"cmp ax,bx\nje %s\nmov bx,1\njmp end_%s\n%s:\nmov bx,0\nend_%s:\npop ax\n",temp.c_str(),temp.c_str(),temp.c_str(),temp.c_str());

    }


}
;

simple_expression :
term
{
    fprintf(fout,"Line %d: simple_expression : term\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");
    $$->return_type=$1->return_type;


}
| simple_expression  ADDOP {fprintf(assemblyout,"push ax\nmov ax,bx\n");} term
{
    fprintf(fout,"Line %d: simple_expression : simple_expression ADDOP term\n",line_count);
    fprintf(assemblyout,";"); //print statement
    if ($1->return_type=="void" || $4->return_type=="void")
    {
        fprintf(fout,"Error at line %d: Void function used in expression\n",line_count);
        fprintf(errorout,"Error at line %d: Void function used in expression\n",line_count);
        err++;
    }
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",$1->vec->at(i)->getName().c_str()); //print statement
    }
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());
    fprintf(assemblyout,"%s",$2->getName().c_str()); //print statement
    for(int i=0; i<$4->vec->size(); i++)
    {
        $$->vec->push_back($4->vec->at(i));
        fprintf(fout,"%s",$4->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",$4->vec->at(i)->getName().c_str()); //print statement
    }
    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    if ($1->return_type=="float" || $4->return_type=="float")
        $$->return_type="float";
    else
        $$->return_type=$1->return_type;
    if ($2->getName()=="+")
        fprintf(assemblyout,"add bx,ax\npop ax\n");
    else if ($2->getName()=="-")
        fprintf(assemblyout,"sub ax,bx\nmov bx,ax\npop ax\n");

}

;

term :
unary_expression
{
    fprintf(fout,"Line %d: term :	unary_expression\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");
    $$->return_type=$1->return_type;


}
|  term  MULOP {fprintf(assemblyout,"push ax\nmov ax,bx\n");} unary_expression
{
    fprintf(fout,"Line %d: term : term MULOP unary_expression\n",line_count);
fprintf(assemblyout,";"); //print statement
    if ($2->getName()=="%")
    {
        if ($1->return_type!="int")
        {
            fprintf(fout,"Error at line %d: Non-Integer operand on modulus operator\n",line_count);
            fprintf(errorout,"Error at line %d: Non-Integer operand on modulus operator\n",line_count);
            err++;
        }

        else if ($4->return_type!="int")
        {
            fprintf(fout,"Error at line %d: Non-Integer operand on modulus operator\n",line_count);
            fprintf(errorout,"Error at line %d: Non-Integer operand on modulus operator\n",line_count);
            err++;
        }

        if ($4->vec->at(0)->getName()=="0")
        {
            fprintf(fout,"Error at line %d: Modulus by Zero\n",line_count);
            fprintf(errorout,"Error at line %d: Modulus by Zero\n",line_count);
            err++;
        }


    }
    if ($1->return_type=="void" || $4->return_type=="void")
    {
        fprintf(fout,"Error at line %d: Void function used in expression\n",line_count);
        fprintf(errorout,"Error at line %d: Void function used in expression\n",line_count);
        err++;
    }
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",$1->vec->at(i)->getName().c_str()); //print statement
    }
    if ($2->getName()=="%")
        $$->return_type="int";
    else if ($1->return_type=="float" || $4->return_type=="float")
        $$->return_type="float";
    else
        $$->return_type=$1->return_type;
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());
    fprintf(assemblyout,"%s",$2->getName().c_str()); //print statement
    for(int i=0; i<$4->vec->size(); i++)
    {
        $$->vec->push_back($4->vec->at(i));
        fprintf(fout,"%s",$4->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",$4->vec->at(i)->getName().c_str()); //print statement
    }

    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    if ($2->getName()=="*")
    {fprintf(assemblyout,"imul bx\nmov bx,ax\npop ax\n");}
    else if ($2->getName()=="%")
    {
     fprintf(assemblyout,"xor dx,dx\nidiv bx\nmov bx,dx\npop ax\n");
    }
    else
    {
      fprintf(assemblyout,"xor dx,dx\nidiv bx\nmov bx,ax\npop ax\n");
    }
}
;

unary_expression :
ADDOP unary_expression
{
    fprintf(fout,"Line %d: unary_expression : ADDOP unary_expression\n",line_count);
    fprintf(assemblyout,";"); //print statement
    $$=new complex_obj();
    $$->vec->push_back($1);
    fprintf(fout,"%s",$1->getName().c_str());
    fprintf(assemblyout,"%s",$1->getName().c_str()); //print statement
    for(int i=0; i<$2->vec->size(); i++)
    {
        $$->vec->push_back($2->vec->at(i));
        fprintf(fout,"%s",$2->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",$2->vec->at(i)->getName().c_str()); //print statement
    }
    $$->return_type=$2->return_type;
    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    if ($1->getName()=="-")
    fprintf(assemblyout,"neg bx\n");


}
| NOT unary_expression
{
    fprintf(fout,"Line %d: unary_expression : NOT unary_expression\n",line_count);
     fprintf(assemblyout,";"); //print statement
    $$=new complex_obj();
    $$->vec->push_back($1);
    fprintf(fout,"%s",$1->getName().c_str());
    fprintf(assemblyout,"%s",$1->getName().c_str()); //print statement
    for(int i=0; i<$2->vec->size(); i++)
    {
        $$->vec->push_back($2->vec->at(i));
        fprintf(fout,"%s",$2->vec->at(i)->getName().c_str());
         fprintf(assemblyout,"%s",$2->vec->at(i)->getName().c_str()); //print statement
    }
    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    $$->return_type=$2->return_type;
    labels.push(newLabel());
    fprintf(assemblyout,"cmp bx,0\njne %s\nmov bx,1\njmp end_%s\n%s:\nmov bx,0\nend_%s:\n",labels.top().c_str(),labels.top().c_str(),labels.top().c_str(),labels.top().c_str());
    labels.pop();
}
| factor
{
    fprintf(fout,"Line %d: unary_expression : factor\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");
    $$->return_type=$1->return_type;
}

;

factor	:
variable
{
    fprintf(fout,"Line %d: factor	: variable\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
    }
    $$->return_type=$1->return_type;
    fprintf(fout,"\n");
    if ($1->getDataType().find("array")==string::npos)
    {if ($1->vec->at(0)->global==true)
    fprintf(assemblyout,"mov bx,%s\n",$1->vec->at(0)->getName().c_str());
    else
    fprintf(assemblyout,"mov bx,[bp-%d]\n",$1->offset);}
    else
    {if ($1->vec->at(0)->global==true)
        fprintf(assemblyout,"push si\nmov si,ax\nmov bx,[%s+si]\npop si\npop ax\n",$1->vec->at(0)->getName().c_str());
    else
        fprintf(assemblyout,"sub bp,ax\nmov bx,[bp]\nadd bp,ax\npop ax\n");
    }


}
| ID LPAREN argument_list RPAREN
{
    fprintf(fout,"Line %d: factor : ID LPAREN argument_list RPAREN\n",line_count);
    fprintf(assemblyout,";"); //print statement
    $$=new complex_obj();
    SymbolInfo* element=st.Look_up($1->getName());
    if (element==NULL)
    {
        fprintf(fout,"Error at line %d: Undeclared function %s\n",line_count,$1->getName().c_str());
        fprintf(errorout,"Error at line %d: Undeclared function %s\n",line_count,$1->getName().c_str());
        $$->return_type="int";
        err++;
    }
    else
    {
        if (element->num_of_param==-1)
        {
            fprintf(fout,"Error at line %d: %s is not a function\n",line_count,$1->getName().c_str());
            fprintf(errorout,"Error at line %d: %s is not a function\n",line_count,$1->getName().c_str());
            err++;
        }
        $$->return_type=element->getDataType();
    }
    if (element!=NULL && element->num_of_param!=args_type.size())
    {
        fprintf(fout,"Error at line %d: Total number of arguments mismatch in function %s\n",line_count,$1->getName().c_str());
        fprintf(errorout,"Error at line %d: Total number of arguments mismatch in function %s\n",line_count,$1->getName().c_str());
        err++;
    }
    for(int i=0; i<args_type.size(); i++)
    {
        if (element!=NULL && element->parameter_list[i]->getDataType()!=args_type[i])
        {
            if (args_type[i].size()>=6 && args_type[i].substr(args_type[i].size()-6,args_type[i].size())=="_array")
            {
                /*int k=0,j;
                for(j=0;j<$3->vec->size();j++)
                {if (k==i) break;
                	if ($3->vec->at(j)->getName()==",")
                k++;

                }
                fprintf(fout,"Error at line %d: Type Mismatch,%s is an array\n",line_count,$3->vec->at(j)->getName().c_str());*/
                break;
            }
            else
            {
                fprintf(fout,"Error at line %d: %dth argument mismatch in function %s\n",line_count,i+1,$1->getName().c_str());
                fprintf(errorout,"Error at line %d: %dth argument mismatch in function %s\n",line_count,i+1,$1->getName().c_str());
                err++;
            }
            break;
        }
    }

    $$->vec->push_back($1);
    fprintf(fout,"%s",$1->getName().c_str());
    fprintf(assemblyout,"%s",$1->getName().c_str()); //print statement
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());
    fprintf(assemblyout,"%s",$2->getName().c_str()); //print statement

    for(int i=0; i<$3->vec->size(); i++)
    {
        $$->vec->push_back($3->vec->at(i));
        fprintf(fout,"%s",$3->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",$3->vec->at(i)->getName().c_str()); //print statement
    }
    $$->vec->push_back($4);
    fprintf(fout,"%s",$4->getName().c_str());
    fprintf(assemblyout,"%s",$4->getName().c_str()); //print statement
    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    
    fprintf(assemblyout,"call %s\n",$1->getName().c_str());
    for(int i=0;i<args_type.size();i++)
    {
        fprintf(assemblyout,"pop cx\n");
    }
    args_type.clear();
}
| LPAREN expression RPAREN
{
    fprintf(fout,"Line %d: factor : LPAREN expression RPAREN\n",line_count);
    $$=new complex_obj();
    $$->vec->push_back($1);
    fprintf(fout,"%s",$1->getName().c_str());
    $$->return_type=$2->return_type;
    for(int i=0; i<$2->vec->size(); i++)
    {
        $$->vec->push_back($2->vec->at(i));
        fprintf(fout,"%s",$2->vec->at(i)->getName().c_str());
    }
    $$->vec->push_back($3);
    fprintf(fout,"%s",$3->getName().c_str());
    fprintf(fout,"\n");
}
| CONST_INT
{
    fprintf(fout,"Line %d: factor : CONST_INT\n",line_count);
    $$=new complex_obj();
    $$->vec->push_back($1);
    fprintf(fout,"%s",$1->getName().c_str());
    $$->return_type="int";
    fprintf(fout,"\n");
    fprintf(assemblyout,"mov bx,%s\n",$1->getName().c_str());
}
| CONST_FLOAT
{
    fprintf(fout,"Line %d: factor : CONST_FLOAT\n",line_count);
    $$=new complex_obj();
    $$->vec->push_back($1);
    fprintf(fout,"%s",$1->getName().c_str());
    $$->return_type="float";
    fprintf(fout,"\n");

}
| variable INCOP
{
    fprintf(fout,"Line %d: factor : variable INCOP\n",line_count);
    fprintf(assemblyout,";"); //print statement
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",$1->vec->at(i)->getName().c_str()); //print statement
    }
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());
    fprintf(assemblyout,"%s",$2->getName().c_str()); //print statement
    $$->return_type=$1->return_type;
    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
   
    if ($1->getDataType().find("array")==string::npos)
    {if ($1->vec->at(0)->global==true)
    fprintf(assemblyout,"mov bx,%s\ninc %s\n",$1->vec->at(0)->getName().c_str(),$1->vec->at(0)->getName().c_str());
    else
    fprintf(assemblyout,"mov bx,[bp-%d]\ninc [bp-%d]\n",$1->offset,$1->offset);}
    else
    {
    if ($1->vec->at(0)->global==true)
    fprintf(assemblyout,"push si\nmov si,ax\nmov bx,[%s+si]\ninc [%s+si]\npop si\npop ax\n",$1->vec->at(0)->getName().c_str());
    else
    fprintf(assemblyout,"sub bp,ax\nmov bx,[bp]\ninc [bp]\nadd bp,ax\npop ax\n");
    }

}
| variable DECOP
{
    fprintf(fout,"Line %d: factor : variable DECOP\n",line_count);
    fprintf(assemblyout,";"); //print statement
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
        fprintf(assemblyout,"%s",$1->vec->at(i)->getName().c_str()); //print statement
        
    }
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());
    fprintf(assemblyout,"%s",$2->getName().c_str()); //print statement
    $$->return_type=$1->return_type;
    fprintf(fout,"\n");
    fprintf(assemblyout,"\n"); //print statement
    if ($1->getDataType().find("array")==string::npos)
    {if ($1->vec->at(0)->global==true)
    fprintf(assemblyout,"mov bx,%s\npush bx\ndec bx\nmov %s,bx\npop bx\n",$1->vec->at(0)->getName().c_str(),$1->vec->at(0)->getName().c_str());
    else
   fprintf(assemblyout,"mov bx,[bp-%d]\npush bx\ndec bx\nmov [bp-%d],bx\npop bx\n",$1->offset,$1->offset);}
   else
   {if ($1->vec->at(0)->global==true)
    fprintf(assemblyout,"push si\nmov si,ax\nmov bx,[%s+si]\npush bx\ndec bx\nmov [%s+si],bx\npop bx\npop si\npop ax\n",$1->vec->at(0)->getName().c_str());
    else
    fprintf(assemblyout,"sub bp,ax\nmov bx,[bp]\npush bx\ndec bx\nmov [bp],bx\nadd bp,ax\npop bx\npop ax\n");
   }


}

;

argument_list :
arguments
{
    fprintf(fout,"Line %d: argument_list : arguments\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");


}
|
{
    fprintf(fout,"Line %d: argument_list :\n",line_count);
    $$=new complex_obj();
    fprintf(fout,"\n");

}
;

arguments :
arguments COMMA logic_expression
{
    fprintf(fout,"Line %d: arguments : arguments COMMA logic_expression\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
    }
    $$->vec->push_back($2);
    fprintf(fout,"%s",$2->getName().c_str());
    for(int i=0; i<$3->vec->size(); i++)
    {
        $$->vec->push_back($3->vec->at(i));
        fprintf(fout,"%s",$3->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");
    args_type.push_back($3->return_type);
    fprintf(assemblyout,"push bx\n");
}
| logic_expression
{
    fprintf(fout,"Line %d: arguments : logic_expression\n",line_count);
    $$=new complex_obj();
    for(int i=0; i<$1->vec->size(); i++)
    {
        $$->vec->push_back($1->vec->at(i));
        fprintf(fout,"%s",$1->vec->at(i)->getName().c_str());
    }
    fprintf(fout,"\n");
    args_type.push_back($1->return_type);
    fprintf(assemblyout,"push bx\n");
}
;


%%
int main(int argc,char *argv[])
{
    FILE *fp;
    if((fp=fopen(argv[1],"r"))==NULL)
    {
        printf("Cannot Open Input File.\n");
        exit(1);
    }

    fout= fopen("log.txt","w");
    errorout= fopen("error.txt","w");
    assemblyout=fopen("code.asm","w");


    yyin=fp;
    yyparse();
    if (err!=0)
    {
        fclose(assemblyout);
        assemblyout=fopen("code.asm","w");
    }
    

    fclose(fp);
    fclose(fout);
    fclose(errorout);
    fclose(assemblyout);
    optimize_code();

    return 0;
}
