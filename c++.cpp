#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <sstream>
#include <array>

using namespace std;

// 随机数生成器（现代C++风格）
mt19937 rng(random_device{}());

// 基础数据集
const vector<string> last_names = {
    "王", "李", "张", "刘", "陈", "杨", "黄", "赵", "周", "吴"
};

const vector<string> male_names = {
    "伟", "强", "磊", "军", "勇", 
    "杰", "涛", "斌", "超", "鹏"
};

const vector<string> female_names = {
    "芳", "娜", "敏", "静", "丽",
    "娟", "艳", "玲", "霞", "婷"
};

const array<string, 5> provinces = {
    "北京市", "上海市", "广东省", "浙江省", "江苏省"
};

// 地址生成器
struct AddressGenerator {
    unordered_map<string, vector<string>> cities = {
        {"北京市", {"市辖区"}},
        {"上海市", {"市辖区"}},
        {"广东省", {"广州市", "深圳市", "东莞市"}},
        {"浙江省", {"杭州市", "宁波市", "温州市"}},
        {"江苏省", {"南京市", "苏州市", "无锡市"}}
    };

    vector<string> streets = {
        "中山路", "解放路", "人民路", 
        "建设路", "和平街", "创业路"
    };
};

// 日期生成工具
class DateGenerator {
public:
    static string generate_birthdate(int min_age = 18, int max_age = 80) {
        uniform_int_distribution<int> year_dist(1940, 2005);
        uniform_int_distribution<int> month_dist(1, 12);
        
        int year = year_dist(rng);
        int month = month_dist(rng);
        int day = generate_day(year, month);

        return format_date(year, month, day);
    }

private:
    static int generate_day(int year, int month) {
        static const array<int, 13> days_in_month = {
            0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
        };

        int max_day = days_in_month[month];
        if (month == 2 && is_leap_year(year)) max_day = 29;
        
        uniform_int_distribution<int> day_dist(1, max_day);
        return day_dist(rng);
    }

    static bool is_leap_year(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    static string format_date(int y, int m, int d) {
        ostringstream oss;
        oss << y << "-" << (m < 10 ? "0" : "") << m << "-" 
            << (d < 10 ? "0" : "") << d;
        return oss.str();
    }
};

// 虚拟身份生成类
class VirtualIdentityGenerator {
public:
    struct Identity {
        string name;
        string gender;
        string birthdate;
        string address;
        string phone;
        string email;
    };

    Identity generate() {
        Identity id;
        id.gender = random_gender();
        id.name = generate_name(id.gender);
        id.birthdate = DateGenerator::generate_birthdate();
        id.address = generate_address();
        id.phone = generate_phone();
        id.email = generate_email(id.name);
        return id;
    }

private:
    string random_gender() {
        return uniform_int_distribution<>(0, 1)(rng) ? "男" : "女";
    }

    string generate_name(const string& gender) {
        uniform_int_distribution<> last_dist(0, last_names.size()-1);
        string last = last_names[last_dist(rng)];
        
        const auto& first_pool = (gender == "男") ? male_names : female_names;
        uniform_int_distribution<> first_dist(0, first_pool.size()-1);
        
        return last + first_pool[first_dist(rng)];
    }

    string generate_address() {
        AddressGenerator addr;
        uniform_int_distribution<> prov_dist(0, provinces.size()-1);
        string province = provinces[prov_dist(rng)];
        
        auto& city_list = addr.cities[province];
        uniform_int_distribution<> city_dist(0, city_list.size()-1);
        
        uniform_int_distribution<> street_dist(0, addr.streets.size()-1);
        uniform_int_distribution<> num_dist(1, 999);
        
        ostringstream oss;
        oss << province << city_list[city_dist(rng)] 
            << addr.streets[street_dist(rng)] 
            << num_dist(rng) << "号";
        return oss.str();
    }

    string generate_phone() {
        static vector<string> prefixes = {"13", "15", "18", "19"};
        uniform_int_distribution<> prefix_dist(0, prefixes.size()-1);
        
        ostringstream oss;
        oss << prefixes[prefix_dist(rng)];
        for (int i = 0; i < 9; ++i) {
            oss << uniform_int_distribution<>(0, 9)(rng);
        }
        return oss.str();
    }

    string generate_email(const string& name) {
        static vector<string> domains = {"example.com", "testmail.net", "dummy.org"};
        uniform_int_distribution<> domain_dist(0, domains.size()-1);
        
        string clean_name;
        for (char c : name) { // 移除姓名中的空格（中文不需要）
            if (!isspace(c)) clean_name += tolower(c);
        }
        
        uniform_int_distribution<> num_dist(10, 99);
        return clean_name + to_string(num_dist(rng)) + "@" + domains[domain_dist(rng)];
    }
};

// 示例用法
int main() {
    VirtualIdentityGenerator generator;
    auto id = generator.generate();

    cout << "虚拟身份信息：" << endl
         << "姓名: " << id.name << endl
         << "性别: " << id.gender << endl
         << "出生日期: " << id.birthdate << endl
         << "地址: " << id.address << endl
         << "手机: " << id.phone << endl
         << "邮箱: " << id.email << endl;

    return 0;
}
