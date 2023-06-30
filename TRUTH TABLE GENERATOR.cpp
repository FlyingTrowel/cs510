#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {

    string expression;
    int totalVar;
    
    cout<<"Instruction : " <<endl;
    cout<<"Please use :-" <<endl;
    cout<<"P as first variable" <<endl;
    cout<<"Q as second" <<endl;
    cout<<"R as third" <<endl;
    cout<<"S as fourth" <<endl;
    cout<<"~ as NOT" <<endl;
    cout<<"v as OR" <<endl;
    cout<<"^ as AND" <<endl;
    cout<<"Enter propositional logic expression : ";
    getline(cin, expression);
    
    cout<<"Enter amount of variable : ";
    cin>>totalVar;
    
    const int totalRow = pow(2, totalVar);
    const int totalCol = totalVar;
    int table[totalRow][totalCol];
    int temp[totalRow][totalCol];
    int result[totalRow];
    
    //1 input
    if(totalVar == 1)
    {
        int i = 0;
        table[i][i] = 1;
        table[i+1][i] = 0;
        result[i] = 1;
        result[i+1] = 0;
        bool exist = (expression.find('~') != string::npos);
        if(exist)
        {
            for(int i=0; i<totalRow; i++)
            {
                if(result[i] == 0)
                { result[i] = 1; }
                    
                else if(result[i] == 1)
                { result[i] = 0; }
            }
        }
        cout<<"P | " <<expression <<endl;
    }
    
    //2 input
    else if(totalVar == 2)
    {
        //first var
        int i;
        for(i=0; i<totalRow / 2; i++)
        {
            table[i][0] = 1;
        }
        while(i<totalRow)
        {
            table[i][0] = 0;
            i++;
        }
        
        //second var
        for(i=0; i<totalRow; i=i+2)
        {
            table[i][1] = 1;
            table[i+1][1] = 0;
        }
        
        cout<<"P Q | " <<expression <<endl;
        
        bool modified1 = false;
        bool modified2 = false;
        //loop that check every character in a string
        for (int e = 0; e < expression.length(); e++) {
            
            bool exist = (expression.find('~') != string::npos);
            if (expression[e] == '~') {
                
                
                if(expression[e+1] == 'P')
                {
                    //cout<<"hooray" <<endl;
                    for(int i=0; i<totalRow; i++)
                    {
                        if(table[i][0] == 0)
                        { temp[i][0] = 1; }
                    
                        else if(table[i][0] == 1)
                        { temp[i][0] = 0; }
                    }
                    modified1 = true;
                }
                else if(modified1 == false)
                {
                    for(int i=0; i<totalRow; i++)
                    {
                        temp[i][0] = table[i][0];
                    }
                }
                
                if(expression[e+1] == 'Q')
                {
                    for(int i=0; i<totalRow; i++)
                    {
                        if(table[i][1] == 0)
                        { temp[i][1] = 1; }
                    
                        else if(table[i][1] == 1)
                        { temp[i][1] = 0; }
                    }
                    modified2 = true;
                }
                else if(modified2 == false)
                {
                    for(int i=0; i<totalRow; i++)
                    {
                        temp[i][1] = table[i][1];
                    }
                }
            }
            
            if(!exist)
            {
                //cout <<"hooray" <<endl;
                for (int i = 0; i < totalRow; i++) {
                    for (int j = 0; j < totalCol; j++) {
                        temp[i][j] = table[i][j];
                    }
                }
            }
        }
        //second loop to insert output ( was used to ensure that loop doesnt overlap)
        for (int e = 0; e < expression.length(); e++) {
            if (expression[e] == 'v')
            {
                for(int i=0; i < totalRow; i++)
                {
                    if(temp[i][0] == 1 || temp[i][1] == 1)
                    { result[i] = 1; }
                    else
                    { result[i] = 0; }
                }
            }
            
            if (expression[e] == '^')
            {
                for(int i=0; i < totalRow; i++)
                {
                    if(temp[i][0] == 1 && temp[i][1] == 1)
                    { result[i] = 1; }
                    else
                    { result[i] = 0; }
                }
            }
        }
    }
    
    //3 input
/*    else if(totalVar == 3)
    {
        //first var
        int i;
        for(i=0; i<totalRow / 2; i++)
        {
            table[i][0] = 1;
        }
        while(i<totalRow)
        {
            table[i][0] = 0;
            i++;
        }
        
        //second var
        for(i=0; i<totalRow; i=i+4)
        {
            table[i][1] = 1;
            table[i+1][1] = 1;
        }
        for(i=2; i<totalRow; i=i+4)
        {
            table[i][1] = 0;
            table[i+1][1] = 0;
        }
        
        //third var
        for(i=0; i<totalRow; i=i+2) 
        {
            table[i][2] = 1;
            table[i+1][2] = 0;
        }
        
        cout<<"P Q R | " <<expression <<endl;
    }
    
    //4 input
    else if(totalVar == 4)
    {
        //first var
        int i;
        for(i=0; i<totalRow / 2; i++)
        {
            table[i][0] = 1;
        }
        while(i<totalRow)
        {
            table[i][0] = 0;
            i++;
        }
        
        //second var
        for(i=0; i<totalRow; i=i+8)
        {
            table[i][1] = 1;
            table[i+1][1] = 1;
            table[i+2][1] = 1;
            table[i+3][1] = 1;
        }
        for(i=4; i<totalRow; i=i+8)
        {
            table[i][1] = 0;
            table[i+1][1] = 0;
            table[i+2][1] = 0;
            table[i+3][1] = 0;
        }
        
        //third var
        for(i=0; i<totalRow; i=i+4)
        {
            table[i][2] = 1;
            table[i+1][2] = 1;
        }
        for(i=2; i<totalRow; i=i+4)
        {
            table[i][2] = 0;
            table[i+1][2] = 0;
        }
        
        //fourth var
        for(i=0; i<totalRow; i=i+2)
        {
            table[i][3] = 1;
            table[i+1][3] = 0;
        }
        
        cout<<"P Q R S | " <<expression <<endl;
    }
    */
    
    //DISPLAY ARRAY
    //cout<<totalRow <<endl;
    
    for (int i = 0; i < totalRow; i++) {
        for (int j = 0; j < totalCol; j++) {
            cout << table[i][j] << " ";
        }
        cout << "| " <<result[i] <<endl;
    }
    
    return 0;
}
