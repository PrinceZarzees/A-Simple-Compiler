#include<bits/stdc++.h>
void optimize_code()
{
    fstream source,dest;
   source.open("code.asm",ios::in);
   dest.open("optimized_code.asm",ios::out);
   string prev1,prev2,prev3;
   string word1,word2,word3;
   prev1=prev2=prev3="null";
   string line;
   int spcount=0;
    while(getline(source, line)){ 
        stringstream ss(line);
        ss>>word1>>word2;
        if (word1.at(0)==';')
        {
            dest<<line<<endl;
        }
        else if (word1=="mov")
        {
            if (prev1=="sub" && prev2=="sp" && prev3=="2")
            {
                dest<<"sub sp,"<<spcount<<"\n";
                if (spcount>2)
                {dest<<";peepholed consecutive subs\n";}
                spcount=0;
            }
              if (prev1=="mov" && prev2=="bx" && prev3=="0")
            {
                dest<<"mov bx,0\n";
            }
            word3=word2.substr(word2.find(",")+1,word2.size());
            word2=word2.substr(0,word2.find(","));
          
            if (prev1=="mov" && prev2==word3 && prev3==word2)
            {dest<<";peepholed "<<line<<"\n";
            }
            else if (word2=="bx" && word3=="0")
            {
                //do not print;
            }
            else
            {
                dest<<line<<"\n";
            }
            prev1=word1;
            prev2=word2;
            prev3=word3;
        }
        else if (word1=="sub")
        {
            word3=word2.substr(word2.find(",")+1,word2.size());
         word2=word2.substr(0,word2.find(","));
         if (word2=="sp" && word3=="2")
         {
            spcount+=2;
            if (prev1=="mov" && prev2=="bx" && prev3=="0")
         {
            dest<<"mov bx,0"<<"\n";
         }
         }
         else
         {if (prev1=="sub" && prev2=="sp" && prev3=="2")
            {
                dest<<"sub sp,"<<spcount<<"\n";
                if (spcount>2)
                {dest<<";peepholed consecutive subs\n";}
                spcount=0;
                dest<<line<<endl;
            }
         else if (prev1=="mov" && prev2=="bx" && prev3=="0" && word2=="bx")
         {
            dest<<"mov bx,"<<word3<<"\n";
            dest<<";peepholed "<<line<<"\n";
         }
         else if (prev1=="mov" && prev2=="bx" && prev3=="0")
         {
            dest<<"mov bx,0"<<"\n";
            dest<<line<<"\n";
         }
         else
            dest<<line<<"\n";
         }
         prev1=word1;
         prev2=word2;
         prev3=word3;

        }
        else if (word1=="add")
        {
            if (prev1=="sub" && prev2=="sp" && prev3=="2")
            {
                dest<<"sub sp,"<<spcount<<"\n";
                if (spcount>2)
                {dest<<";peepholed consecutive subs\n";}
                spcount=0;
                dest<<line<<endl;
            }
            word3=word2.substr(word2.find(",")+1,word2.size());
            word2=word2.substr(0,word2.find(","));
        if (prev1=="mov" && prev2=="bx" && prev3=="0" && word2=="bx")
        {
         dest<<"mov bx,"<<word3<<"\n";
         dest<<";peepholed "<<line<<"\n";
        }
        else if (prev1=="mov" && prev2=="bx" && prev3=="0")
         {
            dest<<"mov bx,0"<<"\n";
            dest<<line<<endl;
         }
        else
        dest<<line<<"\n";
        prev1=word1;
        prev2=word2;
        prev3=word3;
        }
        else if((word1=="imul" || word1=="idiv") && word2=="bx")
        {
            if (prev1=="mov" && prev2=="bx" && prev3=="0")
            {
                dest<<"mov bx,0\n";
            }
            if (prev1=="sub" && prev2=="sp" && prev3=="2")
            {
                dest<<"sub sp,"<<spcount<<"\n";
                if (spcount>2)
                {dest<<";peepholed consecutive subs\n";}
                spcount=0;
            }

            if (prev1=="mov" && prev2=="bx" && prev3=="1")
        { dest<<";peepholed "<<line<<"\n";
        }
        else
        {
            dest<<line<<endl;
        }
        prev1=word1;
        prev2=word2;


        }
        else
        {  
            if (prev1=="mov" && prev2=="bx" && prev3=="0")
            {
                dest<<"mov bx,0\n";
            }
            if (prev1=="sub" && prev2=="sp" && prev3=="2")
            {
                dest<<"sub sp,"<<spcount<<"\n";
                if (spcount>2)
                {dest<<";peepholed consecutive subs\n";}
                spcount=0;
            }

        dest<<line<<"\n";
        prev1=word1;
        prev2=word2;
        prev3=word3;
        }
    }

    dest.close();

}
