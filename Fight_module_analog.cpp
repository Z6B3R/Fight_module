#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
struct player
{
    std::string name, tag;
    int HP = -1, AC = -1, IP = -1;
    void set(std::string utag, std::string uname, int uhp, int uac, int uip)
    {
        name = uname;
        HP = uhp;
        AC = uac;
        IP = uip;
        tag = utag;
    }
    void show_players_info(std::vector<player> &party)
    {
        for (int x = 0; x < party.size(); ++x)
        {
            std::cout << party[x].tag << '|' << party[x].name << '|' << party[x].HP << '|' << party[x].AC << '|' << party[x].IP << std::endl;
        }
        std::cout << "__________________" << std::endl;
    }
};

bool create_member(player &mem, std::vector<player> &fight)
{
    std::string name; int hp = 0, ac = 0, ip = 0;
    int num = 0;
    std::cout << "Количество игроков: "; std::cin >> num;
    for (int x = 0; x < num; ++x)
    {
        std::string tag = "human";
        std::cout << "Введи имя персонажа: "; std::cin >> name;
        std::cout << "\nВведи хиты: "; std::cin >> hp;
        std::cout << "\nВведи очки брони: "; std::cin >> ac;
        std::cout << "\nВведи очки инициативы: "; std::cin >> ip;
        mem.set(tag, name, hp, ac, ip);
        fight.push_back(mem);
    }
    std::cout << "Введи количество противников: "; std::cin >> num;
    for (int x = 0; x < num; ++x)
    {
        std::string tag = "npc";
        std::cout << "Введи имя противника: "; std::cin >> name;
        std::cout << "\nВведи хиты: "; std::cin >> hp;
        std::cout << "\nВведи очки брони: "; std::cin >> ac;
        std::cout << "\nВведи очки инициативы: "; std::cin >> ip;
        mem.set(tag, name, hp, ac, ip);
        fight.push_back(mem);
    }
    return true;
}
bool well_sort_IP(std::vector<player> &party)
{
    bool check_sort = false;
    do
    {
        for (int x = 0; x < party.size();)
        {
            if (x + 1 >= party.size())
                break;
            else if (party[x].IP < party[x + 1].IP)
            {
                std::swap(party[x], party[x + 1]);
                ++x;
            }
            else if (party[x].IP == party[x + 1].IP && party[x].tag == "npc")
            {
                std::swap(party[x], party[x + 1]);
                ++x;
            }
            else
                ++x;
        }
        for (int x = 0; x < party.size(); ++x)
        {
            if (x + 1 >= party.size())
                break;
            else if (party[x].IP > party[x + 1].IP || party[x].IP == party[x+1].IP)
            {
                check_sort = true;
                continue;
            }
            else
            {
                check_sort = false;
                break;
            }

        }
    } while (check_sort == false);
    return true;
}
int main()
{
    setlocale(LC_ALL, "");
    player newmem;
    std::vector<player>fight_party;
    create_member(newmem, fight_party);
    newmem.show_players_info(fight_party);
    well_sort_IP(fight_party);
    newmem.show_players_info(fight_party);
}
