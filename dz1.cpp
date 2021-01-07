// dz1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

  string text = "you come on like a bloodstained hurricane, leave me alone let me be this time, you carry on like a holy man pushing redemption I dont want to mention, the reason i know that i am Stricken and cant let you go ";
struct  Block 
{
   string block;
    uint8_t blocksize = 12;

  };
void fill_blocks(  string& text, vector<Block>& block1)
{
    int a = 0;
    string textdt = text; 
    char zaglushka = '=';
    while (textdt.length() % 12 != 0) 
    {
        textdt.push_back(zaglushka);
    }
    int how_many_blocks = textdt.length() /12;   
    block1.resize(how_many_blocks);
    for (int j = 0; j < textdt.length() / 12; j++)
    {
        block1[j].block += (textdt.substr(a, 12));
        a += 12;        
    }

}    
void create_gamma(Block& gamma )
{        
    for (int g = 0; g <12 ; g++) 
    {    
        int gammas = rand();
        gamma.block .push_back(gammas);                            
       }
    }
Block operator^ (Block& block1, Block& gamma) {
    Block Ksor;
    for (int h = 0; h < 12; h++) {
        Ksor.block.push_back (block1.block[h] ^ gamma.block[h]);                
    }  
    return Ksor;  
  }

Block operator << (Block& Ksor, int u) {
    Block shift;
    unsigned char second;
    unsigned char last;
    unsigned char first;
    
    for (int y = 0; y < Ksor.block.size()-1; y++) {

       second = (static_cast<unsigned char>(Ksor.block[y + 1]) >> 1); 

        shift.block.push_back((static_cast<unsigned char> (Ksor.block[y]) << u) | second);
     
    }
   last = static_cast<unsigned char> (Ksor.block[11]) << u;
   first = static_cast<unsigned char> (Ksor.block[0]) >> 1;
  shift.block.push_back (last | first);
    return shift;
 }
 
Block operator >> (Block& shift, int u) {
    Block shift_2;
    unsigned char second_2;
    unsigned char last_2;
    unsigned char first_2;

    for (int y = 0; y < shift.block.size() - 1; y++) {

        second_2 = (static_cast<unsigned char>(shift.block[y]) << 1);

        shift_2.block.push_back((static_cast<unsigned char> (shift.block[y+1]) >> u) | second_2);

    }
    last_2 = static_cast<unsigned char> (shift.block[11]) << 1;
    first_2 = static_cast<unsigned char> (shift.block[0]) >> u;
    string abc;
    abc. push_back(last_2 | first_2);
   shift_2.block = abc + shift_2.block ;
    return shift_2;
}

int main(int argc, char* argv[])

 {

    ofstream file("hw1.txt", ios::out);
    file << text << endl;
    file.close();  
    int random = atoi(argv[1]);
     srand(random);
     
     vector<Block> block1; 
     string textdt = text;
     char zaglushka = '=';
     while (textdt.length() % 12 != 0)
     {
         textdt.push_back(zaglushka);
     }
     int how_many_blocks = textdt.length() / 12; 

     fill_blocks(text, block1);
     int a = 0;
     vector <Block> gamma(how_many_blocks);
     vector <Block> gamma_2(how_many_blocks);
     for (int i = 0; i < how_many_blocks; i++)
     {
         create_gamma(gamma[i]);
     }
     for (int t = 0; t < how_many_blocks; t++) {
         
         block1[t] = block1[t] ^ gamma[t];     
     }
    
     for (int s = 0; s < how_many_blocks; s++) {
         
            block1[s] = block1[s] << 7;
                     
     }
    
     for (int d = 0; d < how_many_blocks; d++) {
         
         block1[d] = (block1[d] >> 7) ;
     }   
     srand(random);
     for (int o = 0; o < how_many_blocks; o++)
     {
         create_gamma(gamma_2[o]);
     }
     for (int e = 0; e < how_many_blocks; e++) 
     {
         block1[e] = block1[e] ^ gamma_2[e];

         ofstream file("hw1.txt", ios::app);
         file << block1[e].block;
         file.close();
     }
    
     
     

     
}




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
