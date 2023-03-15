#include <iostream>

using namespace std;

//Функция вывода показания спидометра
void speed_output(const float &speed)
{
    char speedStr[8];
    sprintf_s(speedStr, "% .1f", speed);
    string speedDig = (string)speedStr + " KM/H";
    cout << endl << "--SPEED--" << endl << speedDig << endl << endl;
}
//Функциия проверки пользовательского ввода
bool speed_check(float &speed, const float &delta)
{
    float currentSpeed = speed + delta;
    if (currentSpeed > 150)
    {
        cout << "Speed limit exceeded!" << endl;
        return false;
    }
    else
    {
        speed = currentSpeed;
        return true;
    }
}

int main()
{
    cout << "-----Speedometer-----" << endl;
    float speed = 0.0f;
    //Цикл имитации поездки
    do 
    {
        float delta;
        //Ввод разницы скорости
        do 
        {
            cout << "Enter speed difference (km/h): ";
            cin >> delta;
        } while (!speed_check(speed,delta));
        //Проверка на отрицательное значение
        if (speed < 0.0f) speed = 0.0f;
        //Вывод показания спидометра
        speed_output(speed);
    } while (speed >= 0.01f);
    cout << "Trip completed!" << endl;
    return 0;
}