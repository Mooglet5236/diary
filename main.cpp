#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

fstream file;

char content[100];
char date[100];
char filename[100];
char read[100];

int menu()
{
    int choice;
    cout << "請輸入要執行的動作：(1)寫檔 (2)讀檔 (3)離開" << endl;
    cin >> choice;
    return choice;
}

void basicWriteInput()
{
    cout << "請輸入要寫入的檔名" << endl;
    cin >> filename;
    
    cout << "請輸入要寫入的日期 yyyy-mm-dd" << endl;
    cin >> date;
    
    cout << "請輸入要寫入的內容" << endl;
    cin >> content;
}

void write()
{
    strcat(date,"\n");
    strcat(date,content);
    strcat(date, "\n");
}

void encode()
{
    size_t length = strlen(date);
    
    for ( int i = 0; i <= length; i = i + 1 )
    {
        date[i] = date[i] + 100;
    }
    
}

void writeIn()
{
    size_t length = strlen(date);
    file.open(filename,ios::app);
    file.write(date,length);
    file.close();
}

void clear()
{
    size_t length = strlen(date);
    for ( int i = 0; i <= length; i = i + 1)
    {
        date[i] = 0;
    }
}

int askRewrite()
{
    int yesNo;
    cout << "請問是否要再寫一次？(1)寫 (2)不寫" << endl;
    cin >>yesNo;
    return yesNo;
}

void basicReadInput()
{
    cout << "請輸入要讀的檔名" << endl;
    cin >> filename;
    
    size_t length = strlen(date);
    
    file.open(filename, ios::in);
    file.read(date,500);
    for ( int i = 0; i <= length; i = i + 1 )
    {
        date[i] = date[i] - 100;
    }
    cout << date << endl;
    file.close();
}

int main()
{
    int choice ;
    int ans;
    
    do{
        choice = menu();
        if ( choice == 1 )
        {
            do{
                ans = 0;
                basicWriteInput();
                write();
                encode();
                writeIn();
                clear();
                ans = askRewrite();
            }while(ans == 1);
        }
        else if ( choice == 2 )
        {
            basicReadInput();
        }
    }while(choice != 3);
}
