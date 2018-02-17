#include <iostream>
#include <list>
#include <map>
#include <cstdlib>

using namespace std;

class lru_cache
{
public:
    lru_cache(int cache_size):cache_hit(0) {m_cache_size = cache_size;}
    ~lru_cache(){}
    
    float get_cache_hit_ratio() {
        cout << "cache " << cache_hit << " " << cmds_serviced << endl;
        return (cache_hit/cmds_serviced);
    }

    int get_value(int addr)
    {
        ++cmds_serviced;
        if (cache.find(addr) != cache.end())
        {
            int value = cache[addr];
            mru.remove(addr);
            mru.push_back(addr);
            ++cache_hit;
            return value;
        }
        return -1;
    }

    void set_value(int addr, int value)
    {
        if (cache.find(addr) != cache.end())
        {
            mru.remove(addr);
        }
        else
        {
            if (cache.size() >= m_cache_size)
            {
                cache.erase(mru.front());
                mru.pop_front();
            }
        }
        mru.push_back(addr);
        cache[addr] = value;
    }

private:
    int m_cache_size;
    list <int> mru;
    map <int, int> cache;
    float cache_hit;
    float cmds_serviced;

};

int main(int argc, char* argv[])
{
    lru_cache* cache = new lru_cache(1000);

    for (int i = 0; i < 100000; ++i)
    {
        int addr = rand()%10000;
        cache->set_value(addr, i);

        addr = rand()%10000;
        cache->get_value(addr);
        
    }

    cout << "hit ratio" << (float)cache->get_cache_hit_ratio() << endl;

    return 0;
}

