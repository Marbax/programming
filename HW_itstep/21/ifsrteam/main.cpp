#include <iostream>
#include <fstream>
#include <vector>
#include <valarray>
#include <map>
#include <string.h>

/* 
Шифр Цезаря — один из древнейших шифров. При шифровании
каждый символ заменяется другим, отстоящим от него в алфавите на
фиксированное число позиций.

Написать программу, которая позволяет зашифровать содержимое
текстового документа и расшифровать его. Ключ генерируется случайным
образом и сохраняется в файле «key.bin». Зашифрованный текстовый
документ записать в новый файл.
 */

// из массива символов, создает std::map со двигом символов относительно того же массива и заменяет все символы в файле
void caesarCrypt(std::basic_string<char> txt_path, std::basic_string<char> crypted_txt_path, std::basic_string<char> key_path);

// загружает мапу ,которой расшифровует файл
void caesarDecrypt(std::basic_string<char> crypted_txt_path, std::basic_string<char> key_path);

// сохраняет крипто мапу , меняя ключ и значение местами
void saveCryptoMap(std::fstream &fs_key, std::map<char, char> crypto_map);

// выгружает сразу готовую крипто карту
std::map<char, char> loadCryptoMap(std::fstream &fs_key);

// шифрует все симыволы со сдвигом их цифрового кода
void asciiCrypt(std::basic_string<char> txt_path, std::basic_string<char> crypted_txt_path, std::basic_string<char> key_path);

// расшифровует аналогично шифрованию ,но с обратным сдвигом
void asciiDecrypt(std::basic_string<char> crypted_txt_path, std::basic_string<char> key_path);

// сохраняет значеие сдвига
void saveKey(std::fstream &fs_key, unsigned short crypt_key);

// загружает значение сдвига
unsigned short loadKey(std::fstream &fs_key);

//----------------------------_ИСПОЛЬЗОВАНИЕ_--------------------------------
// ./executive_file --crypt path_to_source path_to_out path_where_create_key
// ./executive_file --decrypt path_to_crypted_file path_to_key

int main(int argc, char *argv[])
{
    std::basic_string<char> txt_path = R"(./test.txt)";
    std::basic_string<char> crypted_txt_path = R"(./new_test.txt)";
    std::basic_string<char> key_path = R"(./key.bin)";

    if (static_cast<std::basic_string<char>>(argv[1]) == "--crypt" && argv[2] && argv[3])
    {
        txt_path = static_cast<std::basic_string<char>>(argv[2]);
        crypted_txt_path = static_cast<std::basic_string<char>>(argv[3]);
        if (argv[4])
        {
            key_path = static_cast<std::basic_string<char>>(argv[4]);
        }
        caesarCrypt(txt_path, crypted_txt_path, key_path);
        //asciiCrypt(txt_path, crypted_txt_path, key_path);
        std::cout << "\n\t\tCAESAR CRYPTED THATS FOR U" << std::endl;
    }

    if (static_cast<std::basic_string<char>>(argv[1]) == "--decrypt" && argv[2] && argv[3])
    {
        crypted_txt_path = argv[2];
        key_path = argv[3];
        //asciiDecrypt(crypted_txt_path, key_path);
        caesarDecrypt(crypted_txt_path, key_path);
        std::cout << "\n\t\tCAESAR DECRYPTED THATS FOR U. AVE CAESAR!" << std::endl;
    }
}

