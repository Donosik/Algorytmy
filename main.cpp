#include <iostream>
#include <string>
#include <vector>

std::vector<int> BruteForce(std::string ciag, std::string szukanyCiag)
{
    std::vector<int> index;

    for (int i = 0; i < ciag.size(); i++)
    {
        if (ciag[i] == szukanyCiag[0])
        {
            bool jestCiag = true;
            for (int j = i; j < szukanyCiag.size() + i; j++)
            {
                if (ciag[j] != szukanyCiag[j - i])
                {
                    jestCiag = false;
                    break;
                }
            }
            if (jestCiag)
            {
                index.push_back(i);
            }
        }
    }

    return index;
}

//TODO:
std::string Palindrom(std::string ciag)
{
    std::string palindrom = "";

    for (int i = 0; i < ciag.size(); i++)
    {
        for (int j = ciag.size() - 1; j > i; j--)
        {
            if (ciag[i] == ciag[j])
            {
                bool jestPalindrom = true;
                for (int k = i; k < j; k++)
                {
                    if (ciag[k] != ciag[j - (k - i)])
                    {
                        jestPalindrom = false;
                        break;
                    }
                }
                if (jestPalindrom)
                {
                    for (int k = i; k <= j; k++)
                    {
                        palindrom += ciag[k];
                    }
                    char a = palindrom[0];
                    for (int k = 0; k < palindrom.size(); k++)
                    {
                        if (a != palindrom[k])
                        {
                            return palindrom;
                        }
                    }
                    palindrom = "";
                    continue;
                }
            }
        }
    }

    return palindrom;
}

bool BoyeraMoorea(std::string ciag, std::string wzorzec)
{
    // przechodzi przez cały wyraz
    for (int i = wzorzec.size() - 1; i < ciag.size();)
    {
        bool jestLitera = false;
        // przechodzi przez cały wzorzec żeby sprawdzić czy litera jest we wzorcu
        for (int j = wzorzec.size() - 1; j >= 0; j--)
        {
            // jesli litera jest we wzorcu
            if (ciag[i] == wzorzec[j])
            {
                // jesli litera jest ostatnia we wzorcu
                if (j == wzorzec.size() - 1)
                {
                    bool jestWzorzec = true;
                    // sprawdzamy czy cale slowo jest we wzorcu
                    for (int k = 0; k < wzorzec.size(); k++)
                    {
                        if (ciag[i - j + k] != wzorzec[k])
                        {
                            jestWzorzec = false;
                        }
                    }
                    // gdy jest znalezione to zwracamy true
                    if (jestWzorzec)
                    {
                        return true;
                    }
                }
                i++;
                jestLitera = true;
                break;
            }

        }
        if (!jestLitera)
        {
            i += wzorzec.size();
        }
    }

    // jesli wszystko przeszlo to nie ma wzorca w slowie
    return false;
}

int Konwersja(int liczba, bool na2)
{
    int wynik = 0;
    if (na2)
    {
        std::string x = "";

        while (liczba > 0)
        {
            if (liczba % 2 == 0)
            {
                x = "0" + x;
            }
            else
            {
                x = "1" + x;
                liczba--;
            }
            liczba = liczba / 2;
        }
        wynik = std::stoi(x);
    }
    else
    {
        std::string x = std::to_string(liczba);
        for (int i = x.size() - 1; i >= 0; i--)
        {
            if (x[i] == '1')
            {
                wynik += pow(2, x.size() - 1 - i);
            }
        }

    }
    return wynik;
}

std::string negatyw(std::string ciag)
{
    std::string negatyw = "";

    for (int i = 0; i < ciag.size(); i++)
    {
        int a = ciag[i];
        a = 255 - a;
        char b = a;
        negatyw += b;
    }

    return negatyw;
}

int main()
{
    std::cout << "------" << std::endl;
    {
        std::vector<int> array = BruteForce("BAABABAAABAAB", "AAB");
        for (auto x: array)
        {
            std::cout << x << std::endl;
        }
    }
    std::cout << "------" << std::endl;
    {
        std::cout << Palindrom("CABCBABBB") << std::endl;
        std::cout << Palindrom("CABCABBB") << std::endl;
    }
    std::cout << "------" << std::endl;
    {
        std::cout << BoyeraMoorea("Z pamietnika mlodej lekarki", "lek") << std::endl;
    }
    std::cout << "------" << std::endl;
    {
        std::cout << Konwersja(1000, false) << std::endl;
    }
    std::cout << "------" << std::endl;
    {
        std::cout << negatyw("Znaki") << std::endl;
    }
    std::cout << "------" << std::endl;
    return 0;
}