void caesarCrypt(std::basic_string<char> txt_path, std::basic_string<char> crypted_txt_path, std::basic_string<char> key_path) try
{
    srand(time(0));
    std::fstream fs;
    unsigned short crypt_key = rand() % 10 + 3;
    std::basic_string<char> symbols("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    std::map<char, char> crypto_map;

    for (size_t i = 0; i < symbols.size(); i++)
    {
        int tmp_i;
        tmp_i = 0;
        if (i + crypt_key >= symbols.size())
        {
            tmp_i = (i + crypt_key) - symbols.size();
            crypto_map.insert(std::pair<char, char>(symbols.at(i), symbols.at(tmp_i)));
        }
        else
        {
            crypto_map.insert(std::pair<char, char>(symbols.at(i), symbols.at(i + crypt_key)));
        }
    }

    fs.open(key_path, std::ios::out | std::ios::binary);
    if (!fs.is_open())
        throw std::logic_error("Can't open " + key_path + " !");
    saveCryptoMap(fs, crypto_map);
    fs.close();

    fs.open(txt_path, std::ios::in);
    if (!fs.is_open())
        throw std::logic_error("Can't open " + txt_path + " !");
    std::vector<std::string> rows;
    std::string buf;
    int i = 0;
    while (std::getline(fs, buf))
    {
        rows.push_back(buf);
        i++;
    }
    fs.close();

    fs.open(crypted_txt_path, std::ios::out | std::ios::trunc);
    if (!fs.is_open())
        throw std::logic_error("Can't open " + crypted_txt_path + " !");
    for (size_t i = 0; i < rows.size(); i++)
    {
        buf.clear();

        for (size_t j = 0; j < rows.at(i).size(); j++)
        {
            if (!crypto_map[rows.at(i).at(j)])
            {
                buf.push_back(rows.at(i).at(j));
            }
            else
                buf.push_back(crypto_map.at(rows.at(i).at(j)));
        }

        fs << buf << "\n";
    }
    fs.close();
}
catch (const std::out_of_range &ex)
{
    std::cerr << "Error on crypt. " << ex.what() << std::endl;
}
catch (const std::logic_error &ex)
{
    std::cerr << "Error on crypt. " << ex.what() << std::endl;
}

void caesarDecrypt(std::basic_string<char> crypted_txt_path, std::basic_string<char> key_path) try
{
    srand(time(0));
    std::fstream fs;
    std::basic_string<char> symbols("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

    fs.open(key_path, std::ios::in | std::ios::binary);
    if (!fs.is_open())
        throw std::logic_error("Can't open " + key_path + " !");
    std::map<char, char> decrypto_map = loadCryptoMap(fs);
    fs.close();
    /* std::map<char, char> decrypto_map;
    for (auto item : crypto_map)
    {
        decrypto_map.insert(std::pair<char, char>(item.second, item.first));
        std::cout << item.second << " -> " << item.first << std::endl;
    } */

    fs.open(crypted_txt_path, std::ios::in);
    if (!fs.is_open())
        throw std::logic_error("Can't open " + crypted_txt_path + " !");
    std::vector<std::string> rows;
    std::string buf;
    int i = 0;
    while (std::getline(fs, buf))
    {
        rows.push_back(buf);
        i++;
    }
    fs.close();

    fs.open(crypted_txt_path, std::ios::out | std::ios::trunc);
    if (!fs.is_open())
        throw std::logic_error("Can't open " + crypted_txt_path + " !");
    for (size_t i = 0; i < rows.size(); i++)
    {
        buf.clear();

        for (size_t j = 0; j < rows.at(i).size(); j++)
        {
            if (!decrypto_map[rows.at(i).at(j)])
            {
                buf.push_back(rows.at(i).at(j));
            }
            else
                buf.push_back(decrypto_map.at(rows.at(i).at(j)));
        }

        fs << buf << "\n";
    }
    fs.close();
}
catch (const std::out_of_range &ex)
{
    std::cerr << "Error on decrypt. " << ex.what() << std::endl;
}
catch (const std::logic_error &ex)
{
    std::cerr << "Error on decrypt. " << ex.what() << std::endl;
}

void saveCryptoMap(std::fstream &fs_key, std::map<char, char> crypto_map)
{
    unsigned short size = crypto_map.size();
    fs_key.write((char *)&size, sizeof(unsigned short));

    // записывает ключи в обратном порядке
    for (auto item : crypto_map)
    {
        fs_key.write((char *)&item.second, sizeof(char));
        fs_key.write((char *)&item.first, sizeof(char));
    }
}

std::map<char, char> loadCryptoMap(std::fstream &fs_key)
{
    unsigned short size;
    fs_key.read((char *)&size, sizeof(unsigned short));
    std::map<char, char> crypto_map;
    char first;
    char second;
    for (size_t i = 0; i < size; i++)
    {
        fs_key.read((char *)&first, sizeof(char));
        fs_key.read((char *)&second, sizeof(char));
        crypto_map.insert(std::pair<char, char>(first, second));
    }
    return crypto_map;
}

void asciiCrypt(std::basic_string<char> txt_path, std::basic_string<char> crypted_txt_path, std::basic_string<char> key_path) try
{
    srand(time(0));
    std::fstream fs;
    unsigned short crypt_key = rand() % 10 + 3;

    fs.open(key_path, std::ios::out | std::ios::binary);
    if (!fs.is_open())
        throw std::logic_error("Can't open " + key_path + " !");
    saveKey(fs, crypt_key);
    fs.close();

    fs.open(txt_path, std::ios::in);
    if (!fs.is_open())
        throw std::logic_error("Can't open " + txt_path + " !");
    std::vector<std::string> rows;
    std::string buf;
    int i = 0;
    while (std::getline(fs, buf))
    {
        rows.push_back(buf);
        i++;
    }
    fs.close();

    fs.open(crypted_txt_path, std::ios::out | std::ios::trunc);
    if (!fs.is_open())
        throw std::logic_error("Can't open " + crypted_txt_path + " !");
    for (size_t i = 0; i < rows.size(); i++)
    {
        buf.clear();

        for (size_t j = 0; j < rows.at(i).size(); j++)
        {
            buf.push_back(static_cast<unsigned short>(rows.at(i).at(j)) + crypt_key);
        }

        fs << buf << "\n";
    }
    fs.close();
}
catch (const std::out_of_range &ex)
{
    std::cerr << ex.what() << std::endl;
}
catch (const std::logic_error &ex)
{
    std::cerr << "Error. " << ex.what() << std::endl;
}

void asciiDecrypt(std::basic_string<char> crypted_txt_path, std::basic_string<char> key_path) try
{
    std::fstream fs;

    fs.open(key_path, std::ios::in | std::ios::binary);
    if (!fs.is_open())
        throw std::logic_error("Can't open " + key_path + " !");
    unsigned short crypt_key = loadKey(fs);
    fs.close();

    fs.open(crypted_txt_path, std::ios::in);
    if (!fs.is_open())
        throw std::logic_error("Can't open " + crypted_txt_path + " !");
    std::vector<std::string> rows;
    std::string buf;
    int i = 0;
    while (std::getline(fs, buf))
    {
        rows.push_back(buf);
        i++;
    }

    fs.close();
    fs.open(crypted_txt_path, std::ios::out | std::ios::trunc);
    if (!fs.is_open())
        throw std::logic_error("Can't open " + crypted_txt_path + " !");
    for (size_t i = 0; i < rows.size(); i++)
    {
        buf.clear();

        for (size_t j = 0; j < rows.at(i).size(); j++)
        {
            buf.push_back(static_cast<char>((rows.at(i).at(j)) - crypt_key));
        }

        fs << buf << "\n";
    }
    fs.close();
}
catch (const std::out_of_range &ex)
{
    std::cerr << ex.what() << std::endl;
}
catch (const std::logic_error &ex)
{
    std::cerr << "Error. " << ex.what() << std::endl;
}

void saveKey(std::fstream &fs_key, unsigned short crypt_key)
{
    fs_key.write((char *)&crypt_key, sizeof(unsigned short));
}

unsigned short loadKey(std::fstream &fs_key)
{
    unsigned short crypt_key;
    fs_key.read((char *)&crypt_key, sizeof(unsigned short));
    return crypt_key;
}
